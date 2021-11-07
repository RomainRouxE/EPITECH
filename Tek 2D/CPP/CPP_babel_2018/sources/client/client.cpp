/*
** EPITECH PROJECT, 2018
** babel
** File description:
** clientmethods
*/

#include <iostream>
#include "Client.hpp"
#include <QtWidgets>
#include <QtNetwork>
#include <QApplication>

Client::Client(): tcp(new TcpClient())
    , instructor(new Instructor(3)), type(0)
{ 
    Login w_login(nullptr, this);
    Registered w_reg(nullptr, this);
    w_reg.show();
    w_login.show();
    w_reg.exec();
}

void Client::launch_registered(Data r)
{
    if (r.answer == Protocol::SUCCESS){
        std::cout << "logged" << std::endl;
        //instructor->build_data_ask(Protocol::CONTACTS,"", 0, Protocol::ASK);
    }
}

void Client::connect_server(std::string user, int port, QString host, std::string pass)
{
    tcp->setIp(host);
    tcp->setPort(port);
    setUser(user);
    setPassword(pass);
    tcp->connect_server();
}

Client::~Client()
{

}

void Client::setUser(std::string input)
{
    user = input;
}

void Client::setPassword(std::string input)
{
    password = input;
}

std::string Client::getUser()
{
    return user;
}

std::string Client::getPassword()
{
    return password;
}

void Client::empty_askq()
{
    while (instructor->getsizeAsk() != 0){
        tcp->write(instructor->front_ask());
        instructor->pop_ask();
    }
}

void Client::handle_login(Data r)
{
    if (geType() == 1)
        instructor->build_data_ask(Protocol::LOGIN, user, 0, Protocol::ASK);
    else
        instructor->build_data_ask(Protocol::CREATE, user, 0, Protocol::ASK);
}

void Client::empty_recvq()
{
    while (instructor->getsizeRecv() != 0){
        switch (instructor->front_recv().instruct){
        case (Protocol::HANDSHAKE):
            handle_login(instructor->front_recv());
            break;
        case (Protocol::CREATE):
            launch_registered(instructor->front_recv());
            break;
        case (Protocol::LOGIN):
            launch_registered(instructor->front_recv());
            break;
        case (Protocol::CONTACTS):
            update_contacts(instructor->front_recv());
            break;
        case (Protocol::CALL):
            handle_call(instructor->front_recv().field);
            break;
        default:
            std::cout << "Unknown" << std::endl;
            break;
        }
        instructor->pop_recvq();
        empty_askq();
    }
}

void Client::update_contacts(Data r)
{
    if (r.answer == Protocol::SUCCESS){
        friends.push_back(r.field);
        instructor->build_data_ask(Protocol::CONTACTS,"", 0, Protocol::ASK);
    }
    else
        std::cout << "couldn't add friend" << std::endl;
}

void Client::handle_request()
{
    instructor->push_recvdataq(tcp->getRequest(), 0);
    empty_recvq();
}

void Client::add_contact(std::string contact)
{
    instructor->build_data_ask(Protocol::ADD, contact, 0, Protocol::ASK);
    empty_askq();
}

void Client::make_call(std::string contact)
{
    instructor->build_data_ask(Protocol::CALL, contact, 0, Protocol::ASK);
    empty_askq();
}

TcpClient *Client::getTcp()
{
    return tcp;
}

int Client::Client::geType()
{
    return type;
}

int Client::seType(int input)
{
    type = input;
}

void Client::handle_call(std::string entry)
{
    std::string delimiter = ":";
    std::string addr = entry.substr(0, entry.find(delimiter));
    entry.erase(0, entry.find(delimiter) + 1);
    std::string str_port = entry.substr(0, 4);
    entry.erase(0, entry.find(delimiter)+1);
    std::string to_b =  entry.substr(0, 4);
    int i = 0;
    udpsocket.init(atoi(to_b.c_str()), addr, atoi(str_port.c_str()));
    audio.init();
    encoder.init_encoder();
    encoder.init_decoder();
    while (1){
        audio.record();
        encoder.encode(audio.captured);
        udpsocket.to_send_packets.push_back(udpsocket.create_packet(encoder.encoded, encoder.enc_bytes));
        udpsocket.write();
        if (udpsocket.read()){
            encoder.decode(udpsocket.received_packets.front().encoded, udpsocket.received_packets.front().enc_b);
            audio.list_to_play.push_back(encoder.decoded);
            udpsocket.received_packets.pop_front();
            i++;
            if (i > 3){
                audio.play();
                i = 0;
            }
        }
    }
}