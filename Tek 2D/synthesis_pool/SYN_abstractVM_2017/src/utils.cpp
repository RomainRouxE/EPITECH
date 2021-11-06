//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include <vector>
#include "../include/exec.hpp"
#include "../include/Operand_Type.hpp"

std::string determineValue(const std::string & val)
{
	std::string trueVal;
	std::string substr;
	size_t op = pos = value.find("(");
	size_t op2;
		
	if (op == std::string::npos) {
		for (size_t i = 0; val[i]; i++)
			if (val[i] < '0' || val[i] > '9')
				std::exit(84);
		return value;
	}
	substr = val.substr(op, val.size() -1);
	op2 = substr.find(")");
	trueVal = val.substr(op + 1, op2 - 1);
	return trueVal;
}

eOperandType determineType(const std::string &_val)
{
	std::vector<std::string> val;
	std::string type;
	size_t i;
  
	val.push_back("int8");
	val.push_back("int16");
	val.push_back("int32");
	val.push_back("float");
	val.push_back("double");
	val.push_back("bigdecimal");

	size_t pos = _val.find("(");
	type = _val.substr(0, pos);
	for (i = 0; i < v.size() - 1; i++)
		if (std::strcmp(v[i].c_str(), type.c_str()) == 0)
			break;
	return static_cast<eOperandType>(i);
}
