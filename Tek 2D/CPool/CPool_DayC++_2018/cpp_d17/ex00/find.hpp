//
// EPITECH PROJECT, 2018
// find.hpp
// File description:
// find.hpp
//

#ifndef FIND_HPP_
#define	FIND_HPP_

#include <algorithm>

template<typename Container>
typename Container::iterator do_find(Container & container, int search) {
	return std::find(container.begin(), container.end(), search);
}

#endif
