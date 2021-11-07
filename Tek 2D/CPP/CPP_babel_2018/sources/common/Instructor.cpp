/*
** EPITECH PROJECT, 2018
** babel
** File description:
** Instructor
*/
#include <iostream>
#include "Instructor.hpp"

Instructor::Instructor(int a)
{  
    type = a;
}

Instructor::~Instructor()
{
}

void Instructor::askLogin(std::string login)
{
    build_data_ask(Protocol::LOGIN, login, 0, Protocol::ASK);
}

void Instructor::build_data_ask(int instr, std::string str, int id, int code)
{
    Data new_data;
    
    new_data.instruct= short(instr);
    new_data.answer = short(code);
    new_data.size = short(str.length()+1);
    new_data.field = str;
    new_data.id = id;
    tosendq.push(new_data);
}

int Instructor::getsizeAsk()
{
    return tosendq.size();
}

int Instructor::getsizeRecv()
{
    return recvq.size();
}

Data Instructor::front_ask()
{
    return tosendq.front();
}

void Instructor::pop_ask()
{
    tosendq.pop();
}

void Instructor::pop_recvq()
{
    recvq.pop();
}

Data Instructor::front_recv()
{
    return recvq.front();
}

void Instructor::push_recvdataq(std::string request, int id)
{
    std::bitset<8> instruct_bytes(request.at(0));
    std::bitset<8> answer_bytes(request.at(1));
    std::bitset<8> size_bytes(request.at(2));

    Data new_data;
    new_data.instruct = static_cast<signed char>(instruct_bytes.to_ulong());
    new_data.answer = static_cast<signed char>(answer_bytes.to_ulong());
    new_data.size = static_cast<signed char>(size_bytes.to_ulong());
    new_data.field = request.substr(sizeof(new_data.instruct) + sizeof(new_data.size)+ sizeof(new_data.answer) - type, sizeof(new_data.instruct)+sizeof(new_data.size)+ sizeof(new_data.answer) + new_data.size);
    new_data.id = id;
    recvq.push(new_data);
}
