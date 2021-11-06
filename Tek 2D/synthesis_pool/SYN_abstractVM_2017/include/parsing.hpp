//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef PARSING_HPP_
# define PARSER_HPP_

# include <string>
# include <regex>
# include <map>
# include "exec_type.hpp"
# include "gest_error.hpp"

# define CLEAR_RGX "([ \\t]*)clear(;([^\n\r])*)*"
# define DUP_RGX "([ \\t]*)dup(;([^\n\r])*)*"
# define SWAP_RGX "([ \\t]*)swap(;([^\n\r])*)*"
# define POP_RGX "([ \\t]*)pop(;([^\n\r])*)*"
# define ADD_RGX "([ \\t]*)add(;([^\n\r])*)*"
# define SUB_RGX "([ \\t]*)sub(;([^\n\r])*)*"
# define MUL_RGX "([ \\t]*)mul(;([^\n\r])*)*"
# define DUMP_RGX "([ \\t]*)dump(;([^\n\r])*)*"
# define DIV_RGX "([ \\t]*)div(;([^\n\r])*)*"
# define MOD_RGX "([ \\t]*)mod(;([^\n\r])*)*"
# define PRINT_RGX "([ \\t]*)print(;([^\n\r])*)*"
# define EXIT_RGX "([ \\t]*)exit(;([^\n\r])*)*"
# define ASSERT_RGX "([ \\t]*)assert ((int(8|16|32)[(](-?[0-9]+)[)])|(float|double|bigdecimal)[(]((-?[0-9]+(\\.[0-9]+)?)[)]))(([ \\t]*);([^\n\r])*)*"
# define LOAD_RGX "([ \\t]*)load ((int(8|16|32)|(float|double|bigdecimal)[(](-?[0-9]+)[)]))(([ \\t]*);([^\n\r])*)*"
# define PUSH_RGX "([ \\t]*)push ((int(8|16|32)[(](-?[0-9]+)[)])|(float|double|bigdecimal)[(]((-?[0-9]+(\\.[0-9]+)?)[)]))(([ \\t]*);([^\n\r])*)*"
# define STORE_RGX "([ \\t]*)store ((int(8|16|32)|(float|double|bigdecimal)[(](-?[0-9]+)[)]))(([ \\t]*);([^\n\r])*)*"
# define COMMENTS_RGX "(([ \\t]*);([^\n\r])*)"

class Parsing
{
public:
	Parsing(std::string _Line);
	virtual ~Parsing();
	eExecType getexectype() const;
	std::string detectval();
private:
	std::string _line;
	eExecType _type;
};

#endif /* PARSING_HPP_ */
