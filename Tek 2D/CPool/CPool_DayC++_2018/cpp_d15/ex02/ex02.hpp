//
// EPITECH PROJECT, 2018
// ex02.hpp
// File description:
// ex02.hpp
//

#include <iostream>

template <typename X>
X const	&min(X const &a, X const &b)
{
	std::cout << "template min" << std::endl;
	if (b < a)
		return (b);
	return (a);
}

int const &min(int const &a, int const &b)
{
	std::cout << "non-template min" << std::endl;
	if (b < a)
		return (b);
	return (a);
}

template<typename X>
X templateMin(X const *tab, int const len)
{
	int i(1);
	X val = tab[0];

	while (i < len) {
		val = min<X>(val, tab[i]);
		i++;
	}
	return (val);
}

int nonTemplateMin(int const *tab, int const len)
{
	int i(1);
	int val = tab[0];

	while (i < len) {
		val = min(val, tab[i]);
		i++;
	}
	return (val);
}
