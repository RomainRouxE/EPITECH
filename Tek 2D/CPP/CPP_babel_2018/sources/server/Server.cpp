/*
** EPITECH PROJECT, 2018
** babel
** File description:
** server
*/

#include <iostream>
#include "Server.hpp"

Server::Server(boost::asio::io_service& io_service, int port):
acceptor_(io_service, tcp::endpoint(tcp::v4(),port)), instructor(new Instructor(2)), ids(0)
{
    accept_function();
}

Server::~Server()
{
}

void Server::login(Data r)
{
    std::list<Account>::iterator it;
    for (it = accounts.begin(); it != accounts.end(); ++it){
            if (it->getName().compare(r.field) == 0){
                instructor->build_data_ask(Protocol::LOGIN, "Success", r.id, Protocol::SUCCESS);
                it->setId(r.id);
                it->sethost(getTcpbyId(r.id)->return_host());
                return;
            }
    }
    instructor->build_data_ask(Protocol::LOGIN, "FAILED", r.id, Protocol::FAILED);
}

void Server::create_user(Data r)
{
    std::list<Account>::iterator it;
    for (it = accounts.begin(); it != accounts.end(); ++it){
            if (it->getName().compare(r.field) == 0){
                instructor->build_data_ask(Protocol::CREATE, "Failed", r.id, Protocol::FAILED);
                return;
            }
    }
    instructor->build_data_ask(Protocol::CREATE, "Success", r.id, Protocol::SUCCESS);
    Account new_account(r.field, r.id);
    new_account.sethost(getTcpbyId(r.id)->return_host());
    accounts.push_back(new_account);
}

void Server::add_contact(Data r)
{
    std::string name = getName(r.id);
    int friend_add;
    bool known = false;
    std::list<Account>::iterator it;
    std::list<std::string>::iterator ita;
    for (it = accounts.begin(); it != accounts.end(); ++it){
        if (it->getName().compare(r.field) == 0 && it->getName().compare(name) == 1){
            for (ita = it->friends.begin(); ita != it->friends.end(); ++ita){
                if (ita->compare(r.field) == 0)
                     known = true;
            }
        if (!known){
            instructor->build_data_ask(Protocol::CONTACTS, r.field, r.id, Protocol::SUCCESS);
            friend_add = getId(r.field);
            instructor->build_data_ask(Protocol::CONTACTS, name, friend_add, Protocol::SUCCESS);
            return;
            }
        }
    }
    instructor->build_data_ask(Protocol::CONTACTS, r.field, r.id, Protocol::FAILED);
}

std::string Server::getName(int id)
{
    std::list<Account>::iterator it;
    for (it = accounts.begin(); it != accounts.end(); ++it){
        if (it->getId() == id)
                return it->getName();
    }
}

int Server::getId(std::string name)
{
    std::list<Account>::iterator it;
    for (it = accounts.begin(); it != accounts.end(); ++it){
        if (it->getName().compare(name) == 0)
                return it->getId();
    }
}

void Server::handle_requests()
{
    if (instructor->getsizeRecv() != 0){
        Data tmp = instructor->front_recv();
        switch(tmp.instruct){
            case (Protocol::LOGIN):
                login(tmp);
                instructor->pop_recvq();
                break;
            case (Protocol::CREATE):
                create_user(tmp);
                instructor->pop_recvq();
                break;
            case (Protocol::ADD):
                add_contact(tmp);
                instructor->pop_recvq();
                break;
            case (Protocol::CONTACTS):
                send_contacts(tmp);
                instructor->pop_recvq();
                break;
            case (Protocol::CALL):
                send_udplink(tmp);
                instructor->pop_recvq();
                break;
            default:
                break;
        }
    }
}

void Server::send_udplink(Data r)
{
    std::list<Account>::iterator it;
    std::list<Account>::iterator ita;
    std::list<Account>::iterator itc;
    for (it = accounts.begin(); it != accounts.end(); ++it){
        if (it->getName().compare(r.field) == 0){
            std::string str_to_send;
            std::string str_to_send2;
            str_to_send.append(it->gethost());
            str_to_send.append(":");
            str_to_send.append("3838");
            str_to_send.append(":");
            str_to_send.append("7777");
            std::cout << str_to_send << std::endl;
            instructor->build_data_ask(Protocol::CALL, str_to_send, r.id, Protocol::SUCCESS);
            int friend_add = getId(r.field);
            std::string name_friend = getName(r.id);
            for (ita = accounts.begin(); ita != accounts.end(); ++ita){
                if (ita->getName().compare(r.field) == 0){
                    for (itc = accounts.begin(); itc != accounts.end(); ++itc){
                        if (itc->getId() == r.id)
                            str_to_send2.append(itc->gethost());
                    }
                    str_to_send2.append(":");
                    str_to_send2.append("7777");
                    str_to_send2.append(":");
                    str_to_send2.append("3838");
                    std::cout << str_to_send2<< std::endl;
                    instructor->build_data_ask(Protocol::CALL, str_to_send2, friend_add, Protocol::SUCCESS);
                    return;
                }
            }
        }
    }
    instructor->build_data_ask(Protocol::CALL, r.field, r.id, Protocol::FAILED);
}

void Server::send_contacts(Data r)
{
    std::list<Account>::iterator it;
    std::list<std::string>::iterator ita;
    for (it = accounts.begin(); it != accounts.end(); ++it){
        if (it->getName().compare(getName(r.id)) == 0){
            std::cout << "found" << std::endl;
            for (ita = it->friends.begin(); ita != it->friends.end(); ++ita){
                std::cout << *ita << "ita" << std::endl;
                instructor->build_data_ask(Protocol::CONTACTS, *ita, r.id , Protocol::SUCCESS);
            }
        }
    }
    std::cout << "out" << std::endl;    
}
 

void Server::handle_ask()
{
    if (instructor->getsizeAsk() != 0){
        Data tmp = instructor->front_ask();
        std::bitset<8> instr(tmp.instruct);
        std::bitset<8> ans(tmp.answer);
        std::bitset<8> si(tmp.size);
        std::string tmp_str;
        std::string tmp_attr;
        tmp_attr = (signed char) tmp.instruct;
        tmp_str.append(tmp_attr);
        tmp_attr = (signed char) tmp.answer;
        tmp_str.append(tmp_attr);
        tmp_attr = (signed char) tmp.size;
        tmp_str.append(tmp_attr);
        tmp_str.append(tmp.field);
        getTcpbyId(tmp.id)->write(tmp_str);
        instructor->pop_ask();
    }
    handle_requests();
}

Tcpconnect::ptr Server::getTcpbyId(int id)
{
    std::list<Tcpconnect::ptr>::iterator it;
    for (it = tcps.begin(); it != tcps.end(); ++it){
        if ((*it)->getId() == id)
            return ((*it));
    }
}

void Server::accept_function()
{
    Tcpconnect::ptr new_connect =
    Tcpconnect::create(acceptor_.get_io_service(), ids++);
    acceptor_.async_accept(new_connect->socket(), boost::bind(&Server::accept_handler, this, new_connect,boost::asio::placeholders::error));
}


void Server::accept_handler(Tcpconnect::ptr new_connect, const boost::system::error_code& error)
{
    if (!error){
        new_connect->setInstr(instructor);
        tcps.push_back(new_connect);
        instructor->build_data_ask(Protocol::HANDSHAKE, "Welcome", new_connect->_id, Protocol::SUCCESS);
        new_connect->start();
    }
    else
        new_connect->close();
    accept_function();
}
