/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *downloadButton;
    QComboBox *portComboBox;
    QPushButton *chooseButton;
    QPushButton *openButton;
    QPushButton *closeButton;
    QPushButton *sendButton;
    QLabel *statusLabel;
    QTextEdit *textEdit;
    QProgressBar *progressBar;
    QRadioButton *r_btn_collect;
    QRadioButton *r_btn_inference;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        downloadButton = new QPushButton(centralwidget);
        downloadButton->setObjectName(QString::fromUtf8("downloadButton"));
        downloadButton->setGeometry(QRect(440, 450, 75, 23));
        portComboBox = new QComboBox(centralwidget);
        portComboBox->setObjectName(QString::fromUtf8("portComboBox"));
        portComboBox->setGeometry(QRect(10, 20, 91, 22));
        chooseButton = new QPushButton(centralwidget);
        chooseButton->setObjectName(QString::fromUtf8("chooseButton"));
        chooseButton->setGeometry(QRect(360, 450, 75, 23));
        openButton = new QPushButton(centralwidget);
        openButton->setObjectName(QString::fromUtf8("openButton"));
        openButton->setGeometry(QRect(110, 20, 75, 23));
        closeButton = new QPushButton(centralwidget);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setGeometry(QRect(190, 20, 75, 23));
        sendButton = new QPushButton(centralwidget);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setGeometry(QRect(110, 110, 75, 23));
        statusLabel = new QLabel(centralwidget);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setGeometry(QRect(20, 60, 53, 15));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(0, 220, 351, 261));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(0, 530, 601, 23));
        progressBar->setValue(24);
        r_btn_collect = new QRadioButton(centralwidget);
        r_btn_collect->setObjectName(QString::fromUtf8("r_btn_collect"));
        r_btn_collect->setGeometry(QRect(360, 340, 121, 19));
        r_btn_inference = new QRadioButton(centralwidget);
        r_btn_inference->setObjectName(QString::fromUtf8("r_btn_inference"));
        r_btn_inference->setGeometry(QRect(360, 370, 121, 19));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        downloadButton->setText(QCoreApplication::translate("MainWindow", "\344\270\213\350\275\275", nullptr));
        chooseButton->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        openButton->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        closeButton->setText(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255", nullptr));
        sendButton->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        statusLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        r_btn_collect->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\261\240\344\277\241\346\201\257\351\207\207\351\233\206\350\275\257\344\273\266", nullptr));
        r_btn_inference->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\261\240\345\201\245\345\272\267\346\216\250\347\220\206\350\275\257\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
