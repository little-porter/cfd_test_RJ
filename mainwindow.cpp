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

    ui->progressBar->setValue(0); // 初始化进度条为0

    connect(serialPort, &QSerialPort::readyRead, this, &MainWindow::readSerialData);

    // connect(ui->portComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::populatePorts);

    connect(ui->chooseButton, &QPushButton::clicked, this, &MainWindow::onChooseFile);
    connect(ui->openButton, &QPushButton::clicked, this, &MainWindow::onOpenSerialPort);
    connect(ui->closeButton, &QPushButton::clicked, this, &MainWindow::onCloseSerialPort);
    connect(ui->downloadButton, &QPushButton::clicked, this, &MainWindow::onSendData);
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
    QString portName = ui->portComboBox->currentText();
    qint32 baudRate = 115200;

    serialPort->setPortName(portName);
    serialPort->setBaudRate(baudRate);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    if (serialPort->open(QIODevice::ReadWrite)) {
        ui->statusLabel->setText("串口已打开");
    } else {
        ui->statusLabel->setText("串口打开失败");
    }
}

void MainWindow::onCloseSerialPort()
{
    if (serialPort->isOpen()) {
        serialPort->close();
        ui->statusLabel->setText("串口已关闭");
    }
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
