//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "../include/exec.hpp"
#include "../include/Operand_type.hpp"
#include "../include/utils.hpp"
#include <list>

Exec::Exec()
{
	int   idx;

	for (idx = 0; idx < 16; idx++)
		this->_int8.push_back(NULL);
	for (idx = 0; idx < 16; idx++)
		this->_int16.push_back(NULL);
	for (idx = 0; idx < 16; idx++)
		this->_int32.push_back(NULL);
	for (idx = 0; idx < 16; idx++)
		this->_float.push_back(NULL);
	for (idx = 0; idx < 16; idx++)
		this->_double.push_back(NULL);
	for (idx = 0; idx < 16; idx++)
		this->_bigdecimal.push_back(NULL);
}

Exec::~Exec()
{	
}

Exec::Exec(eExecType type, std::list<IOperand *>& stack, std::string val)
{
	switch(type)
	{
	case PUSH:
		push(stack, val);
		break;
	case ASSERT:
		assert(stack, val);
		break;
	case LOAD:
		load(stack, val);
		break;
	case STORE:
		store(stack, val);
		break;
	default:
		throw Error("Invalid instruction", 84);
	}
}

Exec::Exec(eExecType type, std::list<IOperand *>& stack)
{
	switch(type)
	{
	case POP:
		pop(stack);
		break;
	case CLEAR:
		clear(stack);
		break;
	case DUP:
		dup(stack);
		break;
	case SWAP:
		swap(stack);
		break;
	case DUMP:
		dump(stack);
		break;
	case ADD:
		add(stack);
		break;
	case SUB:
		sub(stack);
		break;
	case MUL:
		mul(stack);
		break;
	case DIV:
		div(stack);
		break;
	case MOD:
		mod(stack);
		break;
	case PRINT:
		print(stack);
		break;
	case EXIT:
		exit();
		break;
	case COMMENTS:
		break;
	default:
		throw Error("Invalid instruction", 84);
	}
}

void	Exec::push(std::list<IOperand *>& stack, std::string value)
{
	IOperand *val;

	val = Factory::createOperand(determineType(value), determineValue(value));
	stack.push_front(val);
}

void	Exec::pop(std::list<IOperand *>& stack)
{
	if (stack.empty())
		throw Error("stack is empty", 84);
	else
		stack.pop_front();
	return;
}

void	Exec::add(std::list<IOperand *>& stack)
{
	IOperand *op;
	IOperand *op2;

	if (stack.size() < 2)
		throw Error("stack size < 2", 84);
	op = stack.front();
	stack.pop_front();
	op2 = stack.front();
	stack.pop_front();
	stack.push_front(op + op2);
}

void	Exec::sub(std::list<IOperand *>& stack)
{
	IOperand *op;
	IOperand *op2;

	if (stack.size() < 2)
		throw Error("stack size < 2", 84);
	op = stack.front();
	stack.pop_front();
	op2 = stack.front();
	stack.pop_front();
	stack.push_front(op - op2);
}

void	Exec::mul(std::list<IOperand *>& stack)
{
	IOperand *op;
	IOperand *op2;

	if (stack.size() < 2)
                throw Error("stack size < 2", 84);
	op = stack.front();
	stack.pop_front();
	op2 = stack.front();
	stack.pop_front();
	stack.push_front(op * op2);
}

void	Exec::div(std::list<IOperand *>& stack)
{
	IOperand *op;
	IOperand *op2;

	if (stack.size() < 2)
                throw Error("stack size < 2", 84);
	op = stack.front();
	stack.pop_front();
	op2 = stack.front();
	stack.pop_front();
	if (op2->toString() == "0" || op->toString() == "0")
		throw Error("division by zero", 84);
	stack.push_front(op / op2);
}

void	Exec::mod(std::list<IOperand *>& stack)
{
	IOperand *op;
	IOperand *op2;
	
	if (stack.size() < 2)
		throw Error("stack size < 2", 84);
	op = stack.front();
	stack.pop_front();
	op2 = stack.front();
	stack.pop_front();
	if (op2->toString() == "0" || op->toString() == "0")
		throw Error("modulo by zero", 84);
	stack.push_front(op % op2);
}

/*void	exec::sqrt(std::list<IOperand *>& stack)
{
	IOperand *op;

	op = stack.front();
	stack.pop_front();
	stack.push_front(std::sqrt(op));
	}*/

void	Exec::clear(std::list<IOperand *>& stack)
{
	if (stack.empty() == true)
		while (stack.empty() == false)
			stack.clear();
	return;
}

void	Exec::dup(std::list<IOperand *>& stack)
{
	IOperand *op;

	op = stack.front();
	stack.push_front(op);
}

void	Exec::swap(std::list<IOperand *>& stack)
{
	IOperand *op;
	IOperand *op2;

	op = stack.front();
	stack.pop_front();
	op2 = stack.front();
	stack.pop_front();
	stack.push_front(op2);
	stack.push_front(op);
}

void	Exec::dump(std::list<IOperand *>& stack)
{
	auto it = stack.begin();

	while (it != stack.end()) {
		std::cout << *it << "\n" << std::endl;
		++it;
	}
}

void	Exec::load(std::list<IOperand *>& stack, std::string val)
{
	double id = stold(determineValue(val));
	IOperand *value;
	
	if (value.empty() == true)
		throw Error("Invalid register", 84);
	if (((double)((int)id)) != id)
		throw Error("Invalid register", 84);
	switch (value->getType())
	{
	case Int8:
		value = this->_int8[id];
		break;
	case Int16:
		value = this->_int16[id];
		break;
	case Int32:
		value = this->_int32[id];
		break;
	case Float:
		value = this->_float[id];
		break;
	case Double:
		value =this->_double[id];
		break;
	case BigDecimal:
		value = this->_bigdecimal[id];
		break;
	default:
		throw Error("Invalid type", 84);
	}
	if (value == NULL)
		throw Error("this register haven't been set", 84);
	stack.push_front(value);
}

void	Exec::store(std::list<IOperand *>& stack, std::string val)
{
	IOperand *value = stack.front();
	double id = stold(determineValue(val));
		
	if (value.empty() == true)
		throw Error("Invalid register", 84);
	if (((double)((int)id)) != id)
		throw Error("Invalid registre", 84);
	switch (value->getType())
	{
	case Int8:
		this->_int8[id] = value;
		break;
	case Int16:
		this->_int16[id] = value;
		break;
	case Int32:
		this->_int32[id] = value;
		break;
	case Float:
		this->_float[id] = value;
		break;
	case Double:
		this->_double[id] = value;
		break;
	case BigDecimal:
		this->_bigdecimal[id] = value;
		break;
	default:
		throw Error("Invalid type", 84);
	}
	stack.pop_front();
}

void	Exec::assert(std::list<IOperand *>& stack, std::string value)
{
	std::string val;
	eOperandType type;
	std::string val2;
	eOperandType type2;

	val = determineValue(value);
	type = determineType(value);
	val2 = determineValue(stack.front().toString());
	type2 = determineType(stack.front().toString());
	if (val != val2 && type != type2)
		throw Error("value is not equal to the top", 84);
}

void	Exec::exit()
{	
	std::exit(0);
}

void	Exec::print(std::list<IOperand *>& stack)
{
	IOperand *val = stack.front();
	
	if (val->getType() != Int8)
		throw Error("invalid type", 84);
	std::cout << static_cast<char>(atoi(determineValue(val->toString()).c_str())) << std::endl;
}
