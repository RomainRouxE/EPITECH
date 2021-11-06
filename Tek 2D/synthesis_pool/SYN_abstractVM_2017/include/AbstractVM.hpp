//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef ABSTRACTVM_HPP_
# define ABSTRACTVM_HPP_

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <vector>
# include <stack>
# include <list>

# include "exec_type.hpp"
# include "IOperand.hpp"
# include "stream.hpp"
# include "exec.hpp"
# include "parsing.hpp"
# include "gest_error.hpp"

class AbstractVM
{
public:
	virtual ~AbstractVM();
	AbstractVM(const int, char **);
	void load_exec();
	void execution();
	
private:
	std::list<IOperand *> Operandstack;
	std::vector<std::string> exec_list;
	std::string file_name;
	std::string load_line();
	stream *_stream;
	eExecType verif_line();	
};

#endif /* IOPERAND_HPP_ */
