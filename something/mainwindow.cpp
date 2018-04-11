#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new TcpSocket(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_connect_clicked()
{
    switch (connectedState)
    {
    case false:
        if (socket->doConnect(ui->ip->toPlainText(), ui->port->toPlainText()))
        {
            ui->ip->setDisabled(true);
            ui->port->setDisabled(true);
            ui->connect->setText("Disconnect");
            connectedState = true;
        }
        else
        {
            ui->connect->setText("Connect");
            connectedState = false;
        }
        break;
    case true:
        socket->doDisconnect();
        ui->ip->setDisabled(false);
        ui->port->setDisabled(false);
        ui->connect->setText("Connect");
        connectedState = false;
        break;
    }
}

void MainWindow::on_send_clicked()
{
    if (connectedState)
    {
        ui->output->setPlainText(socket->doThing(ui->input->toPlainText(), ui->comboBox->currentIndex()));
    }
}
