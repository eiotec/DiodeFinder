#ifndef DIODEFINDER_H
#define DIODEFINDER_H

#include <QLabel>
#include <vector>
#include <opencv2/opencv.hpp>
#include <math.h>
#include <iostream>
#include <fstream>
#include <sys/stat.h>

#include "sceneobject.h"
#include "stableobject.h"


using namespace std;
using namespace cv;


/**
 * @brief Main DiodeFinder class.
 */
class DiodeFinder
{
    public:

        /** @brief QLabel with current camera frame. */
        QLabel* camera_label;

        /** @brief QLabel with current processed frame. */
        QLabel* processed_label;

        /** @brief QLabel with program output (results). */
        QLabel* output_label;

        /** @brief Video capture class. */
        VideoCapture videoCap;

        /** @brief Matrix for captured frame. */
        Mat camera_mat;

        /** @brief Matrix for processed frame. */
        Mat processed_mat;

        /** @brief Matrix for output (result) frame. */
        Mat output_mat;

        /** @brief HSL palette's H upper limit. */
        int hu;

        /** @brief HSL palette's H down limit. */
        int hd;

        /** @brief HSL palette's L upper limit. */
        int lu;

        /** @brief HSL palette's L down limit. */
        int ld;

        /** @brief HSL palette's S upper limit. */
        int su;

        /** @brief HSL palette's S down limit. */
        int sd;

        /** @brief Blur filter size. */
        int blur;

        /** @brief Median filter size. */
        int median;

        /** @brief Triangle ratio (1:tRatio). */
        int tRatio;

        /** @brief Object finder accuracy (distance ~ +/-epsilon). */
        float epsilon;

        /** @brief Current points on the scene. */
        vector<Point> points;

        /** @brief Current objects on the scene. */
        vector<SceneObject> objects;

        /** @brief History of recent this->objects vector's content. */
        vector<SceneObject> objectsHistory;

        /** @brief Objects recoginzed as stable on the scene. */
        vector<StableObject> stableObjects;

        /** @brief Whether to save data to data.fifo nod. */
        bool saveData;

        /** @brief FIFO stream. */
        static fstream fifo;



        /**
         * @brief DiodeFinder Constructor.
         * @param camera_pixmap QPixmap for Qt with current camera frame.
         * @param processed_pixmap QPixmap for Qt with current processed frame.
         */
        DiodeFinder(QLabel *camera_label, QLabel *processed_label, QLabel *output_label);

        /** @brief Empty constructor. */
        DiodeFinder();

        /** @brief Destructor. */
        ~DiodeFinder();

        /**
         * @brief Checks whether video capture node is opened successfully.
         * @return True if ok.
         */
        bool isOk();

        /**
         * @brief Captures video frame.
         */
        void capture();

        /**
         * @brief Processing given camera frame.
         */
        void process();

        /**
         * @brief Finds points on process_mat and saves them to points vector.
         */
        void findPoints();

        /**
         * @brief Finds objects among already found points within the scene.
         */
        void findObjects();

        /**
         * @brief Finds stable objects (filters found objects on the scene).
         */
        void findStableObjects();

        /**
         * @brief Modifies QPixmap for Qt widget and saves data to node file.
         */
        void output();

        /**
         * @brief Enables FIFO output for visualization.
         * @param filename FIFO filename.
         */
        void enableFIFO(const char* filename);

        /**
         * @brief Picks color from captured frame.
         * @param x X coord on camera_mat.
         * @param y Y coors on camera_mat.
         */
        Vec3b pickColor(int x, int y);


};

#endif // DIODEFINDER_H
