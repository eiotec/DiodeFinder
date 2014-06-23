#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <thread>
#include <iostream>
#include <stdio.h>
#include <QMainWindow>
#include <QProcess>
#include "diodefinder.h"


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:

        /** @brief Flag whether mouse btn has been clicked. */
        bool isClicked;

        /** @brief Flag whether the app is opened. */
        bool isOpen;

        /** @brief DiodeFinderr instance. */
        DiodeFinder df;

        /** @brief Constructor. */
        explicit MainWindow(QWidget *parent = 0);

        /** @brief Destructor. */
        ~MainWindow();

        /**
         * @brief Closing event.
         * @param event
         */
        void closeEvent(QCloseEvent *event);

        /**
         * @brief Refreshing DiodeFinder results.
         */
        void refreshResults();

    private:

        /** @brief Container with all UI elements. */
        Ui::MainWindow *ui;

    signals:

        /** @brief Signal emitted when user clicks on the main window. */
        void mouseClickEvent();

    public slots:

        /** @brief For "Start" button being clicked. */
        void onStart();

        /** @brief For a slider being moved. */
        void onSliderChange(int);

        /** @brief When slider is released. */
        void onSliderReleased();

        /** @brief For "mouseClickEvent" signal. */
        void onClick();

        /** @brief When "3D" button is clicked. */
        void onVisualizationStart();

    protected:

        void mousePressEvent(QMouseEvent *e);
        void mouseReleaseEvent(QMouseEvent *e);

};

#endif // MAINWINDOW_H
