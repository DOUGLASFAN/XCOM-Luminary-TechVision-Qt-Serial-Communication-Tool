/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QTextBrowser *textBrowser;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *comboBoxPort;
    QLabel *label_3;
    QComboBox *comboBoxBaudrate;
    QLabel *label_4;
    QComboBox *comboBoxStopBits;
    QLabel *label_5;
    QComboBox *comboBoxDataBits;
    QLabel *label_6;
    QComboBox *comboBoxParity;
    QPushButton *pushButton;
    QLabel *label_7;
    QLabel *label_2;
    QPushButton *pushButtonClean;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *textEditSend;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButtonSend;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButtonTimeSend;
    QLabel *label_8;
    QLineEdit *lineEditTime;
    QLabel *label_9;
    QLineEdit *lineEditFilePath;
    QPushButton *pushButtonOpenFile;
    QPushButton *pushButtonSendFile;
    QPushButton *pushButtonStopSendFile;
    QProgressBar *progressBar;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(679, 437);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(30, 20, 641, 381));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        textBrowser = new QTextBrowser(verticalLayoutWidget);
        textBrowser->setObjectName("textBrowser");

        horizontalLayout->addWidget(textBrowser);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        formLayout->setHorizontalSpacing(4);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        comboBoxPort = new QComboBox(verticalLayoutWidget);
        comboBoxPort->setObjectName("comboBoxPort");

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBoxPort);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        comboBoxBaudrate = new QComboBox(verticalLayoutWidget);
        comboBoxBaudrate->addItem(QString());
        comboBoxBaudrate->addItem(QString());
        comboBoxBaudrate->addItem(QString());
        comboBoxBaudrate->addItem(QString());
        comboBoxBaudrate->setObjectName("comboBoxBaudrate");
        comboBoxBaudrate->setEnabled(false);

        formLayout->setWidget(1, QFormLayout::FieldRole, comboBoxBaudrate);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName("label_4");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        comboBoxStopBits = new QComboBox(verticalLayoutWidget);
        comboBoxStopBits->addItem(QString());
        comboBoxStopBits->addItem(QString());
        comboBoxStopBits->addItem(QString());
        comboBoxStopBits->setObjectName("comboBoxStopBits");
        comboBoxStopBits->setEnabled(false);

        formLayout->setWidget(2, QFormLayout::FieldRole, comboBoxStopBits);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName("label_5");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_5);

        comboBoxDataBits = new QComboBox(verticalLayoutWidget);
        comboBoxDataBits->addItem(QString());
        comboBoxDataBits->addItem(QString());
        comboBoxDataBits->addItem(QString());
        comboBoxDataBits->addItem(QString());
        comboBoxDataBits->setObjectName("comboBoxDataBits");
        comboBoxDataBits->setEnabled(false);

        formLayout->setWidget(3, QFormLayout::FieldRole, comboBoxDataBits);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName("label_6");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_6);

        comboBoxParity = new QComboBox(verticalLayoutWidget);
        comboBoxParity->addItem(QString());
        comboBoxParity->addItem(QString());
        comboBoxParity->addItem(QString());
        comboBoxParity->setObjectName("comboBoxParity");
        comboBoxParity->setEnabled(false);

        formLayout->setWidget(4, QFormLayout::FieldRole, comboBoxParity);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setCursor(QCursor(Qt::CursorShape::OpenHandCursor));

        formLayout->setWidget(5, QFormLayout::FieldRole, pushButton);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName("label_7");

        formLayout->setWidget(7, QFormLayout::LabelRole, label_7);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(7, QFormLayout::FieldRole, label_2);

        pushButtonClean = new QPushButton(verticalLayoutWidget);
        pushButtonClean->setObjectName("pushButtonClean");

        formLayout->setWidget(6, QFormLayout::FieldRole, pushButtonClean);

        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName("label_10");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_10);


        horizontalLayout->addLayout(formLayout);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        textEditSend = new QTextEdit(verticalLayoutWidget);
        textEditSend->setObjectName("textEditSend");
        textEditSend->setEnabled(false);

        horizontalLayout_2->addWidget(textEditSend);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        pushButtonSend = new QPushButton(verticalLayoutWidget);
        pushButtonSend->setObjectName("pushButtonSend");
        pushButtonSend->setEnabled(false);

        verticalLayout_3->addWidget(pushButtonSend);


        horizontalLayout_2->addLayout(verticalLayout_3);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        radioButtonTimeSend = new QRadioButton(verticalLayoutWidget);
        radioButtonTimeSend->setObjectName("radioButtonTimeSend");

        horizontalLayout_3->addWidget(radioButtonTimeSend);

        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName("label_8");

        horizontalLayout_3->addWidget(label_8);

        lineEditTime = new QLineEdit(verticalLayoutWidget);
        lineEditTime->setObjectName("lineEditTime");
        lineEditTime->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_3->addWidget(lineEditTime);

        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName("label_9");

        horizontalLayout_3->addWidget(label_9);

        lineEditFilePath = new QLineEdit(verticalLayoutWidget);
        lineEditFilePath->setObjectName("lineEditFilePath");

        horizontalLayout_3->addWidget(lineEditFilePath);

        pushButtonOpenFile = new QPushButton(verticalLayoutWidget);
        pushButtonOpenFile->setObjectName("pushButtonOpenFile");

        horizontalLayout_3->addWidget(pushButtonOpenFile);

        pushButtonSendFile = new QPushButton(verticalLayoutWidget);
        pushButtonSendFile->setObjectName("pushButtonSendFile");
        pushButtonSendFile->setEnabled(false);

        horizontalLayout_3->addWidget(pushButtonSendFile);

        pushButtonStopSendFile = new QPushButton(verticalLayoutWidget);
        pushButtonStopSendFile->setObjectName("pushButtonStopSendFile");
        pushButtonStopSendFile->setEnabled(false);

        horizontalLayout_3->addWidget(pushButtonStopSendFile);

        horizontalLayout_3->setStretch(0, 5);
        horizontalLayout_3->setStretch(1, 2);
        horizontalLayout_3->setStretch(2, 2);
        horizontalLayout_3->setStretch(3, 2);
        horizontalLayout_3->setStretch(4, 10);
        horizontalLayout_3->setStretch(5, 5);
        horizontalLayout_3->setStretch(6, 5);
        horizontalLayout_3->setStretch(7, 5);

        verticalLayout->addLayout(horizontalLayout_3);

        progressBar = new QProgressBar(verticalLayoutWidget);
        progressBar->setObjectName("progressBar");
        progressBar->setEnabled(true);
        progressBar->setValue(0);

        verticalLayout->addWidget(progressBar);

        verticalLayout->setStretch(0, 9);
        verticalLayout->setStretch(1, 9);
        verticalLayout->setStretch(2, 1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 679, 18));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\351\200\211\346\213\251\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207:", nullptr));
        comboBoxBaudrate->setItemText(0, QCoreApplication::translate("MainWindow", "9600", nullptr));
        comboBoxBaudrate->setItemText(1, QCoreApplication::translate("MainWindow", "19200", nullptr));
        comboBoxBaudrate->setItemText(2, QCoreApplication::translate("MainWindow", "38400", nullptr));
        comboBoxBaudrate->setItemText(3, QCoreApplication::translate("MainWindow", "115200", nullptr));

        label_4->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215:", nullptr));
        comboBoxStopBits->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        comboBoxStopBits->setItemText(1, QCoreApplication::translate("MainWindow", "1.5", nullptr));
        comboBoxStopBits->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));

        label_5->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215:", nullptr));
        comboBoxDataBits->setItemText(0, QCoreApplication::translate("MainWindow", "5", nullptr));
        comboBoxDataBits->setItemText(1, QCoreApplication::translate("MainWindow", "6", nullptr));
        comboBoxDataBits->setItemText(2, QCoreApplication::translate("MainWindow", "7", nullptr));
        comboBoxDataBits->setItemText(3, QCoreApplication::translate("MainWindow", "8", nullptr));

        comboBoxDataBits->setCurrentText(QCoreApplication::translate("MainWindow", "8", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\345\245\207\345\201\266\346\240\241\351\252\214:", nullptr));
        comboBoxParity->setItemText(0, QCoreApplication::translate("MainWindow", "\346\227\240", nullptr));
        comboBoxParity->setItemText(1, QCoreApplication::translate("MainWindow", "\345\245\207\346\240\241\351\252\214", nullptr));
        comboBoxParity->setItemText(2, QCoreApplication::translate("MainWindow", "\345\201\266\346\240\241\351\252\214", nullptr));

        pushButton->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\347\212\266\346\200\201\357\274\232", nullptr));
        label_2->setText(QString());
        pushButtonClean->setText(QCoreApplication::translate("MainWindow", "\346\270\205\351\231\244\346\216\245\346\224\266", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\346\223\215\344\275\234:", nullptr));
        pushButtonSend->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        radioButtonTimeSend->setText(QCoreApplication::translate("MainWindow", "\345\256\232\346\227\266\345\217\221\351\200\201", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\345\221\250\346\234\237\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "ms", nullptr));
        pushButtonOpenFile->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        pushButtonSendFile->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\346\226\207\344\273\266", nullptr));
        pushButtonStopSendFile->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
