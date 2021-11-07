/*
** EPITECH PROJECT, 2018
** babel
** File description:
** server
*/


#ifndef SERVER_HPP_
#define SERVER_HPP_
#include <list>
#include "Account.hpp"
#include "Tcpconnect.hpp"
class Server {
	public:
		Server(boost::asio::io_service& io_service, int port);
		~Server();
        void accept_function();
        void accept_handler(Tcpconnect::ptr new_connect, const boost::system::error_code &error);
		Tcpconnect::ptr getTcpbyId(int id);
		void handle_requests();
		void handle_ask();
		void login(Data input);
		void create_user(Data input);
		void add_contact(Data input);
		void send_contacts(Data r);
		void send_udplink(Data r);
		std::string getName(int id);
		int getId(std::string name);
		int ids;
	protected:
	private:
	Instructor *instructor;
	std::list<Tcpconnect::ptr> tcps;
	std::list<Account> accounts;
    tcp::acceptor acceptor_;
};

#endif /* !SERVER_HPP_ */
