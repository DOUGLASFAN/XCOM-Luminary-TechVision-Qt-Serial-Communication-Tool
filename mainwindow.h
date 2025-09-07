#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTimer>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
// 如果需要使用端口信息相关功能

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
    void on_pushButton_clicked();
    void readSerialData();
    void handleSerialError(QSerialPort::SerialPortError error);

    void on_pushButtonSend_clicked();
    void updateSerialPorts();
    void on_pushButtonClean_clicked();

    void on_radioButtonTimeSend_clicked();
    void sendDataPeriodically();

    void on_pushButtonOpenFile_clicked();

    void on_pushButtonSendFile_clicked();

    void on_pushButtonStopSendFile_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort *serial; //串口对象指针
    void scanAvailableSerial();//定义扫描串口函数

    QTimer *serialScanTimer;  // 串口扫描定时器
    QFile *fileToSend;         // 待发送的文件
    QTimer *timerSend;
    bool isSending;           // 发送状态标志
    const qint64 BLOCK_SIZE = 4096;  // 每次发送的块大小

};
#endif // MAINWINDOW_H
