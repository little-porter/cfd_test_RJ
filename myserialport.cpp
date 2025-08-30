#include "myserialport.h"

myserialport::myserialport()
{
    QString portName = "COM1";
    qint32 baudRate = 115200;

    serialPort->setPortName(portName);
    serialPort->setBaudRate(baudRate);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    if (serialPort->open(QIODevice::ReadWrite)) {
        qDebug()<<"串口 COM1打开成功！";
    } else {
        qDebug()<<"串口 COM1打开失败";
    }

}

myserialport::myserialport(QString portName)
{
    serialName = portName;
    QString COMName = portName;
    qint32 baudRate = 115200;
    serialPort = new QSerialPort(this);
    thread = new QThread(this);
    serialPort->setPortName(COMName);
    serialPort->setBaudRate(baudRate);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    if (serialPort->open(QIODevice::ReadWrite)) {
        qDebug()<<"串口 "<<serialName<<"打开成功！";
    } else {
        qDebug()<<"串口 "<<serialName<<"打开失败";
    }

    // 2. 启动定时发送
    timer = new QTimer(this);
    timer->setInterval(10);
    connect(timer, &QTimer::timeout, this, &myserialport::myserialport_send_task);
    timer->start();
    // m_idle_timer = new QTimer(this);
    // m_idle_timer->setSingleShot(true); // 单次触发
    // m_idle_timer->setInterval(3);
    // connect(m_idle_timer, &QTimer::timeout, this, &myserialport::myserialport_receive_data_deal);
    // m_idle_timer->start();
    // this->moveToThread(thread);
    // connect(thread,&QThread::started,this,&myserialport::myserialport_send_task);
    connect(serialPort, &QSerialPort::readyRead, this, &myserialport::myserialport_receive_handler);

    // thread->start();  // 触发 started 信号
    memset(&rx_fifo,0,sizeof(rx_fifo));
    memset(&tx_fifo,0,sizeof(tx_fifo));
    m_threadStop = true;
}

myserialport::~myserialport()
{
    if(serialPort->isOpen()){
        serialPort->close();
    }
    if(thread->isRunning()){
        m_threadStop = false;
    }
    if(timer->isActive()){
        timer->stop();
    }

    delete serialPort;
    serialPort = nullptr;
    delete thread;
    thread = nullptr;
    delete timer;
    timer = nullptr;
}


bool myserialport::myserialport_sendData(quint8 *data,quint16 data_len)
{
    quint16 copy_size = 0;
    if(data_len > MYSERIALPORT_DATA_MAXSIZE){
        copy_size = MYSERIALPORT_DATA_MAXSIZE;
    }else{
        copy_size = data_len;
    }

    memcpy(tx_fifo.fifo[tx_fifo.tail].data,data,copy_size);
    tx_fifo.fifo[tx_fifo.tail].length = copy_size;

    tx_fifo.tail++;
    tx_fifo.tail %= MYSERIALPORT_FIFO_SIZE;

    return true;
}

quint16 myserialport::myserialport_receiveData(quint8 *data,quint16 max_len)
{
    quint16 read_size = 0;
    if(rx_fifo.pos == rx_fifo.tail){        //缓存无数据
        return read_size;
    }

    if(rx_fifo.fifo[rx_fifo.pos].length > max_len){
        read_size = max_len;
    }else{
        read_size = rx_fifo.fifo[rx_fifo.pos].length;
    }

    memcpy(data,rx_fifo.fifo[rx_fifo.pos].data,read_size);
    rx_fifo.pos++;
    rx_fifo.pos %= MYSERIALPORT_FIFO_SIZE;

    return read_size;
}


void myserialport::myserialport_send_task(void)
{
    // while(m_threadStop){
        // if(serialPort->isOpen()){
        //     qDebug() << "🔴 收到数据！线程ID：" << QThread::currentThreadId();
        //     qDebug() << "串口对象线程：" << serialPort->thread();
        // }
        if(tx_fifo.pos != tx_fifo.tail){
            qint64 bytesWritten = serialPort->write((const char *)(tx_fifo.fifo[tx_fifo.pos].data), \
                                                    (qint64)tx_fifo.fifo[tx_fifo.pos].length);
            if(bytesWritten != tx_fifo.fifo[tx_fifo.pos].length){
                qDebug() << "serialPort:" << serialName << "send data fail!";
            }
            serialPort->flush();
            tx_fifo.pos++;
            tx_fifo.pos %= MYSERIALPORT_FIFO_SIZE;
            // QThread::msleep(100);
        }
        // else{
        //     // QThread::msleep(20);
        // }
    // }
    // emit finished();  // 通知线程退出
}


void myserialport::myserialport_receive_handler(void)
{
    if(!serialPort->bytesAvailable()) return;

    QByteArray data = serialPort->readAll();

    receiveBuffer.append(data);
    // m_idle_timer->start();
    if (receiveBuffer.isEmpty() || receiveBuffer.length() < 4) {
        // 理论上不应该发生，但安全起见
        return;
    }
    if(receiveBuffer[1] == 0x03 || receiveBuffer[1] == 0x04){
        if(receiveBuffer.length() < (receiveBuffer[2]<<8|receiveBuffer[3] + 6)){
            // m_idle_timer->start();
            return;
        }
    }


    quint16 read_size = 0;
    if(receiveBuffer.length() > MYSERIALPORT_DATA_MAXSIZE){
        read_size = MYSERIALPORT_DATA_MAXSIZE;
    }else{
        read_size = receiveBuffer.length();
    }

    memcpy(rx_fifo.fifo[rx_fifo.tail].data,receiveBuffer.data(),read_size);
    rx_fifo.fifo[rx_fifo.tail].length = read_size;
    rx_fifo.tail++;
    rx_fifo.tail %= MYSERIALPORT_FIFO_SIZE;

    receiveBuffer.clear();
}

// void myserialport::myserialport_receive_data_deal(void)
// {
//     // m_idle_timer->stop();
//     if (receiveBuffer.isEmpty()) {
//         // 理论上不应该发生，但安全起见
//         return;
//     }
//     if(receiveBuffer.length() < (receiveBuffer[2]<<8|receiveBuffer[3])){
//         // m_idle_timer->start();
//         return;
//     }


//     quint16 read_size = 0;
//     if(receiveBuffer.length() > MYSERIALPORT_DATA_MAXSIZE){
//         read_size = MYSERIALPORT_DATA_MAXSIZE;
//     }else{
//         read_size = receiveBuffer.length();
//     }

//     memcpy(rx_fifo.fifo[rx_fifo.tail].data,receiveBuffer.data(),read_size);
//     rx_fifo.fifo[rx_fifo.tail].length = read_size;
//     rx_fifo.tail++;
//     rx_fifo.tail %= MYSERIALPORT_FIFO_SIZE;

//     receiveBuffer.clear();
// }
