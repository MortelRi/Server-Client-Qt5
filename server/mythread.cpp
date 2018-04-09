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
    QByteArray Data = socket->readAll();
    int index = Data.back() - '0';
    Data.chop(1);
    QString text = QString::fromUtf8(Data);
    qDebug() << socketDescriptor << " Data in: " << text;

    switch (index)
    {
    case 0:     //сортировка символов текста по убыванию
        std::sort(text.begin(), text.end(), std::greater<QString>());
        qDebug() << socketDescriptor << " Data out: " << text;
        socket->write(text.toUtf8());
        break;
    case 1:     //Разворот текста
        std::reverse(text.begin(), text.end());
        qDebug() << socketDescriptor << " Data out: " << text;
        socket->write(text.toUtf8());
        break;
    case 2:     //Сортировка строк текста по возрастанию
    {
        QStringList list = text.split("\n", QString::SkipEmptyParts);
        std::sort(list.begin(), list.end());
        text = list.join("\n");
        qDebug() << socketDescriptor << " Data out: " << text;
        socket->write(text.toUtf8());
        break;
    }
    case 3:     //Статистика по используемым символам в тексте
        QMap<QString, int> map;
        for(auto it = text.begin(); it != text.end(); it++)
            map[*it] = std::count(text.begin(), text.end(), *it);
        QMapIterator<QString, int> i(map);
        text.clear();
        while (i.hasNext()) {
            i.next();
            text += QString("%1 %2\n").arg(i.value()).arg(i.key());
        }
        socket->write(text.toUtf8());
        break;
    }

}

void MyThread::disconnected()
{
    qDebug() << socketDescriptor << " Disconnected";
    socket->deleteLater();
    exit(0);
}
