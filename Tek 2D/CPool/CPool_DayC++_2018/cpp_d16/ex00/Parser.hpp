//
// EPITECH PROJECT, 2018
// Parser.hpp
// File description:
// Parser.hpp
//

#ifndef __PARSER_HPP_
#define	__PARSER_HPP_

#include <string>
#include <stack>

class Parser {
protected:
	std::stack<std::string> operators;
	std::stack<std::string> operands;
	int result;

	void run(std::string & operation);

public:
	Parser();
	Parser(const Parser & source);
	virtual ~Parser();

	void feed(const std::string &);
	int result() const;
	void reset();

};

#endif
