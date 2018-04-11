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

QString TcpSocket::doThing(QString text, int index)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly), in(socket);
    QString result;
    out << quint16(0) << text << index;

    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));

    socket->write(block);

    if (socket->waitForReadyRead(5000))
    {
        quint16 blockSize = 0;
        while(true) {
            if (blockSize == 0) {
                if (socket->bytesAvailable() < sizeof(quint16)) break;
                in >> blockSize;
            }

            if (socket->bytesAvailable() < blockSize) break;

            in >> result;
            blockSize = 0;
        }
        return result;
    }

    return nullptr;
}

