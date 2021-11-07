/*
** EPITECH PROJECT, 2018
** babel
** File description:
** clientcp
*/

#ifndef TCPCLIENT_HPP_
#define TCPCLIENT_HPP_
#include <QDataStream>
#include <QTcpSocket>
#include "Instructor.hpp"
#include "ATcpClient.hpp"
class QTcpSocket;
class QNetworkSession;
class TcpClient: public QObject, public ATcpClient
{
    Q_OBJECT
	public:
		TcpClient();
		~TcpClient();
        void connect_server();
        void setIp(QString ip);
        void setPort(int port);
        void write(Data data);
        void read();
        QTcpSocket *getSocket();
        int getError();
        std::string getRequest();
    QDataStream in;
    signals:
        void valueChanged(bool value);
        void newpacket(bool value);
        void newpacketa(bool value);
    private slots:
        void Error(QAbstractSocket::SocketError socketError);
	protected:
	private:
    int error_code;
    QObject *parent;
    QTcpSocket *socket;
    unsigned int port;
    QString ip;
    std::string request;
    QByteArray buffer;
};

#endif /* !TCPCLIENT_HPP_ */
