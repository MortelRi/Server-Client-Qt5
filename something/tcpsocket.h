#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QDataStream>

class TcpSocket : public QObject
{
    Q_OBJECT
public:
    explicit TcpSocket(QObject *parent = 0);
    ~TcpSocket();
    bool doConnect(QString ip, QString port);
    void doDisconnect();
    QString doThing(QString text, int index);

private:
    QTcpSocket *socket;
};

#endif // TCPSOCKET_H
