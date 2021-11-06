//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef STREAM_HPP_
# define STREAM_HPP_

# include <unistd.h>
# include <iostream>
# include <sstream>
# include <fstream>
# include <string>

# include "gest_error.hpp"

enum class streamType
{ STDIN, FILE };

class stream
{
protected:
	stream();
	virtual ~stream();
	void comments(std::string& );
	void epurstr(std::string& );
	void clear(std::string& );
public:
	virtual std::string getLine() = 0;
	virtual bool isOpen() const = 0;
	virtual void close() = 0;
	virtual streamType type() const = 0;
	virtual bool exit() const = 0;
};

class cinstream : public stream
{
public:
	cinstream();
	virtual ~cinstream();
	virtual std::string getLine();
	virtual bool isOpen() const;
	virtual void close();
	virtual streamType type() const;
	virtual bool exit() const;
private:
	bool _open;
	bool _exit;
};

class filestream : public stream
{
public:
	filestream(std::string);
	virtual ~filestream();
	virtual std::string getLine();
	virtual bool isOpen() const;
	virtual void close();
	virtual streamType type() const;
	virtual bool exit() const;
private:
	bool _stream;
};

#endif /* STREAM_HPP_ */
