/*
** EPITECH PROJECT, 2018
** babel
** File description:
** Account
*/

#ifndef ACCOUNT_HPP_
#define ACCOUNT_HPP_
#include <string>
#include <list>
class Account {
	public:
		Account(std::string n, int i);
		~Account();
        int getId();
        void setId(int input){
            id = input;
        }
        void sethost(std::string hosta){
            host = hosta;
        }
        std::string gethost(){
            return host;
        }
        std::string getName(){
            return name;
        }
    std::list<std::string> friends;
	protected:
	private:
    int id;
    std::string name;
    std::string host;
};

#endif /* !ACCOUNT_HPP_ */
