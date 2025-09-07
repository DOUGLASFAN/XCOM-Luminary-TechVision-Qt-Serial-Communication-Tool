#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QTimer>
#include <QFile>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,serial(new QSerialPort(this))  // 创建QSerialPort对象，用于串口通信
    , serialScanTimer(new QTimer(this))
    ,fileToSend(nullptr)
    , timerSend(new QTimer(this)) // 初始化定时发送的定时器
    , isSending(false)

{
    ui->setupUi(this);

    // 设置窗口标题
    setWindowTitle("光龙锐志Luminary TechVision串口通信工具");  // 直接设置标题文字

    // 设置窗口图标
    setWindowIcon(QIcon("icon.ico"));

    scanAvailableSerial();

    // 初始化定时器，设置扫描间隔为1000ms(1秒)
    serialScanTimer->setInterval(1000);
    // 启动定时器
    serialScanTimer->start();

    // 连接定时器超时信号到扫描槽函数
    connect(serialScanTimer, &QTimer::timeout, this, &MainWindow::updateSerialPorts);

    // 连接定时器的 timeout 信号到自定义槽函数(定时发送)
    connect(timerSend, &QTimer::timeout, this, &MainWindow::sendDataPeriodically);

    //当串口有数据可读时，可触发readSerialData函数
    connect(serial, &QSerialPort::readyRead, this, &MainWindow::readSerialData);

    // 连接串口错误信号到错误处理槽函数
    connect(serial, &QSerialPort::errorOccurred, this, &MainWindow::handleSerialError);

}

void MainWindow::scanAvailableSerial()
{
    // 获取所有可用串口信息列表
    QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();

    // 遍历所有串口，将串口名称添加到下拉列表(comboBoxPort)
    for(const QSerialPortInfo &portInfo : ports){

        // 如果下拉列表中没有这个串口，则添加
        if(ui->comboBoxPort->findText(portInfo.portName()) == -1){
            ui->comboBoxPort->addItem(portInfo.portName());//设备信息映射到组件中
        }

    }

}

MainWindow::~MainWindow()
{
    // 清理文件资源
    if (fileToSend && fileToSend->isOpen()) {
        fileToSend->close();
        delete fileToSend;
    }
    delete ui;
}

void MainWindow::updateSerialPorts(){
    // 记录当前选中的串口（避免清空后丢失选择状态）
    QString currentSelected = ui->comboBoxPort->currentText();

    // 清空下拉列表中的所有选项
    ui->comboBoxPort->clear();

    // 重新扫描并添加所有可用串口
    scanAvailableSerial();

    // 尝试恢复之前的选中状态（如果该串口仍存在）
    int index = ui->comboBoxPort->findText(currentSelected);
    if(index != -1){
        ui->comboBoxPort->setCurrentIndex(index);
    }
    // 如果当前有打开的串口，且被意外移除，需要处理
    else if(serial->isOpen()){
        serial->close();
        ui->pushButton->setText("打开串口");
        ui->label_2->setText(QString("串口 %1 已断开连接").arg(currentSelected));
    }
}


void MainWindow::handleSerialError(QSerialPort::SerialPortError error)
{


    if(error != QSerialPort::NoError){
        QMessageBox::warning(this,"串口错误","发生错误："+serial->errorString());

        // 如果是资源错误（如串口被拔出）
        if(error == QSerialPort::ResourceError){
            if(serial->isOpen()){
                serial->close();
            }

            ui->pushButton->setText("打开串口");
            ui->comboBoxPort->setEnabled(true);

            ui->textEditSend->setEnabled(false);

            ui->pushButtonSend->setEnabled(false);

            ui->comboBoxBaudrate->setEnabled(false);

            ui->comboBoxParity->setEnabled(false);

            ui->comboBoxDataBits->setEnabled(false);

            ui->comboBoxStopBits->setEnabled(false);

        }
    }
}


void MainWindow::readSerialData(){
    // 检查串口是否打开且有数据可读取
    if(serial->isOpen() && serial->bytesAvailable()){
        QByteArray data =  serial->readAll();
        qDebug() << data;
        ui->textBrowser->append(data);
    }
}


void MainWindow::on_pushButton_clicked()
{
    // 获取当前选择的串口名称
    QString portName = ui->comboBoxPort->currentText();

    if(serial->isOpen()){
        serial->close();

        // 显示关闭信息，包含串口名称
        ui->label_2->setText(QString("已经关闭串口 %1").arg(portName));

        ui->textEditSend->setEnabled(false);

        ui->pushButtonSend->setEnabled(false);

        ui->comboBoxBaudrate->setEnabled(false);

        ui->comboBoxParity->setEnabled(false);

        ui->comboBoxDataBits->setEnabled(false);

        ui->comboBoxStopBits->setEnabled(false);


        ui->pushButton->setText("打开串口");

        ui->comboBoxPort->setEnabled(true);
    }else{
        //打开串口
        serial->setPortName(ui->comboBoxPort->currentText());

        //设置比特率
        serial->setBaudRate(ui->comboBoxBaudrate->currentText().toInt());

        //设置停止位
        if(ui->comboBoxStopBits->currentText() == "1"){
            serial->setStopBits(QSerialPort::OneStop);
        }else if(ui->comboBoxStopBits->currentText() == "1.5"){
            serial->setStopBits(QSerialPort::OneAndHalfStop);
        }else if(ui->comboBoxStopBits->currentText() == "2"){
            serial->setStopBits(QSerialPort::TwoStop);
        }else{
            serial->setStopBits(QSerialPort::OneStop);
        }

        //设置数据位
        switch (ui->comboBoxDataBits->currentText().toInt()){
        case 5:
            serial->setDataBits(QSerialPort::Data5);
            break;
        case 6:
            serial->setDataBits(QSerialPort::Data6);
            break;
        case 7:
            serial->setDataBits(QSerialPort::Data7);
            break;
        case 8:
            serial->setDataBits(QSerialPort::Data8);
            break;
        default :
            serial->setDataBits(QSerialPort::Data8);
        }

        //设置奇偶校验
        if(ui->comboBoxParity->currentText() == "无"){
            serial->setParity(QSerialPort::NoParity);
        }else if(ui->comboBoxParity->currentText() == "奇校验"){
            serial->setParity(QSerialPort::EvenParity);
        }else if(ui->comboBoxParity->currentText() == "偶校验"){
            serial->setParity(QSerialPort::OddParity);
        }else{
            serial->setParity(QSerialPort::NoParity);
        }


        if(serial->open(QIODevice::ReadWrite)){// 尝试以读写方式打开串口

            // 显示关闭信息，包含串口名称
            ui->label_2->setText(QString("已经打开串口 %1").arg(portName));

            ui->comboBoxPort->setEnabled(false);

            ui->comboBoxBaudrate->setEnabled(true);

            ui->comboBoxParity->setEnabled(true);

            ui->comboBoxDataBits->setEnabled(true);

            ui->comboBoxStopBits->setEnabled(true);

            ui->pushButton->setText("关闭串口");

            ui->textEditSend->setEnabled(true);

            ui->pushButtonSend->setEnabled(true);

            qDebug() << serial->isOpen() ; // 输出调试信息，显示串口是否已打开
        }else{
            QMessageBox::information(this,"提示","串口打开失败"); // 打开失败，显示提示对话框
        }


    }


}


void MainWindow::on_pushButtonSend_clicked()
{
    if(serial->isOpen()){
        QString text = ui->textEditSend->toPlainText() + "\r\n";
        QByteArray data = text.toUtf8();
        qint64 length = serial->write(data);

        if(length == -1){
            QMessageBox::warning(this,"错误提示","串口数据发送失败");
        }else if(length != data.size()){
            QMessageBox::warning(this,"错误提示","串口发送数据部分丢失");
        }

    }else{
        QMessageBox::warning(this,"错误提示","串口未打开");
    }

}



void MainWindow::on_pushButtonClean_clicked()
{
    ui->textBrowser->clear();
}


void MainWindow::on_radioButtonTimeSend_clicked()
{
    // 检查串口是否打开
    if (!serial->isOpen()) {
        QMessageBox::information(this, "提示", "请先打开串口");
        ui->radioButtonTimeSend->setChecked(false);  // 强制取消选中
        return;
    }


    // 检查定时周期输入是否有效
    bool ok;
    int period = ui->lineEditTime->text().toInt(&ok);
    if (!ok || period <= 0) {
        QMessageBox::warning(this, "输入错误", "请输入有效的发送周期（正整数毫秒）");
        ui->radioButtonTimeSend->setChecked(false);  // 强制取消选中
        return;
    }



    // 根据单选按钮状态控制定时器
    if (ui->radioButtonTimeSend->isChecked()) {
        // 开启定时发送
        timerSend->setInterval(period);  // 设置周期
        timerSend->start();              // 启动定时器
        ui->lineEditTime->setEnabled(false);  // 禁用周期编辑（避免运行中修改）
        QMessageBox::information(this, "提示", "已开启定时发送，周期：" + QString::number(period) + "ms");
    } else {
        // 关闭定时发送
        timerSend->stop();               // 停止定时器
        ui->lineEditTime->setEnabled(true);   // 启用周期编辑
    }
}

// 定时发送的实际执行函数（定时器触发时调用）
void MainWindow::sendDataPeriodically()
{
    if (!serial->isOpen()) return;  // 确保串口已打开

    QString text = ui->textEditSend->toPlainText() + "\r\n";  // 添加换行符
    QByteArray data = text.toUtf8();
    qint64 length = serial->write(data);

    // 发送错误处理
    if (length == -1) {
        QMessageBox::warning(this, "错误", "发送失败：" + serial->errorString());
        timerSend->stop();  // 发送失败时停止定时器
        ui->radioButtonTimeSend->setChecked(false);  // 取消选中状态
    } else if (length != data.size()) {
        QMessageBox::warning(this, "警告", "数据部分丢失，仅发送了" + QString::number(length) + "字节");
    }
}

void MainWindow::on_pushButtonOpenFile_clicked()
{
    // 弹出文件选择对话框
    QString filePath = QFileDialog::getOpenFileName(
        this,
        "选择文件",
        QDir::homePath(),
        "所有文件 (*.*);;文本文件 (*.txt);;二进制文件 (*.bin)"
        );

    if (filePath.isEmpty()) {
        return; // 用户取消选择
    }

    //显示选中的文件路径
    ui->lineEditFilePath->setText(filePath);


    // 初始化待发送文件
    if (fileToSend) {
        if (fileToSend->isOpen()) {
            fileToSend->close();
        }
        delete fileToSend;
    }
    fileToSend = new QFile(filePath);

    // 尝试打开文件（只读、二进制模式）
    if (!fileToSend->open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "错误", "无法打开文件：" + fileToSend->errorString());
        delete fileToSend;
        fileToSend = nullptr;
        return;
    }


    // 启用“发送文件”按钮
    ui->pushButtonSendFile->setEnabled(true);


}


void MainWindow::on_pushButtonSendFile_clicked()
{
    // 检查串口是否打开
    if (!serial->isOpen()) {
        QMessageBox::warning(this, "错误", "请先打开串口");
        return;
    }

    // 检查文件是否有效
    if (!fileToSend || !fileToSend->isOpen()) {
        QMessageBox::warning(this, "错误", "未选择有效文件或文件未打开");
        return;
    }

    // 读取文件所有内容（注意：大文件可能占用大量内存）
    QByteArray fileData = fileToSend->readAll();
    if (fileData.isEmpty()) {
        QMessageBox::information(this, "提示", "文件为空或读取失败");
        fileToSend->close();
        return;
    }

    // 重置文件指针到开头
    fileToSend->seek(0);
    isSending = true;

    // 更新UI状态
    ui->pushButtonOpenFile->setEnabled(false);
    ui->pushButtonSendFile->setEnabled(false);
    ui->pushButtonStopSendFile->setEnabled(true);

    // 启动分块发送（在单独的循环中执行，避免阻塞UI）
    QByteArray block;
    qint64 totalSent = 0;
    const qint64 fileSize = fileToSend->size();

    while (isSending && !fileToSend->atEnd()) {
        // 读取一块数据
        block = fileToSend->read(BLOCK_SIZE);
        if (block.isEmpty()) break;

        // 发送数据
        qint64 sent = serial->write(block);
        if (sent == -1) {
            QMessageBox::warning(this, "错误", "发送失败：" + serial->errorString());
            isSending = false;
            break;
        }

        // 等待数据发送完成（超时3秒）
        if (!serial->waitForBytesWritten(3000)) {
            QMessageBox::warning(this, "警告", "发送超时");
            isSending = false;
            break;
        }

        totalSent += sent;

        // 更新进度条
        int progress = static_cast<int>((totalSent * 100) / fileSize);
        ui->progressBar->setValue(progress);

        // 处理UI事件，避免界面卡死
        QApplication::processEvents();
    }



    // 发送结束处理
    fileToSend->close();
    isSending = false;

    // 恢复UI状态
    ui->pushButtonOpenFile->setEnabled(true);
    ui->pushButtonSendFile->setEnabled(false);
    ui->pushButtonStopSendFile->setEnabled(false);
    ui->lineEditFilePath->clear();


    // 显示结果
    if (totalSent == fileSize) {
        QMessageBox::information(this, "完成", QString("发送成功，共%1字节").arg(totalSent));
    } else if (totalSent > 0) {
        QMessageBox::information(this, "中断", QString("发送中断，已发送%1字节").arg(totalSent));
    }


}


void MainWindow::on_pushButtonStopSendFile_clicked()
{
    if (isSending) {
        isSending = false;  // 通过标志位中断发送循环
        QMessageBox::information(this, "提示", "正在停止发送...");
    }
}

