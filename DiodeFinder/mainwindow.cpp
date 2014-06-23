#include "mainwindow.h"
#include "ui_mainwindow.h"


using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isOpen = true;
    isClicked = false;
    df = DiodeFinder(ui->image1, ui->image2, ui->image3);
    onSliderChange(0);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::refreshResults() {
    char buf[100];
    sprintf(buf, "points: %d, objects: %d, stable_objects: %d", df.points.size(), df.objects.size(), df.stableObjects.size());
    ui->lblResults->setText(QString(buf));
}


void MainWindow::closeEvent(QCloseEvent *event) {
    isOpen = false;
}


void MainWindow::onStart() {

    while (isOpen) {
        df.capture();
        df.process();
        df.findPoints();
        df.findObjects();
        df.findStableObjects();
        df.output();
        refreshResults();
        //this_thread::sleep_for(chrono::milliseconds(100));
        //cout << QCursor::pos().x() << ", " << QCursor::pos().y() << " : " << ui-> << ", " << this->pos().y() << endl;
        //cout << ui->image1->contentsRect().contains(QCursor::pos()-this->pos()) << endl;
        //cout << ui->image1->mapFromGlobal(QCursor::pos()).x() << ", " << ui->image1->mapFromGlobal(QCursor::pos()).y() << endl;
        //cout << ui->image1->rect().contains(ui->image1->mapFromGlobal(QCursor::pos())) << endl;
    }

}


void MainWindow::onSliderChange(int x) {

    //Boundaries
    if (ui->sliderHU->value()<0) ui->sliderHU->setValue(0);

    //Override values
    df.hd = ui->sliderHD->value();
    df.hu = ui->sliderHU->value();
    df.sd = ui->sliderSD->value();
    df.su = ui->sliderSU->value();
    df.lu = ui->sliderLU->value();
    df.ld = ui->sliderLD->value();
    df.blur = ui->sliderBlur->value()*2+1;
    df.median = ui->sliderMedian->value()*2+1;
    df.tRatio = ui->sliderRatio->value();
    df.epsilon = (float)ui->sliderEpsilon->value() / 100;

    //Display params
    char buf[200];
    sprintf(buf, "min(H: %d, S: %d, L: %d), max(H: %d, S: %d, L: %d), blur: %d, median: %d, picking_diff: %d, triangle_ratio: 1/%d, epsilon: %.2f", df.hd, df.sd, df.ld, df.hu, df.su, df.lu, df.blur, df.median, ui->sliderDiff->value(), df.tRatio, df.epsilon);
    ui->lblParams->setText(QString(buf));

}


void MainWindow::onSliderReleased() {
    onSliderChange(0);
}


void MainWindow::mousePressEvent(QMouseEvent *e) {
    isClicked = true;
}


void MainWindow::mouseReleaseEvent(QMouseEvent *e) {
    if (isClicked) {
        isClicked = false;
        emit mouseClickEvent();
    }
}


void MainWindow::onClick() {

    //Color picking from camera-captured image
    QPoint point = ui->image1->mapFromGlobal(QCursor::pos());
    if (ui->image1->rect().contains(point)) {

        //Get picking difference
        int picking_diff = ui->sliderDiff->value();

        //Get pixel at the point and set sliders
        Vec3b pixel = df.pickColor(point.x(), point.y());
        ui->sliderHU->setValue(pixel[0]>180-picking_diff ? pixel[0]-180+picking_diff : pixel[0]+picking_diff);
        ui->sliderHD->setValue(pixel[0]-picking_diff);
        ui->sliderLU->setValue(pixel[1]>255-picking_diff ? 255 : pixel[1]+picking_diff);
        ui->sliderLD->setValue(pixel[1]<picking_diff ? 0 : pixel[1]-picking_diff);
        ui->sliderSU->setValue(pixel[2]>255-picking_diff ? 255 : pixel[2]+picking_diff);
        ui->sliderSD->setValue(pixel[2]<picking_diff ? 0 : pixel[2]-picking_diff);
        onSliderChange(0);
    }

}


void MainWindow::onVisualizationStart() {

    if (!df.saveData) {
        //system("java -jar \"DiodeVisualizer.jar\" &");
        //system("/bin/sh DiodeVisualizer.sh");
        system("`pwd`/DiodeVizualizer.sh");
        //QProcess p;
        //p.start("./DiodeVisualizer.sh");
        //p.waitForFinished();
        df.enableFIFO("data.fifo");
    }

}
