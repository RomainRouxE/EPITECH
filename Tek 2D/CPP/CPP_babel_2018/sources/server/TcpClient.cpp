/*
** EPITECH PROJECT, 2018
** babel
** File description:
** tcpclient
*/
#include <iostream>
#include "TcpClient.hpp"

TcpClient::TcpClient():socket(new QTcpSocket()), error_code(0)
{
    connect(this->socket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),this, &TcpClient::Error);
    connect(this->socket, &QIODevice::readyRead, this, &TcpClient::read);
}

void TcpClient::Error(QAbstractSocket::SocketError socketError)
{
    switch (socketError){
        case QAbstractSocket::RemoteHostClosedError:
            error_code = 0;
        case QAbstractSocket::HostNotFoundError:
            error_code = 1;
            break;
        case QAbstractSocket::ConnectionRefusedError:
            error_code = 2;
            break;
        default:
            error_code = 3;
    }
    emit valueChanged(true);
}

TcpClient::~TcpClient()
{
    
}

void TcpClient::write(Data data)
{
    QByteArray tmp;
    QDataStream toserver(&tmp, QIODevice::WriteOnly);
    toserver << qint8(data.instruct) << qint8(data.answer) << qint8(data.size) << qint8(data.field.size());
    toserver.writeRawData(data.field.c_str(), data.field.size());
    socket->write(tmp);
} 

void TcpClient::connect_server()
{
    socket->connectToHost(ip,port);
}

void TcpClient::setIp(QString input)
{
    ip = input;
}

void TcpClient::setPort(int input)
{
    port = input;
}

void TcpClient::read()
{
    QByteArray nextFortune;
    nextFortune = socket->readLine();
    QDataStream io(nextFortune);
    qint8 inst;
    io >> inst;
    request = std::string(nextFortune.constData(), nextFortune.length());
    emit newpacketa(true);
}