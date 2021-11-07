/*
** EPITECH PROJECT, 2018
** babel
** File description:
** ATcpClient
*/

#ifndef ATCPCLIENT_HPP_
#define ATCPCLIENT_HPP_
#include <string>
#include "Instructor.hpp"
class ATcpClient {
	public:
		virtual ~ATcpClient(){}
        virtual void connect_server() = 0;
        virtual void setPort(int port) = 0;
        virtual void write(Data data) = 0;
        virtual void read() = 0;
        virtual int getError() = 0;
        virtual std::string getRequest() = 0;
	protected:
	private:
        int error_code;
        unsigned int port;
        std::string request;
};

#endif /* !ATCPCLIENT_HPP_ */
