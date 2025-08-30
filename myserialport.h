#ifndef MYSERIALPORT_H
#define MYSERIALPORT_H

#include <QDebug>
#include "qglobal.h"
#include <string>
#include <QThread>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>

#include <QObject>

#define MYSERIALPORT_FIFO_SIZE      100
#define MYSERIALPORT_DATA_MAXSIZE   2048


class myserialport : public QObject
{
public:
    myserialport();
    myserialport(QString portName);
    ~myserialport();
    bool myserialport_sendData(quint8 *data,quint16 data_len);
    quint16 myserialport_receiveData(quint8 *data,quint16 max_len);
private:
    typedef struct _myserialport_data{
        // _myserialport_data() {}
        quint8 data[MYSERIALPORT_DATA_MAXSIZE];
        quint16 length;
    }myserialport_data_t;

    typedef struct _myserialport_fifo{
        // _myserialport_fifo() {}
        myserialport_data_t fifo[MYSERIALPORT_FIFO_SIZE];
        quint16 pos;
        quint16 tail;
    }myserialport_fifo_t;

    myserialport_fifo_t rx_fifo;
    myserialport_fifo_t tx_fifo;

    bool m_threadStop;
    QThread *thread;
    QTimer *timer;
    // QTimer *m_idle_timer;
    QString serialName;
    QSerialPort *serialPort;

    QByteArray receiveBuffer;
private slots:
    void myserialport_send_task(void);
    void myserialport_receive_handler(void);
    void myserialport_receive_data_deal(void);
};

#endif // MYSERIALPORT_H
