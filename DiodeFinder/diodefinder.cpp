#include "diodefinder.h"


using namespace std;
using namespace cv;


fstream DiodeFinder::fifo;


DiodeFinder::DiodeFinder() {
    hu=hd=lu=ld=su=sd=blur=median=tRatio=epsilon=0;
    saveData = false;
    mkfifo("data.fifo", 0777);
}


DiodeFinder::DiodeFinder(QLabel* camera_label, QLabel* processed_label, QLabel* output_label) {
    this->camera_label = camera_label;
    this->processed_label = processed_label;
    this->output_label = output_label;
    hu=hd=lu=ld=su=sd=blur=median=tRatio=epsilon=0;
    videoCap = VideoCapture(1);
    saveData = false;
    mkfifo("data.fifo", 0777);
}


DiodeFinder::~DiodeFinder() {
    if (fifo.is_open()) fifo.close();
}


bool DiodeFinder::isOk() {
    return videoCap.isOpened();
}


void DiodeFinder::capture() {
    videoCap >> camera_mat;
    cvtColor(camera_mat, camera_mat, CV_BGR2RGB);
    resize(camera_mat, camera_mat, Size(400,300));
    //flip(camera_mat, camera_mat, 1);
}


void DiodeFinder::process() {

    //Equalize histogram + copy
    /*
    vector<Mat> channels;
    split(camera_mat, channels);
    Mat R,G,B;
    equalizeHist(channels[0], R);
    equalizeHist(channels[1], G);
    equalizeHist(channels[2], B);
    vector<Mat> pr;
    pr.push_back(R);
    pr.push_back(G);
    pr.push_back(B);
    merge(pr, processed_mat);
    */

    //Copy and blur
    cv::blur(camera_mat, processed_mat, Size(blur,blur));

    //Copy and perform some threshold
    cvtColor(processed_mat, processed_mat, CV_RGB2HLS);
    if (hu>=0) {
        if (hd<0) {
            Mat range1, range2;
            inRange(processed_mat, Scalar((hd<0 ? 0 : hd),ld,sd), Scalar(hu,lu,su), range1);
            inRange(processed_mat, Scalar((hd<0 ? 180-hd : hd),ld,sd), Scalar(180,lu,su), range2);
            add(range1, range2, processed_mat);
        }
        else {
            inRange(processed_mat, Scalar(hd,ld,sd), Scalar(hu,lu,su), processed_mat);
        }
    }

    //Median filter for processed image
    medianBlur(processed_mat, processed_mat, median);

    //Initialize output_mat with the same params as camera_mat
    output_mat = Mat(camera_mat.rows, camera_mat.cols, camera_mat.type());
    output_mat = Scalar(0,0,0);

}


void DiodeFinder::findPoints() {

    //Clear vector
    points.clear();

    //Vertical centers (row pos)
    vector<Point> vert_centers;
    for (int i=0; i<processed_mat.cols; i++) {

        int startPos = -1;
        for (int j=0; j<processed_mat.rows; j++) {

            uchar pixel = processed_mat.at<uchar>(j,i);
            if (pixel>0) {
                if (startPos==-1) {
                    startPos = j;
                }
            }
            else {
                if (startPos!=-1) {
                    int endPos = j;
                    int pos = (startPos+endPos)/2;
                    startPos = -1;
                    //cout << startPos << ", " << endPos << ": " << (startPos+endPos) << ", " << pos << endl;
                    Point pnt(i,pos);
                    line(output_mat, pnt, pnt, Scalar(255,0,0));
                    vert_centers.push_back(pnt);
                }
            }

        }

    }

    //Horizontal centers (col pos)
    for (int j=0; j<processed_mat.rows; j++) {

        int startPos = -1;
        for (int i=0; i<processed_mat.cols; i++) {

            uchar pixel = processed_mat.at<uchar>(j,i);
            if (pixel>0) {
                if (startPos==-1) {
                    startPos = i;
                }
            }
            else {
                if (startPos!=-1) {
                    int endPos = i;
                    int pos = (startPos+endPos)/2;
                    startPos = -1;
                    //cout << startPos << ", " << endPos << ": " << (startPos+endPos) << ", " << pos << endl;
                    Point pnt(pos,j);
                    line(output_mat, pnt, pnt, Scalar(0,255,0));

                    //Search in vertical centers
                    for (auto it=vert_centers.begin(); it!=vert_centers.end(); ++it) {
                        Point vert_pnt = *it;
                        if (vert_pnt.x==pnt.x && vert_pnt.y==pnt.y) {

                            //Save point!
                            points.push_back(Point(pnt.x, pnt.y));

                            //Draw point
                            circle(output_mat, pnt, 5, Scalar(255,255,255));

                        }

                    }

                }
            }

        }

    }

}


void DiodeFinder::findObjects() {

    //Clear objects vector
    objects.clear();

    //Copy local vector of points
    vector<Point> points = this->points;

    //Iterate all the points and look for those that meet the criteria
    for (int ic=0; ic<points.size(); ic++) {

        //Actual points vector's size
        int pointsLen = points.size();
        if (pointsLen<3) break;

        //Current point - base point
        Point basePoint = points[ic];

        //Look for short point (closer one)
        for (int is=0; is<pointsLen; is++) {

            //Avoid checking the same point
            if (ic==is) continue;

            //Get this point
            Point shortPoint = points[is];

            //Calculate distance
            float shortDist = SceneObject::distance(&shortPoint, &basePoint);

            //Then look for long point (further one)
            for (int il=0; il<pointsLen; il++) {

                //Avoid checking the same point
                if (ic==il || is==il) continue;

                //This point
                Point longPoint = points[il];

                //Calculate distance between base point and this one (longer distance)
                float longDist = SceneObject::distance(&longPoint, &basePoint);

                //Check distance ratio
                float ratio = shortDist/longDist;
                if (abs(ratio-tRatio)<=epsilon) {

                    //Check distance between long and short point (diagonal distance)
                    float diagonalDist = SceneObject::distance(&shortPoint, &longPoint);
                    if (abs(1 - diagonalDist / sqrt(pow(shortDist,2)+pow(longDist,2))) <= epsilon) {

                        //Save the object
                        SceneObject object(basePoint, shortPoint, longPoint);
                        objects.push_back(object);

                        //Draw it
                        line(output_mat, basePoint, shortPoint, Scalar(0,0,255));
                        line(output_mat, basePoint, longPoint, Scalar(0,0,255));
                        line(output_mat, longPoint, shortPoint, Scalar(0,0,255));
                        circle(output_mat, basePoint, 10, Scalar(255,255,255));

                        //Remove points from points vector
                        points.erase(points.begin() + ic);
                        points.erase(points.begin() + is);
                        points.erase(points.begin() + il);

                        //Iterate points from the beginning
                        ic = -1;
                        il = pointsLen;
                        is = pointsLen;

                    }

                }

            }

        }

    }

}


void DiodeFinder::findStableObjects() {

    //Only when there is a history
    if (!objectsHistory.empty()) {

        //Clear stable objects
        stableObjects.clear();

        //Iterate each object
        for (int i=0; i<objects.size(); i++) {

            SceneObject obj1 = objects[i];
            //cout << obj1.basePoint.x << ", " << obj1.basePoint.y << ": " << obj1.rotation << endl;

            //Find objects most similar to this one
            int jSoFar = -1;
            float diffSoFar = -1;
            for (int j=0; j<objectsHistory.size(); j++) {

                SceneObject obj2 = objectsHistory[j];
                float diff = SceneObject::diff(&obj1, &obj2);

                //Check if it's closest
                if (diffSoFar==-1 || diff<diffSoFar) {
                    jSoFar = j;
                    diffSoFar = diff;
                }

            }

            //If there is
            if (jSoFar!=-1) {

                SceneObject obj2 = objectsHistory[jSoFar];
                StableObject stable(obj1);

                //Calculate speed
                stable.speed = diffSoFar;

                //Check if it's possible for this object to be stable
                /* TODO */

                //Add stable object
                stableObjects.push_back(stable);

                //Remove from the history
                objectsHistory.erase(objectsHistory.begin() + jSoFar);

                //cout << stable.sceneObject.rotation << ", " << stable.speed << endl;

            }

        }

    }

    //Throw back history
    objectsHistory = objects;

}


void DiodeFinder::output() {

    //Define formats
    QImage::Format format1 = QImage::Format_RGB888;
    QImage::Format format2 = QImage::Format_Indexed8;
    QImage::Format format3 = format1;

    //Captured frame
    QPixmap camera_pixmap = QPixmap::fromImage(QImage((unsigned char*)camera_mat.data, camera_mat.cols, camera_mat.rows, format1));
    camera_label->setPixmap(camera_pixmap);

    //Processed frame
    QPixmap processed_pixmap = QPixmap::fromImage(QImage((unsigned char*)processed_mat.data, processed_mat.cols, processed_mat.rows, format2));
    processed_label->setPixmap(processed_pixmap);

    //Output frame
    QPixmap output_pixmap = QPixmap::fromImage(QImage((unsigned char*)output_mat.data, output_mat.cols, output_mat.rows, format3));
    output_label->setPixmap(output_pixmap);

    //Wait for display
    waitKey(100);

    //Save stable objects to nod
    if (saveData) {
        if (fifo.is_open()) {

            //"New frame" message
            fifo << "F " << stableObjects.size() << endl;
            //cout << "F " << stableObjects.size() << endl;

            //Each object
            for (int i=0; i<stableObjects.size(); i++) {
                StableObject obj = stableObjects[i];
                Point basePoint = obj.sceneObject.basePoint;

                //"Object definition" message
                fifo << "D " << i << " " << basePoint.x << " " << basePoint.y << " " << obj.sceneObject.size << " " << obj.sceneObject.rotation << " " << obj.speed << endl;
                //cout << "D " << i << " " << basePoint.x << " " << basePoint.y << " " << obj.sceneObject.size << " " << obj.sceneObject.rotation << " " << obj.speed << endl;
            }
        }
    }

}


void DiodeFinder::enableFIFO(const char* filename) {
    saveData = true;
    fifo.open(filename, fstream::out);
}


Vec3b DiodeFinder::pickColor(int x, int y) {

    //Pick HLS color from camera_mat
    Mat hls;
    cvtColor(camera_mat, hls, CV_RGB2HLS);
    Vec3b pixel = hls.at<Vec3b>(y, x);
    //cout << "size: " << hls.cols << ", " << hls.rows << endl;
    //cout << "Pick: " << x << ", " << y << " : " << (int)pixel[0] << ", " << (int)pixel[1] << ", " << (int)pixel[2] << endl;
    return pixel;

}
