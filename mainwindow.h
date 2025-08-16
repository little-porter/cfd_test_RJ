#ifndef MAINWINDOW_H
#define MAINWINDOW_H



#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QElapsedTimer> // 新增：用于计时

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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void onChooseFile();
    void onOpenSerialPort();
    void onCloseSerialPort();
    void onSendData();
    void readSerialData();
    void populatePorts();

private:
    // void populatePorts();
    bool sendChunk(const QByteArray &data); // 新增：发送数据块的函数
    bool upgrade_start(const char *data,quint16 len,quint16 frm_num,ota_upgrade_flag_t flag);

private:
    Ui::MainWindow *ui;
    QSerialPort    *serialPort;
    QString selectedFilePath;
    quint16 file_crc;
    app_flag_t app_flag;
    const int maxPacketSize = 1024; // 定义最大包大小
    QElapsedTimer sendTimer;        // 发送计时器
};
#endif // MAINWINDOW_H
