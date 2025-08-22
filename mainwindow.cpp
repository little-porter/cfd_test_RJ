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

    ui->progressBar->setValue(0); // 初始化进度条为0

    connect(serialPort, &QSerialPort::readyRead, this, &MainWindow::readSerialData);

    // connect(ui->portComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::populatePorts);

    connect(ui->chooseButton, &QPushButton::clicked, this, &MainWindow::onChooseFile);
    connect(ui->openButton, &QPushButton::clicked, this, &MainWindow::onOpenSerialPort);
    connect(ui->closeButton, &QPushButton::clicked, this, &MainWindow::onCloseSerialPort);
    connect(ui->downloadButton, &QPushButton::clicked, this, &MainWindow::onSendData);

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

typedef alignas(1) struct _ota_msg
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

    qint64 bytesWritten = serialPort->write((const char *)msg,size);
    serialPort->flush();
    if (bytesWritten != size) {
        return false;
    }
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


void MainWindow::onSendData()
{
    if (selectedFilePath.isEmpty()) {
        QMessageBox::warning(this, "错误", "请先选择一个文件");
        return;
    }

    if (!serialPort->isOpen()) {
        QMessageBox::warning(this, "错误", "串口未打开");
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
    }else{
        // m_run_process = RUN_PROCESS_GET_DATA;
    }
}

void MainWindow::run_process_init_handler(void)
{
    quint8 data[8] = {0},cmd = 0x03;
    quint16 crc = 0;
    quint8  read_data[100] = {0};
    while(myserial->myserialport_receiveData(read_data,sizeof(read_data)));
    data[1] = cmd;
    data[2] = 0x00;
    data[3] = 0x00;
    data[4] = 0x00;
    data[5] = 0x01;
    if(!modbusAddrList.empty()){
        modbusAddrList.clear();
    }

    for(quint8 i = 0; i<255; i++){
        data[0] = i;
        crc = modbus_calculate_crc(data,6);
        data[6] = crc&0xff;
        data[7] = crc>>8;
        myserial->myserialport_sendData(data,sizeof(data));
        delay(20);
        quint16 read_bytes = myserial->myserialport_receiveData(read_data,sizeof(read_data));
        if(read_bytes > 0){
            if(read_data[0] == i && read_data[1] == cmd && (read_data[2]<<8|read_data[3]) == 0x02){
                modbusAddrList.push_back(read_data[4]<<8|read_data[5]);
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

void MainWindow::run_process_get_info_handler(void)
{
    quint8 data[8] = {0},cmd = 0x03;
    quint16 read_reg_addr = 0x0000,read_reg_num = 0x22,crc = 0;
    quint16 read_bytes = 0;
    quint8  read_data[100] = {0};
    while(myserial->myserialport_receiveData(read_data,sizeof(read_data)));

    QString str_id = ui->cbox_modbus_addr->currentText();
    bool ok = false;
    quint8 id = (quint8)str_id.toUInt(&ok,10);
    if(ok){
        data[0] = id;
    }else{
        qDebug()<<"modbus 地址转换失败";
        return;
    }
    data[1] = cmd;
    data[2] = read_reg_addr>>8;
    data[3] = read_reg_addr&0xff;
    data[4] = read_reg_num>>8;
    data[5] = read_reg_num&0xff;
    crc = modbus_calculate_crc(data,6);
    data[6] = crc&0xff;
    data[7] = crc>>8;


    myserial->myserialport_sendData(data,sizeof(data));

    delay(200);

    read_bytes = myserial->myserialport_receiveData(read_data,sizeof(read_data));
    if(read_bytes > 0){
        if(read_data[0] == id && read_data[1] == cmd && (read_data[2]<<8|read_data[3]) == read_reg_num*2){
            ui->lEdit_modbus_addr->setText(QString::number(read_data[0]));
            ui->lEdit_capacity->setText(QString::number(read_data[6]<<8|read_data[7]));
            ui->lEdit_device_serial->setText(QString::fromUtf8((char *)&read_data[18]));
            ui->lEdit_mac->setText(QString::fromUtf8((char *)&read_data[38]));
        }else{
            qDebug()<<"info msg error";
        }
    }else{
        qDebug()<<"设备未应答";
    }

    read_reg_addr = 0x3000;
    read_reg_num = 0x000C;
    data[2] = read_reg_addr>>8;
    data[3] = read_reg_addr&0xff;
    data[4] = read_reg_num>>8;
    data[5] = read_reg_num&0xff;
    crc = modbus_calculate_crc(data,6);
    data[6] = crc&0xff;
    data[7] = crc>>8;

    myserial->myserialport_sendData(data,sizeof(data));

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
        }else{
            qDebug()<<"info msg error";
        }
    }else{
        qDebug()<<"设备未应答";
    }
}

void MainWindow::run_process_get_data_handler(void)
{
    quint8 data[8] = {0},cmd = 0x03;
    quint16 read_reg_addr = 0x1000,read_reg_num = 0x0B,crc = 0;
    quint16 read_bytes = 0;
    quint8  read_data[100] = {0};

    while(myserial->myserialport_receiveData(read_data,sizeof(read_data)));

    QString str_id = ui->cbox_modbus_addr->currentText();
    bool ok = false;
    quint8 id = (quint8)str_id.toUInt(&ok,10);
    if(ok){
        data[0] = id;
    }else{
        qDebug()<<"modbus 地址转换失败";
        return;
    }
    data[1] = cmd;
    data[2] = read_reg_addr>>8;
    data[3] = read_reg_addr&0xff;
    data[4] = read_reg_num>>8;
    data[5] = read_reg_num&0xff;
    crc = modbus_calculate_crc(data,6);
    data[6] = crc&0xff;
    data[7] = crc>>8;


    myserial->myserialport_sendData(data,sizeof(data));

    delay(100);

    read_bytes = myserial->myserialport_receiveData(read_data,sizeof(read_data));
    if(read_bytes > 0){
        if(read_data[0] == id && read_data[1] == cmd && (read_data[2]<<8|read_data[3]) == read_reg_num*2){
            ui->lEdit_voltage->setText(QString::number((read_data[4]<<8|read_data[5])*1.0/1000));
            ui->lEdit_current->setText(QString::number((read_data[6]<<8|read_data[7])*1.0/1000));
            ui->lEdit_res->setText(QString::number((read_data[8]<<8|read_data[9])*1.0/100));
            ui->lEdit_cycle->setText(QString::number(read_data[10]<<8|read_data[11]));
            ui->lEdit_cfdzt->setText(QString::number(read_data[12]<<8|read_data[13]));
            ui->lEdit_battery_temperature->setText(QString::number((read_data[14]<<8|read_data[15])*1.0/100));
            ui->lEdit_CO->setText(QString::number(read_data[16]<<8|read_data[17]));
            ui->lEdit_H2->setText(QString::number(read_data[18]<<8|read_data[19]));
            ui->lEdit_SMK->setText(QString::number(read_data[20]<<8|read_data[21]));
            ui->lEdit_env_temperature->setText(QString::number((read_data[22]<<8|read_data[23])*1.0/100));
            ui->lEdit_humidity->setText(QString::number((read_data[24]<<8|read_data[25])*1.0/100));
        }else{
            qDebug()<<"info msg error";
        }
    }else{
        qDebug()<<"设备未应答";
    }

}

void MainWindow::run_process_upgrade_handler(void)
{

}

void MainWindow::run_process_set_prama_handler(void)
{

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
    case RUN_PROCESS_GET_DATA:
        if(time_cnt%10 == 0){
            run_process_get_data_handler();
        }
        m_run_process = RUN_PROCESS_GET_DATA;
        break;
    case RUN_PROCESS_SET_PARAM:
        run_process_set_prama_handler();
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




