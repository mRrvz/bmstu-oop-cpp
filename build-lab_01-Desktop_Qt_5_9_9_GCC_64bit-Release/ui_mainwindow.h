/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QPushButton *load_button;
    QFrame *frame;
    QPushButton *move_button;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QDoubleSpinBox *dz_box;
    QDoubleSpinBox *dy_box;
    QDoubleSpinBox *dx_box;
    QLabel *label;
    QLabel *label_2;
    QFrame *frame_2;
    QPushButton *scale_button;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_6;
    QDoubleSpinBox *ky_box;
    QLabel *label_4;
    QDoubleSpinBox *kx_box;
    QLabel *label_5;
    QDoubleSpinBox *kz_box;
    QFrame *frame_3;
    QPushButton *turn_button;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_4;
    QLabel *label_10;
    QDoubleSpinBox *oy_box;
    QLabel *label_11;
    QDoubleSpinBox *ox_box;
    QLabel *label_12;
    QDoubleSpinBox *oz_box;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1065, 757);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(30, 20, 1001, 571));
        load_button = new QPushButton(centralwidget);
        load_button->setObjectName(QStringLiteral("load_button"));
        load_button->setGeometry(QRect(420, 690, 211, 25));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(30, 610, 291, 61));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        move_button = new QPushButton(frame);
        move_button->setObjectName(QStringLiteral("move_button"));
        move_button->setGeometry(QRect(0, 30, 290, 31));
        gridLayoutWidget = new QWidget(frame);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 291, 31));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 5, 1, 1);

        dz_box = new QDoubleSpinBox(gridLayoutWidget);
        dz_box->setObjectName(QStringLiteral("dz_box"));
        dz_box->setMinimum(-1e+23);
        dz_box->setMaximum(1e+16);

        gridLayout->addWidget(dz_box, 0, 6, 1, 1);

        dy_box = new QDoubleSpinBox(gridLayoutWidget);
        dy_box->setObjectName(QStringLiteral("dy_box"));
        dy_box->setMinimum(-1e+22);
        dy_box->setMaximum(1e+22);

        gridLayout->addWidget(dy_box, 0, 4, 1, 1);

        dx_box = new QDoubleSpinBox(gridLayoutWidget);
        dx_box->setObjectName(QStringLiteral("dx_box"));
        dx_box->setMinimum(-1e+16);
        dx_box->setMaximum(1e+16);

        gridLayout->addWidget(dx_box, 0, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 2);

        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(380, 610, 301, 61));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        scale_button = new QPushButton(frame_2);
        scale_button->setObjectName(QStringLiteral("scale_button"));
        scale_button->setGeometry(QRect(0, 30, 301, 31));
        gridLayoutWidget_2 = new QWidget(frame_2);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(0, 0, 301, 31));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(gridLayoutWidget_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 0, 4, 1, 1);

        ky_box = new QDoubleSpinBox(gridLayoutWidget_2);
        ky_box->setObjectName(QStringLiteral("ky_box"));
        ky_box->setMinimum(0);
        ky_box->setMaximum(1e+22);

        gridLayout_2->addWidget(ky_box, 0, 3, 1, 1);

        label_4 = new QLabel(gridLayoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        kx_box = new QDoubleSpinBox(gridLayoutWidget_2);
        kx_box->setObjectName(QStringLiteral("kx_box"));
        kx_box->setMinimum(0);
        kx_box->setMaximum(1e+16);

        gridLayout_2->addWidget(kx_box, 0, 1, 1, 1);

        label_5 = new QLabel(gridLayoutWidget_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 0, 2, 1, 1);

        kz_box = new QDoubleSpinBox(gridLayoutWidget_2);
        kz_box->setObjectName(QStringLiteral("kz_box"));
        kz_box->setMinimum(0);
        kz_box->setMaximum(1e+16);

        gridLayout_2->addWidget(kz_box, 0, 5, 1, 1);

        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(740, 610, 291, 61));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        turn_button = new QPushButton(frame_3);
        turn_button->setObjectName(QStringLiteral("turn_button"));
        turn_button->setGeometry(QRect(0, 30, 291, 31));
        gridLayoutWidget_4 = new QWidget(frame_3);
        gridLayoutWidget_4->setObjectName(QStringLiteral("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(0, 0, 291, 31));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(gridLayoutWidget_4);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_4->addWidget(label_10, 0, 4, 1, 1);

        oy_box = new QDoubleSpinBox(gridLayoutWidget_4);
        oy_box->setObjectName(QStringLiteral("oy_box"));
        oy_box->setMinimum(-1e+22);
        oy_box->setMaximum(1e+22);

        gridLayout_4->addWidget(oy_box, 0, 3, 1, 1);

        label_11 = new QLabel(gridLayoutWidget_4);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_4->addWidget(label_11, 0, 0, 1, 1);

        ox_box = new QDoubleSpinBox(gridLayoutWidget_4);
        ox_box->setObjectName(QStringLiteral("ox_box"));
        ox_box->setMinimum(-1e+16);
        ox_box->setMaximum(1e+16);

        gridLayout_4->addWidget(ox_box, 0, 1, 1, 1);

        label_12 = new QLabel(gridLayoutWidget_4);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_4->addWidget(label_12, 0, 2, 1, 1);

        oz_box = new QDoubleSpinBox(gridLayoutWidget_4);
        oz_box->setObjectName(QStringLiteral("oz_box"));
        oz_box->setMinimum(-1e+23);
        oz_box->setMaximum(1e+16);

        gridLayout_4->addWidget(oz_box, 0, 5, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        load_button->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \321\204\320\270\320\263\321\203\321\200\321\203", Q_NULLPTR));
        move_button->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\201\321\202\320\270\321\202\321\214", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", " dz", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", " dx", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", " dy", Q_NULLPTR));
        scale_button->setText(QApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", " kz", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", " kx", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", " ky", Q_NULLPTR));
        turn_button->setText(QApplication::translate("MainWindow", "\320\222\321\200\320\260\321\211\320\260\321\202\321\214", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", " kz", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", " ox", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", " ky", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
