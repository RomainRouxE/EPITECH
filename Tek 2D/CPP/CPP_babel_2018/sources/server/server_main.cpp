/*
** EPITECH PROJECT, 2018
** babel
** File description:
** server
*/

#include <iostream>
#include "Tcpconnect.hpp"
#include "Server.hpp"
#include <boost/asio.hpp>

int main(int arc, char **argv)
{
    if (arc != 2)
        return (84);
    try{
        boost::asio::io_service io_service;
        Server server(io_service, std::atof(argv[1]));
        while (1){
            io_service.poll();
            server.handle_ask();
        }
    }
    catch(std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    return (0);
}