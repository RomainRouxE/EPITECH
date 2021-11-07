/*
** EPITECH PROJECT, 2018
** babel
** File description:
** clienth
*/

#ifndef _CLIENT_HPP_
#define _CLIENT_HPP_
#include "Login.hpp"
#include "Registered.hpp"
#include "Instructor.hpp"
#include "UDPsocket.hpp"
#include "Audio.hpp"
#include "Encoder.hpp"
#include "TcpClient.hpp"

class Client{
public:
    Client();
    ~Client();
    void setUser(std::string input);
    std::string getUser();
    void setPassword(std::string input);
    std::string getPassword();
    TcpClient *getTcp();
    int geType();
    int seType(int input);
    void connect_server(std::string user, int port, QString host, std::string pass);
    void affichage_test();
    void empty_askq();
    void empty_recvq();
    void handle_request();
    void handle_login(Data r);
    void launch_registered(Data r);
    void update_contacts(Data r);
    void add_contact(std::string contact);
    void make_call(std::string contact);
    void handle_call(std::string entry);
    Audio audio;
    Encoder encoder;
    UDPSocket udpsocket;
private:
    Login *w_login;
    Registered *w_reg;
    std::string user;
    std::string password;
    Instructor *instructor;
    TcpClient *tcp;
    std::list<std::string> friends;
    int type;
};


#endif /* !CLIENT_HPP_ */
