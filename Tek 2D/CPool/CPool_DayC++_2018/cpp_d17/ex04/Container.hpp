//
// EPITECH PROJECT, 2018
// Container.hpp
// File description:
// Container.hpp
//

#ifndef CONTENER_HPP_
#define CONTENER_HPP_

#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <vector>

template<typename T>
void aff(T val) {
	std::cout << "Value: " << val << std::endl;
}

template<typename T>
void add(T &val) {
	val += 1;
}

template<typename T, template <typename, typename> class container>
class contain
{
private:
	container<T, std::allocator<T> > _contain;
	T _val;
	
public:
	void push(T val)
		{
		_contain.push_back(val);
	}
	void aff()
		{
		std::for_each(_contain.begin(), _contain.end(), &::aff<T>);
	}
	void add()
		{
		std::for_each(_contain.begin(), _contain.end(), &::add<T>);
	}
};

#endif
