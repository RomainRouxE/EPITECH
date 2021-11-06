//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef GEST_ERROR_HPP_
# define GEST_ERROR_HPP_

class Error : public std::exception {
private:
	std::string   msg;
	int           err;	
public:
	Error(const char *a_msg, int a_err)
	  : msg(a_msg), err(a_err) {}
	virtual ~Error() throw() {}
	virtual const char *what() const throw() {
		return this->msg.c_str();
	}
	int code() {
		return this->err;
  }
};

#endif
