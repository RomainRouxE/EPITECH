//
// EPITECH PROJECT, 2018
// Picture.cpp
// File description:
// Picture.cpp
//

#include <fstream>
#include "Picture.hpp"

static std::string readFile(const std::string file)
{
	char c;
	std::string str;
	
	std::ifstream my_stream(file.c_str());
	if (my_stream) {
		while (my_stream.get(c))
			str += c;
		my_stream.close();
	}
	else
		str = "ERROR";
	return (str);
}

Picture::Picture()
{
	_data = "";
}

Picture::Picture(const std::string &file)
{
	_data = readFile(file);
}

Picture::~Picture()
{
}

void Picture::setData(std::string const &data)
{
	_data = data;
}

bool Picture::getPictureFromFile(const std::string &file)
{
	_data = readFile(file);
	if (_data == "ERROR")
		return (false);
	return (true);
}

std::string Picture::getData() const
{
	return _data;
}
