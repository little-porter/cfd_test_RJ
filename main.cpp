#include "mainwindow.h"
// #include <QDesktopWidget>
#include <QScreen>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;

    // // 获取屏幕尺寸
    // QScreen *screen = QGuiApplication::primaryScreen();
    // QRect screenGeometry = screen->geometry();
    // int height = screenGeometry.height();
    // int width = screenGeometry.width();

    // // 设置窗口为屏幕的 80%
    // w.resize(width * 0.8, height * 0.8);

    // // 居中显示
    // w.move((width - w.width()) / 2, (height - w.height()) / 2);

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);

    w.show();
    return a.exec();
}
