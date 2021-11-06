//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef EXEC_HPP_
# define EXEC_HPP_

# include <vector>
# include <cstring>
# include <stack>
# include <list>

# include "IOperand.hpp"
# include "gest_error.hpp"
# include "Factory.hpp"
# include "exec_type.hpp"

class Exec
{
public:
	Exec();
	virtual ~Exec();
	Exec(eExecType type, std::list<IOperand *>& stack);
	Exec(eExecType type, std::list<IOperand *>& stack, std::string val);
private:
	std::vector<IOperand *> _int8;
	std::vector<IOperand *> _int16;
	std::vector<IOperand *> _int32;
	std::vector<IOperand *> _float;
	std::vector<IOperand *> _double;
	std::vector<IOperand *> _bigdecimal;
	void pop(std::list<IOperand *>&);
	void clear(std::list<IOperand *>&);
	void dup(std::list<IOperand *>&);
	void swap(std::list<IOperand *>&);
	void dump(std::list<IOperand *>&);
	void add(std::list<IOperand *>&);
	void sub(std::list<IOperand *>&);
	void mul(std::list<IOperand *>&);
	void div(std::list<IOperand *>&);
	void mod(std::list<IOperand *>&);
	void print(std::list<IOperand *>&);
	void exit();	
	void push(std::list<IOperand *>&, std::string);
	void assert(std::list<IOperand *>&, std::string);
	void load(std::list<IOperand *>&, std::string);
	void store(std::list<IOperand *>&, std::string);
};

#endif
