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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QComboBox *portComboBox;
    QPushButton *openButton;
    QPushButton *closeButton;
    QPushButton *sendButton;
    QLabel *statusLabel;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLineEdit *lineEdit_4;
    QLabel *label_11;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_9;
    QLabel *label_16;
    QLabel *label_8;
    QLabel *label_18;
    QLabel *label_13;
    QLabel *label_6;
    QLineEdit *lineEdit;
    QLabel *label_20;
    QLabel *label_10;
    QLineEdit *lineEdit_3;
    QLabel *label_7;
    QLineEdit *lineEdit_2;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_12;
    QLabel *label_5;
    QLabel *label_2;
    QLabel *label_17;
    QLabel *label_19;
    QWidget *tab_2;
    QLabel *label_23;
    QLineEdit *lEdit_voltage;
    QLabel *label_28;
    QLineEdit *lEdit_current;
    QLabel *label_29;
    QLineEdit *lEdit_res;
    QLabel *label_30;
    QLineEdit *lEdit_cycle;
    QLabel *label_31;
    QLineEdit *lEdit_cfdzt;
    QLabel *label_32;
    QLineEdit *lEdit_battery_temperature;
    QLabel *label_46;
    QLineEdit *lEdit_CO;
    QLabel *label_47;
    QLineEdit *lEdit_H2;
    QLabel *label_48;
    QLineEdit *lEdit_SMK;
    QLabel *label_49;
    QLineEdit *lEdit_env_temperature;
    QLabel *label_50;
    QLineEdit *lEdit_humidity;
    QWidget *tab_3;
    QLineEdit *lEdit_inference_version;
    QLabel *label_21;
    QLabel *label_22;
    QLineEdit *lEdit_collect_version;
    QLabel *label_41;
    QLineEdit *lEdit_device_serial;
    QLabel *label_42;
    QLineEdit *lEdit_mac;
    QLabel *label_43;
    QLineEdit *lEdit_modbus_addr;
    QLabel *label_44;
    QLineEdit *lEdit_capacity;
    QPushButton *btn_getInfo;
    QWidget *tab_4;
    QRadioButton *r_btn_inference;
    QPushButton *chooseButton;
    QTextEdit *textEdit;
    QProgressBar *progressBar;
    QRadioButton *r_btn_collect;
    QPushButton *downloadButton;
    QLabel *label_45;
    QComboBox *comboBox;
    QWidget *tab_5;
    QLineEdit *lineEdit_17;
    QLabel *label_33;
    QLabel *label_34;
    QLabel *label_35;
    QLabel *label_36;
    QLabel *label_37;
    QLabel *label_38;
    QLabel *label_39;
    QLabel *label_40;
    QLineEdit *lineEdit_18;
    QLineEdit *lineEdit_19;
    QLineEdit *lineEdit_20;
    QLineEdit *lineEdit_21;
    QLineEdit *lineEdit_22;
    QLineEdit *lineEdit_23;
    QLineEdit *lineEdit_24;
    QGroupBox *groupBox;
    QLabel *label_24;
    QLineEdit *lineEdit_7;
    QLabel *label_25;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_10;
    QLabel *label_26;
    QLabel *label_27;
    QComboBox *cbox_modbus_addr;
    QPushButton *btn_net_init;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(884, 702);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        portComboBox = new QComboBox(centralwidget);
        portComboBox->setObjectName(QString::fromUtf8("portComboBox"));
        portComboBox->setGeometry(QRect(10, 20, 91, 22));
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
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 170, 861, 511));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        lineEdit_4 = new QLineEdit(tab);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(280, 70, 71, 21));
        lineEdit_4->setReadOnly(true);
        label_11 = new QLabel(tab);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(100, 90, 20, 20));
        label_11->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"border-radius:10px;"));
        label_11->setFrameShape(QFrame::Box);
        label_11->setLineWidth(1);
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 30, 53, 21));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 60, 53, 21));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 90, 53, 21));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(30, 240, 53, 21));
        label_16 = new QLabel(tab);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(100, 240, 20, 20));
        label_16->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"border-radius:10px;"));
        label_16->setFrameShape(QFrame::Box);
        label_16->setLineWidth(1);
        label_8 = new QLabel(tab);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(30, 210, 53, 21));
        label_18 = new QLabel(tab);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(190, 110, 91, 16));
        label_13 = new QLabel(tab);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(100, 150, 20, 20));
        label_13->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"border-radius:10px;"));
        label_13->setFrameShape(QFrame::Box);
        label_13->setLineWidth(1);
        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 150, 53, 21));
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(280, 40, 71, 21));
        lineEdit->setReadOnly(true);
        label_20 = new QLabel(tab);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(190, 80, 91, 16));
        label_10 = new QLabel(tab);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(100, 60, 20, 20));
        label_10->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"border-radius:10px;"));
        label_10->setFrameShape(QFrame::Box);
        label_10->setLineWidth(1);
        lineEdit_3 = new QLineEdit(tab);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(280, 150, 71, 21));
        lineEdit_3->setReadOnly(true);
        label_7 = new QLabel(tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 180, 53, 21));
        lineEdit_2 = new QLineEdit(tab);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(280, 110, 71, 21));
        lineEdit_2->setReadOnly(true);
        label_14 = new QLabel(tab);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(100, 180, 20, 20));
        label_14->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"border-radius:10px;"));
        label_14->setFrameShape(QFrame::Box);
        label_14->setLineWidth(1);
        label_15 = new QLabel(tab);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(100, 210, 20, 20));
        label_15->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"border-radius:10px;"));
        label_15->setFrameShape(QFrame::Box);
        label_15->setLineWidth(1);
        label_12 = new QLabel(tab);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(100, 120, 20, 20));
        label_12->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"border-radius:10px;"));
        label_12->setFrameShape(QFrame::Box);
        label_12->setLineWidth(1);
        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 120, 53, 21));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 30, 20, 20));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"border-radius:10px;"));
        label_2->setFrameShape(QFrame::Box);
        label_2->setLineWidth(1);
        label_17 = new QLabel(tab);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(190, 40, 91, 16));
        label_19 = new QLabel(tab);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(190, 150, 91, 16));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        label_23 = new QLabel(tab_2);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(20, 20, 61, 20));
        lEdit_voltage = new QLineEdit(tab_2);
        lEdit_voltage->setObjectName(QString::fromUtf8("lEdit_voltage"));
        lEdit_voltage->setGeometry(QRect(50, 20, 71, 21));
        label_28 = new QLabel(tab_2);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(20, 50, 31, 20));
        lEdit_current = new QLineEdit(tab_2);
        lEdit_current->setObjectName(QString::fromUtf8("lEdit_current"));
        lEdit_current->setGeometry(QRect(50, 50, 71, 21));
        label_29 = new QLabel(tab_2);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(20, 80, 31, 20));
        lEdit_res = new QLineEdit(tab_2);
        lEdit_res->setObjectName(QString::fromUtf8("lEdit_res"));
        lEdit_res->setGeometry(QRect(50, 80, 71, 21));
        label_30 = new QLabel(tab_2);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(20, 110, 61, 20));
        lEdit_cycle = new QLineEdit(tab_2);
        lEdit_cycle->setObjectName(QString::fromUtf8("lEdit_cycle"));
        lEdit_cycle->setGeometry(QRect(80, 110, 71, 21));
        label_31 = new QLabel(tab_2);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(20, 150, 71, 20));
        lEdit_cfdzt = new QLineEdit(tab_2);
        lEdit_cfdzt->setObjectName(QString::fromUtf8("lEdit_cfdzt"));
        lEdit_cfdzt->setGeometry(QRect(80, 150, 71, 21));
        label_32 = new QLabel(tab_2);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(20, 200, 71, 20));
        lEdit_battery_temperature = new QLineEdit(tab_2);
        lEdit_battery_temperature->setObjectName(QString::fromUtf8("lEdit_battery_temperature"));
        lEdit_battery_temperature->setGeometry(QRect(80, 200, 71, 21));
        label_46 = new QLabel(tab_2);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setGeometry(QRect(20, 240, 71, 20));
        lEdit_CO = new QLineEdit(tab_2);
        lEdit_CO->setObjectName(QString::fromUtf8("lEdit_CO"));
        lEdit_CO->setGeometry(QRect(100, 240, 71, 21));
        label_47 = new QLabel(tab_2);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        label_47->setGeometry(QRect(20, 270, 71, 20));
        lEdit_H2 = new QLineEdit(tab_2);
        lEdit_H2->setObjectName(QString::fromUtf8("lEdit_H2"));
        lEdit_H2->setGeometry(QRect(100, 270, 71, 21));
        label_48 = new QLabel(tab_2);
        label_48->setObjectName(QString::fromUtf8("label_48"));
        label_48->setGeometry(QRect(20, 300, 71, 20));
        lEdit_SMK = new QLineEdit(tab_2);
        lEdit_SMK->setObjectName(QString::fromUtf8("lEdit_SMK"));
        lEdit_SMK->setGeometry(QRect(100, 300, 71, 21));
        label_49 = new QLabel(tab_2);
        label_49->setObjectName(QString::fromUtf8("label_49"));
        label_49->setGeometry(QRect(20, 330, 71, 20));
        lEdit_env_temperature = new QLineEdit(tab_2);
        lEdit_env_temperature->setObjectName(QString::fromUtf8("lEdit_env_temperature"));
        lEdit_env_temperature->setGeometry(QRect(100, 330, 71, 21));
        label_50 = new QLabel(tab_2);
        label_50->setObjectName(QString::fromUtf8("label_50"));
        label_50->setGeometry(QRect(20, 360, 71, 20));
        lEdit_humidity = new QLineEdit(tab_2);
        lEdit_humidity->setObjectName(QString::fromUtf8("lEdit_humidity"));
        lEdit_humidity->setGeometry(QRect(100, 360, 71, 21));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        lEdit_inference_version = new QLineEdit(tab_3);
        lEdit_inference_version->setObjectName(QString::fromUtf8("lEdit_inference_version"));
        lEdit_inference_version->setGeometry(QRect(160, 30, 171, 21));
        lEdit_inference_version->setReadOnly(true);
        label_21 = new QLabel(tab_3);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(10, 10, 151, 20));
        label_22 = new QLabel(tab_3);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(10, 30, 151, 20));
        lEdit_collect_version = new QLineEdit(tab_3);
        lEdit_collect_version->setObjectName(QString::fromUtf8("lEdit_collect_version"));
        lEdit_collect_version->setGeometry(QRect(160, 10, 171, 21));
        lEdit_collect_version->setReadOnly(true);
        label_41 = new QLabel(tab_3);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setGeometry(QRect(10, 70, 151, 20));
        lEdit_device_serial = new QLineEdit(tab_3);
        lEdit_device_serial->setObjectName(QString::fromUtf8("lEdit_device_serial"));
        lEdit_device_serial->setGeometry(QRect(160, 60, 141, 21));
        lEdit_device_serial->setReadOnly(true);
        label_42 = new QLabel(tab_3);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setGeometry(QRect(10, 110, 151, 20));
        lEdit_mac = new QLineEdit(tab_3);
        lEdit_mac->setObjectName(QString::fromUtf8("lEdit_mac"));
        lEdit_mac->setGeometry(QRect(160, 110, 141, 21));
        lEdit_mac->setReadOnly(true);
        label_43 = new QLabel(tab_3);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setGeometry(QRect(10, 150, 151, 20));
        lEdit_modbus_addr = new QLineEdit(tab_3);
        lEdit_modbus_addr->setObjectName(QString::fromUtf8("lEdit_modbus_addr"));
        lEdit_modbus_addr->setGeometry(QRect(160, 150, 141, 21));
        lEdit_modbus_addr->setReadOnly(true);
        label_44 = new QLabel(tab_3);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setGeometry(QRect(10, 190, 151, 20));
        lEdit_capacity = new QLineEdit(tab_3);
        lEdit_capacity->setObjectName(QString::fromUtf8("lEdit_capacity"));
        lEdit_capacity->setGeometry(QRect(160, 190, 141, 21));
        lEdit_capacity->setReadOnly(true);
        btn_getInfo = new QPushButton(tab_3);
        btn_getInfo->setObjectName(QString::fromUtf8("btn_getInfo"));
        btn_getInfo->setGeometry(QRect(420, 20, 75, 23));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        r_btn_inference = new QRadioButton(tab_4);
        r_btn_inference->setObjectName(QString::fromUtf8("r_btn_inference"));
        r_btn_inference->setGeometry(QRect(260, 170, 121, 19));
        chooseButton = new QPushButton(tab_4);
        chooseButton->setObjectName(QString::fromUtf8("chooseButton"));
        chooseButton->setGeometry(QRect(30, 170, 75, 23));
        textEdit = new QTextEdit(tab_4);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(30, 30, 351, 111));
        progressBar = new QProgressBar(tab_4);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(30, 150, 211, 23));
        progressBar->setValue(24);
        r_btn_collect = new QRadioButton(tab_4);
        r_btn_collect->setObjectName(QString::fromUtf8("r_btn_collect"));
        r_btn_collect->setGeometry(QRect(260, 150, 121, 19));
        downloadButton = new QPushButton(tab_4);
        downloadButton->setObjectName(QString::fromUtf8("downloadButton"));
        downloadButton->setGeometry(QRect(110, 170, 75, 23));
        label_45 = new QLabel(tab_4);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setGeometry(QRect(40, 250, 81, 16));
        comboBox = new QComboBox(tab_4);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(120, 250, 69, 22));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        lineEdit_17 = new QLineEdit(tab_5);
        lineEdit_17->setObjectName(QString::fromUtf8("lineEdit_17"));
        lineEdit_17->setGeometry(QRect(150, 10, 113, 21));
        label_33 = new QLabel(tab_5);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(20, 10, 81, 16));
        label_34 = new QLabel(tab_5);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(20, 40, 101, 16));
        label_35 = new QLabel(tab_5);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(20, 70, 101, 16));
        label_36 = new QLabel(tab_5);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setGeometry(QRect(20, 100, 101, 16));
        label_37 = new QLabel(tab_5);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(20, 140, 101, 16));
        label_38 = new QLabel(tab_5);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setGeometry(QRect(20, 170, 101, 16));
        label_39 = new QLabel(tab_5);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setGeometry(QRect(20, 200, 101, 16));
        label_40 = new QLabel(tab_5);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setGeometry(QRect(20, 240, 101, 16));
        lineEdit_18 = new QLineEdit(tab_5);
        lineEdit_18->setObjectName(QString::fromUtf8("lineEdit_18"));
        lineEdit_18->setGeometry(QRect(150, 40, 113, 21));
        lineEdit_19 = new QLineEdit(tab_5);
        lineEdit_19->setObjectName(QString::fromUtf8("lineEdit_19"));
        lineEdit_19->setGeometry(QRect(150, 70, 113, 21));
        lineEdit_20 = new QLineEdit(tab_5);
        lineEdit_20->setObjectName(QString::fromUtf8("lineEdit_20"));
        lineEdit_20->setGeometry(QRect(150, 100, 113, 21));
        lineEdit_21 = new QLineEdit(tab_5);
        lineEdit_21->setObjectName(QString::fromUtf8("lineEdit_21"));
        lineEdit_21->setGeometry(QRect(150, 130, 113, 21));
        lineEdit_22 = new QLineEdit(tab_5);
        lineEdit_22->setObjectName(QString::fromUtf8("lineEdit_22"));
        lineEdit_22->setGeometry(QRect(150, 170, 113, 21));
        lineEdit_23 = new QLineEdit(tab_5);
        lineEdit_23->setObjectName(QString::fromUtf8("lineEdit_23"));
        lineEdit_23->setGeometry(QRect(150, 200, 113, 21));
        lineEdit_24 = new QLineEdit(tab_5);
        lineEdit_24->setObjectName(QString::fromUtf8("lineEdit_24"));
        lineEdit_24->setGeometry(QRect(150, 240, 113, 21));
        tabWidget->addTab(tab_5, QString());
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(490, 9, 371, 151));
        label_24 = new QLabel(groupBox);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(10, 90, 91, 16));
        lineEdit_7 = new QLineEdit(groupBox);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(100, 20, 71, 21));
        lineEdit_7->setReadOnly(true);
        label_25 = new QLabel(groupBox);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(10, 60, 91, 16));
        lineEdit_8 = new QLineEdit(groupBox);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(100, 120, 71, 21));
        lineEdit_8->setReadOnly(true);
        lineEdit_9 = new QLineEdit(groupBox);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));
        lineEdit_9->setGeometry(QRect(100, 90, 71, 21));
        lineEdit_9->setReadOnly(true);
        lineEdit_10 = new QLineEdit(groupBox);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));
        lineEdit_10->setGeometry(QRect(100, 50, 71, 21));
        lineEdit_10->setReadOnly(true);
        label_26 = new QLabel(groupBox);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(10, 20, 91, 16));
        label_27 = new QLabel(groupBox);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(10, 120, 91, 16));
        cbox_modbus_addr = new QComboBox(centralwidget);
        cbox_modbus_addr->setObjectName(QString::fromUtf8("cbox_modbus_addr"));
        cbox_modbus_addr->setGeometry(QRect(290, 90, 69, 22));
        btn_net_init = new QPushButton(centralwidget);
        btn_net_init->setObjectName(QString::fromUtf8("btn_net_init"));
        btn_net_init->setGeometry(QRect(370, 90, 75, 23));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 884, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        openButton->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        closeButton->setText(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255", nullptr));
        sendButton->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        statusLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_11->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "\347\201\253\350\255\246", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\254\240\345\216\213\346\212\245\350\255\246", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\350\277\207\345\216\213\346\212\245\350\255\246", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "CO\346\212\245\350\255\246", nullptr));
        label_16->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "H2\346\212\245\350\255\246", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "SOC", nullptr));
        label_13->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "\350\277\207\346\224\276\346\212\245\350\255\246", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "\347\203\255\345\244\261\346\216\247\346\246\202\347\216\207", nullptr));
        label_10->setText(QString());
        label_7->setText(QCoreApplication::translate("MainWindow", "\347\203\237\351\233\276\346\212\245\350\255\246", nullptr));
        label_14->setText(QString());
        label_15->setText(QString());
        label_12->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "\350\277\207\345\205\205\346\212\245\350\255\246", nullptr));
        label_2->setText(QString());
        label_17->setText(QCoreApplication::translate("MainWindow", "\347\203\255\345\244\261\346\216\247\351\242\204\350\255\246\347\255\211\347\272\247", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "SOH", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\346\212\245\350\255\246\351\242\204\350\255\246\344\277\241\346\201\257", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "\347\224\265\345\216\213", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\265\201", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "\345\206\205\351\230\273", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "\345\205\205\346\224\276\347\224\265\350\275\256\346\254\241", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "\345\205\205\346\224\276\347\224\265\347\212\266\346\200\201", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\261\240\346\270\251\345\272\246", nullptr));
        label_46->setText(QCoreApplication::translate("MainWindow", "\344\270\200\346\260\247\345\214\226\347\242\263\346\265\223\345\272\246", nullptr));
        label_47->setText(QCoreApplication::translate("MainWindow", "\346\260\242\346\260\224\346\265\223\345\272\246", nullptr));
        label_48->setText(QCoreApplication::translate("MainWindow", "\347\203\237\351\233\276\347\212\266\346\200\201", nullptr));
        label_49->setText(QCoreApplication::translate("MainWindow", "\347\216\257\345\242\203\346\270\251\345\272\246", nullptr));
        label_50->setText(QCoreApplication::translate("MainWindow", "\347\216\257\345\242\203\346\271\277\345\272\246", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\347\212\266\346\200\201\344\277\241\346\201\257", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\261\240\344\277\241\346\201\257\351\207\207\351\233\206\350\275\257\344\273\266\350\275\257\344\273\266\347\211\210\346\234\254", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\261\240\345\201\245\345\272\267\346\216\250\347\220\206\350\275\257\344\273\266\350\275\257\344\273\266\347\211\210\346\234\254", nullptr));
        label_41->setText(QCoreApplication::translate("MainWindow", "\350\256\276\345\244\207\347\274\226\345\217\267", nullptr));
        label_42->setText(QCoreApplication::translate("MainWindow", "\350\256\276\345\244\207MAC\345\234\260\345\235\200", nullptr));
        label_43->setText(QCoreApplication::translate("MainWindow", "\350\256\276\345\244\207Modbus\345\234\260\345\235\200", nullptr));
        label_44->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\261\240\351\242\235\345\256\232\345\256\271\351\207\217", nullptr));
        btn_getInfo->setText(QCoreApplication::translate("MainWindow", "\350\216\267\345\217\226", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "\350\275\257\344\273\266\347\211\210\346\234\254\344\277\241\346\201\257", nullptr));
        r_btn_inference->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\261\240\345\201\245\345\272\267\346\216\250\347\220\206\350\275\257\344\273\266", nullptr));
        chooseButton->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        r_btn_collect->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\261\240\344\277\241\346\201\257\351\207\207\351\233\206\350\275\257\344\273\266", nullptr));
        downloadButton->setText(QCoreApplication::translate("MainWindow", "\344\270\213\350\275\275", nullptr));
        label_45->setText(QCoreApplication::translate("MainWindow", "\350\275\257\344\273\266\345\215\207\347\272\247\346\240\207\345\277\227", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "\350\275\257\344\273\266\345\215\207\347\272\247", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "\346\260\242\346\260\224\346\212\245\350\255\246\351\230\210\345\200\274", nullptr));
        label_34->setText(QCoreApplication::translate("MainWindow", "\344\270\200\346\260\247\345\214\226\347\242\263\346\212\245\350\255\246\351\230\210\345\200\274", nullptr));
        label_35->setText(QCoreApplication::translate("MainWindow", "\346\270\251\345\272\246\346\212\245\350\255\246\351\230\210\345\200\274", nullptr));
        label_36->setText(QCoreApplication::translate("MainWindow", "\346\270\251\345\215\207\347\216\207\346\212\245\350\255\246\351\230\210\345\200\274", nullptr));
        label_37->setText(QCoreApplication::translate("MainWindow", "\347\224\265\345\216\213\346\212\245\350\255\246\351\253\230\351\230\210\345\200\274", nullptr));
        label_38->setText(QCoreApplication::translate("MainWindow", "\347\224\265\345\216\213\346\212\245\350\255\246\344\275\216\351\230\210\345\200\274", nullptr));
        label_39->setText(QCoreApplication::translate("MainWindow", "\346\224\276\347\224\265\347\224\265\346\265\201\346\212\245\350\255\246\351\230\210\345\200\274", nullptr));
        label_40->setText(QCoreApplication::translate("MainWindow", "\345\205\205\347\224\265\347\224\265\346\265\201\346\212\245\350\255\246\351\230\210\345\200\274", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("MainWindow", "\351\230\210\345\200\274\350\256\276\347\275\256", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\347\224\265\346\261\240\345\275\223\345\211\215\345\256\236\346\227\266\344\277\241\346\201\257", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "SOC", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "\347\203\255\345\244\261\346\216\247\346\246\202\347\216\207", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "\347\203\255\345\244\261\346\216\247\351\242\204\350\255\246\347\255\211\347\272\247", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "SOH", nullptr));
        btn_net_init->setText(QCoreApplication::translate("MainWindow", "\350\256\276\345\244\207\350\216\267\345\217\226", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
