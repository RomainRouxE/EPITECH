/*
** EPITECH PROJECT, 2018
** babel
** File description:
** UDPSocket
*/

#include "UDPsocket.hpp"

UDPSocket::UDPSocket()
{

}

UDPSocket::~UDPSocket()
{

}

void UDPSocket::write()
{
    while (!to_send_packets.empty()){
        QByteArray buff;
        QDataStream out(&buff, QIODevice::WriteOnly);
        out << to_send_packets.front().enc_b;
        out << QVector<quint8>::fromStdVector(to_send_packets.front().encoded);
        qint64 writeBytes = socket->writeDatagram(buff,QHostAddress(QString::fromUtf8(host.c_str())), host_port);
        to_send_packets.pop_front();
    }
}

void UDPSocket::init(int to_bind, std::string addr, int port)
{
    socket = new QUdpSocket(this);
    binded = socket->bind(to_bind);
    host = addr;
    host_port = port;
}

bool UDPSocket::read()
{
    bool re = false;
    QTextStream qout(stdout);
    
    while(socket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(socket->pendingDatagramSize());
        qint64 readBytes = socket->readDatagram(datagram.data(), datagram.size());
        QDataStream in(&datagram, QIODevice::ReadOnly);
        UDPpacket packet;
        QVector<quint8> vec;
        in >> packet.enc_b >> vec;
        packet.encoded = vec.toStdVector();
        received_packets.push_back(packet);
        re = true;
    }
    return (re);
}

UDPpacket UDPSocket::create_packet(std::vector<unsigned char> frames, int bytes)
{
    UDPpacket packet;
    packet.encoded = frames;
    packet.enc_b = bytes;
    return (packet);
}