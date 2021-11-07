//
// EPITECH PROJECT, 2018
// Wrap.hpp
// File description:
// Wrap header
//

#ifndef WRAP_H_
#define WRAP_H_

#include <string>
#include "Object.hpp"

class Wrap : public Object
{
protected:
	Object *gift;
	bool open;
public:
	Wrap();
	virtual ~Wrap();
	virtual void wrapMeThat(Object *gift);
	void openMe();
	void closeMe();
};

#endif /* WRAP_H_ */
