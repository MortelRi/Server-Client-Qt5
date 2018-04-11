#include "mythread.h"

MyThread::MyThread(int ID, QObject *parent) :
    QThread(parent)
{
    this->socketDescriptor = ID;
}

void MyThread::run()
{
    qDebug() << socketDescriptor << " Starting thread";
    socket = new QTcpSocket();
    if(!socket->setSocketDescriptor(this->socketDescriptor))
    {
        emit error(socket->error());
        return;
    }

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()),Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()),Qt::DirectConnection);

    qDebug() << socketDescriptor << " Client connected";

    exec();
}

void MyThread::readyRead()
{
    QString text;
    int index = -1;
    quint16 blockSize = 0;
    QByteArray block;
    QDataStream in(socket), out(&block, QIODevice::WriteOnly);

    while(true) {
        if (blockSize == 0) {
            if (socket->bytesAvailable() < sizeof(quint16)) break;
            in >> blockSize;
        }

        if (socket->bytesAvailable() < blockSize) break;

        in >> text;
        in >> index;
        blockSize = 0;
    }
    qDebug() << socketDescriptor << " Data in: " << text.toStdString().c_str();

    switch (index)
    {
    case 0:     //сортировка символов текста по убыванию
        std::sort(text.begin(), text.end(), std::greater<QString>());
        break;
    case 1:     //Разворот текста
        std::reverse(text.begin(), text.end());
        break;
    case 2:     //Сортировка строк текста по возрастанию
    {
        QStringList list = text.split("\n", QString::SkipEmptyParts);
        std::sort(list.begin(), list.end());
        text = list.join("\n");
        break;
    }
    case 3:     //Статистика по используемым символам в тексте
        QMap<QString, int> map;

        std::sort(text.begin(), text.end());
        for(auto it = text.begin(); it != text.end(); it = std::upper_bound(text.begin(), text.end(), *it))
            map[*it] = std::upper_bound(text.begin(), text.end(), *it) - std::lower_bound(text.begin(), text.end(), *it);

        QMapIterator<QString, int> i(map);
        text.clear();
        while (i.hasNext()) {
            i.next();
            text += QString("%1 %2").arg(i.value()).arg(i.key());
            if (i.hasNext()) text += QString("\n");
        }
        break;
    }

    qDebug() << socketDescriptor << " Data out: " << text.toStdString().c_str();
    out << quint16(0) << text;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
    socket->write(block);
}

void MyThread::disconnected()
{
    qDebug() << socketDescriptor << " Disconnected";
    socket->deleteLater();
    exit(0);
}
