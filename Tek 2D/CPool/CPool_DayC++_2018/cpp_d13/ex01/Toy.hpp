//
// EPITECH PROJECT, 2018
// Toy.hpp
// File description:
// Toy.hpp
//

#ifndef TOY_HPP_
#define TOY_HPP_

#include <iostream>
#include <string>
#include "Picture.hpp"

class Toy
{
public:
	typedef enum ToyType
	{
		BASIC_TOY,
		ALIEN
	}		ToyType;
private:
	ToyType	_type;
	std::string	_name;
	Picture	_picture;
	
public:
	Toy();
	Toy(ToyType type, std::string const &name, std::string const &file);
	Toy(Toy const &cls);
	~Toy();
	ToyType	getType() const;
	std::string getName() const;
	void setName(std::string const &name);
	bool setAscii(std::string const &data);
	std::string getAscii() const;
	Picture	getPicture() const;
	Toy &operator=(Toy const &cls);
};

#endif
