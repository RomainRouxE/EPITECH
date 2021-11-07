//
// EPITECH PROJECT, 2018
// Skat.hpp
// File description:
// Skat.hpp
//

#ifndef SKAT_H_
#define SKAT_H_

# include <string>
# include <iostream>

class Skat
{
public:
	Skat(std::string const& name, int stimPaks);
	Skat(std::string const& name);
	Skat(int stimPaks);
	Skat();
	~Skat();
	
public:
	int&	stimPaks();
	const std::string& name();
	
public:
	void shareStimPaks(int number, int &stock);
	void addStimPaks(unsigned int number);
	void useStimPaks();
	
public:
	void status();
	
private:
	std::string _name;
	int _stimPaks;
};

#endif
