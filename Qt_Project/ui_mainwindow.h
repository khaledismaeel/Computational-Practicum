/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QCustomPlot *func_plot;
    QLineEdit *ln_func_prec;
    QLabel *lbl_err_inv;
    QLineEdit *ln_err_prec_from;
    QLineEdit *ln_err_xlim;
    QLineEdit *ln_func_y0;
    QLabel *lbl_func_initx;
    QLineEdit *ln_func_xlim;
    QLabel *lbl_func_xlim;
    QCheckBox *chk_func_as;
    QLabel *lbl_err_to;
    QCheckBox *chk_func_em;
    QLabel *lbl_func_prec;
    QCustomPlot *err_plot;
    QCheckBox *chk_func_rk_le;
    QLabel *lbl_func_inv;
    QLineEdit *ln_err_x0;
    QLabel *lbl_func_inity;
    QCheckBox *chk_err_em;
    QLineEdit *ln_err_y0;
    QLineEdit *ln_func_x0;
    QLabel *lbl_err_from;
    QLabel *lbl_err_xlim;
    QCheckBox *chk_err_rk;
    QLabel *lbl_err_prec_to;
    QLineEdit *ln_err_prec_to;
    QPushButton *btn_err_plot;
    QLabel *lbl_err_prec_from;
    QCheckBox *chk_func_iem;
    QPushButton *btn_func_clear;
    QCheckBox *chk_func_iem_le;
    QCheckBox *chk_func_em_le;
    QCheckBox *chk_func_rk;
    QPushButton *btn_func_plot;
    QCheckBox *chk_err_iem;
    QPushButton *btn_err_clear;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1024, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        func_plot = new QCustomPlot(centralwidget);
        func_plot->setObjectName(QString::fromUtf8("func_plot"));

        gridLayout->addWidget(func_plot, 0, 0, 1, 5);

        ln_func_prec = new QLineEdit(centralwidget);
        ln_func_prec->setObjectName(QString::fromUtf8("ln_func_prec"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ln_func_prec->sizePolicy().hasHeightForWidth());
        ln_func_prec->setSizePolicy(sizePolicy);

        gridLayout->addWidget(ln_func_prec, 11, 1, 1, 1);

        lbl_err_inv = new QLabel(centralwidget);
        lbl_err_inv->setObjectName(QString::fromUtf8("lbl_err_inv"));
        lbl_err_inv->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lbl_err_inv, 13, 8, 1, 2);

        ln_err_prec_from = new QLineEdit(centralwidget);
        ln_err_prec_from->setObjectName(QString::fromUtf8("ln_err_prec_from"));
        sizePolicy.setHeightForWidth(ln_err_prec_from->sizePolicy().hasHeightForWidth());
        ln_err_prec_from->setSizePolicy(sizePolicy);

        gridLayout->addWidget(ln_err_prec_from, 11, 6, 1, 1);

        ln_err_xlim = new QLineEdit(centralwidget);
        ln_err_xlim->setObjectName(QString::fromUtf8("ln_err_xlim"));
        sizePolicy.setHeightForWidth(ln_err_xlim->sizePolicy().hasHeightForWidth());
        ln_err_xlim->setSizePolicy(sizePolicy);

        gridLayout->addWidget(ln_err_xlim, 10, 6, 1, 1);

        ln_func_y0 = new QLineEdit(centralwidget);
        ln_func_y0->setObjectName(QString::fromUtf8("ln_func_y0"));
        sizePolicy.setHeightForWidth(ln_func_y0->sizePolicy().hasHeightForWidth());
        ln_func_y0->setSizePolicy(sizePolicy);

        gridLayout->addWidget(ln_func_y0, 9, 1, 1, 1);

        lbl_func_initx = new QLabel(centralwidget);
        lbl_func_initx->setObjectName(QString::fromUtf8("lbl_func_initx"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lbl_func_initx->sizePolicy().hasHeightForWidth());
        lbl_func_initx->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(lbl_func_initx, 6, 0, 1, 1);

        ln_func_xlim = new QLineEdit(centralwidget);
        ln_func_xlim->setObjectName(QString::fromUtf8("ln_func_xlim"));
        sizePolicy.setHeightForWidth(ln_func_xlim->sizePolicy().hasHeightForWidth());
        ln_func_xlim->setSizePolicy(sizePolicy);

        gridLayout->addWidget(ln_func_xlim, 10, 1, 1, 1);

        lbl_func_xlim = new QLabel(centralwidget);
        lbl_func_xlim->setObjectName(QString::fromUtf8("lbl_func_xlim"));
        sizePolicy1.setHeightForWidth(lbl_func_xlim->sizePolicy().hasHeightForWidth());
        lbl_func_xlim->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(lbl_func_xlim, 10, 0, 1, 1);

        chk_func_as = new QCheckBox(centralwidget);
        chk_func_as->setObjectName(QString::fromUtf8("chk_func_as"));
        sizePolicy.setHeightForWidth(chk_func_as->sizePolicy().hasHeightForWidth());
        chk_func_as->setSizePolicy(sizePolicy);

        gridLayout->addWidget(chk_func_as, 6, 2, 1, 1);

        lbl_err_to = new QLabel(centralwidget);
        lbl_err_to->setObjectName(QString::fromUtf8("lbl_err_to"));

        gridLayout->addWidget(lbl_err_to, 9, 5, 1, 1);

        chk_func_em = new QCheckBox(centralwidget);
        chk_func_em->setObjectName(QString::fromUtf8("chk_func_em"));
        sizePolicy.setHeightForWidth(chk_func_em->sizePolicy().hasHeightForWidth());
        chk_func_em->setSizePolicy(sizePolicy);
        chk_func_em->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(chk_func_em, 9, 2, 1, 1);

        lbl_func_prec = new QLabel(centralwidget);
        lbl_func_prec->setObjectName(QString::fromUtf8("lbl_func_prec"));
        sizePolicy1.setHeightForWidth(lbl_func_prec->sizePolicy().hasHeightForWidth());
        lbl_func_prec->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(lbl_func_prec, 11, 0, 1, 1);

        err_plot = new QCustomPlot(centralwidget);
        err_plot->setObjectName(QString::fromUtf8("err_plot"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(err_plot->sizePolicy().hasHeightForWidth());
        err_plot->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(err_plot, 0, 5, 1, 5);

        chk_func_rk_le = new QCheckBox(centralwidget);
        chk_func_rk_le->setObjectName(QString::fromUtf8("chk_func_rk_le"));

        gridLayout->addWidget(chk_func_rk_le, 11, 3, 1, 2);

        lbl_func_inv = new QLabel(centralwidget);
        lbl_func_inv->setObjectName(QString::fromUtf8("lbl_func_inv"));
        lbl_func_inv->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lbl_func_inv, 13, 3, 1, 2);

        ln_err_x0 = new QLineEdit(centralwidget);
        ln_err_x0->setObjectName(QString::fromUtf8("ln_err_x0"));
        sizePolicy.setHeightForWidth(ln_err_x0->sizePolicy().hasHeightForWidth());
        ln_err_x0->setSizePolicy(sizePolicy);

        gridLayout->addWidget(ln_err_x0, 6, 6, 1, 1);

        lbl_func_inity = new QLabel(centralwidget);
        lbl_func_inity->setObjectName(QString::fromUtf8("lbl_func_inity"));
        sizePolicy1.setHeightForWidth(lbl_func_inity->sizePolicy().hasHeightForWidth());
        lbl_func_inity->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(lbl_func_inity, 9, 0, 1, 1);

        chk_err_em = new QCheckBox(centralwidget);
        chk_err_em->setObjectName(QString::fromUtf8("chk_err_em"));
        sizePolicy.setHeightForWidth(chk_err_em->sizePolicy().hasHeightForWidth());
        chk_err_em->setSizePolicy(sizePolicy);

        gridLayout->addWidget(chk_err_em, 6, 7, 1, 1);

        ln_err_y0 = new QLineEdit(centralwidget);
        ln_err_y0->setObjectName(QString::fromUtf8("ln_err_y0"));
        sizePolicy.setHeightForWidth(ln_err_y0->sizePolicy().hasHeightForWidth());
        ln_err_y0->setSizePolicy(sizePolicy);

        gridLayout->addWidget(ln_err_y0, 9, 6, 1, 1);

        ln_func_x0 = new QLineEdit(centralwidget);
        ln_func_x0->setObjectName(QString::fromUtf8("ln_func_x0"));
        sizePolicy.setHeightForWidth(ln_func_x0->sizePolicy().hasHeightForWidth());
        ln_func_x0->setSizePolicy(sizePolicy);

        gridLayout->addWidget(ln_func_x0, 6, 1, 1, 1);

        lbl_err_from = new QLabel(centralwidget);
        lbl_err_from->setObjectName(QString::fromUtf8("lbl_err_from"));
        sizePolicy1.setHeightForWidth(lbl_err_from->sizePolicy().hasHeightForWidth());
        lbl_err_from->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(lbl_err_from, 6, 5, 1, 1);

        lbl_err_xlim = new QLabel(centralwidget);
        lbl_err_xlim->setObjectName(QString::fromUtf8("lbl_err_xlim"));

        gridLayout->addWidget(lbl_err_xlim, 10, 5, 1, 1);

        chk_err_rk = new QCheckBox(centralwidget);
        chk_err_rk->setObjectName(QString::fromUtf8("chk_err_rk"));
        sizePolicy.setHeightForWidth(chk_err_rk->sizePolicy().hasHeightForWidth());
        chk_err_rk->setSizePolicy(sizePolicy);

        gridLayout->addWidget(chk_err_rk, 10, 7, 1, 1);

        lbl_err_prec_to = new QLabel(centralwidget);
        lbl_err_prec_to->setObjectName(QString::fromUtf8("lbl_err_prec_to"));

        gridLayout->addWidget(lbl_err_prec_to, 12, 5, 1, 1);

        ln_err_prec_to = new QLineEdit(centralwidget);
        ln_err_prec_to->setObjectName(QString::fromUtf8("ln_err_prec_to"));
        sizePolicy.setHeightForWidth(ln_err_prec_to->sizePolicy().hasHeightForWidth());
        ln_err_prec_to->setSizePolicy(sizePolicy);

        gridLayout->addWidget(ln_err_prec_to, 12, 6, 1, 1);

        btn_err_plot = new QPushButton(centralwidget);
        btn_err_plot->setObjectName(QString::fromUtf8("btn_err_plot"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(btn_err_plot->sizePolicy().hasHeightForWidth());
        btn_err_plot->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(btn_err_plot, 13, 5, 1, 2);

        lbl_err_prec_from = new QLabel(centralwidget);
        lbl_err_prec_from->setObjectName(QString::fromUtf8("lbl_err_prec_from"));

        gridLayout->addWidget(lbl_err_prec_from, 11, 5, 1, 1);

        chk_func_iem = new QCheckBox(centralwidget);
        chk_func_iem->setObjectName(QString::fromUtf8("chk_func_iem"));
        sizePolicy.setHeightForWidth(chk_func_iem->sizePolicy().hasHeightForWidth());
        chk_func_iem->setSizePolicy(sizePolicy);

        gridLayout->addWidget(chk_func_iem, 10, 2, 1, 1);

        btn_func_clear = new QPushButton(centralwidget);
        btn_func_clear->setObjectName(QString::fromUtf8("btn_func_clear"));
        QSizePolicy sizePolicy4(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(btn_func_clear->sizePolicy().hasHeightForWidth());
        btn_func_clear->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(btn_func_clear, 13, 2, 1, 1);

        chk_func_iem_le = new QCheckBox(centralwidget);
        chk_func_iem_le->setObjectName(QString::fromUtf8("chk_func_iem_le"));

        gridLayout->addWidget(chk_func_iem_le, 10, 3, 1, 2);

        chk_func_em_le = new QCheckBox(centralwidget);
        chk_func_em_le->setObjectName(QString::fromUtf8("chk_func_em_le"));

        gridLayout->addWidget(chk_func_em_le, 9, 3, 1, 2);

        chk_func_rk = new QCheckBox(centralwidget);
        chk_func_rk->setObjectName(QString::fromUtf8("chk_func_rk"));
        sizePolicy.setHeightForWidth(chk_func_rk->sizePolicy().hasHeightForWidth());
        chk_func_rk->setSizePolicy(sizePolicy);

        gridLayout->addWidget(chk_func_rk, 11, 2, 1, 1);

        btn_func_plot = new QPushButton(centralwidget);
        btn_func_plot->setObjectName(QString::fromUtf8("btn_func_plot"));
        sizePolicy3.setHeightForWidth(btn_func_plot->sizePolicy().hasHeightForWidth());
        btn_func_plot->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(btn_func_plot, 13, 0, 1, 2);

        chk_err_iem = new QCheckBox(centralwidget);
        chk_err_iem->setObjectName(QString::fromUtf8("chk_err_iem"));
        sizePolicy.setHeightForWidth(chk_err_iem->sizePolicy().hasHeightForWidth());
        chk_err_iem->setSizePolicy(sizePolicy);

        gridLayout->addWidget(chk_err_iem, 9, 7, 1, 1);

        btn_err_clear = new QPushButton(centralwidget);
        btn_err_clear->setObjectName(QString::fromUtf8("btn_err_clear"));
        sizePolicy3.setHeightForWidth(btn_err_clear->sizePolicy().hasHeightForWidth());
        btn_err_clear->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(btn_err_clear, 13, 7, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        lbl_err_inv->setText(QApplication::translate("MainWindow", "Invalid input!", nullptr));
        lbl_func_initx->setText(QApplication::translate("MainWindow", "Initial X:", nullptr));
        lbl_func_xlim->setText(QApplication::translate("MainWindow", "X limit:", nullptr));
        chk_func_as->setText(QApplication::translate("MainWindow", "Analytical Solution", nullptr));
        lbl_err_to->setText(QApplication::translate("MainWindow", "Initial Y:", nullptr));
        chk_func_em->setText(QApplication::translate("MainWindow", "Euler Method", nullptr));
        lbl_func_prec->setText(QApplication::translate("MainWindow", "Precision:", nullptr));
        chk_func_rk_le->setText(QApplication::translate("MainWindow", "RKM local error", nullptr));
        lbl_func_inv->setText(QApplication::translate("MainWindow", "Invalid input!", nullptr));
        lbl_func_inity->setText(QApplication::translate("MainWindow", "Initial Y:", nullptr));
        chk_err_em->setText(QApplication::translate("MainWindow", "Euler Method", nullptr));
        lbl_err_from->setText(QApplication::translate("MainWindow", "Initial X:", nullptr));
        lbl_err_xlim->setText(QApplication::translate("MainWindow", "X limit:", nullptr));
        chk_err_rk->setText(QApplication::translate("MainWindow", "Runge-Kutta Method", nullptr));
        lbl_err_prec_to->setText(QApplication::translate("MainWindow", "Prc to:", nullptr));
        btn_err_plot->setText(QApplication::translate("MainWindow", "Plot", nullptr));
        lbl_err_prec_from->setText(QApplication::translate("MainWindow", "Prc from:", nullptr));
        chk_func_iem->setText(QApplication::translate("MainWindow", "Impr. Euler Method", nullptr));
        btn_func_clear->setText(QApplication::translate("MainWindow", "Clear", nullptr));
        chk_func_iem_le->setText(QApplication::translate("MainWindow", "IEM local error", nullptr));
        chk_func_em_le->setText(QApplication::translate("MainWindow", "EM local error", nullptr));
        chk_func_rk->setText(QApplication::translate("MainWindow", "Runge-Kutta Method", nullptr));
        btn_func_plot->setText(QApplication::translate("MainWindow", "Plot", nullptr));
        chk_err_iem->setText(QApplication::translate("MainWindow", "Impr. Euler Method", nullptr));
        btn_err_clear->setText(QApplication::translate("MainWindow", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
