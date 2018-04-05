/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPlainTextEdit *ip;
    QPlainTextEdit *port;
    QPushButton *connect;
    QPlainTextEdit *input;
    QPlainTextEdit *output;
    QPushButton *send;
    QComboBox *comboBox;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMaximumSize(QSize(400, 300));
        QFont font;
        font.setFamily(QStringLiteral("DejaVu Sans Mono"));
        font.setBold(true);
        font.setWeight(75);
        MainWindow->setFont(font);
        MainWindow->setTabletTracking(false);
        MainWindow->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        MainWindow->setDocumentMode(false);
        MainWindow->setDockNestingEnabled(false);
        MainWindow->setUnifiedTitleAndToolBarOnMac(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ip = new QPlainTextEdit(centralWidget);
        ip->setObjectName(QStringLiteral("ip"));
        ip->setGeometry(QRect(60, 10, 141, 21));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ip->sizePolicy().hasHeightForWidth());
        ip->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QStringLiteral("DejaVu Sans Mono"));
        ip->setFont(font1);
        ip->setAcceptDrops(true);
        ip->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ip->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        port = new QPlainTextEdit(centralWidget);
        port->setObjectName(QStringLiteral("port"));
        port->setGeometry(QRect(250, 10, 41, 21));
        port->setFont(font);
        port->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        port->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        connect = new QPushButton(centralWidget);
        connect->setObjectName(QStringLiteral("connect"));
        connect->setGeometry(QRect(310, 10, 80, 21));
        input = new QPlainTextEdit(centralWidget);
        input->setObjectName(QStringLiteral("input"));
        input->setGeometry(QRect(10, 40, 381, 91));
        output = new QPlainTextEdit(centralWidget);
        output->setObjectName(QStringLiteral("output"));
        output->setGeometry(QRect(10, 170, 381, 91));
        output->setReadOnly(true);
        send = new QPushButton(centralWidget);
        send->setObjectName(QStringLiteral("send"));
        send->setGeometry(QRect(310, 140, 80, 21));
        comboBox = new QComboBox(centralWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(10, 140, 271, 22));
        comboBox->setLocale(QLocale(QLocale::Russian, QLocale::Russia));
        comboBox->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 10, 16, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(210, 10, 31, 16));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setEnabled(true);
        menuBar->setGeometry(QRect(0, 0, 400, 18));
        menuBar->setNativeMenuBar(true);
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setEnabled(true);
        statusBar->setSizeGripEnabled(false);
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Client", nullptr));
#ifndef QT_NO_WHATSTHIS
        ip->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        ip->setPlainText(QApplication::translate("MainWindow", "127.0.0.1", nullptr));
        port->setPlainText(QApplication::translate("MainWindow", "1234", nullptr));
        connect->setText(QApplication::translate("MainWindow", "Connect", nullptr));
        input->setDocumentTitle(QString());
        input->setPlainText(QString());
        input->setPlaceholderText(QApplication::translate("MainWindow", "Input", nullptr));
        output->setPlainText(QString());
        output->setPlaceholderText(QApplication::translate("MainWindow", "Output", nullptr));
        send->setText(QApplication::translate("MainWindow", "Send", nullptr));
        comboBox->setItemText(0, QApplication::translate("MainWindow", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\272\320\260 \321\201\320\270\320\274\320\262\320\276\320\273\320\276\320\262 \321\202\320\265\320\272\321\201\321\202\320\260 \320\277\320\276 \321\203\320\261\321\213\320\262\320\260\320\275\320\270\321\216", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "\320\240\320\260\320\267\320\262\320\276\321\200\320\276\321\202 \321\202\320\265\320\272\321\201\321\202\320\260", nullptr));
        comboBox->setItemText(2, QApplication::translate("MainWindow", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\272\320\260 \321\201\321\202\321\200\320\276\320\272 \321\202\320\265\320\272\321\201\321\202\320\260 \320\277\320\276 \320\262\320\276\320\267\321\200\320\260\321\201\321\202\320\260\320\275\320\270\321\216", nullptr));
        comboBox->setItemText(3, QApplication::translate("MainWindow", "\320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260 \320\277\320\276 \320\270\321\201\320\277\320\276\320\273\321\214\320\267\321\203\320\265\320\274\321\213\320\274 \321\201\320\270\320\274\320\262\320\276\320\273\320\260\320\274 \320\262 \321\202\320\265\320\272\321\201\321\202\320\265", nullptr));

        label->setText(QApplication::translate("MainWindow", "IP", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Port", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
