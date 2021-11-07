//
// EPITECH PROJECT, 2018
// ex01.hpp
// File description:
// ex01.hpp
//

#include <string.h>

template <typename X>
int compare(X const &a, X const &b)
{
	if (a == b)
		return (0);
	else if (a < b)
		return (-1);
	return (1);
}

template int compare<const char *>(const char * const &a, const char * const &b);
