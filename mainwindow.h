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
#define PROJECT_EVENT_GET_PRAMA_BIT 1<<4

#define PARAM_EVENT_SET_ALARM_THRESHOLD 1<<0
#define PARAM_EVENT_SET_SERIAL          1<<1
#define PARAM_EVENT_SET_TIME            1<<2
#define PARAM_EVENT_SET_CURRENT         1<<3
#define PARAM_EVENT_SET_CAPACITY        1<<4

#define PARAM_EVENT_SET_BALANCE         1<<5
#define PARAM_EVENT_SET_VOLTAGE_CALIB   1<<6
#define PARAM_EVENT_SET_NTC_CALIB       1<<7
#define PARAM_EVENT_SET_ENV_CALIB       1<<8
#define PARAM_EVENT_SET_CO_CALIB        1<<9
#define PARAM_EVENT_SET_H2_CALIB        1<<10
#define PARAM_EVENT_SET_H2_K            1<<11
#define PARAM_EVENT_SET_H2_REF          1<<12
#define PARAM_EVENT_SET_H2_REF_ONE      1<<13
#define PARAM_EVENT_SET_H2_REF_ZERO     1<<15
#define PARAM_EVENT_SET_H2_AUTO_OPEN    1<<16


#define PARAM_EVENT_GET_VOLTAGE_CALIB   1<<0
#define PARAM_EVENT_GET_NTC_CALIB       1<<1
#define PARAM_EVENT_GET_ENV_CALIB       1<<2
#define PARAM_EVENT_GET_CO_CALIB        1<<3
#define PARAM_EVENT_GET_H2_CALIB        1<<4
#define PARAM_EVENT_GET_H2_REF          1<<5

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

    void readSerialData(void);
    void populatePorts(void);

    void on_btn_getInfo_clicked(void);

    // void net_init(void);

    void on_btn_net_init_clicked();
    void on_downloadButton_clicked();

    void on_btn_threshold_set_clicked();

    void on_btn_serial_set_clicked();

    void on_btn_time_set_clicked();

    void on_btn_capacity_set_clicked();

    void on_btn_current_set_clicked();

    void on_btn_balanced_clicked();

    void on_btn_voltage_calib_set_clicked();

    void on_btn_voltage_calib_get_clicked();

    void on_btn_co_calib_set_clicked();

    void on_btn_h2_calib_set_clicked();

    void on_btn_co_calib_get_clicked();

    void on_btn_ntc_calib_get_clicked();

    void on_btn_env_calib_get_clicked();

    void on_btn_h2_calib_get_clicked();

    void on_btn_ntc_calib_set_clicked();

    void on_btn_env_calib_set_clicked();

    void on_btn_voltage_calib_clear_clicked();

    void on_btn_ntc_calib_clear_clicked();

    void on_btn_env_calib_clear_clicked();

    void on_btn_co_calib_clear_clicked();

    void on_btn_h2_calib_clear_clicked();

    void on_btn_h2_k_set_clicked();

    void on_btn_h2_ref_set_clicked();

    void on_btn_h2_ref_clear_clicked();

    void on_btn_h2_ref_get_clicked();

    void on_btn_h2_set_start_clicked();

    void on_btn_h2_ref_one_set_clicked();

    void on_btn_h2_ref_zero_set_clicked();

    void on_btn_h2_set_close_clicked();

private:
    typedef enum _run_process{
        RUN_PROCESS_INIT = 0,
        RUN_PROCESS_GET_INFO,
        RUN_PROCESS_GET_DATA,
        RUN_PROCESS_UPGRADE,
        RUN_PROCESS_SET_PARAM,
        RUN_PROCESS_GET_PARAM,
    }run_process_t;

    typedef quint32 project_event_t;

    typedef union _u8_float
    {
        float f_data;
        quint8 u8_data[4];
    }u8_float_t;
private:
    void project_event_handler(void);

    void upgrade_handler(void);
private:
    // void populatePorts();
    bool sendChunk(const QByteArray &data); // 新增：发送数据块的函数
    bool upgrade_start(const char *data,quint16 len,quint16 frm_num,ota_upgrade_flag_t flag);

    void device_config_info_get(void);
    void device_version_mac_info_get(void);

    void comm_timer_run_task(void);
    void run_process_init_handler(void);
    void run_process_get_info_handler(void);
    void run_process_get_result_handler(void);
    void run_process_get_data_handler(void);
    void run_process_upgrade_handler(void);
    void run_process_set_param_handler(void);
    void run_process_get_param_handler(void);

    void device_alarm_threshold_set(void);
    void device_serial_set(void);
    void device_time_set(void);
    void device_capacity_set(void);
    void device_current_set(void);
    void device_balance_set(void);

    void device_voltage_calibration_set(void);
    void device_ntc_calibration_set(void);
    void device_env_calibration_set(void);
    void device_co_calibration_set(void);
    void device_h2_calibration_set(void);
    void device_h2_map_set(void);
    void device_h2_K_set(void);
    void device_h2_ref_one_set(void);
    void device_h2_ref_zero_set(void);
    void device_h2_ref_auto_open_set(bool status);

    void device_voltage_calibration_get(void);
    void device_ntc_calibration_get(void);
    void device_env_calibration_get(void);
    void device_co_calibration_get(void);
    void device_h2_calibration_get(void);

    void device_h2_ref_get(void);

    quint8 device_id_get(void);
    bool device_reg_data_read(quint16 reg_addr,quint16 reg_num,quint8 cmd,quint8 id);
    bool device_reg_data_write(quint16 reg_addr,quint16 reg_num,quint8 cmd,quint8 *payload);
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
    project_event_t m_param_event;
    project_event_t m_get_param_event;

    bool autoOpenFlag;
    quint8 m_balance_flag;
};
#endif // MAINWINDOW_H
