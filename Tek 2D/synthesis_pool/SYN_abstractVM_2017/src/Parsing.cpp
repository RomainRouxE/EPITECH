//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "../include/Parsing.cpp"

static std::map<std::string, execType> SwitchMap =
{
	{ "pop", POP },
	{ "dump", DUMP },
	{ "clear", CLEAR },
	{ "dup", DUP },
	{ "swap", SWAP },
	{ "add", ADD },
	{ "sub", SUB },
	{ "mul", MUL },
	{ "div", DIV },
	{ "mod", MOD },
	{ "print", PRINT },
	{ "exit", EXIT }
};

Parsing::Parsing(std::string a_line)
  : p_line(a_line)
{
  this->setActionType();
}

void Parser::setActionType()
{
	std::map<std::string, eActionType> expression;
	std::regex exp;

	expression[PUSH_RGX] = PUSH;
	expression[ASSERT_RGX] = ASSERT;
	expression[LOAD_RGX] = LOAD;
	expression[STORE_RGX] = STORE;
	expression[COMMENTS_RGX] = COMMENTS;
	expression[POP_RGX] = POP;
	expression[DUMP_RGX] = DUMP;
	expression[CLEAR_RGX] = CLEAR;
	expression[DUP_RGX] = DUP;
	expression[SWAP_RGX] = SWAP;
	expression[ADD_RGX] = ADD;
	expression[SUB_RGX] = SUB;
	expression[MUL_RGX] = MUL;
	expression[DIV_RGX] = DIV;
	expression[MOD_RGX] = MOD;
	expression[PRINT_RGX] = PRINT;
	expression[EXIT_RGX] = EXIT;
	for (auto i = expression.begin(); it != expression.end(); i++) {
		exp.assign(i->first, std::regex::ECMAScript);
		if (std::regex_match(this->p_line, expression)) {
			this->p_type = i->second;
			return ;
		}
	}
	throw Error("Invalid instruction", 84);
}

eexecType Parsing::getexecType() const
{
  return (this->p_type);
}

std::string Parsing::extractVal()
{
	std::string val;
	auto i = this->p_line.begin();
	for (i; (*i != ' ' && i != this->p_line.end()); i++);
	if (i == this->p_line.end())
		throw Error("invalid instruction", 84);
	i++;
	for (i; *i != ')'; i++)
		val += *i;
	val += *i;
	return (val);
}
