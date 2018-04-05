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
    std::string text = Data.toStdString();
    qDebug() << socketDescriptor << " Data in: " << text.c_str();

    switch (index)
    {
    case 0:     //сортировка символов текста по убыванию
        std::sort(text.begin(), text.end(), std::greater<char>());
        qDebug() << socketDescriptor << " Data out: " << text.c_str();
        socket->write(text.c_str());
        break;
    case 1:     //Разворот текста
        std::reverse(text.begin(), text.end());
        qDebug() << socketDescriptor << " Data out: " << text.c_str();
        socket->write(text.c_str());
        break;
    case 2:     //Сортировка строк текста по возрастанию
    {
        std::size_t found;
        std::vector<std::string> vecText;

        for(unsigned int i = 0; i < text.size(); i++)
        {
            found = text.find("\n", i);
            if (found != std::string::npos){
                vecText.push_back(text.substr(i, found - i));
                i = found;
            }
            else{
                vecText.push_back(text.substr(i, text.back() - i));
                break;
            }
        }
        text.clear();
        std::sort(vecText.begin(), vecText.end());

        for(auto it = vecText.begin(); it != vecText.end(); it++){
            text.append(*it);
            if (it+1 != vecText.end())
                text.push_back('\n');
        }

        qDebug() << socketDescriptor << " Data out: " << text.c_str();
        socket->write(text.c_str());
        break;
    }
    case 3:     //Статистика по используемым символам в тексте
        std::vector<char> vecText;
        std::ostringstream ss;
        std::string s;

        for(auto ch = text.begin(); ch != text.end(); ch++)
        {
            bool comp = true;
            if(!vecText.empty())
            {
                for(auto it = vecText.begin(); it != vecText.end(); it++)
                {
                    if (*it == *ch)
                    {
                        comp = false;
                        break;
                    }
                }
            }
            if (comp)
            {
                vecText.push_back(*ch);
                ss << std::count(text.begin(), text.end(), *ch) << " " << *ch;
                if (ch + 1 != text.end())
                    ss << std::endl;
                s += ss.str();
                ss.str("");
            }
        }

        qDebug() << socketDescriptor << " Data out: " << s.c_str();
        socket->write(s.c_str());
        break;
    }

}

void MyThread::disconnected()
{
    qDebug() << socketDescriptor << " Disconnected";
    socket->deleteLater();
    exit(0);
}
