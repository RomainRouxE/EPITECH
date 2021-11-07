//
// EPITECH PROJECT, 2018
// Object.hpp
// File description:
// Class object header
//

#ifndef OBJECT_H_
#define OBJECT_H_

class Object
{
protected:
public:
	Object();
	virtual ~Object();
	virtual void isTaken(void);
	virtual void wrapMeThat(Object *gift);
};

#endif /* OBJECT_H_ */
