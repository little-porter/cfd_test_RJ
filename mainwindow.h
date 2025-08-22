#ifndef MAINWINDOW_H
#define MAINWINDOW_H



#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QElapsedTimer> // 新增：用于计时
#include "myserialport.h"
#include <QTimer>


typedef enum _ota_upgrade_flag
{
    OTA_UPGRADE_START = 0,
    OTA_UPGRADING     = 1,
    OTA_UPGRADE_STOP  = 2,
}ota_upgrade_flag_t;


typedef enum _app_flag
{
    APP_FLAG_COLLECT = 0,
    APP_FLAG_INFERENCE,
}app_flag_t;


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

#define PROJECT_EVENT_INIT_BIT      1<<0
#define PROJECT_EVENT_GET_INFO_BIT  1<<1
#define PROJECT_EVENT_UPGRADE_BIT   1<<2
#define PROJECT_EVENT_SET_PRAMA_BIT 1<<3


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void onChooseFile(void);
    void onOpenSerialPort(void);
    void onCloseSerialPort(void);
    void onSendData(void);
    void readSerialData(void);
    void populatePorts(void);

    void on_btn_getInfo_clicked(void);

    // void net_init(void);

    void on_btn_net_init_clicked();
private:
    typedef enum _run_process{
        RUN_PROCESS_INIT = 0,
        RUN_PROCESS_GET_INFO,
        RUN_PROCESS_GET_DATA,
        RUN_PROCESS_UPGRADE,
        RUN_PROCESS_SET_PARAM,
    }run_process_t;

    typedef quint32 project_event_t;
private:
    void project_event_handler(void);


private:
    // void populatePorts();
    bool sendChunk(const QByteArray &data); // 新增：发送数据块的函数
    bool upgrade_start(const char *data,quint16 len,quint16 frm_num,ota_upgrade_flag_t flag);

    void comm_timer_run_task(void);
    void run_process_init_handler(void);
    void run_process_get_info_handler(void);
    void run_process_get_data_handler(void);
    void run_process_upgrade_handler(void);
    void run_process_set_prama_handler(void);
private:
    Ui::MainWindow *ui;
    QSerialPort    *serialPort;
    QString selectedFilePath;
    quint16 file_crc;
    app_flag_t app_flag;
    const int maxPacketSize = 1024; // 定义最大包大小
    QElapsedTimer sendTimer;        // 发送计时器

    QTimer *m_comm_timer;
    myserialport *myserial;
    std::list<quint16> modbusAddrList;
    run_process_t   m_run_process;
    project_event_t m_run_event;

};
#endif // MAINWINDOW_H
