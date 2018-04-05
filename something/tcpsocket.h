#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>

class TcpSocket : public QObject
{
    Q_OBJECT
public:
    explicit TcpSocket(QObject *parent = 0);
    ~TcpSocket();
    bool doConnect(QString ip, QString port);
    void doDisconnect();
    QString doThing(const char *text, const char *index);

private:
    QTcpSocket *socket;
};

#endif // TCPSOCKET_H
