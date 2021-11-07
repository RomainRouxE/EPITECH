/*
** EPITECH PROJECT, 2018
** babel
** File description:
** tcpserverconnect
*/

#ifndef TCPCONNECT_HPP_
#define TCPCONNECT_HPP_
#include "Instructor.hpp"
#include <bitset>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>
#include <vector>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include <iostream>
#include "ATcpCo.hpp"
using boost::asio::ip::tcp;

class Tcpconnect: public boost::enable_shared_from_this<Tcpconnect>, public ATcpCo {
	public:
		Tcpconnect(boost::asio::io_service& io_service, int id);
		~Tcpconnect();
        typedef boost::shared_ptr<Tcpconnect> ptr;
        tcp::socket& socket();
        int getId();
        void write(std::string message);
        void start();
        void read(){
        }
        std::string return_host();
        void setInstr(Instructor *instr);
        void close();
        static ptr create(boost::asio::io_service& io_service, int id){
            return ptr(new Tcpconnect(io_service, id));
        }
    int _id;
	protected:
	private:
    void handle_write();
    void handle_read();
    Instructor *instructor;
    tcp::socket socket_;
    std::string message_;
    boost::asio::streambuf request;
};

#endif /* !TCPCONNECT_HPP_ */
