/*
** EPITECH PROJECT, 2018
** babel
** File description:
** UDPSocket
*/

#ifndef UDPSOCKET_HPP_
#define UDPSOCKET_HPP_
#include <opus.h>
#include <vector>
#include <list>
#include <iostream>
#include <QDataStream>
#include <QUdpSocket>
struct UDPpacket{
    int enc_b;
    std::vector<unsigned char> encoded;
};
class UDPSocket: public QObject
{
    Q_OBJECT
	public:
        UDPSocket();
        ~UDPSocket();
        void write();
        bool read();
        void init(int to_bind, std::string addr, int port);
        UDPpacket create_packet(std::vector<unsigned char> frames, int bytes);
        std::list<UDPpacket> received_packets;
        std::list<UDPpacket> to_send_packets;
        QUdpSocket *socket;
        std::string host;
        int host_port;
        int binded;
};

#endif /* !UDPSOCKET_HPP_ */