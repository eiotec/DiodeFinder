/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLabel *image2;
    QLabel *image1;
    QLabel *image3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *startBtn;
    QPushButton *visualizationBtn;
    QLabel *label_7;
    QSlider *sliderBlur;
    QLabel *label_8;
    QSlider *sliderMedian;
    QLabel *label_9;
    QSlider *sliderDiff;
    QLabel *label_10;
    QSlider *sliderRatio;
    QLabel *label_11;
    QSlider *sliderEpsilon;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSlider *sliderHU;
    QLabel *label;
    QSlider *sliderLU;
    QLabel *label_2;
    QSlider *sliderSU;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSlider *sliderHD;
    QLabel *label_5;
    QSlider *sliderLD;
    QLabel *label_6;
    QSlider *sliderSD;
    QLabel *lblParams;
    QLabel *lblResults;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1232, 476);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetFixedSize);
        image2 = new QLabel(centralWidget);
        image2->setObjectName(QStringLiteral("image2"));
        image2->setMinimumSize(QSize(400, 300));
        image2->setMaximumSize(QSize(400, 300));
        image2->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix/img1.jpg")));

        gridLayout->addWidget(image2, 0, 1, 1, 1);

        image1 = new QLabel(centralWidget);
        image1->setObjectName(QStringLiteral("image1"));
        image1->setMaximumSize(QSize(400, 300));
        image1->setMouseTracking(false);
        image1->setFrameShape(QFrame::StyledPanel);
        image1->setFrameShadow(QFrame::Plain);
        image1->setLineWidth(1);
        image1->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix/img1.jpg")));
        image1->setScaledContents(false);

        gridLayout->addWidget(image1, 0, 0, 1, 1);

        image3 = new QLabel(centralWidget);
        image3->setObjectName(QStringLiteral("image3"));
        image3->setMinimumSize(QSize(400, 300));
        image3->setMaximumSize(QSize(400, 300));
        image3->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix/img1.jpg")));

        gridLayout->addWidget(image3, 0, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        startBtn = new QPushButton(centralWidget);
        startBtn->setObjectName(QStringLiteral("startBtn"));

        horizontalLayout_3->addWidget(startBtn);

        visualizationBtn = new QPushButton(centralWidget);
        visualizationBtn->setObjectName(QStringLiteral("visualizationBtn"));

        horizontalLayout_3->addWidget(visualizationBtn);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_3->addWidget(label_7);

        sliderBlur = new QSlider(centralWidget);
        sliderBlur->setObjectName(QStringLiteral("sliderBlur"));
        sliderBlur->setMinimum(0);
        sliderBlur->setMaximum(10);
        sliderBlur->setPageStep(1);
        sliderBlur->setValue(0);
        sliderBlur->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(sliderBlur);

        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_3->addWidget(label_8);

        sliderMedian = new QSlider(centralWidget);
        sliderMedian->setObjectName(QStringLiteral("sliderMedian"));
        sliderMedian->setMinimum(0);
        sliderMedian->setMaximum(10);
        sliderMedian->setPageStep(1);
        sliderMedian->setValue(4);
        sliderMedian->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(sliderMedian);

        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_3->addWidget(label_9);

        sliderDiff = new QSlider(centralWidget);
        sliderDiff->setObjectName(QStringLiteral("sliderDiff"));
        sliderDiff->setValue(30);
        sliderDiff->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(sliderDiff);

        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_3->addWidget(label_10);

        sliderRatio = new QSlider(centralWidget);
        sliderRatio->setObjectName(QStringLiteral("sliderRatio"));
        sliderRatio->setMinimum(1);
        sliderRatio->setMaximum(20);
        sliderRatio->setValue(2);
        sliderRatio->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(sliderRatio);

        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_3->addWidget(label_11);

        sliderEpsilon = new QSlider(centralWidget);
        sliderEpsilon->setObjectName(QStringLiteral("sliderEpsilon"));
        sliderEpsilon->setValue(8);
        sliderEpsilon->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(sliderEpsilon);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        sliderHU = new QSlider(centralWidget);
        sliderHU->setObjectName(QStringLiteral("sliderHU"));
        sliderHU->setMinimum(-180);
        sliderHU->setMaximum(180);
        sliderHU->setValue(20);
        sliderHU->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(sliderHU);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        sliderLU = new QSlider(centralWidget);
        sliderLU->setObjectName(QStringLiteral("sliderLU"));
        sliderLU->setMaximum(255);
        sliderLU->setValue(150);
        sliderLU->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(sliderLU);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        sliderSU = new QSlider(centralWidget);
        sliderSU->setObjectName(QStringLiteral("sliderSU"));
        sliderSU->setMaximum(255);
        sliderSU->setValue(255);
        sliderSU->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(sliderSU);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        sliderHD = new QSlider(centralWidget);
        sliderHD->setObjectName(QStringLiteral("sliderHD"));
        sliderHD->setMinimum(-180);
        sliderHD->setMaximum(180);
        sliderHD->setValue(-20);
        sliderHD->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(sliderHD);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_4->addWidget(label_5);

        sliderLD = new QSlider(centralWidget);
        sliderLD->setObjectName(QStringLiteral("sliderLD"));
        sliderLD->setMaximum(255);
        sliderLD->setValue(100);
        sliderLD->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(sliderLD);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_4->addWidget(label_6);

        sliderSD = new QSlider(centralWidget);
        sliderSD->setObjectName(QStringLiteral("sliderSD"));
        sliderSD->setMaximum(255);
        sliderSD->setValue(230);
        sliderSD->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(sliderSD);


        verticalLayout_2->addLayout(horizontalLayout_4);

        lblParams = new QLabel(centralWidget);
        lblParams->setObjectName(QStringLiteral("lblParams"));

        verticalLayout_2->addWidget(lblParams);

        lblResults = new QLabel(centralWidget);
        lblResults->setObjectName(QStringLiteral("lblResults"));

        verticalLayout_2->addWidget(lblResults);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(startBtn, SIGNAL(clicked()), MainWindow, SLOT(onStart()));
        QObject::connect(sliderHU, SIGNAL(sliderMoved(int)), MainWindow, SLOT(onSliderChange(int)));
        QObject::connect(sliderLU, SIGNAL(sliderMoved(int)), MainWindow, SLOT(onSliderChange(int)));
        QObject::connect(sliderSU, SIGNAL(sliderMoved(int)), MainWindow, SLOT(onSliderChange(int)));
        QObject::connect(sliderSD, SIGNAL(sliderMoved(int)), MainWindow, SLOT(onSliderChange(int)));
        QObject::connect(sliderLD, SIGNAL(sliderMoved(int)), MainWindow, SLOT(onSliderChange(int)));
        QObject::connect(sliderHD, SIGNAL(sliderMoved(int)), MainWindow, SLOT(onSliderChange(int)));
        QObject::connect(sliderBlur, SIGNAL(sliderMoved(int)), MainWindow, SLOT(onSliderChange(int)));
        QObject::connect(sliderMedian, SIGNAL(sliderMoved(int)), MainWindow, SLOT(onSliderChange(int)));
        QObject::connect(MainWindow, SIGNAL(mouseClickEvent()), MainWindow, SLOT(onClick()));
        QObject::connect(sliderDiff, SIGNAL(sliderMoved(int)), MainWindow, SLOT(onSliderChange(int)));
        QObject::connect(sliderHD, SIGNAL(sliderReleased()), MainWindow, SLOT(onSliderReleased()));
        QObject::connect(sliderHU, SIGNAL(sliderReleased()), MainWindow, SLOT(onSliderReleased()));
        QObject::connect(sliderLD, SIGNAL(sliderReleased()), MainWindow, SLOT(onSliderReleased()));
        QObject::connect(sliderLU, SIGNAL(sliderReleased()), MainWindow, SLOT(onSliderReleased()));
        QObject::connect(sliderSD, SIGNAL(sliderReleased()), MainWindow, SLOT(onSliderReleased()));
        QObject::connect(sliderSU, SIGNAL(sliderReleased()), MainWindow, SLOT(onSliderReleased()));
        QObject::connect(sliderBlur, SIGNAL(sliderReleased()), MainWindow, SLOT(onSliderReleased()));
        QObject::connect(sliderDiff, SIGNAL(sliderReleased()), MainWindow, SLOT(onSliderReleased()));
        QObject::connect(sliderMedian, SIGNAL(sliderReleased()), MainWindow, SLOT(onSliderReleased()));
        QObject::connect(sliderEpsilon, SIGNAL(sliderMoved(int)), MainWindow, SLOT(onSliderChange(int)));
        QObject::connect(sliderEpsilon, SIGNAL(sliderReleased()), MainWindow, SLOT(onSliderReleased()));
        QObject::connect(sliderRatio, SIGNAL(sliderMoved(int)), MainWindow, SLOT(onSliderChange(int)));
        QObject::connect(sliderRatio, SIGNAL(sliderReleased()), MainWindow, SLOT(onSliderReleased()));
        QObject::connect(visualizationBtn, SIGNAL(clicked()), MainWindow, SLOT(onVisualizationStart()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "DiodeFinder", 0));
        image2->setText(QString());
        image1->setText(QString());
        image3->setText(QString());
        startBtn->setText(QApplication::translate("MainWindow", "Start", 0));
        visualizationBtn->setText(QApplication::translate("MainWindow", "3D", 0));
        label_7->setText(QApplication::translate("MainWindow", "Blur", 0));
        label_8->setText(QApplication::translate("MainWindow", "Median", 0));
        label_9->setText(QApplication::translate("MainWindow", "Picking difference", 0));
        label_10->setText(QApplication::translate("MainWindow", "Triangle ratio", 0));
        label_11->setText(QApplication::translate("MainWindow", "Epsilon", 0));
        label_3->setText(QApplication::translate("MainWindow", "H+", 0));
        label->setText(QApplication::translate("MainWindow", "L+", 0));
        label_2->setText(QApplication::translate("MainWindow", "S+", 0));
        label_4->setText(QApplication::translate("MainWindow", "H -", 0));
        label_5->setText(QApplication::translate("MainWindow", "L -", 0));
        label_6->setText(QApplication::translate("MainWindow", "S -", 0));
        lblParams->setText(QApplication::translate("MainWindow", "Params:", 0));
        lblResults->setText(QApplication::translate("MainWindow", "Results:", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
