//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "../include/AbstractVM.hpp"

AbstractVM::AbstractVM(const int ac, char **av)
{
	if (ac > 2)
		throw Error("Invalid argument", 84);
	else if (ac == 2) {
		if (av[1] != "")
			this->file_name = av[1];
		else
			throw Error("Invalid FileName", 84);
	}
	else
		this->file_name = "";
	if (this->file_name!= "")
		this->_stream = new filestream(this->file_name);
	else
		this->_stream = new cinstream();
}

AbstractVM::~AbstractVM()
{
	if (this->_stream->isOpen())
		this->_stream->close();	
}

void AbstractVM::load_exec()
{
	Exec ac;
	auto i = this->exec_list.begin();
	while (i != this->exec_list.end()) {
		Parsing pars(*i);
//		if (pars.getexectype() == PUSH || pars.getexectype() == STORE
//		    || pars.getexectype() == LOAD || pars.getexectype() == ASSERT)
//			ac.exec(pars.getexectype(), this->Operandstack, pars.detectval());
//		else
//			ac.exec(pars.getexectype(), this->Operandstack);
		i++;
	}
}

void AbstractVM::execution()
{
	while(this->_stream->isOpen()) {
		std::string cmd = this->_stream->getLine();
		this->exec_list.push_back(cmd);
		if (cmd == ";;" && this->_stream->exit() == false)
			throw Error("Error ! program need the 'exit' instruction to quit", 84);
	}
}
