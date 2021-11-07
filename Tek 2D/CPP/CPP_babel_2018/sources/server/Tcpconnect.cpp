/*
** EPITECH PROJECT, 2018
** babel
** File description:
** Tcpconnect
*/

#include "Tcpconnect.hpp"
#include "Account.hpp"

Tcpconnect::Tcpconnect(boost::asio::io_service& io_service, int id):socket_(io_service), _id(id)
{

}

Tcpconnect::~Tcpconnect()
{
        
}

std::string Tcpconnect::return_host()
{
    return (socket_.remote_endpoint().address().to_string());
}

void Tcpconnect::handle_read()
{
    std::ostringstream tmp;
    tmp << &request;
    std::string tmp_str = tmp.str();
    instructor->push_recvdataq(tmp_str, _id);
    start();
}

void Tcpconnect::close()
{
    socket_.close();
}

void Tcpconnect::handle_write()
{
    boost::asio::async_read_until(socket_,request,"\0",boost::bind(&Tcpconnect::handle_read, shared_from_this()));
}

void Tcpconnect::setInstr(Instructor *instr)
{
    instructor = instr;
}

void Tcpconnect::start()
{
    socket_.non_blocking(true);
}

tcp::socket& Tcpconnect::socket()
{
    return socket_;
}

int Tcpconnect::getId()
{
    return _id;
}

void Tcpconnect::write(std::string message)
{
    boost::asio::async_write(socket_, boost::asio::buffer(message),
    boost::bind(&Tcpconnect::handle_write, shared_from_this()));   
}