//
// EPITECH PROJECT, 2018
// Picture.hpp
// File description:
// Picture.hpp
//

#ifndef PICTURE_HPP_
#define PICTURE_HPP_

#include <iostream>
#include <string>

class Picture
{
public:
	std::string _data;
	bool getPictureFromFile(const std::string &file);

	Picture();
	Picture(const std::string &file);
	Picture(Picture const &Pic);
	~Picture();
	void setData(std::string const &data);
	std::string getData() const;
	Picture	&operator=(Picture const &Pic);
};

#endif
