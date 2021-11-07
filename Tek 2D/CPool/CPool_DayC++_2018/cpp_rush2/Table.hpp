//
// EPITECH PROJECT, 2018
// Table.hpp
// File description:
// Class table header
//

#ifndef TABLE_H_
#define TABLE_H_

#include "Object.hpp"

class ITable
{
protected:
	int _nbObject;
	Object _gift[11];
public:
	ITable();
	virtual ~ITable();
	int getObject() const;
	void addObject(Object *gift);
	void moveObject();
	void lookObject();
};

#endif /* TABLE_H_ */
