//
// EPITECH PROJECT, 2018
// Box.hpp
// File description:
// Box header
//

#ifndef BOX_H_
#define BOX_H_

#include <string>
#include "Wrap.hpp"

class Box : public Wrap
{
protected:

public:
        Box();
	virtual ~Box();
	virtual void wrapMeThat(Object *gift);
};

#endif /* BOX_H_ */
