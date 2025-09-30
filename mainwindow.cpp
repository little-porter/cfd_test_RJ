#include "mainwindow.h"
#include "./ui_mainwindow.h"


#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QTimer>
#include <QEventLoop>

void modbus_generate_crcTable(void);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , serialPort(new QSerialPort(this))
{
    ui->setupUi(this);
    populatePorts();
    modbus_generate_crcTable();
    myserial = nullptr;
    m_run_process = RUN_PROCESS_INIT;
    m_run_event = 0;
    m_param_event = 0;
    m_get_param_event = 0;
    m_balance_flag = 0;
    autoOpenFlag = false;

    setWindowFlags(Qt::Window | Qt::WindowTitleHint |
                   Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);

    ui->progressBar->setValue(0); // 初始化进度条为0

    connect(serialPort, &QSerialPort::readyRead, this, &MainWindow::readSerialData);

    // connect(ui->portComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::populatePorts);

    connect(ui->chooseButton, &QPushButton::clicked, this, &MainWindow::onChooseFile);
    connect(ui->openButton, &QPushButton::clicked, this, &MainWindow::onOpenSerialPort);
    connect(ui->closeButton, &QPushButton::clicked, this, &MainWindow::onCloseSerialPort);
    // connect(ui->downloadButton, &QPushButton::clicked, this, &MainWindow::onSendData);

    connect(ui->btn_getInfo, &QPushButton::clicked, this, &MainWindow::on_btn_getInfo_clicked);

    m_comm_timer = new QTimer(this);
    m_comm_timer->setInterval(100);
    connect(m_comm_timer, &QTimer::timeout, this, &MainWindow::comm_timer_run_task);
    m_comm_timer->start();
}



MainWindow::~MainWindow()
{
    if(serialPort->isOpen()){
        serialPort->close();
    }
    delete ui;
}


void delay(int millisecondsToWait) {
    QEventLoop loop;
    QTimer::singleShot(millisecondsToWait, &loop, SLOT(quit()));
    loop.exec();
}

#define POLYNOMIAL 0xA001
uint16_t crcTable[256];

/*生成CRC-16表*/
void modbus_generate_crcTable(void) {
    uint16_t polynomial = POLYNOMIAL;
    for (int i = 0; i < 256; i++)
    {
        uint16_t crc = 0;
        uint16_t c = (uint16_t)i;
        for (int j = 0; j < 8; j++)
        {
            if (((crc ^ c) & 0x0001) != 0)
                crc = (crc >> 1) ^ polynomial;
            else
                crc >>= 1;
            c >>= 1;
        }
        crcTable[i] = crc;
    }
}

/*计算CRC*/
uint16_t modbus_calculate_crc(uint8_t *data,uint16_t length)
{
    uint16_t crc = 0xFFFF;

    for(uint16_t i = 0; i < length; i++){
        uint16_t index = (crc ^ data[i]) & 0xFF;
        crc = (crc >> 8) ^ crcTable[index];
    }

    return crc;
}



void MainWindow::onChooseFile()
{
    selectedFilePath = QFileDialog::getOpenFileName(this, tr("选择文件"), "", tr("所有文件 (*)"));
    if (!selectedFilePath.isEmpty()) {
        ui->textEdit->setPlainText(selectedFilePath);
    }

    if(ui->r_btn_collect->isChecked()){
        app_flag = APP_FLAG_COLLECT;
    }else if(ui->r_btn_inference->isChecked()){
        app_flag = APP_FLAG_INFERENCE;
    }else{;}

    QFile file(selectedFilePath);
    if (file.open(QIODevice::ReadOnly)) {
        QByteArray fileData = file.readAll();
        uint16_t size = (uint16_t)fileData.size();
        file_crc = modbus_calculate_crc((uint8_t *)fileData.constData(),size); // 计算 CRC
        file.close();

        // 显示 CRC
        ui->textEdit->append(tr("文件 CRC16: 0x%1").arg(file_crc, 4, 16, QChar('0')));
    } else {
        QMessageBox::warning(this, "错误", "无法读取文件以计算 CRC");
    }
}


void MainWindow::populatePorts()
{
    ui->portComboBox->clear();
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        ui->portComboBox->addItem(info.portName());
    }
}

void MainWindow::onOpenSerialPort()
{
    // QString portName = ui->portComboBox->currentText();
    // qint32 baudRate = 115200;

    // serialPort->setPortName(portName);
    // serialPort->setBaudRate(baudRate);
    // serialPort->setDataBits(QSerialPort::Data8);
    // serialPort->setParity(QSerialPort::NoParity);
    // serialPort->setStopBits(QSerialPort::OneStop);
    // serialPort->setFlowControl(QSerialPort::NoFlowControl);

    // if (serialPort->open(QIODevice::ReadWrite)) {
    //     ui->statusLabel->setText("串口已打开");
    // } else {
    //     ui->statusLabel->setText("串口打开失败");
    // }

    if(myserial == nullptr){
        QString portName = ui->portComboBox->currentText();
        myserial = new myserialport(portName);
    }else{
        qDebug()<<"串口以打开";
    }

}

void MainWindow::onCloseSerialPort()
{
    if (serialPort->isOpen()) {
        serialPort->close();
        ui->statusLabel->setText("串口已关闭");
    }

    delete myserial;
    myserial = nullptr;
}

alignas(1) typedef struct _ota_msg
{
    quint8 dev_addr;
    quint8 cmd;
    quint8 dev_type;
    quint8 frm_flag;
    quint16 frm_num;
    quint16 data_len;
    quint8 payload[0];
}oat_msg_t;


quint16 calculate_crc(quint8 *data,quint16 len)
{
    quint16 crc = 0;

    return crc;
}


bool  MainWindow::upgrade_start(const char *data,quint16 len,quint16 frm_num,ota_upgrade_flag_t flag)
{
    quint16 size = sizeof(oat_msg_t)+len+2;
    oat_msg_t *msg = (oat_msg_t *)calloc(1,sizeof(oat_msg_t)+len+2);
    quint16 crc = 0;

    msg->dev_addr = 0xff;
    msg->cmd= 0xff;
    if(app_flag == APP_FLAG_COLLECT){
        msg->dev_type = 0x02;
    }else{
         msg->dev_type = 0x01;
    }
    if(flag == OTA_UPGRADE_START){
        msg->frm_flag = 0x00;
    }else if(flag == OTA_UPGRADE_STOP){
        msg->frm_flag = 0x11;
    }else{
        msg->frm_flag = 0x10;
    }
    msg->frm_num =  frm_num>>8 | ((frm_num&0xFF)<<8); //frm_num;
    msg->data_len =  len;        //len>>8 | ((len&0xFF)<<8);
    memcpy(msg->payload,data,len);

    crc = modbus_calculate_crc((uint8_t *)msg,size - 2);
    msg->payload[len] = crc&0xff;
    msg->payload[len+1] = crc>>8;

    // qint64 bytesWritten = serialPort->write((const char *)msg,size);
    myserial->myserialport_sendData((quint8 *)msg,size);

    // serialPort->flush();
    // if (bytesWritten != size) {
    //     return false;
    // }
    return true;
}


void reverse_bytes(quint8 *data,quint8 num)
{
    quint8 temp;
    // num = (num/2)*2;

    for(qint8 i=0;i<num/2;i++){
        temp = data[num - i -1];
        data[num - i -1] = data[i];
        data[i] = temp;
    }

}


void MainWindow::upgrade_handler()
{
    if (selectedFilePath.isEmpty()) {
        QMessageBox::warning(this, "错误", "请先选择一个文件");
        return;
    }

    QFile file(selectedFilePath);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "错误", "无法打开文件");
        return;
    }

    qint64 fileSize = file.size();
    ui->progressBar->setMaximum(fileSize); // 设置进度条的最大值为文件大小
    ui->progressBar->setValue(0); // 初始化进度条为0
    qint64 totalBytesSent = 0;
    quint16 frm_num = 0;
    ota_upgrade_flag_t flag = OTA_UPGRADE_START;
    sendTimer.start();
    flag = OTA_UPGRADE_START;
    uint32_t bin_len = (uint32_t)fileSize;
    // reverse_bytes((quint8 *)&bin_len,sizeof(uint32_t));
    upgrade_start((const char *)&bin_len,sizeof(uint32_t),frm_num++,flag);
    delay(200);
    flag = OTA_UPGRADING;
    while (!file.atEnd()) {
        QByteArray data = file.read(maxPacketSize);

        if (!upgrade_start(data.constData(),data.size(),frm_num++,flag)) {
            QMessageBox::warning(this, "错误", "发送失败");
            break;
        }
        totalBytesSent += data.size();
        ui->textEdit->append(tr("已发送 %1 字节").arg(totalBytesSent));
        ui->progressBar->setValue(totalBytesSent); // 更新进度条
        delay(200);
    }

    /*发送结束帧*/
    flag =  OTA_UPGRADE_STOP;
    quint16 crc = file_crc;
    // reverse_bytes((quint8 *)&crc,sizeof(quint16));
    upgrade_start((const char *)&crc,sizeof(crc),0,flag);

    file.close();
    qint64 elapsedMs = sendTimer.elapsed(); // 获取经过的毫秒数
    double elapsedSec = elapsedMs / 1000.0;


    ui->textEdit->append(tr("\n发送完成，共发送 %1 字节").arg(totalBytesSent));
    ui->textEdit->append(tr("耗时: %1 秒").arg(elapsedSec, 0, 'f', 3)); // 保留两位小数
}

void MainWindow::readSerialData()
{
    QByteArray data = serialPort->readAll();
    QString received = QString::fromUtf8(data);
    // ui->receiveTextEdit->insertPlainText(received);
}

bool MainWindow::sendChunk(const QByteArray &data)
{
    qint64 bytesWritten = serialPort->write(data);
    serialPort->flush();
    if (bytesWritten != data.size()) {
        return false;
    }
    return true;
}


void MainWindow::on_btn_getInfo_clicked()
{
    m_run_event |= PROJECT_EVENT_GET_INFO_BIT;
}


void MainWindow::on_btn_net_init_clicked()
{
    m_run_event |= PROJECT_EVENT_INIT_BIT;
}


void MainWindow::on_downloadButton_clicked()
{
    m_run_event |= PROJECT_EVENT_UPGRADE_BIT;
}

void MainWindow::project_event_handler(void)
{
    if(m_run_event&PROJECT_EVENT_INIT_BIT){
        m_run_process = RUN_PROCESS_INIT;
        m_run_event &= (~PROJECT_EVENT_INIT_BIT);
    }else if(m_run_event&PROJECT_EVENT_GET_INFO_BIT){
        m_run_process = RUN_PROCESS_GET_INFO;
        m_run_event &= (~PROJECT_EVENT_GET_INFO_BIT);
    }else if(m_run_event&PROJECT_EVENT_UPGRADE_BIT){
        m_run_process = RUN_PROCESS_UPGRADE;
        m_run_event &= (~PROJECT_EVENT_UPGRADE_BIT);
    }else if(m_run_event&PROJECT_EVENT_SET_PRAMA_BIT){
        m_run_process = RUN_PROCESS_SET_PARAM;
        m_run_event &= (~PROJECT_EVENT_SET_PRAMA_BIT);
    }else if(m_run_event&PROJECT_EVENT_GET_PRAMA_BIT){
        m_run_process = RUN_PROCESS_GET_PARAM;
        m_run_event &= (~PROJECT_EVENT_GET_PRAMA_BIT);
    }
    else{
        // m_run_process = RUN_PROCESS_GET_DATA;
    }
}

void MainWindow::run_process_init_handler(void)
{
    quint8 cmd = 0x03,data[8] = {0x00,cmd,0x00,0x00,0x00,0x01,0x00,0x00};
    quint16 crc = 0;
    quint8  read_data[100] = {0};
    while(myserial->myserialport_receiveData(read_data,sizeof(read_data)));

    if(!modbusAddrList.empty()){
        modbusAddrList.clear();
    }

    for(quint8 i = 0; i<100; i++){
        data[0] = i;
        crc = modbus_calculate_crc(data,6);
        data[6] = crc&0xff;
        data[7] = crc>>8;
        myserial->myserialport_sendData(data,sizeof(data));
        delay(30);
        quint16 read_bytes = myserial->myserialport_receiveData(read_data,sizeof(read_data));
        if(read_bytes > 0){
            if(read_data[0] == i && read_data[1] == cmd && (read_data[2]<<8|read_data[3]) == 0x02){
                // modbusAddrList.push_back(read_data[4]<<8|read_data[5]);
                 modbusAddrList.push_back(i);
                // modbusAddrList.push_back(i);
            }else{
                qDebug()<<"设备"<<QString::number(i)<<"数据格式错误";
            }
        }else{
            qDebug()<<"设备"<<QString::number(i)<<"未应答";
        }
    }

    for (auto it = modbusAddrList.begin(); it != modbusAddrList.end(); ++it){
        ui->cbox_modbus_addr->addItem(QString::number(*it));
    }
    ui->cbox_modbus_addr->setCurrentIndex(0);
}

quint8 MainWindow::device_id_get(void)
{
    bool ok = false;
    QString str_id = ui->cbox_modbus_addr->currentText();
    quint8 id = (quint8)str_id.toUInt(&ok,10);
    if(!ok){
        id = 0;
        qDebug()<<"地址转换失败,返回默认地址0";
    }else{;}
    return id;
}

bool MainWindow::device_reg_data_read(quint16 reg_addr,quint16 reg_num,quint8 cmd,quint8 id)
{
    bool ret = true;
    quint8 data[8] = {0};
    quint16 crc;
    data[0] = id;
    data[1] = cmd;
    data[2] = reg_addr>>8;
    data[3] = reg_addr&0xff;
    data[4] = reg_num>>8;
    data[5] = reg_num&0xff;
    crc = modbus_calculate_crc(data,6);
    data[6] = crc&0xff;
    data[7] = crc>>8;

    myserial->myserialport_sendData(data,sizeof(data));
    return ret;
}

bool MainWindow::device_reg_data_write(quint16 reg_addr,quint16 reg_num,quint8 cmd,quint8 *payload)
{
    bool ret;
    quint16 size = 8 + reg_num*2;
    quint8 *data = (quint8 *)calloc(1,size);
    quint16 crc = 0;
    if(!(data[0] = device_id_get())){
        free(data);
        return ret;
    }else{;}
    data[1] = cmd;
    data[2] = reg_addr>>8;
    data[3] = reg_addr&0xff;
    data[4] = reg_num>>8;
    data[5] = reg_num&0xff;
    memcpy(&data[6],payload,reg_num*2);
    crc = modbus_calculate_crc(data,size-2);
    data[size-2] = crc&0xff;
    data[size-1] = crc>>8;

    myserial->myserialport_sendData(data,size);
    free(data);
    ret = true;
    return ret;
}

/*****************************************************************************
 * 获取设备信息，软件版本，阈值信息
 *
 * ***************************************************************************/
void MainWindow::device_config_info_get(void)
{
    quint8  cmd = 0x03,id = 0x00;
    quint16 read_reg_addr = 0x0000,read_reg_num = 0x1E;
    quint16 read_bytes = 0;
    quint8  read_data[100] = {0};
    while(myserial->myserialport_receiveData(read_data,sizeof(read_data)));

    if(!(id = device_id_get())){
        qDebug()<<"[device read config info] cmd not send!";
        return;
    }else{;}

    qDebug()<<"[device read config info]"<<"reg_addr = "<<Qt::hex<<read_reg_addr<<"reg_num = "<<read_reg_num;
    device_reg_data_read(read_reg_addr,read_reg_num,cmd,id);

    delay(200);

    read_bytes = myserial->myserialport_receiveData(read_data,sizeof(read_data));
    if(read_bytes > 0){
        if(read_data[0] == id && read_data[1] == cmd && (read_data[2]<<8|read_data[3]) == read_reg_num*2){
            ui->lEdit_modbus_addr->setText(QString::number(read_data[0+4]<<8|read_data[1+4]));
            ui->lEdit_capacity->setText(QString::number(read_data[6+4]<<8|read_data[7+4]));
            ui->lEdit_balance->setText(QString::number(read_data[12+4]<<8|read_data[13+4]));
            ui->lEdit_device_serial->setText(QString::fromUtf8((char *)&read_data[14+4]));
            ui->lEdit_h2_th->setText(QString::number(read_data[34+4]<<8|read_data[35+4]));
            ui->lEdit_co_th->setText(QString::number(read_data[36+4]<<8|read_data[37+4]));
            ui->lEdit_temp_th->setText(QString::number(read_data[38+4]<<8|read_data[39+4]));
            ui->lEdit_temp_ratio_th->setText(QString::number(read_data[40+4]<<8|read_data[41+4]));
            ui->lEdit_voltage_high_th->setText(QString::number(read_data[42+4]<<8|read_data[43+4]));
            ui->lEdit_voltage_low_th->setText(QString::number(read_data[44+4]<<8|read_data[45+4]));
            ui->lEdit_discharge_th->setText(QString::number(read_data[46+4]<<8|read_data[47+4]));
            ui->lEdit_charge_th->setText(QString::number(read_data[48+4]<<8|read_data[49+4]));
        }else{
            qDebug()<<"config info msg check error!";
        }
    }else{
        qDebug()<<"device not respond!";
    }
}

void MainWindow::device_version_mac_info_get(void)
{
    quint8  cmd = 0x03,id = 0x00;
    quint16 read_reg_addr = 0x3000,read_reg_num = 0x0015;
    quint16 read_bytes = 0;
    quint8  read_data[100] = {0};
    while(myserial->myserialport_receiveData(read_data,sizeof(read_data)));

    if(!(id = device_id_get())){
        qDebug()<<"[device read version mac info] cmd not send!";
        return;
    }else{;}

    qDebug()<<"[device read version mac info]"<<"reg_addr = "<<Qt::hex<<read_reg_addr<<"reg_num = "<<read_reg_num;
    device_reg_data_read(read_reg_addr,read_reg_num,cmd,id);

    delay(200);
    read_bytes = myserial->myserialport_receiveData(read_data,sizeof(read_data));
    if(read_bytes > 0){
        if(read_data[0] == id && read_data[1] == cmd && (read_data[2]<<8|read_data[3]) == read_reg_num*2){
            ui->lEdit_collect_version->setText(QString::number(read_data[4]<<8|read_data[5])+"-"
                                               +QString::number(read_data[6]<<8|read_data[7])+"-"
                                               +QString::number(read_data[8]<<8|read_data[9])+" "
                                               +QString::number(read_data[10]<<8|read_data[11])+"."
                                               +QString::number(read_data[12]<<8|read_data[13])+"."
                                               +QString::number(read_data[14]<<8|read_data[15]));
            ui->lEdit_inference_version->setText(QString::number(read_data[16]<<8|read_data[17])+"-"
                                                 +QString::number(read_data[18]<<8|read_data[19])+"-"
                                                 +QString::number(read_data[20]<<8|read_data[21])+" "
                                                 +QString::number(read_data[22]<<8|read_data[23])+"."
                                                 +QString::number(read_data[24]<<8|read_data[25])+"."
                                                 +QString::number(read_data[26]<<8|read_data[27]));
            ui->lEdit_mac->setText(QString::fromUtf8((char *)&read_data[24+4]));
        }else{
            qDebug()<<"version mac info msg check error!";
        }
    }else{
        qDebug()<<"device not respond!";
    }
}

void MainWindow::run_process_get_info_handler(void)
{
    device_config_info_get();
    device_version_mac_info_get();
}

void set_led_on(QLabel *label)
{
    label->setStyleSheet(
        "QLabel {"
        "  background-color: red;"
        "  border-radius: 15px;" // 半径是宽度/高度的一半
        "}"
        );
}

void set_led_off(QLabel *label)
{
    label->setStyleSheet(
        "QLabel {"
        "  background-color: green;"
        "  border-radius: 15px;" // 半径是宽度/高度的一半
        "}"
        );
}


void MainWindow::run_process_get_result_handler(void)
{
    quint8  cmd = 0x03,id = 0x00;
    quint16 read_reg_addr = 0x2000,read_reg_num = 0x0F;
    quint16 read_bytes = 0;
    quint8  read_data[100] = {0};

    while(myserial->myserialport_receiveData(read_data,sizeof(read_data)));

    if(!(id = device_id_get())){
        qDebug()<<"[device read result info] cmd not send!";
        return;
    }else{;}


    qDebug()<<"[device read result info]"<<"reg_addr = "<<Qt::hex<<read_reg_addr<<"reg_num = "<<read_reg_num;
    device_reg_data_read(read_reg_addr,read_reg_num,cmd,id);

    delay(100);

    read_bytes = myserial->myserialport_receiveData(read_data,sizeof(read_data));
    if(read_bytes > 0){
        if(read_data[0] == id && read_data[1] == cmd && (read_data[2]<<8|read_data[3]) == read_reg_num*2){
            if((read_data[30]<<8|read_data[31]) == 0){
                ui->lEdit_rsk_level->setText("无预警信息");
            }else if((read_data[30]<<8|read_data[31]) == 1){
                ui->lEdit_rsk_level->setText("一级预警");
            }else if((read_data[30]<<8|read_data[31]) == 2){
                ui->lEdit_rsk_level->setText("二级预警");
            }else if((read_data[30]<<8|read_data[31]) == 3){
                ui->lEdit_rsk_level->setText("三级预警");
            }else if((read_data[30]<<8|read_data[31]) == 4){
                ui->lEdit_rsk_level->setText("四级预警");
            }else{
                ui->lEdit_rsk_level->setText("");
            }

            ui->lEdit_soc->setText(QString::number((read_data[4]<<8|read_data[5])*1.0/100));
            ui->lEdit_soh->setText(QString::number((read_data[10]<<8|read_data[11])*1.0/100));
            ui->lEdit_rsk_ratio->setText(QString::number((read_data[20]<<8|read_data[21])*1.0/100));

            if((read_data[32]<<8|read_data[33]) == 0x01){       //火警
                set_led_on(ui->label_fire);
            }else{
                set_led_off(ui->label_fire);
            }

            if((read_data[28]<<8|read_data[29])&0x01){          //欠压
                set_led_on(ui->label_underVoltage);
            }else{
                set_led_off(ui->label_underVoltage);
            }
            if((read_data[28]<<8|read_data[29])&0x02){          //过压
                set_led_on(ui->label_overVoltage);
            }else{
                set_led_off(ui->label_overVoltage);
            }
            if((read_data[28]<<8|read_data[29])&0x04){          //过充
                set_led_on(ui->label_overCharge);
            }else{
                set_led_off(ui->label_overCharge);
            }
            if((read_data[28]<<8|read_data[29])&0x08){          //过放
                set_led_on(ui->label_overDischarge);
            }else{
                set_led_off(ui->label_overDischarge);
            }
            if((read_data[28]<<8|read_data[29])&0x10){          //过温
                set_led_on(ui->label_overTemp);
            }else{
                set_led_off(ui->label_overTemp);
            }
            if((read_data[28]<<8|read_data[29])&0x20){          //烟雾
                set_led_on(ui->label_smk);
            }else{
                set_led_off(ui->label_smk);
            }
            if((read_data[28]<<8|read_data[29])&0x40){          //H2
                set_led_on(ui->label_h2);
            }else{
                set_led_off(ui->label_h2);
            }

            if((read_data[28]<<8|read_data[29])&0x80){          //CO
                set_led_on(ui->label_co);
            }else{
                set_led_off(ui->label_co);
            }

        }else{
            qDebug()<<"result info msg check error!";
        }
    }else{
        qDebug()<<"device not respond!";
    }
}



void MainWindow::run_process_get_data_handler(void)
{
    quint8  cmd = 0x03,id = 0x00;
    quint16 read_reg_addr = 0x1000,read_reg_num = 0x14,crc = 0;
    quint16 read_bytes = 0;
    quint8  read_data[100] = {0};

    while(myserial->myserialport_receiveData(read_data,sizeof(read_data)));

    if(!(id = device_id_get())){
        qDebug()<<"[device read data info] cmd not send!";
        return;
    }else{;}

    device_reg_data_read(read_reg_addr,read_reg_num,cmd,id);
    qDebug()<<"[device read data info]"<<"reg_addr = "<<Qt::hex<<read_reg_addr<<"reg_num = "<<read_reg_num;

    delay(100);

    read_bytes = myserial->myserialport_receiveData(read_data,sizeof(read_data));
    if(read_bytes > 0){
        if(read_data[0] == id && read_data[1] == cmd && (read_data[2]<<8|read_data[3]) == read_reg_num*2){
            // quint16 u_current = read_data[4]<<8|read_data[5];
            // qint16 data[19] = {0};
            // float  fdata[19] = {0};
            // quint8 *pdata = (quint8 *)data;
            // memcpy(data,&read_data[4],38);
            // for(int i=0; i<19;i++){
            //     quint8 temp = 0;
            //     temp = pdata[2*i];
            //     pdata[2*i] = pdata[2*i+1];
            //     pdata[2*i+1] = temp;
            // }

            // QList<QLineEdit *> lineEdit = { ui->lEdit_current,ui->lEdit_cycle,ui->lEdit_cfdzt,ui->lEdit_voltage,ui->lEdit_res,
            //                                 ui->lEdit_battery_temperature,ui->lEdit_CO,ui->lEdit_H2,ui->lEdit_SMK,ui->lEdit_env_temperature,
            //                                 ui->lEdit_humidity,ui->lEdit_heart,
            //                                 ui->lEdit_voltage_real,ui->lEdit_res_real,ui->lEdit_battery_temperature_real,ui->lEdit_CO_real,ui->lEdit_H2_real,
            //                                ui->lEdit_SMK_real,ui->lEdit_env_temperature_real};


            qint16 current = 0;
            memcpy(&current,&read_data[4],2);
            // current = (current>>8)|((current&0xFF)<<8);
            // memcpy(&current,&u_current,2);

            ui->lEdit_current->setText(QString::number((current)*1.0/1000));
            ui->lEdit_cycle->setText(QString::number(read_data[6]<<8|read_data[7]));
            ui->lEdit_cfdzt->setText(QString::number(read_data[8]<<8|read_data[9]));

            quint16 u_voltage = read_data[10]<<8|read_data[11];
            qint16 voltage = 0;
            memcpy(&voltage,&u_voltage,sizeof(quint16));
               ui->lEdit_voltage->setText(QString::number(voltage*1.0/1000));
            if((read_data[12]<<8|read_data[13]) == 0xFFFF){
                ui->lEdit_res->setText("oL");
            }else{
                ui->lEdit_res->setText(QString::number((read_data[12]<<8|read_data[13])*1.0/100));
            }
            ui->lEdit_battery_temperature->setText(QString::number((read_data[14]<<8|read_data[15])*1.0/100));
            ui->lEdit_CO->setText(QString::number((read_data[16]<<8|read_data[17])*1.0));
            ui->lEdit_H2->setText(QString::number((read_data[18]<<8|read_data[19])*1.0));
            ui->lEdit_SMK->setText(QString::number(read_data[20]<<8|read_data[21]));
            ui->lEdit_env_temperature->setText(QString::number((read_data[22]<<8|read_data[23])*1.0/100));
            ui->lEdit_humidity->setText(QString::number((read_data[24]<<8|read_data[25])*1.0/100));

            ui->lEdit_heart->setText(QString::number((read_data[26]<<8|read_data[27])));

            u_voltage = read_data[28]<<8|read_data[29];
            memcpy(&voltage,&u_voltage,sizeof(quint16));
            ui->lEdit_voltage_real->setText(QString::number(voltage*1.0/1000));

            ui->lEdit_res_real->setText(QString::number((read_data[30]<<8|read_data[31])*1.0/100));
            ui->lEdit_battery_temperature_real->setText(QString::number((read_data[32]<<8|read_data[33])*1.0/100));
            ui->lEdit_CO_real->setText(QString::number((read_data[34]<<8|read_data[35])*1.0));
            ui->lEdit_H2_real->setText(QString::number((read_data[36]<<8|read_data[37])*1.0));
            ui->lEdit_SMK_real->setText(QString::number(read_data[38]<<8|read_data[39]));
            ui->lEdit_env_temperature_real->setText(QString::number((read_data[40]<<8|read_data[41])*1.0/100));
            ui->lEdit_humidity_real->setText(QString::number((read_data[42]<<8|read_data[43])*1.0/100));
        }else{
            qDebug()<<"data info msg check error!";
        }
    }else{
        qDebug()<<"device not respond!";
    }

}

void MainWindow::run_process_upgrade_handler(void)
{
    upgrade_handler();
}

void MainWindow::device_alarm_threshold_set(void)
{
    quint8  data[24] = {0},cmd = 0x10;
    quint16 set_reg_addr = 0x0011,set_reg_num = 0x08,crc = 0;
    // quint16 read_bytes = 0;
    quint8  read_data[100] = {0};

    QList<QLineEdit *> lineEdit = {ui->lEdit_h2_th_set,ui->lEdit_co_th_set,ui->lEdit_temp_th_set,
                                    ui->lEdit_temp_ratio_th_set,ui->lEdit_voltage_high_th_set,
                                    ui->lEdit_voltage_low_th_set,ui->lEdit_discharge_th_set,
                                    ui->lEdit_charge_th_set};
    for(int i=0;i<lineEdit.size();++i){
        uint16_t value = 0;
        bool ok = false;
        QString str_id = lineEdit[i]->text();
        value = (quint16)str_id.toUInt(&ok,10);
        if(ok){
            data[2*i] =  value>>8;
            data[2*i+1] =  value&0xFF;
        }else{;}
    }


    if(!device_reg_data_write(set_reg_addr,set_reg_num,cmd,data)){
        qDebug()<<"[device set threshold info] cmd not send!";
        return;
    }else{
        qDebug()<<"[device set threshold info]"<<"reg_addr = "<<Qt::hex<<set_reg_addr<<"reg_num = "<<set_reg_num;
    }

    delay(20);
    while(myserial->myserialport_receiveData(read_data,sizeof(read_data)));
}

void MainWindow::device_serial_set(void)
{
    quint8 data[28] = {0},cmd = 0x10;
    quint16 set_reg_addr = 0x0007,set_reg_num = 0x0A;
    // quint16 read_bytes = 0;
    quint8  read_data[100] = {0};

    bool ok = false;
    QString str_id = ui->lEdit_serial_set->text();
    str_id = str_id.left(16);
    QByteArray utf8Data;
    if(str_id.length()>0){
        utf8Data = str_id.toUtf8();
        memcpy(&data[0],utf8Data.constData(),utf8Data.size());
    }else{;}

    if(!device_reg_data_write(set_reg_addr,set_reg_num,cmd,data)){
        qDebug()<<"[device set serial info] cmd not send!";
        return;
    }else{
        qDebug()<<"[device set serial info]"<<"reg_addr = "<<Qt::hex<<set_reg_addr<<"reg_num = "<<set_reg_num;
    }

    delay(20);
    while(myserial->myserialport_receiveData(read_data,sizeof(read_data)));
}

void device_time_set(void)
{

}

void MainWindow::device_capacity_set(void)
{
    quint8 data[10] = {0},cmd = 0x10;
    quint16 set_reg_addr = 0x0003,set_reg_num = 0x01,crc = 0;
    // quint16 read_bytes = 0;
    quint8  read_data[100] = {0};

    bool ok = false;
    quint16 value = 0;
    QString str_id = ui->lEdit_capacity_set->text();
    value = (quint16)str_id.toUInt(&ok,10);
    if(ok){
        data[0] =  value>>8;
        data[1] =  value&0xFF;
    }else{;}

    if(!device_reg_data_write(set_reg_addr,set_reg_num,cmd,data)){
        qDebug()<<"[device set capacity info] cmd not send!";
        return;
    }else{
        qDebug()<<"[device set capacity info]"<<"reg_addr = "<<Qt::hex<<set_reg_addr<<"reg_num = "<<set_reg_num;
    }

    delay(20);
    while(myserial->myserialport_receiveData(read_data,sizeof(read_data)));

}

void MainWindow::device_current_set(void)
{
    quint8 data[10] = {0},cmd = 0x10;
    quint16 set_reg_addr = 0x001E,set_reg_num = 0x01,crc = 0;
    // quint16 read_bytes = 0;
    quint8  read_data[100] = {0};

    qint16 value = 0;
    bool ok = false;
    QString str_id = ui->lEdit_current_set->text();
    value = (qint16)(str_id.toDouble(&ok)*1000);
    if(ok){
        memcpy(&data[0],&value,2);
        // data[6] =  value>>8;
        // data[7] =  value&0xFF;
    }else{;}

    if(!device_reg_data_write(set_reg_addr,set_reg_num,cmd,data)){
        qDebug()<<"[device set current info] cmd not send!";
        return;
    }else{
        qDebug()<<"[device set current info]"<<"reg_addr = "<<Qt::hex<<set_reg_addr<<"reg_num = "<<set_reg_num;
    }

    delay(20);
    while(myserial->myserialport_receiveData(read_data,sizeof(read_data)));
}

void MainWindow::device_balance_set(void)
{
    quint8 data[10] = {0},cmd = 0x10;
    quint16 set_reg_addr = 0x0006,set_reg_num = 0x01;
    // quint16 read_bytes = 0;
    quint8  read_data[100] = {0};

    uint16_t value = (quint16)m_balance_flag;
    data[0] =  value>>8;
    data[1] =  value&0xFF;


    if(!device_reg_data_write(set_reg_addr,set_reg_num,cmd,data)){
        qDebug()<<"[device set balance info] cmd not send!";
        return;
    }else{
        qDebug()<<"[device set balance info]"<<"reg_addr = "<<Qt::hex<<set_reg_addr<<"reg_num = "<<set_reg_num;
    }

    delay(20);
    while(myserial->myserialport_receiveData(read_data,sizeof(read_data)));
}

void MainWindow::device_voltage_calibration_set(void)
{
    quint8 data[16] = {0},cmd = 0x10;
    quint16 set_reg_addr = 0x4001,set_reg_num = 0x04;
    // quint16 read_bytes = 0;
    quint8  read_data[100] = {0};

    QList<QLineEdit *> lineEdit = {ui->lEdit_voltage_range_calib,ui->lEdit_voltage_zero_calib};
    for(int i=0; i<lineEdit.size(); i++){
        u8_float_t u8_f_data;
        bool ok = false;
        QString str_id = lineEdit[i]->text();
        u8_f_data.f_data = str_id.toFloat(&ok);
        if(!ok){
            u8_f_data.f_data = 1.0;
        }else{;}
        data[4*i]   = u8_f_data.u8_data[3];
        data[4*i+1] = u8_f_data.u8_data[2];
        data[4*i+2] = u8_f_data.u8_data[1];
        data[4*i+3] = u8_f_data.u8_data[0];
    }

    if(!device_reg_data_write(set_reg_addr,set_reg_num,cmd,data)){
        qDebug()<<"[device set voltage calibration info] cmd not send!";
        return;
    }else{
        qDebug()<<"[device set voltage calibration info]"<<"reg_addr = "<<Qt::hex<<set_reg_addr<<"reg_num = "<<set_reg_num;
    }

    delay(20);
    while(myserial->myserialport_receiveData(read_data,sizeof(read_data)));
}


void MainWindow::device_ntc_calibration_set(void)
{
    quint8 data[16] = {0},cmd = 0x10;
    quint16 set_reg_addr = 0x401D,set_reg_num = 0x04;
    // quint16 read_bytes = 0;
    quint8  read_data[100] = {0};

    QList<QLineEdit *> lineEdit = {ui->lEdit_ntc_temp_k_calib,ui->lEdit_ntc_temp_b_calib};
    for(int i=0; i<lineEdit.size(); i++){
        u8_float_t u8_f_data;
        bool ok = false;
        QString str_id = lineEdit[i]->text();
        u8_f_data.f_data = str_id.toFloat(&ok);
        if(!ok){
            u8_f_data.f_data = 1.0;
        }else{;}
        data[4*i]   = u8_f_data.u8_data[3];
        data[4*i+1] = u8_f_data.u8_data[2];
        data[4*i+2] = u8_f_data.u8_data[1];
        data[4*i+3] = u8_f_data.u8_data[0];
    }

    if(!device_reg_data_write(set_reg_addr,set_reg_num,cmd,data)){
        qDebug()<<"[device set ntc calibration info] cmd not send!";
        return;
    }else{
        qDebug()<<"[device set ntc calibration info]"<<"reg_addr = "<<Qt::hex<<set_reg_addr<<"reg_num = "<<set_reg_num;
    }

    delay(20);
    while(myserial->myserialport_receiveData(read_data,sizeof(read_data)));
}

void MainWindow::device_env_calibration_set(void)
{
    quint8 data[16] = {0},cmd = 0x10;
    quint16 set_reg_addr = 0x4021,set_reg_num = 0x08;
    // quint16 read_bytes = 0;
    quint8  read_data[100] = {0};

    QList<QLineEdit *> lineEdit = {ui->lEdit_env_temp_k_calib,ui->lEdit_env_temp_b_calib,
                                   ui->lEdit_env_hum_k_calib,ui->lEdit_env_hum_b_calib};
    for(int i=0; i<lineEdit.size(); i++){
        u8_float_t u8_f_data;
        bool ok = false;
        QString str_id = lineEdit[i]->text();
        u8_f_data.f_data = str_id.toFloat(&ok);
        if(!ok){
            u8_f_data.f_data = 1.0;
        }else{;}
        data[4*i]   = u8_f_data.u8_data[3];
        data[4*i+1] = u8_f_data.u8_data[2];
        data[4*i+2] = u8_f_data.u8_data[1];
        data[4*i+3] = u8_f_data.u8_data[0];
    }

    if(!device_reg_data_write(set_reg_addr,set_reg_num,cmd,data)){
        qDebug()<<"[device set env calibration info] cmd not send!";
        return;
    }else{
        qDebug()<<"[device set env calibration info]"<<"reg_addr = "<<Qt::hex<<set_reg_addr<<"reg_num = "<<set_reg_num;
    }

    delay(20);
    while(myserial->myserialport_receiveData(read_data,sizeof(read_data)));
}


void MainWindow::device_co_calibration_set(void)
{
    quint8 data[24] = {0},cmd = 0x10;
    quint16 set_reg_addr = 0x4005,set_reg_num = 0x0c,crc = 0;
    // quint16 read_bytes = 0;
    quint8  read_data[100] = {0};


    QList<QLineEdit *> lineEdit = {ui->lEdit_co_k1_calib,ui->lEdit_co_k2_calib,ui->lEdit_co_k3_calib,
                                    ui->lEdit_co_b1_calib,ui->lEdit_co_b2_calib,ui->lEdit_co_b3_calib};
    for(int i=0; i<lineEdit.size();i++){
        u8_float_t u8_f_data;
        bool ok = false;
        QString str_id = lineEdit[i]->text();
        u8_f_data.f_data = str_id.toFloat(&ok);
        if(!ok){
            u8_f_data.f_data = 1.0;
        }else{;}
        data[4*i]   = u8_f_data.u8_data[3];
        data[4*i+1] = u8_f_data.u8_data[2];
        data[4*i+2] = u8_f_data.u8_data[1];
        data[4*i+3] = u8_f_data.u8_data[0];
    }

    if(!device_reg_data_write(set_reg_addr,set_reg_num,cmd,data)){
        qDebug()<<"[device set CO calibration info] cmd not send!";
        return;
    }else{
        qDebug()<<"[device set CO calibration info]"<<"reg_addr = "<<Qt::hex<<set_reg_addr<<"reg_num = "<<set_reg_num;
    }

    delay(20);
    while(myserial->myserialport_receiveData(read_data,sizeof(read_data)));
}

void MainWindow::device_h2_calibration_set(void)
{
    quint8 data[32] = {0},cmd = 0x10;
    quint16 set_reg_addr = 0x4011,set_reg_num = 0x0C,crc = 0;
    // quint16 read_bytes = 0;
    quint8  read_data[100] = {0};

    QList<QLineEdit *> lineEdit = { ui->lEdit_h2_k1,ui->lEdit_h2_k2,
                                    ui->lEdit_h2_k3,ui->lEdit_h2_b1,
                                    ui->lEdit_h2_b2,ui->lEdit_h2_b3};
    for(int i=0; i<lineEdit.size();i++){
        u8_float_t u8_f_data;
        bool ok = false;
        QString str_id = lineEdit[i]->text();
        u8_f_data.f_data = str_id.toFloat(&ok);
        if(!ok){
            u8_f_data.f_data = 1.0;
        }else{;}
        data[4*i]   = u8_f_data.u8_data[3];
        data[4*i+1] = u8_f_data.u8_data[2];
        data[4*i+2] = u8_f_data.u8_data[1];
        data[4*i+3] = u8_f_data.u8_data[0];
    }

    if(!device_reg_data_write(set_reg_addr,set_reg_num,cmd,data)){
        qDebug()<<"[device set H2 calibration info] cmd not send!";
        return;
    }else{
        qDebug()<<"[device set H2 calibration info]"<<"reg_addr = "<<Qt::hex<<set_reg_addr<<"reg_num = "<<set_reg_num;
    }

    delay(20);
    while(myserial->myserialport_receiveData(read_data,sizeof(read_data)));
}

void MainWindow::device_h2_map_set(void)
{
    quint8 data[100] = {0},cmd = 0x10;
    quint16 set_reg_addr = 0x402D,set_reg_num = 0x14;
    // quint16 read_bytes = 0;
    quint8  read_data[100] = {0};

    QList<QLineEdit *> lineEdit = { ui->lEdit_h2_ref1_set,ui->lEdit_h2_ref2_set,ui->lEdit_h2_ref3_set,ui->lEdit_h2_ref4_set,ui->lEdit_h2_ref5_set,
                                    ui->lEdit_h2_real1_set,ui->lEdit_h2_real2_set,ui->lEdit_h2_real3_set,ui->lEdit_h2_real4_set,ui->lEdit_h2_real5_set};
    for(int i=0; i<lineEdit.size();i++){
        u8_float_t u8_f_data;
        bool ok = false;
        QString str_id = lineEdit[i]->text();
        u8_f_data.f_data = str_id.toFloat(&ok);
        if(!ok){
            u8_f_data.f_data = 1.0;
        }else{;}
        data[4*i]   = u8_f_data.u8_data[3];
        data[4*i+1] = u8_f_data.u8_data[2];
        data[4*i+2] = u8_f_data.u8_data[1];
        data[4*i+3] = u8_f_data.u8_data[0];
    }

    if(!device_reg_data_write(set_reg_addr,set_reg_num,cmd,data)){
        qDebug()<<"[device set H2 map info] cmd not send!";
        return;
    }else{
        qDebug()<<"[device set H2 map info]"<<"reg_addr = "<<Qt::hex<<set_reg_addr<<"reg_num = "<<set_reg_num;
    }

    delay(20);
    while(myserial->myserialport_receiveData(read_data,sizeof(read_data)));
}

void MainWindow::device_h2_K_set(void)
{
    quint8 data[32] = {0},cmd = 0x10;
    quint16 set_reg_addr = 0x4041,set_reg_num = 0x02;
    // quint16 read_bytes = 0;
    quint8  read_data[100] = {0};

    QList<QLineEdit *> lineEdit = { ui->lEdit_h2_k};
    for(int i=0; i<lineEdit.size();i++){
        u8_float_t u8_f_data;
        bool ok = false;
        QString str_id = lineEdit[i]->text();
        u8_f_data.f_data = str_id.toFloat(&ok);
        if(!ok){
            u8_f_data.f_data = 1.0;
        }else{;}
        data[4*i]   = u8_f_data.u8_data[3];
        data[4*i+1] = u8_f_data.u8_data[2];
        data[4*i+2] = u8_f_data.u8_data[1];
        data[4*i+3] = u8_f_data.u8_data[0];
    }

    if(!device_reg_data_write(set_reg_addr,set_reg_num,cmd,data)){
        qDebug()<<"[device set H2 K info] cmd not send!";
        return;
    }else{
        qDebug()<<"[device set H2 K info]"<<"reg_addr = "<<Qt::hex<<set_reg_addr<<"reg_num = "<<set_reg_num;
    }

    delay(20);
    while(myserial->myserialport_receiveData(read_data,sizeof(read_data)));
}

void MainWindow::device_h2_ref_zero_set(void)
{
    quint8 data[32] = {0},cmd = 0x10;
    quint16 set_reg_addr = 0x4029,set_reg_num = 0x04;
    // quint16 read_bytes = 0;
    quint8  read_data[100] = {0};

    QList<QLineEdit *> lineEdit = { ui->lEdit_h2_ref_temp_set,ui->lEdit_h2_ref_hum_set};
    for(int i=0; i<lineEdit.size();i++){
        u8_float_t u8_f_data;
        bool ok = false;
        QString str_id = lineEdit[i]->text();
        u8_f_data.f_data = str_id.toFloat(&ok);
        if(!ok){
            u8_f_data.f_data = 1.0;
        }else{;}
        data[4*i]   = u8_f_data.u8_data[3];
        data[4*i+1] = u8_f_data.u8_data[2];
        data[4*i+2] = u8_f_data.u8_data[1];
        data[4*i+3] = u8_f_data.u8_data[0];
    }

    if(!device_reg_data_write(set_reg_addr,set_reg_num,cmd,data)){
        qDebug()<<"[device set H2 K info] cmd not send!";
        return;
    }else{
        qDebug()<<"[device set H2 K info]"<<"reg_addr = "<<Qt::hex<<set_reg_addr<<"reg_num = "<<set_reg_num;
    }

    delay(20);
    while(myserial->myserialport_receiveData(read_data,sizeof(read_data)));
}

void MainWindow::device_h2_ref_one_set(void)
{
    quint8 data[32] = {0},cmd = 0x10;
    quint16 set_reg_addr = 0x402D,set_reg_num = 0x02;
    // quint16 read_bytes = 0;
    quint8  read_data[100] = {0};

    bool ok = false;
    QString str_id = ui->lEdit_h2_ref_num_set->text();
    quint8 reg_num = 0;
    reg_num = str_id.toUInt(&ok);
    if(!ok) return;
    if(reg_num > 5 || reg_num == 0) reg_num = 1;
    set_reg_addr += 2*(reg_num-1);


    QList<QLineEdit *> lineEdit = { ui->lEdit_h2_ref_one_set};
    for(int i=0; i<lineEdit.size();i++){
        u8_float_t u8_f_data;
        ok = false;
        str_id = lineEdit[i]->text();
        u8_f_data.f_data = str_id.toFloat(&ok);
        if(!ok){
            u8_f_data.f_data = 1.0;
        }else{;}
        data[4*i]   = u8_f_data.u8_data[3];
        data[4*i+1] = u8_f_data.u8_data[2];
        data[4*i+2] = u8_f_data.u8_data[1];
        data[4*i+3] = u8_f_data.u8_data[0];
    }

    if(!device_reg_data_write(set_reg_addr,set_reg_num,cmd,data)){
        qDebug()<<"[device set H2 K info] cmd not send!";
        return;
    }else{
        qDebug()<<"[device set H2 K info]"<<"reg_addr = "<<Qt::hex<<set_reg_addr<<"reg_num = "<<set_reg_num;
    }

    delay(20);
    while(myserial->myserialport_receiveData(read_data,sizeof(read_data)));
}

void MainWindow::device_h2_ref_auto_open_set(bool status)
{
    quint8 data[32] = {0},cmd = 0x10;
    quint16 set_reg_addr = 0x4059,set_reg_num = 0x01;
    // quint16 read_bytes = 0;
    quint8  read_data[100] = {0};

    if(status){
        data[0] = 0;
        data[1] = 1;
    }else{
        data[0] = 0;
        data[1] = 0;
    }

    if(!device_reg_data_write(set_reg_addr,set_reg_num,cmd,data)){
        qDebug()<<"[device set H2 K info] cmd not send!";
        return;
    }else{
        qDebug()<<"[device set H2 K info]"<<"reg_addr = "<<Qt::hex<<set_reg_addr<<"reg_num = "<<set_reg_num;
    }

    delay(20);
    while(myserial->myserialport_receiveData(read_data,sizeof(read_data)));
}



void MainWindow::run_process_set_param_handler(void)
{
    if(m_param_event&PARAM_EVENT_SET_ALARM_THRESHOLD){
        device_alarm_threshold_set();
        m_param_event &= ~PARAM_EVENT_SET_ALARM_THRESHOLD;
    }

    if(m_param_event&PARAM_EVENT_SET_SERIAL){
        device_serial_set();
        m_param_event &= ~PARAM_EVENT_SET_SERIAL;
    }

    if(m_param_event&PARAM_EVENT_SET_CAPACITY){
        device_capacity_set();
        m_param_event &= ~PARAM_EVENT_SET_CAPACITY;
    }

    if(m_param_event&PARAM_EVENT_SET_CURRENT){
        device_current_set();
        m_param_event &= ~PARAM_EVENT_SET_CURRENT;
    }

    if(m_param_event&PARAM_EVENT_SET_BALANCE){
        device_balance_set();
        m_param_event &= ~PARAM_EVENT_SET_BALANCE;
    }

    if(m_param_event&PARAM_EVENT_SET_VOLTAGE_CALIB){
        device_voltage_calibration_set();
        m_param_event &= ~PARAM_EVENT_SET_VOLTAGE_CALIB;
    }

    if(m_param_event&PARAM_EVENT_SET_NTC_CALIB){
        device_ntc_calibration_set();
        m_param_event &= ~PARAM_EVENT_SET_NTC_CALIB;
    }

    if(m_param_event&PARAM_EVENT_SET_ENV_CALIB){
        device_env_calibration_set();
        m_param_event &= ~PARAM_EVENT_SET_ENV_CALIB;
    }

    if(m_param_event&PARAM_EVENT_SET_CO_CALIB){
        device_co_calibration_set();
        m_param_event &= ~PARAM_EVENT_SET_CO_CALIB;
    }

    if(m_param_event&PARAM_EVENT_SET_H2_CALIB){
        device_h2_calibration_set();
        m_param_event &= ~PARAM_EVENT_SET_H2_CALIB;
    }

    if(m_param_event&PARAM_EVENT_SET_H2_REF){
        device_h2_map_set();
        m_param_event &= ~PARAM_EVENT_SET_H2_REF;
    }else{;}

    if(m_param_event&PARAM_EVENT_SET_H2_K){
        device_h2_K_set();
        m_param_event &= ~PARAM_EVENT_SET_H2_K;
    }else{;}

    if(m_param_event&PARAM_EVENT_SET_H2_REF_ONE){
        device_h2_ref_one_set();
        m_param_event &= ~PARAM_EVENT_SET_H2_REF_ONE;
    }else{;}

    if(m_param_event&PARAM_EVENT_SET_H2_REF_ZERO){
        device_h2_ref_zero_set();
        m_param_event &= ~PARAM_EVENT_SET_H2_REF_ZERO;
    }else{;}

    if(m_param_event&PARAM_EVENT_SET_H2_AUTO_OPEN){
        device_h2_ref_auto_open_set(autoOpenFlag);
        m_param_event &= ~PARAM_EVENT_SET_H2_AUTO_OPEN;
    }else{;}
}

void MainWindow::device_voltage_calibration_get(void)
{
    quint8  cmd = 0x03,id = 0x00;
    quint16 read_reg_addr = 0x4001,read_reg_num = 0x04;
    quint16 read_bytes = 0;
    quint8  read_data[100] = {0};

    while(myserial->myserialport_receiveData(read_data,sizeof(read_data)));

    if(!(id = device_id_get())){
        qDebug()<<"[device read voltage calibration info] cmd not send!";
        return;
    }else{;}

    device_reg_data_read(read_reg_addr,read_reg_num,cmd,id);
    qDebug()<<"[device read voltage calibration info]"<<"reg_addr = "<<Qt::hex<<read_reg_addr<<"reg_num = "<<read_reg_num;

    delay(100);

    read_bytes = myserial->myserialport_receiveData(read_data,sizeof(read_data));
    if(read_bytes > 0){
        if(read_data[0] == id && read_data[1] == cmd && (read_data[2]<<8|read_data[3]) == read_reg_num*2){
            u8_float_t calibretion[6];
            QList<QLineEdit *> lineEdit = {ui->lEdit_voltage_zero,ui->lEdit_voltage_range};
            for(int i=0;i<lineEdit.size();i++){
                calibretion[i].u8_data[0] = read_data[4+4*i+3];
                calibretion[i].u8_data[1] = read_data[4+4*i+2];
                calibretion[i].u8_data[2] = read_data[4+4*i+1];
                calibretion[i].u8_data[3] = read_data[4+4*i+0];
                lineEdit[i]->setText(QString::number(calibretion[i].f_data,'f',7));
            }
        }else{
            qDebug()<<"read param info check error!";
        }
    }else{
        qDebug()<<"device not respond!";
    }
}

void MainWindow::device_ntc_calibration_get(void)
{
    quint8  cmd = 0x03,id = 0x00;
    quint16 read_reg_addr = 0x401D,read_reg_num = 0x04;
    quint16 read_bytes = 0;
    quint8  read_data[100] = {0};

    while(myserial->myserialport_receiveData(read_data,sizeof(read_data)));

    if(!(id = device_id_get())){
        qDebug()<<"[device read battery ntc calibration info] cmd not send!";
        return;
    }else{;}

    device_reg_data_read(read_reg_addr,read_reg_num,cmd,id);
    qDebug()<<"[device read battery ntc calibration info]"<<"reg_addr = "<<Qt::hex<<read_reg_addr<<"reg_num = "<<read_reg_num;

    delay(100);

    read_bytes = myserial->myserialport_receiveData(read_data,sizeof(read_data));
    if(read_bytes > 0){
        if(read_data[0] == id && read_data[1] == cmd && (read_data[2]<<8|read_data[3]) == read_reg_num*2){
            u8_float_t calibretion[6];
            QList<QLineEdit *> lineEdit = {ui->lEdit_ntc_temp_k,ui->lEdit_ntc_temp_b};
            for(int i=0;i<lineEdit.size();i++){
                calibretion[i].u8_data[0] = read_data[4+4*i+3];
                calibretion[i].u8_data[1] = read_data[4+4*i+2];
                calibretion[i].u8_data[2] = read_data[4+4*i+1];
                calibretion[i].u8_data[3] = read_data[4+4*i+0];
                lineEdit[i]->setText(QString::number(calibretion[i].f_data,'f',7));
            }
        }else{
            qDebug()<<"read param info check error!";
        }
    }else{
        qDebug()<<"device not respond!";
    }
}

void MainWindow::device_env_calibration_get(void)
{
    quint8  cmd = 0x03,id = 0x00;
    quint16 read_reg_addr = 0x4021,read_reg_num = 0x08;
    quint16 read_bytes = 0;
    quint8  read_data[100] = {0};

    while(myserial->myserialport_receiveData(read_data,sizeof(read_data)));

    if(!(id = device_id_get())){
        qDebug()<<"[device read env calibration info] cmd not send!";
        return;
    }else{;}

    device_reg_data_read(read_reg_addr,read_reg_num,cmd,id);
    qDebug()<<"[device read env calibration info]"<<"reg_addr = "<<Qt::hex<<read_reg_addr<<"reg_num = "<<read_reg_num;

    delay(100);

    read_bytes = myserial->myserialport_receiveData(read_data,sizeof(read_data));
    if(read_bytes > 0){
        if(read_data[0] == id && read_data[1] == cmd && (read_data[2]<<8|read_data[3]) == read_reg_num*2){
            u8_float_t calibretion[6];
            QList<QLineEdit *> lineEdit = {ui->lEdit_env_temp_k,ui->lEdit_env_temp_b,
                                           ui->lEdit_env_hum_k,ui->lEdit_env_hum_b};
            for(int i=0;i<lineEdit.size();i++){
                calibretion[i].u8_data[0] = read_data[4+4*i+3];
                calibretion[i].u8_data[1] = read_data[4+4*i+2];
                calibretion[i].u8_data[2] = read_data[4+4*i+1];
                calibretion[i].u8_data[3] = read_data[4+4*i+0];
                lineEdit[i]->setText(QString::number(calibretion[i].f_data,'f',7));
            }
        }else{
            qDebug()<<"read param info check error!";
        }
    }else{
        qDebug()<<"device not respond!";
    }
}

void MainWindow::device_co_calibration_get(void)
{
    quint8  cmd = 0x03,id = 0x00;
    quint16 read_reg_addr = 0x4005,read_reg_num = 0x0c;
    quint16 read_bytes = 0;
    quint8  read_data[100] = {0};

    while(myserial->myserialport_receiveData(read_data,sizeof(read_data)));

    if(!(id = device_id_get())){
        qDebug()<<"[device read CO calibration info] cmd not send!";
        return;
    }else{;}

    device_reg_data_read(read_reg_addr,read_reg_num,cmd,id);
    qDebug()<<"[device read CO calibration info]"<<"reg_addr = "<<Qt::hex<<read_reg_addr<<"reg_num = "<<read_reg_num;

    delay(100);

    read_bytes = myserial->myserialport_receiveData(read_data,sizeof(read_data));
    if(read_bytes > 0){
        if(read_data[0] == id && read_data[1] == cmd && (read_data[2]<<8|read_data[3]) == read_reg_num*2){
            u8_float_t calibretion[6];
            QList<QLineEdit *> lineEdit = {ui->lEdit_co_k1,ui->lEdit_co_k2,
                                           ui->lEdit_co_k3,ui->lEdit_co_b1,
                                           ui->lEdit_co_b2,ui->lEdit_co_b3};
            for(int i=0;i<lineEdit.size();i++){
                calibretion[i].u8_data[0] = read_data[4+4*i+3];
                calibretion[i].u8_data[1] = read_data[4+4*i+2];
                calibretion[i].u8_data[2] = read_data[4+4*i+1];
                calibretion[i].u8_data[3] = read_data[4+4*i+0];
                lineEdit[i]->setText(QString::number(calibretion[i].f_data,'f',7));
            }
        }else{
            qDebug()<<"read param info check error!";
        }
    }else{
        qDebug()<<"device not respond!";
    }
}

void MainWindow::device_h2_calibration_get(void)
{
    quint8  cmd = 0x03,id = 0x00;
    quint16 read_reg_addr = 0x4011,read_reg_num = 0x0c;
    quint16 read_bytes = 0;
    quint8  read_data[100] = {0};

    while(myserial->myserialport_receiveData(read_data,sizeof(read_data)));

    if(!(id = device_id_get())){
        qDebug()<<"[device read param info] cmd not send!";
        return;
    }else{;}

    device_reg_data_read(read_reg_addr,read_reg_num,cmd,id);
    qDebug()<<"[device read param info]"<<"reg_addr = "<<Qt::hex<<read_reg_addr<<"reg_num = "<<read_reg_num;

    delay(100);

    read_bytes = myserial->myserialport_receiveData(read_data,sizeof(read_data));
    if(read_bytes > 0){
        if(read_data[0] == id && read_data[1] == cmd && (read_data[2]<<8|read_data[3]) == read_reg_num*2){
            u8_float_t calibretion[6];
            QList<QLineEdit *> lineEdit = {ui->lEdit_h2_k1,ui->lEdit_h2_k2,
                                           ui->lEdit_h2_k3,ui->lEdit_h2_b1,
                                           ui->lEdit_h2_b2,ui->lEdit_h2_b3};
            for(int i=0;i<lineEdit.size();i++){
                calibretion[i].u8_data[0] = read_data[4+4*i+3];
                calibretion[i].u8_data[1] = read_data[4+4*i+2];
                calibretion[i].u8_data[2] = read_data[4+4*i+1];
                calibretion[i].u8_data[3] = read_data[4+4*i+0];
                lineEdit[i]->setText(QString::number(calibretion[i].f_data,'f',7));
            }
        }else{
            qDebug()<<"read param info check error!";
        }
    }else{
        qDebug()<<"device not respond!";
    }
}

void MainWindow::device_h2_ref_get(void)
{
    quint8  cmd = 0x03,id = 0x00;
    quint16 read_reg_addr = 0x4029,read_reg_num = 0x31;
    quint16 read_bytes = 0;
    quint8  read_data[200] = {0};

    while(myserial->myserialport_receiveData(read_data,sizeof(read_data)));

    if(!(id = device_id_get())){
        qDebug()<<"[device read h2 ref info] cmd not send!";
        return;
    }else{;}

    device_reg_data_read(read_reg_addr,read_reg_num,cmd,id);
    qDebug()<<"[device read h2 ref info]"<<"reg_addr = "<<Qt::hex<<read_reg_addr<<"reg_num = "<<read_reg_num;

    delay(500);

    read_bytes = myserial->myserialport_receiveData(read_data,sizeof(read_data));
    if(read_bytes > 0){
        if(read_data[0] == id && read_data[1] == cmd && (read_data[2]<<8|read_data[3]) == read_reg_num*2){
            u8_float_t calibretion[6];
            QList<QLineEdit *> lineEdit = { ui->lEdit_h2_ref_temp_set,ui->lEdit_h2_ref_hum_set,
                                            ui->lEdit_h2_ref1_set,ui->lEdit_h2_ref2_set,ui->lEdit_h2_ref3_set,ui->lEdit_h2_ref4_set,ui->lEdit_h2_ref5_set,
                                            ui->lEdit_h2_real1_set,ui->lEdit_h2_real2_set,ui->lEdit_h2_real3_set,ui->lEdit_h2_real4_set,ui->lEdit_h2_real5_set,
                                            ui->lEdit_h2_temp1_set,ui->lEdit_h2_temp2_set,ui->lEdit_h2_temp3_set,ui->lEdit_h2_temp4_set,ui->lEdit_h2_temp5_set,
                                            ui->lEdit_h2_hum1_set,ui->lEdit_h2_hum2_set,ui->lEdit_h2_hum3_set,ui->lEdit_h2_hum4_set,ui->lEdit_h2_hum5_set,
                                            ui->lEdit_h2_k,ui->lEdit_h2_b,ui->lEdit_auto_open};
            for(int i=0;i<lineEdit.size();i++){
                if(i < (lineEdit.size()-1)){
                    calibretion[i].u8_data[0] = read_data[4+4*i+3];
                    calibretion[i].u8_data[1] = read_data[4+4*i+2];
                    calibretion[i].u8_data[2] = read_data[4+4*i+1];
                    calibretion[i].u8_data[3] = read_data[4+4*i+0];
                    lineEdit[i]->setText(QString::number(calibretion[i].f_data,'f',7));
                }else{
                    lineEdit[i]->setText(QString::number((read_data[4+4*(i-1)+4]<<8)|(read_data[4+4*(i-1)+5])));
                }
            }
        }else{
            qDebug()<<"read h2 ref info check error!";
        }
    }else{
        qDebug()<<"device not respond!";
    }
}

void MainWindow::run_process_get_param_handler(void)
{
    if(m_get_param_event&PARAM_EVENT_GET_VOLTAGE_CALIB){
        device_voltage_calibration_get();
        m_get_param_event &= ~PARAM_EVENT_GET_VOLTAGE_CALIB;
    }else{;}
    if(m_get_param_event&PARAM_EVENT_GET_NTC_CALIB){
        device_ntc_calibration_get();
        m_get_param_event &= ~PARAM_EVENT_GET_NTC_CALIB;
    }else{;}
    if(m_get_param_event&PARAM_EVENT_GET_ENV_CALIB){
        device_env_calibration_get();
        m_get_param_event &= ~PARAM_EVENT_GET_ENV_CALIB;
    }else{;}
    if(m_get_param_event&PARAM_EVENT_GET_CO_CALIB){
        device_co_calibration_get();
        m_get_param_event &= ~PARAM_EVENT_GET_CO_CALIB;
    }else{;}
    if(m_get_param_event&PARAM_EVENT_GET_H2_CALIB){
        device_h2_calibration_get();
        m_get_param_event &= ~PARAM_EVENT_GET_H2_CALIB;
    }else{;}

    if(m_get_param_event&PARAM_EVENT_GET_H2_REF){
        device_h2_ref_get();
        m_get_param_event &= ~PARAM_EVENT_GET_H2_REF;
    }else{;}
}



void MainWindow::comm_timer_run_task(void)
{
    static quint8 time_cnt = 0;

    if(myserial == nullptr){
        qDebug()<<"串口设备未打开";
        return;
    }

    project_event_handler();

    switch(m_run_process){
    case RUN_PROCESS_INIT:
        run_process_init_handler();
        m_run_process = RUN_PROCESS_GET_INFO;
        break;
    case RUN_PROCESS_GET_INFO:
        run_process_get_info_handler();
        m_run_process = RUN_PROCESS_GET_DATA;
        break;
    case RUN_PROCESS_GET_PARAM:
        run_process_get_param_handler();
        m_run_process = RUN_PROCESS_GET_DATA;
        break;
    case RUN_PROCESS_GET_DATA:
        if(time_cnt%10 == 0){
            run_process_get_data_handler();
        }else if(time_cnt == 1){
            run_process_get_result_handler();
        }
        m_run_process = RUN_PROCESS_GET_DATA;
        break;
    case RUN_PROCESS_SET_PARAM:
        run_process_set_param_handler();
        m_run_process = RUN_PROCESS_GET_DATA;
        break;
    case RUN_PROCESS_UPGRADE:
        run_process_upgrade_handler();
        m_run_process = RUN_PROCESS_GET_DATA;
        break;
    default:
        m_run_process = RUN_PROCESS_GET_DATA;
        break;
    }

    time_cnt++;
    time_cnt %= 20;
}







void MainWindow::on_btn_threshold_set_clicked()
{
    m_param_event |= PARAM_EVENT_SET_ALARM_THRESHOLD;
    m_run_event |= PROJECT_EVENT_SET_PRAMA_BIT;
}


void MainWindow::on_btn_serial_set_clicked()
{
    m_param_event |= PARAM_EVENT_SET_SERIAL;
    m_run_event |= PROJECT_EVENT_SET_PRAMA_BIT;
}


void MainWindow::on_btn_time_set_clicked()
{

}


void MainWindow::on_btn_capacity_set_clicked()
{
    m_param_event |= PARAM_EVENT_SET_CAPACITY;
    m_run_event |= PROJECT_EVENT_SET_PRAMA_BIT;
}


void MainWindow::on_btn_current_set_clicked()
{
    m_param_event |= PARAM_EVENT_SET_CURRENT;
    m_run_event |= PROJECT_EVENT_SET_PRAMA_BIT;
}


void MainWindow::on_btn_balanced_clicked()
{
    if(ui->btn_balanced->text() == "启用"){
        ui->btn_balanced->setText("关闭");
        m_balance_flag = 1;
    }else{
        ui->btn_balanced->setText("启用");
        m_balance_flag = 0;
    }
    m_param_event |= PARAM_EVENT_SET_BALANCE;
    m_run_event |= PROJECT_EVENT_SET_PRAMA_BIT;
}

void MainWindow::on_btn_voltage_calib_get_clicked()
{
    m_get_param_event |= PARAM_EVENT_GET_VOLTAGE_CALIB;
    m_run_event |= PROJECT_EVENT_GET_PRAMA_BIT;
}
void MainWindow::on_btn_ntc_calib_get_clicked()
{
    m_get_param_event |= PARAM_EVENT_GET_NTC_CALIB;
    m_run_event |= PROJECT_EVENT_GET_PRAMA_BIT;
}

void MainWindow::on_btn_env_calib_get_clicked()
{
    m_get_param_event |= PARAM_EVENT_GET_ENV_CALIB;
    m_run_event |= PROJECT_EVENT_GET_PRAMA_BIT;
}
void MainWindow::on_btn_co_calib_get_clicked()
{
    m_get_param_event |= PARAM_EVENT_GET_CO_CALIB;
    m_run_event |= PROJECT_EVENT_GET_PRAMA_BIT;
}

void MainWindow::on_btn_h2_calib_get_clicked()
{
    m_get_param_event |= PARAM_EVENT_GET_H2_CALIB;
    m_run_event |= PROJECT_EVENT_GET_PRAMA_BIT;
}

void MainWindow::on_btn_h2_ref_get_clicked()
{
    m_get_param_event |= PARAM_EVENT_GET_H2_REF;
    m_run_event |= PROJECT_EVENT_GET_PRAMA_BIT;
}

void MainWindow::on_btn_voltage_calib_set_clicked()
{
    m_param_event |= PARAM_EVENT_SET_VOLTAGE_CALIB;
    m_run_event |= PROJECT_EVENT_SET_PRAMA_BIT;
}

void MainWindow::on_btn_ntc_calib_set_clicked()
{
    m_param_event |= PARAM_EVENT_SET_NTC_CALIB;
    m_run_event |= PROJECT_EVENT_SET_PRAMA_BIT;
}

void MainWindow::on_btn_env_calib_set_clicked()
{
    m_param_event |= PARAM_EVENT_SET_ENV_CALIB;
    m_run_event |= PROJECT_EVENT_SET_PRAMA_BIT;
}


void MainWindow::on_btn_co_calib_set_clicked()
{
    m_param_event |= PARAM_EVENT_SET_CO_CALIB;
    m_run_event |= PROJECT_EVENT_SET_PRAMA_BIT;
}


void MainWindow::on_btn_h2_calib_set_clicked()
{
    m_param_event |= PARAM_EVENT_SET_H2_CALIB;
    m_run_event |= PROJECT_EVENT_SET_PRAMA_BIT;
}

void MainWindow::on_btn_h2_k_set_clicked()
{
    m_param_event |= PARAM_EVENT_SET_H2_K;
    m_run_event |= PROJECT_EVENT_SET_PRAMA_BIT;
}

void MainWindow::on_btn_h2_ref_set_clicked()
{
    m_param_event |= PARAM_EVENT_SET_H2_REF;
    m_run_event |= PROJECT_EVENT_SET_PRAMA_BIT;
}


void MainWindow::on_btn_voltage_calib_clear_clicked()
{
    ui->lEdit_voltage_range->clear();
    ui->lEdit_voltage_zero->clear();
}


void MainWindow::on_btn_ntc_calib_clear_clicked()
{
    ui->lEdit_ntc_temp_k->clear();
    ui->lEdit_ntc_temp_b->clear();
}


void MainWindow::on_btn_env_calib_clear_clicked()
{
    ui->lEdit_env_temp_k->clear();
    ui->lEdit_env_temp_b->clear();
    ui->lEdit_env_hum_k->clear();
    ui->lEdit_env_hum_b->clear();
}


void MainWindow::on_btn_co_calib_clear_clicked()
{
    ui->lEdit_co_k1->clear();
    ui->lEdit_co_k2->clear();
    ui->lEdit_co_k3->clear();
    ui->lEdit_co_b1->clear();
    ui->lEdit_co_b2->clear();
    ui->lEdit_co_b3->clear();

}


void MainWindow::on_btn_h2_calib_clear_clicked()
{
    ui->lEdit_h2_k1->clear();
    ui->lEdit_h2_k2->clear();
    ui->lEdit_h2_k3->clear();
    ui->lEdit_h2_b1->clear();
    ui->lEdit_h2_b2->clear();
    ui->lEdit_h2_b3->clear();
}


void MainWindow::on_btn_h2_ref_clear_clicked()
{
    QList<QLineEdit *> lineEdit = { ui->lEdit_h2_ref1_set,ui->lEdit_h2_ref2_set,ui->lEdit_h2_ref3_set,ui->lEdit_h2_ref4_set,ui->lEdit_h2_ref5_set,
                                    ui->lEdit_h2_real1_set,ui->lEdit_h2_real2_set,ui->lEdit_h2_real3_set,ui->lEdit_h2_real4_set,ui->lEdit_h2_real5_set,
                                    ui->lEdit_h2_temp1_set,ui->lEdit_h2_temp2_set,ui->lEdit_h2_temp3_set,ui->lEdit_h2_temp4_set,ui->lEdit_h2_temp5_set,
                                    ui->lEdit_h2_hum1_set,ui->lEdit_h2_hum2_set,ui->lEdit_h2_hum3_set,ui->lEdit_h2_hum4_set,ui->lEdit_h2_hum5_set,
                                    ui->lEdit_h2_k,ui->lEdit_h2_b,ui->lEdit_h2_ref_hum_set,ui->lEdit_h2_ref_temp_set};
    for(int i=0; i<lineEdit.size();i++){
        lineEdit[i]->clear();
    }
}





void MainWindow::on_btn_h2_set_start_clicked()
{
    // if( ui->btn_h2_ref_one_set->isEnabled()){
    //     ui->btn_h2_ref_one_set->setDisabled(false);
    // }
    ui->btn_h2_ref_set->setDisabled(true);
    ui->btn_h2_ref_one_set->setDisabled(false);
    autoOpenFlag = true;
    m_param_event |= PARAM_EVENT_SET_H2_AUTO_OPEN;
    m_run_event |= PROJECT_EVENT_SET_PRAMA_BIT;
}

void MainWindow::on_btn_h2_set_close_clicked()
{
    ui->btn_h2_ref_one_set->setDisabled(true);
    ui->btn_h2_ref_set->setDisabled(false);
    autoOpenFlag = false;
    m_param_event |= PARAM_EVENT_SET_H2_AUTO_OPEN;
    m_run_event |= PROJECT_EVENT_SET_PRAMA_BIT;
}

quint8 click = 0;

void MainWindow::on_btn_h2_ref_one_set_clicked()
{
    // click++;
    // click %= 5;
    // if(click == 0){
    //     ui->btn_h2_ref_one_set->setDisabled(true);
    // }

    m_param_event |= PARAM_EVENT_SET_H2_REF_ONE;
    m_run_event |= PROJECT_EVENT_SET_PRAMA_BIT;
}


void MainWindow::on_btn_h2_ref_zero_set_clicked()
{
    m_param_event |= PARAM_EVENT_SET_H2_REF_ZERO;
    m_run_event |= PROJECT_EVENT_SET_PRAMA_BIT;
}




