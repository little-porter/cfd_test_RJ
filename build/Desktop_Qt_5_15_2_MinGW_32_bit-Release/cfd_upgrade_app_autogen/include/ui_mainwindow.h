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
#include <QtWidgets/QGridLayout>
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
    QWidget *layoutWidget;
    QGridLayout *gridLayout_6;
    QGroupBox *groupBox_8;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_8;
    QLabel *label;
    QLabel *label_fire;
    QLabel *label_3;
    QLabel *label_underVoltage;
    QLabel *label_4;
    QLabel *label_overVoltage;
    QLabel *label_5;
    QLabel *label_overCharge;
    QLabel *label_6;
    QLabel *label_overDischarge;
    QLabel *label_7;
    QLabel *label_smk;
    QLabel *label_8;
    QLabel *label_h2;
    QLabel *label_9;
    QLabel *label_co;
    QGroupBox *groupBox_9;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_9;
    QLabel *label_17;
    QLineEdit *lEdit_rsk_level;
    QLabel *label_20;
    QLineEdit *lEdit_rsk_ratio;
    QLabel *label_18;
    QLineEdit *lEdit_soc;
    QLabel *label_19;
    QLineEdit *lEdit_soh;
    QGroupBox *groupBox_10;
    QWidget *layoutWidget3;
    QGridLayout *gridLayout_10;
    QLabel *label_23;
    QLineEdit *lEdit_voltage;
    QLabel *label_115;
    QLabel *label_28;
    QLineEdit *lEdit_current;
    QLabel *label_116;
    QLabel *label_29;
    QLineEdit *lEdit_res;
    QLabel *label_117;
    QLabel *label_30;
    QLineEdit *lEdit_cycle;
    QLabel *label_31;
    QLineEdit *lEdit_cfdzt;
    QLabel *label_32;
    QLineEdit *lEdit_battery_temperature;
    QLabel *label_118;
    QGroupBox *groupBox_11;
    QWidget *layoutWidget4;
    QGridLayout *gridLayout_11;
    QLabel *label_46;
    QLineEdit *lEdit_CO;
    QLabel *label_112;
    QLabel *label_47;
    QLineEdit *lEdit_H2;
    QLabel *label_113;
    QLabel *label_48;
    QLineEdit *lEdit_SMK;
    QLabel *label_49;
    QLineEdit *lEdit_env_temperature;
    QLabel *label_114;
    QLabel *label_50;
    QLineEdit *lEdit_humidity;
    QWidget *tab_3;
    QWidget *layoutWidget5;
    QGridLayout *gridLayout_13;
    QGroupBox *groupBox_12;
    QWidget *layoutWidget6;
    QGridLayout *gridLayout_14;
    QLabel *label_21;
    QLineEdit *lEdit_collect_version;
    QLabel *label_22;
    QLineEdit *lEdit_inference_version;
    QGroupBox *groupBox_15;
    QWidget *layoutWidget7;
    QGridLayout *gridLayout_18;
    QLabel *label_119;
    QLineEdit *lEdit_h2_th;
    QLabel *label_120;
    QLineEdit *lEdit_co_th;
    QLabel *label_121;
    QLineEdit *lEdit_temp_th;
    QLabel *label_122;
    QLineEdit *lEdit_temp_ratio_th;
    QLabel *label_123;
    QLineEdit *lEdit_voltage_high_th;
    QLabel *label_124;
    QLineEdit *lEdit_voltage_low_th;
    QLabel *label_125;
    QLineEdit *lEdit_discharge_th;
    QLabel *label_126;
    QLineEdit *lEdit_charge_th;
    QGroupBox *groupBox_13;
    QWidget *layoutWidget8;
    QGridLayout *gridLayout_2;
    QLabel *label_41;
    QLineEdit *lEdit_device_serial;
    QLabel *label_42;
    QLineEdit *lEdit_mac;
    QLabel *label_43;
    QLineEdit *lEdit_modbus_addr;
    QLabel *label_44;
    QLineEdit *lEdit_capacity;
    QLabel *label_127;
    QLineEdit *lEdit_low_power;
    QLabel *label_128;
    QLineEdit *lEdit_balance;
    QPushButton *btn_getInfo;
    QWidget *tab_4;
    QGroupBox *groupBox_14;
    QWidget *layoutWidget9;
    QGridLayout *gridLayout_17;
    QProgressBar *progressBar;
    QTextEdit *textEdit;
    QWidget *layoutWidget10;
    QGridLayout *gridLayout_16;
    QRadioButton *r_btn_inference;
    QPushButton *chooseButton;
    QPushButton *downloadButton;
    QLabel *label_45;
    QComboBox *comboBox;
    QRadioButton *r_btn_collect;
    QWidget *tab_5;
    QWidget *layoutWidget11;
    QGridLayout *gridLayout_12;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget12;
    QGridLayout *gridLayout;
    QLabel *label_33;
    QLineEdit *lEdit_h2_th_set;
    QLabel *label_34;
    QLineEdit *lEdit_co_th_set;
    QLabel *label_35;
    QLineEdit *lEdit_temp_th_set;
    QLabel *label_36;
    QLineEdit *lEdit_temp_ratio_th_set;
    QLabel *label_37;
    QLineEdit *lEdit_voltage_high_th_set;
    QLabel *label_38;
    QLineEdit *lEdit_voltage_low_th_set;
    QLabel *label_39;
    QLineEdit *lEdit_discharge_th_set;
    QLabel *label_40;
    QLineEdit *lEdit_charge_th_set;
    QPushButton *btn_threshold_set;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget13;
    QGridLayout *gridLayout_5;
    QLabel *label_53;
    QLineEdit *lEdit_serial_set;
    QPushButton *btn_serial_set;
    QLabel *label_54;
    QLineEdit *lEdit_time_set;
    QPushButton *btn_time_set;
    QLabel *label_55;
    QLineEdit *lEdit_capacity_set;
    QPushButton *btn_capacity_set;
    QLabel *label_111;
    QLineEdit *lEdit_current_set;
    QPushButton *btn_current_set;
    QGroupBox *groupBox_4;
    QWidget *layoutWidget14;
    QGridLayout *gridLayout_7;
    QLabel *label_56;
    QPushButton *btn_serial_set_2;
    QLabel *label_51;
    QPushButton *btn_low_power;
    QLabel *label_52;
    QPushButton *btn_balanced;
    QWidget *tab_2;
    QGroupBox *groupBox;
    QPushButton *btn_voltage_calib_get;
    QWidget *layoutWidget15;
    QGridLayout *gridLayout_3;
    QLabel *label_27;
    QLineEdit *lEdit_voltage_range;
    QLabel *label_26;
    QLineEdit *lEdit_voltage_zero;
    QWidget *layoutWidget_3;
    QGridLayout *gridLayout_19;
    QLabel *label_59;
    QLineEdit *lEdit_co_k_calib;
    QLabel *label_60;
    QLineEdit *lEdit_co_b_calib;
    QWidget *layoutWidget_5;
    QGridLayout *gridLayout_21;
    QLabel *label_63;
    QLineEdit *lEdit_h2_k_calib;
    QLabel *label_64;
    QLineEdit *lEdit_h2_b_calib;
    QGroupBox *groupBox_5;
    QWidget *layoutWidget16;
    QGridLayout *gridLayout_4;
    QLabel *label_24;
    QLineEdit *lEdit_voltage_range_calib;
    QLabel *label_25;
    QLineEdit *lEdit_voltage_zero_calib;
    QPushButton *btn_voltage_calib_set;
    QGroupBox *groupBox_6;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout_15;
    QLabel *label_57;
    QLineEdit *lEdit_co_k_calib_set;
    QLabel *label_58;
    QLineEdit *lEdit_co_b_calib_set;
    QPushButton *btn_co_calib_set;
    QGroupBox *groupBox_7;
    QWidget *layoutWidget_4;
    QGridLayout *gridLayout_20;
    QLabel *label_61;
    QLineEdit *lEdit_h2_k_calib_set;
    QLabel *label_62;
    QLineEdit *lEdit_h2_b_calib_set;
    QPushButton *btn_h2_calib_set;
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
        sendButton->setGeometry(QRect(110, 100, 75, 23));
        statusLabel = new QLabel(centralwidget);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setGeometry(QRect(20, 60, 53, 15));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 200, 861, 461));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 681, 421));
        gridLayout_6 = new QGridLayout(layoutWidget);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        groupBox_8 = new QGroupBox(layoutWidget);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        layoutWidget1 = new QWidget(groupBox_8);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 20, 241, 171));
        gridLayout_8 = new QGridLayout(layoutWidget1);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_8->addWidget(label, 0, 0, 1, 1);

        label_fire = new QLabel(layoutWidget1);
        label_fire->setObjectName(QString::fromUtf8("label_fire"));
        label_fire->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"border-radius:15px;"));
        label_fire->setFrameShape(QFrame::Box);
        label_fire->setLineWidth(1);

        gridLayout_8->addWidget(label_fire, 0, 1, 1, 1);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_8->addWidget(label_3, 0, 2, 1, 1);

        label_underVoltage = new QLabel(layoutWidget1);
        label_underVoltage->setObjectName(QString::fromUtf8("label_underVoltage"));
        label_underVoltage->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"border-radius:15px;"));
        label_underVoltage->setFrameShape(QFrame::Box);
        label_underVoltage->setLineWidth(1);

        gridLayout_8->addWidget(label_underVoltage, 0, 3, 1, 1);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_8->addWidget(label_4, 1, 0, 1, 1);

        label_overVoltage = new QLabel(layoutWidget1);
        label_overVoltage->setObjectName(QString::fromUtf8("label_overVoltage"));
        label_overVoltage->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"border-radius:15px;"));
        label_overVoltage->setFrameShape(QFrame::Box);
        label_overVoltage->setLineWidth(1);

        gridLayout_8->addWidget(label_overVoltage, 1, 1, 1, 1);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_8->addWidget(label_5, 1, 2, 1, 1);

        label_overCharge = new QLabel(layoutWidget1);
        label_overCharge->setObjectName(QString::fromUtf8("label_overCharge"));
        label_overCharge->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"border-radius:15px;"));
        label_overCharge->setFrameShape(QFrame::Box);
        label_overCharge->setLineWidth(1);

        gridLayout_8->addWidget(label_overCharge, 1, 3, 1, 1);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_8->addWidget(label_6, 2, 0, 1, 1);

        label_overDischarge = new QLabel(layoutWidget1);
        label_overDischarge->setObjectName(QString::fromUtf8("label_overDischarge"));
        label_overDischarge->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"border-radius:15px;"));
        label_overDischarge->setFrameShape(QFrame::Box);
        label_overDischarge->setLineWidth(1);

        gridLayout_8->addWidget(label_overDischarge, 2, 1, 1, 1);

        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_8->addWidget(label_7, 2, 2, 1, 1);

        label_smk = new QLabel(layoutWidget1);
        label_smk->setObjectName(QString::fromUtf8("label_smk"));
        label_smk->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"border-radius:15px;"));
        label_smk->setFrameShape(QFrame::Box);
        label_smk->setLineWidth(1);

        gridLayout_8->addWidget(label_smk, 2, 3, 1, 1);

        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_8->addWidget(label_8, 3, 0, 1, 1);

        label_h2 = new QLabel(layoutWidget1);
        label_h2->setObjectName(QString::fromUtf8("label_h2"));
        label_h2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"border-radius:15px;"));
        label_h2->setFrameShape(QFrame::Box);
        label_h2->setLineWidth(1);

        gridLayout_8->addWidget(label_h2, 3, 1, 1, 1);

        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_8->addWidget(label_9, 3, 2, 1, 1);

        label_co = new QLabel(layoutWidget1);
        label_co->setObjectName(QString::fromUtf8("label_co"));
        label_co->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"border-radius:15px;"));
        label_co->setFrameShape(QFrame::Box);
        label_co->setLineWidth(1);

        gridLayout_8->addWidget(label_co, 3, 3, 1, 1);


        gridLayout_6->addWidget(groupBox_8, 0, 0, 1, 1);

        groupBox_9 = new QGroupBox(layoutWidget);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        layoutWidget2 = new QWidget(groupBox_9);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 20, 241, 171));
        gridLayout_9 = new QGridLayout(layoutWidget2);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        label_17 = new QLabel(layoutWidget2);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_9->addWidget(label_17, 0, 0, 1, 1);

        lEdit_rsk_level = new QLineEdit(layoutWidget2);
        lEdit_rsk_level->setObjectName(QString::fromUtf8("lEdit_rsk_level"));
        lEdit_rsk_level->setReadOnly(true);

        gridLayout_9->addWidget(lEdit_rsk_level, 0, 1, 1, 1);

        label_20 = new QLabel(layoutWidget2);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_9->addWidget(label_20, 1, 0, 1, 1);

        lEdit_rsk_ratio = new QLineEdit(layoutWidget2);
        lEdit_rsk_ratio->setObjectName(QString::fromUtf8("lEdit_rsk_ratio"));
        lEdit_rsk_ratio->setReadOnly(true);

        gridLayout_9->addWidget(lEdit_rsk_ratio, 1, 1, 1, 1);

        label_18 = new QLabel(layoutWidget2);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_9->addWidget(label_18, 2, 0, 1, 1);

        lEdit_soc = new QLineEdit(layoutWidget2);
        lEdit_soc->setObjectName(QString::fromUtf8("lEdit_soc"));
        lEdit_soc->setReadOnly(true);

        gridLayout_9->addWidget(lEdit_soc, 2, 1, 1, 1);

        label_19 = new QLabel(layoutWidget2);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_9->addWidget(label_19, 3, 0, 1, 1);

        lEdit_soh = new QLineEdit(layoutWidget2);
        lEdit_soh->setObjectName(QString::fromUtf8("lEdit_soh"));
        lEdit_soh->setReadOnly(true);

        gridLayout_9->addWidget(lEdit_soh, 3, 1, 1, 1);


        gridLayout_6->addWidget(groupBox_9, 0, 1, 1, 1);

        groupBox_10 = new QGroupBox(layoutWidget);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        layoutWidget3 = new QWidget(groupBox_10);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(11, 30, 241, 161));
        gridLayout_10 = new QGridLayout(layoutWidget3);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        label_23 = new QLabel(layoutWidget3);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        gridLayout_10->addWidget(label_23, 0, 0, 1, 1);

        lEdit_voltage = new QLineEdit(layoutWidget3);
        lEdit_voltage->setObjectName(QString::fromUtf8("lEdit_voltage"));
        lEdit_voltage->setReadOnly(true);

        gridLayout_10->addWidget(lEdit_voltage, 0, 1, 1, 1);

        label_115 = new QLabel(layoutWidget3);
        label_115->setObjectName(QString::fromUtf8("label_115"));

        gridLayout_10->addWidget(label_115, 0, 2, 1, 1);

        label_28 = new QLabel(layoutWidget3);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        gridLayout_10->addWidget(label_28, 1, 0, 1, 1);

        lEdit_current = new QLineEdit(layoutWidget3);
        lEdit_current->setObjectName(QString::fromUtf8("lEdit_current"));
        lEdit_current->setReadOnly(true);

        gridLayout_10->addWidget(lEdit_current, 1, 1, 1, 1);

        label_116 = new QLabel(layoutWidget3);
        label_116->setObjectName(QString::fromUtf8("label_116"));

        gridLayout_10->addWidget(label_116, 1, 2, 1, 1);

        label_29 = new QLabel(layoutWidget3);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        gridLayout_10->addWidget(label_29, 2, 0, 1, 1);

        lEdit_res = new QLineEdit(layoutWidget3);
        lEdit_res->setObjectName(QString::fromUtf8("lEdit_res"));
        lEdit_res->setReadOnly(true);

        gridLayout_10->addWidget(lEdit_res, 2, 1, 1, 1);

        label_117 = new QLabel(layoutWidget3);
        label_117->setObjectName(QString::fromUtf8("label_117"));

        gridLayout_10->addWidget(label_117, 2, 2, 1, 1);

        label_30 = new QLabel(layoutWidget3);
        label_30->setObjectName(QString::fromUtf8("label_30"));

        gridLayout_10->addWidget(label_30, 3, 0, 1, 1);

        lEdit_cycle = new QLineEdit(layoutWidget3);
        lEdit_cycle->setObjectName(QString::fromUtf8("lEdit_cycle"));
        lEdit_cycle->setReadOnly(true);

        gridLayout_10->addWidget(lEdit_cycle, 3, 1, 1, 1);

        label_31 = new QLabel(layoutWidget3);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        gridLayout_10->addWidget(label_31, 4, 0, 1, 1);

        lEdit_cfdzt = new QLineEdit(layoutWidget3);
        lEdit_cfdzt->setObjectName(QString::fromUtf8("lEdit_cfdzt"));
        lEdit_cfdzt->setReadOnly(true);

        gridLayout_10->addWidget(lEdit_cfdzt, 4, 1, 1, 1);

        label_32 = new QLabel(layoutWidget3);
        label_32->setObjectName(QString::fromUtf8("label_32"));

        gridLayout_10->addWidget(label_32, 5, 0, 1, 1);

        lEdit_battery_temperature = new QLineEdit(layoutWidget3);
        lEdit_battery_temperature->setObjectName(QString::fromUtf8("lEdit_battery_temperature"));
        lEdit_battery_temperature->setReadOnly(true);

        gridLayout_10->addWidget(lEdit_battery_temperature, 5, 1, 1, 1);

        label_118 = new QLabel(layoutWidget3);
        label_118->setObjectName(QString::fromUtf8("label_118"));

        gridLayout_10->addWidget(label_118, 5, 2, 1, 1);


        gridLayout_6->addWidget(groupBox_10, 1, 0, 1, 1);

        groupBox_11 = new QGroupBox(layoutWidget);
        groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));
        layoutWidget4 = new QWidget(groupBox_11);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(5, 30, 251, 161));
        gridLayout_11 = new QGridLayout(layoutWidget4);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        label_46 = new QLabel(layoutWidget4);
        label_46->setObjectName(QString::fromUtf8("label_46"));

        gridLayout_11->addWidget(label_46, 0, 0, 1, 1);

        lEdit_CO = new QLineEdit(layoutWidget4);
        lEdit_CO->setObjectName(QString::fromUtf8("lEdit_CO"));
        lEdit_CO->setReadOnly(true);

        gridLayout_11->addWidget(lEdit_CO, 0, 1, 1, 1);

        label_112 = new QLabel(layoutWidget4);
        label_112->setObjectName(QString::fromUtf8("label_112"));

        gridLayout_11->addWidget(label_112, 0, 2, 1, 1);

        label_47 = new QLabel(layoutWidget4);
        label_47->setObjectName(QString::fromUtf8("label_47"));

        gridLayout_11->addWidget(label_47, 1, 0, 1, 1);

        lEdit_H2 = new QLineEdit(layoutWidget4);
        lEdit_H2->setObjectName(QString::fromUtf8("lEdit_H2"));
        lEdit_H2->setReadOnly(true);

        gridLayout_11->addWidget(lEdit_H2, 1, 1, 1, 1);

        label_113 = new QLabel(layoutWidget4);
        label_113->setObjectName(QString::fromUtf8("label_113"));

        gridLayout_11->addWidget(label_113, 1, 2, 1, 1);

        label_48 = new QLabel(layoutWidget4);
        label_48->setObjectName(QString::fromUtf8("label_48"));

        gridLayout_11->addWidget(label_48, 2, 0, 1, 1);

        lEdit_SMK = new QLineEdit(layoutWidget4);
        lEdit_SMK->setObjectName(QString::fromUtf8("lEdit_SMK"));
        lEdit_SMK->setReadOnly(true);

        gridLayout_11->addWidget(lEdit_SMK, 2, 1, 1, 1);

        label_49 = new QLabel(layoutWidget4);
        label_49->setObjectName(QString::fromUtf8("label_49"));

        gridLayout_11->addWidget(label_49, 3, 0, 1, 1);

        lEdit_env_temperature = new QLineEdit(layoutWidget4);
        lEdit_env_temperature->setObjectName(QString::fromUtf8("lEdit_env_temperature"));
        lEdit_env_temperature->setReadOnly(true);

        gridLayout_11->addWidget(lEdit_env_temperature, 3, 1, 1, 1);

        label_114 = new QLabel(layoutWidget4);
        label_114->setObjectName(QString::fromUtf8("label_114"));

        gridLayout_11->addWidget(label_114, 3, 2, 1, 1);

        label_50 = new QLabel(layoutWidget4);
        label_50->setObjectName(QString::fromUtf8("label_50"));

        gridLayout_11->addWidget(label_50, 4, 0, 1, 1);

        lEdit_humidity = new QLineEdit(layoutWidget4);
        lEdit_humidity->setObjectName(QString::fromUtf8("lEdit_humidity"));
        lEdit_humidity->setReadOnly(true);

        gridLayout_11->addWidget(lEdit_humidity, 4, 1, 1, 1);


        gridLayout_6->addWidget(groupBox_11, 1, 1, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        layoutWidget5 = new QWidget(tab_3);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(11, 8, 831, 411));
        gridLayout_13 = new QGridLayout(layoutWidget5);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_13->setContentsMargins(0, 0, 0, 0);
        groupBox_12 = new QGroupBox(layoutWidget5);
        groupBox_12->setObjectName(QString::fromUtf8("groupBox_12"));
        layoutWidget6 = new QWidget(groupBox_12);
        layoutWidget6->setObjectName(QString::fromUtf8("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(20, 30, 361, 111));
        gridLayout_14 = new QGridLayout(layoutWidget6);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        gridLayout_14->setContentsMargins(0, 0, 0, 0);
        label_21 = new QLabel(layoutWidget6);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_14->addWidget(label_21, 0, 0, 1, 1);

        lEdit_collect_version = new QLineEdit(layoutWidget6);
        lEdit_collect_version->setObjectName(QString::fromUtf8("lEdit_collect_version"));
        lEdit_collect_version->setReadOnly(true);

        gridLayout_14->addWidget(lEdit_collect_version, 0, 1, 1, 1);

        label_22 = new QLabel(layoutWidget6);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        gridLayout_14->addWidget(label_22, 1, 0, 1, 1);

        lEdit_inference_version = new QLineEdit(layoutWidget6);
        lEdit_inference_version->setObjectName(QString::fromUtf8("lEdit_inference_version"));
        lEdit_inference_version->setReadOnly(true);

        gridLayout_14->addWidget(lEdit_inference_version, 1, 1, 1, 1);


        gridLayout_13->addWidget(groupBox_12, 0, 0, 1, 1);

        groupBox_15 = new QGroupBox(layoutWidget5);
        groupBox_15->setObjectName(QString::fromUtf8("groupBox_15"));
        layoutWidget7 = new QWidget(groupBox_15);
        layoutWidget7->setObjectName(QString::fromUtf8("layoutWidget7"));
        layoutWidget7->setGeometry(QRect(42, 22, 341, 341));
        gridLayout_18 = new QGridLayout(layoutWidget7);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        gridLayout_18->setContentsMargins(0, 0, 0, 0);
        label_119 = new QLabel(layoutWidget7);
        label_119->setObjectName(QString::fromUtf8("label_119"));

        gridLayout_18->addWidget(label_119, 0, 0, 1, 1);

        lEdit_h2_th = new QLineEdit(layoutWidget7);
        lEdit_h2_th->setObjectName(QString::fromUtf8("lEdit_h2_th"));
        lEdit_h2_th->setReadOnly(true);

        gridLayout_18->addWidget(lEdit_h2_th, 0, 1, 1, 1);

        label_120 = new QLabel(layoutWidget7);
        label_120->setObjectName(QString::fromUtf8("label_120"));

        gridLayout_18->addWidget(label_120, 1, 0, 1, 1);

        lEdit_co_th = new QLineEdit(layoutWidget7);
        lEdit_co_th->setObjectName(QString::fromUtf8("lEdit_co_th"));
        lEdit_co_th->setReadOnly(true);

        gridLayout_18->addWidget(lEdit_co_th, 1, 1, 1, 1);

        label_121 = new QLabel(layoutWidget7);
        label_121->setObjectName(QString::fromUtf8("label_121"));

        gridLayout_18->addWidget(label_121, 2, 0, 1, 1);

        lEdit_temp_th = new QLineEdit(layoutWidget7);
        lEdit_temp_th->setObjectName(QString::fromUtf8("lEdit_temp_th"));
        lEdit_temp_th->setReadOnly(true);

        gridLayout_18->addWidget(lEdit_temp_th, 2, 1, 1, 1);

        label_122 = new QLabel(layoutWidget7);
        label_122->setObjectName(QString::fromUtf8("label_122"));

        gridLayout_18->addWidget(label_122, 3, 0, 1, 1);

        lEdit_temp_ratio_th = new QLineEdit(layoutWidget7);
        lEdit_temp_ratio_th->setObjectName(QString::fromUtf8("lEdit_temp_ratio_th"));
        lEdit_temp_ratio_th->setReadOnly(true);

        gridLayout_18->addWidget(lEdit_temp_ratio_th, 3, 1, 1, 1);

        label_123 = new QLabel(layoutWidget7);
        label_123->setObjectName(QString::fromUtf8("label_123"));

        gridLayout_18->addWidget(label_123, 4, 0, 1, 1);

        lEdit_voltage_high_th = new QLineEdit(layoutWidget7);
        lEdit_voltage_high_th->setObjectName(QString::fromUtf8("lEdit_voltage_high_th"));
        lEdit_voltage_high_th->setReadOnly(true);

        gridLayout_18->addWidget(lEdit_voltage_high_th, 4, 1, 1, 1);

        label_124 = new QLabel(layoutWidget7);
        label_124->setObjectName(QString::fromUtf8("label_124"));

        gridLayout_18->addWidget(label_124, 5, 0, 1, 1);

        lEdit_voltage_low_th = new QLineEdit(layoutWidget7);
        lEdit_voltage_low_th->setObjectName(QString::fromUtf8("lEdit_voltage_low_th"));
        lEdit_voltage_low_th->setReadOnly(true);

        gridLayout_18->addWidget(lEdit_voltage_low_th, 5, 1, 1, 1);

        label_125 = new QLabel(layoutWidget7);
        label_125->setObjectName(QString::fromUtf8("label_125"));

        gridLayout_18->addWidget(label_125, 6, 0, 1, 1);

        lEdit_discharge_th = new QLineEdit(layoutWidget7);
        lEdit_discharge_th->setObjectName(QString::fromUtf8("lEdit_discharge_th"));
        lEdit_discharge_th->setReadOnly(true);

        gridLayout_18->addWidget(lEdit_discharge_th, 6, 1, 1, 1);

        label_126 = new QLabel(layoutWidget7);
        label_126->setObjectName(QString::fromUtf8("label_126"));

        gridLayout_18->addWidget(label_126, 7, 0, 1, 1);

        lEdit_charge_th = new QLineEdit(layoutWidget7);
        lEdit_charge_th->setObjectName(QString::fromUtf8("lEdit_charge_th"));
        lEdit_charge_th->setReadOnly(true);

        gridLayout_18->addWidget(lEdit_charge_th, 7, 1, 1, 1);


        gridLayout_13->addWidget(groupBox_15, 0, 1, 2, 1);

        groupBox_13 = new QGroupBox(layoutWidget5);
        groupBox_13->setObjectName(QString::fromUtf8("groupBox_13"));
        layoutWidget8 = new QWidget(groupBox_13);
        layoutWidget8->setObjectName(QString::fromUtf8("layoutWidget8"));
        layoutWidget8->setGeometry(QRect(21, 27, 361, 141));
        gridLayout_2 = new QGridLayout(layoutWidget8);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_41 = new QLabel(layoutWidget8);
        label_41->setObjectName(QString::fromUtf8("label_41"));

        gridLayout_2->addWidget(label_41, 0, 0, 1, 2);

        lEdit_device_serial = new QLineEdit(layoutWidget8);
        lEdit_device_serial->setObjectName(QString::fromUtf8("lEdit_device_serial"));
        lEdit_device_serial->setReadOnly(true);

        gridLayout_2->addWidget(lEdit_device_serial, 0, 2, 1, 2);

        label_42 = new QLabel(layoutWidget8);
        label_42->setObjectName(QString::fromUtf8("label_42"));

        gridLayout_2->addWidget(label_42, 1, 0, 1, 2);

        lEdit_mac = new QLineEdit(layoutWidget8);
        lEdit_mac->setObjectName(QString::fromUtf8("lEdit_mac"));
        lEdit_mac->setReadOnly(true);

        gridLayout_2->addWidget(lEdit_mac, 1, 2, 1, 2);

        label_43 = new QLabel(layoutWidget8);
        label_43->setObjectName(QString::fromUtf8("label_43"));

        gridLayout_2->addWidget(label_43, 2, 0, 1, 2);

        lEdit_modbus_addr = new QLineEdit(layoutWidget8);
        lEdit_modbus_addr->setObjectName(QString::fromUtf8("lEdit_modbus_addr"));
        lEdit_modbus_addr->setReadOnly(true);

        gridLayout_2->addWidget(lEdit_modbus_addr, 2, 2, 1, 2);

        label_44 = new QLabel(layoutWidget8);
        label_44->setObjectName(QString::fromUtf8("label_44"));

        gridLayout_2->addWidget(label_44, 3, 0, 1, 2);

        lEdit_capacity = new QLineEdit(layoutWidget8);
        lEdit_capacity->setObjectName(QString::fromUtf8("lEdit_capacity"));
        lEdit_capacity->setReadOnly(true);

        gridLayout_2->addWidget(lEdit_capacity, 3, 2, 1, 2);

        label_127 = new QLabel(layoutWidget8);
        label_127->setObjectName(QString::fromUtf8("label_127"));

        gridLayout_2->addWidget(label_127, 4, 0, 1, 1);

        lEdit_low_power = new QLineEdit(layoutWidget8);
        lEdit_low_power->setObjectName(QString::fromUtf8("lEdit_low_power"));
        lEdit_low_power->setReadOnly(true);

        gridLayout_2->addWidget(lEdit_low_power, 4, 1, 1, 1);

        label_128 = new QLabel(layoutWidget8);
        label_128->setObjectName(QString::fromUtf8("label_128"));

        gridLayout_2->addWidget(label_128, 4, 2, 1, 1);

        lEdit_balance = new QLineEdit(layoutWidget8);
        lEdit_balance->setObjectName(QString::fromUtf8("lEdit_balance"));
        lEdit_balance->setReadOnly(true);

        gridLayout_2->addWidget(lEdit_balance, 4, 3, 1, 1);


        gridLayout_13->addWidget(groupBox_13, 1, 0, 1, 1);

        btn_getInfo = new QPushButton(layoutWidget5);
        btn_getInfo->setObjectName(QString::fromUtf8("btn_getInfo"));

        gridLayout_13->addWidget(btn_getInfo, 2, 0, 1, 2);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        groupBox_14 = new QGroupBox(tab_4);
        groupBox_14->setObjectName(QString::fromUtf8("groupBox_14"));
        groupBox_14->setGeometry(QRect(10, 10, 321, 401));
        layoutWidget9 = new QWidget(groupBox_14);
        layoutWidget9->setObjectName(QString::fromUtf8("layoutWidget9"));
        layoutWidget9->setGeometry(QRect(10, 20, 301, 361));
        gridLayout_17 = new QGridLayout(layoutWidget9);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        gridLayout_17->setContentsMargins(0, 0, 0, 0);
        progressBar = new QProgressBar(layoutWidget9);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        gridLayout_17->addWidget(progressBar, 1, 0, 1, 1);

        textEdit = new QTextEdit(layoutWidget9);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout_17->addWidget(textEdit, 0, 0, 1, 1);

        layoutWidget10 = new QWidget(tab_4);
        layoutWidget10->setObjectName(QString::fromUtf8("layoutWidget10"));
        layoutWidget10->setGeometry(QRect(340, 286, 251, 121));
        gridLayout_16 = new QGridLayout(layoutWidget10);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        gridLayout_16->setContentsMargins(0, 0, 0, 0);
        r_btn_inference = new QRadioButton(layoutWidget10);
        r_btn_inference->setObjectName(QString::fromUtf8("r_btn_inference"));

        gridLayout_16->addWidget(r_btn_inference, 0, 1, 1, 1);

        chooseButton = new QPushButton(layoutWidget10);
        chooseButton->setObjectName(QString::fromUtf8("chooseButton"));

        gridLayout_16->addWidget(chooseButton, 1, 0, 1, 1);

        downloadButton = new QPushButton(layoutWidget10);
        downloadButton->setObjectName(QString::fromUtf8("downloadButton"));

        gridLayout_16->addWidget(downloadButton, 1, 1, 1, 1);

        label_45 = new QLabel(layoutWidget10);
        label_45->setObjectName(QString::fromUtf8("label_45"));

        gridLayout_16->addWidget(label_45, 2, 0, 1, 1);

        comboBox = new QComboBox(layoutWidget10);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout_16->addWidget(comboBox, 2, 1, 1, 1);

        r_btn_collect = new QRadioButton(layoutWidget10);
        r_btn_collect->setObjectName(QString::fromUtf8("r_btn_collect"));

        gridLayout_16->addWidget(r_btn_collect, 0, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        layoutWidget11 = new QWidget(tab_5);
        layoutWidget11->setObjectName(QString::fromUtf8("layoutWidget11"));
        layoutWidget11->setGeometry(QRect(40, 20, 631, 381));
        gridLayout_12 = new QGridLayout(layoutWidget11);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_12->setContentsMargins(0, 0, 0, 0);
        groupBox_2 = new QGroupBox(layoutWidget11);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        layoutWidget12 = new QWidget(groupBox_2);
        layoutWidget12->setObjectName(QString::fromUtf8("layoutWidget12"));
        layoutWidget12->setGeometry(QRect(10, 22, 291, 341));
        gridLayout = new QGridLayout(layoutWidget12);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_33 = new QLabel(layoutWidget12);
        label_33->setObjectName(QString::fromUtf8("label_33"));

        gridLayout->addWidget(label_33, 0, 0, 1, 1);

        lEdit_h2_th_set = new QLineEdit(layoutWidget12);
        lEdit_h2_th_set->setObjectName(QString::fromUtf8("lEdit_h2_th_set"));

        gridLayout->addWidget(lEdit_h2_th_set, 0, 1, 1, 1);

        label_34 = new QLabel(layoutWidget12);
        label_34->setObjectName(QString::fromUtf8("label_34"));

        gridLayout->addWidget(label_34, 1, 0, 1, 1);

        lEdit_co_th_set = new QLineEdit(layoutWidget12);
        lEdit_co_th_set->setObjectName(QString::fromUtf8("lEdit_co_th_set"));

        gridLayout->addWidget(lEdit_co_th_set, 1, 1, 1, 1);

        label_35 = new QLabel(layoutWidget12);
        label_35->setObjectName(QString::fromUtf8("label_35"));

        gridLayout->addWidget(label_35, 2, 0, 1, 1);

        lEdit_temp_th_set = new QLineEdit(layoutWidget12);
        lEdit_temp_th_set->setObjectName(QString::fromUtf8("lEdit_temp_th_set"));

        gridLayout->addWidget(lEdit_temp_th_set, 2, 1, 1, 1);

        label_36 = new QLabel(layoutWidget12);
        label_36->setObjectName(QString::fromUtf8("label_36"));

        gridLayout->addWidget(label_36, 3, 0, 1, 1);

        lEdit_temp_ratio_th_set = new QLineEdit(layoutWidget12);
        lEdit_temp_ratio_th_set->setObjectName(QString::fromUtf8("lEdit_temp_ratio_th_set"));

        gridLayout->addWidget(lEdit_temp_ratio_th_set, 3, 1, 1, 1);

        label_37 = new QLabel(layoutWidget12);
        label_37->setObjectName(QString::fromUtf8("label_37"));

        gridLayout->addWidget(label_37, 4, 0, 1, 1);

        lEdit_voltage_high_th_set = new QLineEdit(layoutWidget12);
        lEdit_voltage_high_th_set->setObjectName(QString::fromUtf8("lEdit_voltage_high_th_set"));

        gridLayout->addWidget(lEdit_voltage_high_th_set, 4, 1, 1, 1);

        label_38 = new QLabel(layoutWidget12);
        label_38->setObjectName(QString::fromUtf8("label_38"));

        gridLayout->addWidget(label_38, 5, 0, 1, 1);

        lEdit_voltage_low_th_set = new QLineEdit(layoutWidget12);
        lEdit_voltage_low_th_set->setObjectName(QString::fromUtf8("lEdit_voltage_low_th_set"));

        gridLayout->addWidget(lEdit_voltage_low_th_set, 5, 1, 1, 1);

        label_39 = new QLabel(layoutWidget12);
        label_39->setObjectName(QString::fromUtf8("label_39"));

        gridLayout->addWidget(label_39, 6, 0, 1, 1);

        lEdit_discharge_th_set = new QLineEdit(layoutWidget12);
        lEdit_discharge_th_set->setObjectName(QString::fromUtf8("lEdit_discharge_th_set"));

        gridLayout->addWidget(lEdit_discharge_th_set, 6, 1, 1, 1);

        label_40 = new QLabel(layoutWidget12);
        label_40->setObjectName(QString::fromUtf8("label_40"));

        gridLayout->addWidget(label_40, 7, 0, 1, 1);

        lEdit_charge_th_set = new QLineEdit(layoutWidget12);
        lEdit_charge_th_set->setObjectName(QString::fromUtf8("lEdit_charge_th_set"));

        gridLayout->addWidget(lEdit_charge_th_set, 7, 1, 1, 1);

        btn_threshold_set = new QPushButton(layoutWidget12);
        btn_threshold_set->setObjectName(QString::fromUtf8("btn_threshold_set"));

        gridLayout->addWidget(btn_threshold_set, 8, 0, 1, 2);


        gridLayout_12->addWidget(groupBox_2, 0, 0, 2, 1);

        groupBox_3 = new QGroupBox(layoutWidget11);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        layoutWidget13 = new QWidget(groupBox_3);
        layoutWidget13->setObjectName(QString::fromUtf8("layoutWidget13"));
        layoutWidget13->setGeometry(QRect(10, 20, 291, 151));
        gridLayout_5 = new QGridLayout(layoutWidget13);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        label_53 = new QLabel(layoutWidget13);
        label_53->setObjectName(QString::fromUtf8("label_53"));

        gridLayout_5->addWidget(label_53, 0, 0, 1, 1);

        lEdit_serial_set = new QLineEdit(layoutWidget13);
        lEdit_serial_set->setObjectName(QString::fromUtf8("lEdit_serial_set"));

        gridLayout_5->addWidget(lEdit_serial_set, 0, 1, 1, 1);

        btn_serial_set = new QPushButton(layoutWidget13);
        btn_serial_set->setObjectName(QString::fromUtf8("btn_serial_set"));

        gridLayout_5->addWidget(btn_serial_set, 0, 2, 1, 1);

        label_54 = new QLabel(layoutWidget13);
        label_54->setObjectName(QString::fromUtf8("label_54"));

        gridLayout_5->addWidget(label_54, 1, 0, 1, 1);

        lEdit_time_set = new QLineEdit(layoutWidget13);
        lEdit_time_set->setObjectName(QString::fromUtf8("lEdit_time_set"));

        gridLayout_5->addWidget(lEdit_time_set, 1, 1, 1, 1);

        btn_time_set = new QPushButton(layoutWidget13);
        btn_time_set->setObjectName(QString::fromUtf8("btn_time_set"));

        gridLayout_5->addWidget(btn_time_set, 1, 2, 1, 1);

        label_55 = new QLabel(layoutWidget13);
        label_55->setObjectName(QString::fromUtf8("label_55"));

        gridLayout_5->addWidget(label_55, 2, 0, 1, 1);

        lEdit_capacity_set = new QLineEdit(layoutWidget13);
        lEdit_capacity_set->setObjectName(QString::fromUtf8("lEdit_capacity_set"));

        gridLayout_5->addWidget(lEdit_capacity_set, 2, 1, 1, 1);

        btn_capacity_set = new QPushButton(layoutWidget13);
        btn_capacity_set->setObjectName(QString::fromUtf8("btn_capacity_set"));

        gridLayout_5->addWidget(btn_capacity_set, 2, 2, 1, 1);

        label_111 = new QLabel(layoutWidget13);
        label_111->setObjectName(QString::fromUtf8("label_111"));

        gridLayout_5->addWidget(label_111, 3, 0, 1, 1);

        lEdit_current_set = new QLineEdit(layoutWidget13);
        lEdit_current_set->setObjectName(QString::fromUtf8("lEdit_current_set"));

        gridLayout_5->addWidget(lEdit_current_set, 3, 1, 1, 1);

        btn_current_set = new QPushButton(layoutWidget13);
        btn_current_set->setObjectName(QString::fromUtf8("btn_current_set"));

        gridLayout_5->addWidget(btn_current_set, 3, 2, 1, 1);


        gridLayout_12->addWidget(groupBox_3, 0, 1, 1, 1);

        groupBox_4 = new QGroupBox(layoutWidget11);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        layoutWidget14 = new QWidget(groupBox_4);
        layoutWidget14->setObjectName(QString::fromUtf8("layoutWidget14"));
        layoutWidget14->setGeometry(QRect(20, 20, 261, 151));
        gridLayout_7 = new QGridLayout(layoutWidget14);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        label_56 = new QLabel(layoutWidget14);
        label_56->setObjectName(QString::fromUtf8("label_56"));

        gridLayout_7->addWidget(label_56, 0, 0, 1, 1);

        btn_serial_set_2 = new QPushButton(layoutWidget14);
        btn_serial_set_2->setObjectName(QString::fromUtf8("btn_serial_set_2"));

        gridLayout_7->addWidget(btn_serial_set_2, 0, 1, 1, 1);

        label_51 = new QLabel(layoutWidget14);
        label_51->setObjectName(QString::fromUtf8("label_51"));

        gridLayout_7->addWidget(label_51, 1, 0, 1, 1);

        btn_low_power = new QPushButton(layoutWidget14);
        btn_low_power->setObjectName(QString::fromUtf8("btn_low_power"));

        gridLayout_7->addWidget(btn_low_power, 1, 1, 1, 1);

        label_52 = new QLabel(layoutWidget14);
        label_52->setObjectName(QString::fromUtf8("label_52"));

        gridLayout_7->addWidget(label_52, 2, 0, 1, 1);

        btn_balanced = new QPushButton(layoutWidget14);
        btn_balanced->setObjectName(QString::fromUtf8("btn_balanced"));

        gridLayout_7->addWidget(btn_balanced, 2, 1, 1, 1);


        gridLayout_12->addWidget(groupBox_4, 1, 1, 1, 1);

        tabWidget->addTab(tab_5, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 30, 281, 381));
        btn_voltage_calib_get = new QPushButton(groupBox);
        btn_voltage_calib_get->setObjectName(QString::fromUtf8("btn_voltage_calib_get"));
        btn_voltage_calib_get->setGeometry(QRect(190, 100, 75, 23));
        layoutWidget15 = new QWidget(groupBox);
        layoutWidget15->setObjectName(QString::fromUtf8("layoutWidget15"));
        layoutWidget15->setGeometry(QRect(10, 40, 237, 50));
        gridLayout_3 = new QGridLayout(layoutWidget15);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_27 = new QLabel(layoutWidget15);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        gridLayout_3->addWidget(label_27, 0, 0, 1, 1);

        lEdit_voltage_range = new QLineEdit(layoutWidget15);
        lEdit_voltage_range->setObjectName(QString::fromUtf8("lEdit_voltage_range"));
        lEdit_voltage_range->setReadOnly(true);

        gridLayout_3->addWidget(lEdit_voltage_range, 0, 1, 1, 1);

        label_26 = new QLabel(layoutWidget15);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        gridLayout_3->addWidget(label_26, 1, 0, 1, 1);

        lEdit_voltage_zero = new QLineEdit(layoutWidget15);
        lEdit_voltage_zero->setObjectName(QString::fromUtf8("lEdit_voltage_zero"));
        lEdit_voltage_zero->setReadOnly(true);

        gridLayout_3->addWidget(lEdit_voltage_zero, 1, 1, 1, 1);

        layoutWidget_3 = new QWidget(groupBox);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(10, 130, 237, 50));
        gridLayout_19 = new QGridLayout(layoutWidget_3);
        gridLayout_19->setObjectName(QString::fromUtf8("gridLayout_19"));
        gridLayout_19->setContentsMargins(0, 0, 0, 0);
        label_59 = new QLabel(layoutWidget_3);
        label_59->setObjectName(QString::fromUtf8("label_59"));

        gridLayout_19->addWidget(label_59, 0, 0, 1, 1);

        lEdit_co_k_calib = new QLineEdit(layoutWidget_3);
        lEdit_co_k_calib->setObjectName(QString::fromUtf8("lEdit_co_k_calib"));
        lEdit_co_k_calib->setReadOnly(true);

        gridLayout_19->addWidget(lEdit_co_k_calib, 0, 1, 1, 1);

        label_60 = new QLabel(layoutWidget_3);
        label_60->setObjectName(QString::fromUtf8("label_60"));

        gridLayout_19->addWidget(label_60, 1, 0, 1, 1);

        lEdit_co_b_calib = new QLineEdit(layoutWidget_3);
        lEdit_co_b_calib->setObjectName(QString::fromUtf8("lEdit_co_b_calib"));
        lEdit_co_b_calib->setReadOnly(true);

        gridLayout_19->addWidget(lEdit_co_b_calib, 1, 1, 1, 1);

        layoutWidget_5 = new QWidget(groupBox);
        layoutWidget_5->setObjectName(QString::fromUtf8("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(10, 220, 237, 50));
        gridLayout_21 = new QGridLayout(layoutWidget_5);
        gridLayout_21->setObjectName(QString::fromUtf8("gridLayout_21"));
        gridLayout_21->setContentsMargins(0, 0, 0, 0);
        label_63 = new QLabel(layoutWidget_5);
        label_63->setObjectName(QString::fromUtf8("label_63"));

        gridLayout_21->addWidget(label_63, 0, 0, 1, 1);

        lEdit_h2_k_calib = new QLineEdit(layoutWidget_5);
        lEdit_h2_k_calib->setObjectName(QString::fromUtf8("lEdit_h2_k_calib"));
        lEdit_h2_k_calib->setReadOnly(true);

        gridLayout_21->addWidget(lEdit_h2_k_calib, 0, 1, 1, 1);

        label_64 = new QLabel(layoutWidget_5);
        label_64->setObjectName(QString::fromUtf8("label_64"));

        gridLayout_21->addWidget(label_64, 1, 0, 1, 1);

        lEdit_h2_b_calib = new QLineEdit(layoutWidget_5);
        lEdit_h2_b_calib->setObjectName(QString::fromUtf8("lEdit_h2_b_calib"));
        lEdit_h2_b_calib->setReadOnly(true);

        gridLayout_21->addWidget(lEdit_h2_b_calib, 1, 1, 1, 1);

        groupBox_5 = new QGroupBox(tab_2);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(380, 40, 341, 101));
        layoutWidget16 = new QWidget(groupBox_5);
        layoutWidget16->setObjectName(QString::fromUtf8("layoutWidget16"));
        layoutWidget16->setGeometry(QRect(10, 30, 318, 52));
        gridLayout_4 = new QGridLayout(layoutWidget16);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_24 = new QLabel(layoutWidget16);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout_4->addWidget(label_24, 0, 0, 1, 1);

        lEdit_voltage_range_calib = new QLineEdit(layoutWidget16);
        lEdit_voltage_range_calib->setObjectName(QString::fromUtf8("lEdit_voltage_range_calib"));

        gridLayout_4->addWidget(lEdit_voltage_range_calib, 0, 1, 1, 1);

        label_25 = new QLabel(layoutWidget16);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        gridLayout_4->addWidget(label_25, 1, 0, 1, 1);

        lEdit_voltage_zero_calib = new QLineEdit(layoutWidget16);
        lEdit_voltage_zero_calib->setObjectName(QString::fromUtf8("lEdit_voltage_zero_calib"));

        gridLayout_4->addWidget(lEdit_voltage_zero_calib, 1, 1, 1, 1);

        btn_voltage_calib_set = new QPushButton(layoutWidget16);
        btn_voltage_calib_set->setObjectName(QString::fromUtf8("btn_voltage_calib_set"));

        gridLayout_4->addWidget(btn_voltage_calib_set, 1, 2, 1, 1);

        groupBox_6 = new QGroupBox(tab_2);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(380, 150, 341, 101));
        layoutWidget_2 = new QWidget(groupBox_6);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 30, 318, 52));
        gridLayout_15 = new QGridLayout(layoutWidget_2);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        gridLayout_15->setContentsMargins(0, 0, 0, 0);
        label_57 = new QLabel(layoutWidget_2);
        label_57->setObjectName(QString::fromUtf8("label_57"));

        gridLayout_15->addWidget(label_57, 0, 0, 1, 1);

        lEdit_co_k_calib_set = new QLineEdit(layoutWidget_2);
        lEdit_co_k_calib_set->setObjectName(QString::fromUtf8("lEdit_co_k_calib_set"));

        gridLayout_15->addWidget(lEdit_co_k_calib_set, 0, 1, 1, 1);

        label_58 = new QLabel(layoutWidget_2);
        label_58->setObjectName(QString::fromUtf8("label_58"));

        gridLayout_15->addWidget(label_58, 1, 0, 1, 1);

        lEdit_co_b_calib_set = new QLineEdit(layoutWidget_2);
        lEdit_co_b_calib_set->setObjectName(QString::fromUtf8("lEdit_co_b_calib_set"));

        gridLayout_15->addWidget(lEdit_co_b_calib_set, 1, 1, 1, 1);

        btn_co_calib_set = new QPushButton(layoutWidget_2);
        btn_co_calib_set->setObjectName(QString::fromUtf8("btn_co_calib_set"));

        gridLayout_15->addWidget(btn_co_calib_set, 1, 2, 1, 1);

        groupBox_7 = new QGroupBox(tab_2);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(380, 270, 341, 101));
        layoutWidget_4 = new QWidget(groupBox_7);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(10, 30, 318, 52));
        gridLayout_20 = new QGridLayout(layoutWidget_4);
        gridLayout_20->setObjectName(QString::fromUtf8("gridLayout_20"));
        gridLayout_20->setContentsMargins(0, 0, 0, 0);
        label_61 = new QLabel(layoutWidget_4);
        label_61->setObjectName(QString::fromUtf8("label_61"));

        gridLayout_20->addWidget(label_61, 0, 0, 1, 1);

        lEdit_h2_k_calib_set = new QLineEdit(layoutWidget_4);
        lEdit_h2_k_calib_set->setObjectName(QString::fromUtf8("lEdit_h2_k_calib_set"));

        gridLayout_20->addWidget(lEdit_h2_k_calib_set, 0, 1, 1, 1);

        label_62 = new QLabel(layoutWidget_4);
        label_62->setObjectName(QString::fromUtf8("label_62"));

        gridLayout_20->addWidget(label_62, 1, 0, 1, 1);

        lEdit_h2_b_calib_set = new QLineEdit(layoutWidget_4);
        lEdit_h2_b_calib_set->setObjectName(QString::fromUtf8("lEdit_h2_b_calib_set"));

        gridLayout_20->addWidget(lEdit_h2_b_calib_set, 1, 1, 1, 1);

        btn_h2_calib_set = new QPushButton(layoutWidget_4);
        btn_h2_calib_set->setObjectName(QString::fromUtf8("btn_h2_calib_set"));

        gridLayout_20->addWidget(btn_h2_calib_set, 1, 2, 1, 1);

        tabWidget->addTab(tab_2, QString());
        cbox_modbus_addr = new QComboBox(centralwidget);
        cbox_modbus_addr->setObjectName(QString::fromUtf8("cbox_modbus_addr"));
        cbox_modbus_addr->setGeometry(QRect(500, 150, 69, 22));
        btn_net_init = new QPushButton(centralwidget);
        btn_net_init->setObjectName(QString::fromUtf8("btn_net_init"));
        btn_net_init->setGeometry(QRect(580, 150, 75, 23));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 884, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        openButton->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        closeButton->setText(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255", nullptr));
        sendButton->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        statusLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        groupBox_8->setTitle(QCoreApplication::translate("MainWindow", "\346\212\245\350\255\246\344\277\241\346\201\257", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\347\201\253\350\255\246", nullptr));
        label_fire->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\254\240\345\216\213\346\212\245\350\255\246", nullptr));
        label_underVoltage->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "\350\277\207\345\216\213\346\212\245\350\255\246", nullptr));
        label_overVoltage->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "\350\277\207\345\205\205\346\212\245\350\255\246", nullptr));
        label_overCharge->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "\350\277\207\346\224\276\346\212\245\350\255\246", nullptr));
        label_overDischarge->setText(QString());
        label_7->setText(QCoreApplication::translate("MainWindow", "\347\203\237\351\233\276\346\212\245\350\255\246", nullptr));
        label_smk->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "H2\346\212\245\350\255\246", nullptr));
        label_h2->setText(QString());
        label_9->setText(QCoreApplication::translate("MainWindow", "CO\346\212\245\350\255\246", nullptr));
        label_co->setText(QString());
        groupBox_9->setTitle(QCoreApplication::translate("MainWindow", "\351\242\204\350\255\246\344\277\241\346\201\257", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "\347\203\255\345\244\261\346\216\247\351\242\204\350\255\246\347\255\211\347\272\247", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "\347\203\255\345\244\261\346\216\247\346\246\202\347\216\207", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "SOC", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "SOH", nullptr));
        groupBox_10->setTitle(QCoreApplication::translate("MainWindow", "\347\224\265\346\261\240\347\212\266\346\200\201\344\277\241\346\201\257", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "\347\224\265\345\216\213", nullptr));
        label_115->setText(QCoreApplication::translate("MainWindow", "V", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\265\201", nullptr));
        label_116->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "\345\206\205\351\230\273", nullptr));
        label_117->setText(QCoreApplication::translate("MainWindow", "m\316\251", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "\345\205\205\346\224\276\347\224\265\350\275\256\346\254\241", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "\345\205\205\346\224\276\347\224\265\347\212\266\346\200\201", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\261\240\346\270\251\345\272\246", nullptr));
        label_118->setText(QCoreApplication::translate("MainWindow", "\342\204\203", nullptr));
        groupBox_11->setTitle(QCoreApplication::translate("MainWindow", "\347\216\257\345\242\203\347\212\266\346\200\201\344\277\241\346\201\257", nullptr));
        label_46->setText(QCoreApplication::translate("MainWindow", "\344\270\200\346\260\247\345\214\226\347\242\263\346\265\223\345\272\246", nullptr));
        label_112->setText(QCoreApplication::translate("MainWindow", "ppm", nullptr));
        label_47->setText(QCoreApplication::translate("MainWindow", "\346\260\242\346\260\224\346\265\223\345\272\246", nullptr));
        label_113->setText(QCoreApplication::translate("MainWindow", "ppm", nullptr));
        label_48->setText(QCoreApplication::translate("MainWindow", "\347\203\237\351\233\276\347\212\266\346\200\201", nullptr));
        label_49->setText(QCoreApplication::translate("MainWindow", "\347\216\257\345\242\203\346\270\251\345\272\246", nullptr));
        label_114->setText(QCoreApplication::translate("MainWindow", "\342\204\203", nullptr));
        label_50->setText(QCoreApplication::translate("MainWindow", "\347\216\257\345\242\203\346\271\277\345\272\246", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\350\256\276\345\244\207\347\212\266\346\200\201", nullptr));
        groupBox_12->setTitle(QCoreApplication::translate("MainWindow", "\350\275\257\344\273\266\344\277\241\346\201\257", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\261\240\344\277\241\346\201\257\351\207\207\351\233\206\350\275\257\344\273\266\350\275\257\344\273\266\347\211\210\346\234\254", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\261\240\345\201\245\345\272\267\346\216\250\347\220\206\350\275\257\344\273\266\350\275\257\344\273\266\347\211\210\346\234\254", nullptr));
        groupBox_15->setTitle(QCoreApplication::translate("MainWindow", "\351\230\210\345\200\274\344\277\241\346\201\257", nullptr));
        label_119->setText(QCoreApplication::translate("MainWindow", "\346\260\242\346\260\224\346\212\245\350\255\246\351\230\210\345\200\274", nullptr));
        label_120->setText(QCoreApplication::translate("MainWindow", "\344\270\200\346\260\247\345\214\226\347\242\263\346\212\245\350\255\246\351\230\210\345\200\274", nullptr));
        label_121->setText(QCoreApplication::translate("MainWindow", "\346\270\251\345\272\246\346\212\245\350\255\246\351\230\210\345\200\274", nullptr));
        label_122->setText(QCoreApplication::translate("MainWindow", "\346\270\251\345\215\207\347\216\207\346\212\245\350\255\246\351\230\210\345\200\274", nullptr));
        label_123->setText(QCoreApplication::translate("MainWindow", "\347\224\265\345\216\213\346\212\245\350\255\246\351\253\230\351\230\210\345\200\274", nullptr));
        label_124->setText(QCoreApplication::translate("MainWindow", "\347\224\265\345\216\213\346\212\245\350\255\246\344\275\216\351\230\210\345\200\274", nullptr));
        label_125->setText(QCoreApplication::translate("MainWindow", "\346\224\276\347\224\265\347\224\265\346\265\201\346\212\245\350\255\246\351\230\210\345\200\274", nullptr));
        label_126->setText(QCoreApplication::translate("MainWindow", "\345\205\205\347\224\265\347\224\265\346\265\201\346\212\245\350\255\246\351\230\210\345\200\274", nullptr));
        groupBox_13->setTitle(QCoreApplication::translate("MainWindow", "\350\256\276\345\244\207\344\277\241\346\201\257", nullptr));
        label_41->setText(QCoreApplication::translate("MainWindow", "\345\272\217\345\210\227\345\217\267", nullptr));
        label_42->setText(QCoreApplication::translate("MainWindow", "\350\256\276\345\244\207MAC\345\234\260\345\235\200", nullptr));
        label_43->setText(QCoreApplication::translate("MainWindow", "\350\256\276\345\244\207Modbus\345\234\260\345\235\200", nullptr));
        label_44->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\261\240\351\242\235\345\256\232\345\256\271\351\207\217", nullptr));
        label_127->setText(QCoreApplication::translate("MainWindow", "\344\275\216\345\212\237\350\200\227\347\212\266\346\200\201", nullptr));
        label_128->setText(QCoreApplication::translate("MainWindow", "\345\235\207\350\241\241\347\212\266\346\200\201", nullptr));
        btn_getInfo->setText(QCoreApplication::translate("MainWindow", "\350\216\267\345\217\226", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "\350\256\276\345\244\207\344\277\241\346\201\257", nullptr));
        groupBox_14->setTitle(QCoreApplication::translate("MainWindow", "\344\270\213\350\275\275\350\277\207\347\250\213\344\277\241\346\201\257\347\212\266\346\200\201", nullptr));
        r_btn_inference->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\261\240\345\201\245\345\272\267\346\216\250\347\220\206\350\275\257\344\273\266", nullptr));
        chooseButton->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        downloadButton->setText(QCoreApplication::translate("MainWindow", "\344\270\213\350\275\275", nullptr));
        label_45->setText(QCoreApplication::translate("MainWindow", "\350\275\257\344\273\266\345\215\207\347\272\247\346\240\207\345\277\227", nullptr));
        r_btn_collect->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\261\240\344\277\241\346\201\257\351\207\207\351\233\206\350\275\257\344\273\266", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "\350\275\257\344\273\266\345\215\207\347\272\247", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\351\230\210\345\200\274\350\256\276\347\275\256", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "\346\260\242\346\260\224\346\212\245\350\255\246\351\230\210\345\200\274", nullptr));
        label_34->setText(QCoreApplication::translate("MainWindow", "\344\270\200\346\260\247\345\214\226\347\242\263\346\212\245\350\255\246\351\230\210\345\200\274", nullptr));
        label_35->setText(QCoreApplication::translate("MainWindow", "\346\270\251\345\272\246\346\212\245\350\255\246\351\230\210\345\200\274", nullptr));
        label_36->setText(QCoreApplication::translate("MainWindow", "\346\270\251\345\215\207\347\216\207\346\212\245\350\255\246\351\230\210\345\200\274", nullptr));
        label_37->setText(QCoreApplication::translate("MainWindow", "\347\224\265\345\216\213\346\212\245\350\255\246\351\253\230\351\230\210\345\200\274", nullptr));
        label_38->setText(QCoreApplication::translate("MainWindow", "\347\224\265\345\216\213\346\212\245\350\255\246\344\275\216\351\230\210\345\200\274", nullptr));
        label_39->setText(QCoreApplication::translate("MainWindow", "\346\224\276\347\224\265\347\224\265\346\265\201\346\212\245\350\255\246\351\230\210\345\200\274", nullptr));
        label_40->setText(QCoreApplication::translate("MainWindow", "\345\205\205\347\224\265\347\224\265\346\265\201\346\212\245\350\255\246\351\230\210\345\200\274", nullptr));
        btn_threshold_set->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\344\277\241\346\201\257\350\256\276\347\275\256", nullptr));
        label_53->setText(QCoreApplication::translate("MainWindow", "\350\256\276\345\244\207\345\272\217\345\210\227\345\217\267", nullptr));
        btn_serial_set->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        label_54->setText(QCoreApplication::translate("MainWindow", "\346\216\210\346\227\266", nullptr));
        btn_time_set->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        label_55->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\261\240\351\242\235\345\256\232\345\256\271\351\207\217", nullptr));
        btn_capacity_set->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        label_111->setText(QCoreApplication::translate("MainWindow", "\345\205\205\346\224\276\347\224\265\347\224\265\346\265\201", nullptr));
        btn_current_set->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "\347\212\266\346\200\201\350\256\276\347\275\256", nullptr));
        label_56->setText(QCoreApplication::translate("MainWindow", "\350\275\257\344\273\266\345\244\215\344\275\215", nullptr));
        btn_serial_set_2->setText(QCoreApplication::translate("MainWindow", "\345\244\215\344\275\215", nullptr));
        label_51->setText(QCoreApplication::translate("MainWindow", "\344\275\216\345\212\237\350\200\227", nullptr));
        btn_low_power->setText(QCoreApplication::translate("MainWindow", "\345\220\257\347\224\250", nullptr));
        label_52->setText(QCoreApplication::translate("MainWindow", "\345\235\207\350\241\241", nullptr));
        btn_balanced->setText(QCoreApplication::translate("MainWindow", "\345\220\257\347\224\250", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\346\240\241\345\207\206\347\263\273\346\225\260", nullptr));
        btn_voltage_calib_get->setText(QCoreApplication::translate("MainWindow", "\350\216\267\345\217\226", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "\347\224\265\345\216\213\351\207\217\347\250\213\346\240\241\345\207\206\347\263\273\346\225\260", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "\347\224\265\345\216\213\351\233\266\347\202\271\346\240\241\345\207\206\347\263\273\346\225\260", nullptr));
        label_59->setText(QCoreApplication::translate("MainWindow", "CO\346\240\241\345\207\206\347\263\273\346\225\260 k", nullptr));
        label_60->setText(QCoreApplication::translate("MainWindow", "CO\346\240\241\345\207\206\347\263\273\346\225\260 b", nullptr));
        label_63->setText(QCoreApplication::translate("MainWindow", "H2\346\240\241\345\207\206\347\263\273\346\225\260 k", nullptr));
        label_64->setText(QCoreApplication::translate("MainWindow", "H2\346\240\241\345\207\206\347\263\273\346\225\260 b", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "\347\224\265\345\216\213\346\240\241\345\207\206\347\263\273\346\225\260", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "\347\224\265\345\216\213\351\207\217\347\250\213\346\240\241\345\207\206\347\263\273\346\225\260", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "\347\224\265\345\216\213\351\233\266\347\202\271\346\240\241\345\207\206\347\263\273\346\225\260", nullptr));
        btn_voltage_calib_set->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "CO\346\240\241\345\207\206\347\263\273\346\225\260", nullptr));
        label_57->setText(QCoreApplication::translate("MainWindow", "CO\346\240\241\345\207\206\347\263\273\346\225\260 k", nullptr));
        label_58->setText(QCoreApplication::translate("MainWindow", "CO\346\240\241\345\207\206\347\263\273\346\225\260 b", nullptr));
        btn_co_calib_set->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("MainWindow", "H2\346\240\241\345\207\206\347\263\273\346\225\260", nullptr));
        label_61->setText(QCoreApplication::translate("MainWindow", "H2\346\240\241\345\207\206\347\263\273\346\225\260 k", nullptr));
        label_62->setText(QCoreApplication::translate("MainWindow", "H2\346\240\241\345\207\206\347\263\273\346\225\260 b", nullptr));
        btn_h2_calib_set->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\346\240\241\345\207\206", nullptr));
        btn_net_init->setText(QCoreApplication::translate("MainWindow", "\350\256\276\345\244\207\350\216\267\345\217\226", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
