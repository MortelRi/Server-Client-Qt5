#include "tcpsocket.h"

TcpSocket::TcpSocket(QObject *parent)
{
    socket = new QTcpSocket(this);
}

TcpSocket::~TcpSocket()
{
    socket->close();
}

bool TcpSocket::doConnect(QString ip, QString port)
{
    socket->connectToHost(ip, port.toUInt());

    if(socket->waitForConnected(5000))
    {
        return true;
    }

    return false;
}

void TcpSocket::doDisconnect()
{
    socket->disconnectFromHost();
}

QString TcpSocket::doThing(const char* text, const char* index)
{
    socket->write(text);
    socket->write(index);

    if (socket->waitForReadyRead(5000))
    {
        return socket->readAll();
    }

    return nullptr;
}

