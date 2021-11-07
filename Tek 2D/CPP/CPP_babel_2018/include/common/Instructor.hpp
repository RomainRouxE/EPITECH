/*
** EPITECH PROJECT, 2018
** babel
** File description:
** Instructor
*/

#ifndef INSTRUCTOR_HPP_
#define INSTRUCTOR_HPP_
#include <string>
#include <queue>
#include <bitset>
typedef enum Protocol{
    HANDSHAKE = 73,
    LOGIN = 74,
    CREATE = 75,
    CONTACTS = 76,
    ADD = 77,
    REMOVE = 78,
    SUCCESS = 79,
    FAILED = 80,
    ASK = 81,
    CALL = 82,
}Protocol;
typedef struct{
    short instruct;
    short answer;
    short size;
    std::string field;
    int id;
}Data;
class Instructor {
	public:
		Instructor(int a);
		~Instructor();
        void askLogin(std::string login);
        void build_data_ask(int instr, std::string str, int id, int code);
        int getsizeAsk();
        int getsizeRecv();
        void pop_ask();
        void pop_recvq();
        Data front_recv();
        Data front_ask();
        void push_recvdataq(std::string request,int id);
        int type;
	protected:
	private:
    std::queue<Data> tosendq;
    std::queue<Data> recvq;
};

#endif /* !INSTRUCTOR_HPP_ */
