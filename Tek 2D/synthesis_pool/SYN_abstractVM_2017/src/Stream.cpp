//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "../include/Stream.hpp"

stream::stream()
{
}

stream::~stream()
{
}

void stream::comments(std::string& s)
{
	std::string ns;

	if (s.length() < 3)
		return ;
	auto it = s.begin();
	ns += *it; it++;
	ns += *it; it++;
	for (it; (*it != ';' && it != s.end()); it++)
		ns += *it;
	s = ns;
}

void stream::epurstr(std::string& s)
{
	bool space = false;
	auto p = s.begin();
  
	for (auto ch : s) {
		if (std::isspace(ch))
			space = p != s.begin();
		else {
			if (space)
				*p++ = ' ';
			*p++ = ch;
			space = false;
		}
	}
	s.erase(p, s.end());
}

std::string cinstream::getLine()
{
        std::string line;

        getline(file, line);
        return (line);
}

void stream::clear(std::string& s)
{
  this->epurstr(s);
  this->comments(s);
  this->epurstr(s);
}

cinstream::cinstream()
  : _open(true)
{}

Cinstream::~cinstream()
{
  this->close();
}

bool filestream::isOpen() const
{
  return (this->_stream.is_open());
}

void filestream::close()
{
  this->_stream.close();
}

eStreamType filestream::type() const
{
  return (streamType::FILE);
}

bool fileStream::exit() const
{
  return (this->p_exit);
}
