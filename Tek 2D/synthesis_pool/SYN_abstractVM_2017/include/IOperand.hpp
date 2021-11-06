//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef IOPERAND_HPP_
# define IOPERAND_HPP_

# include <string>
# include "Operand_type.hpp"

class  IOperand
{
public:
	virtual  std:: string  toString ()  const =0;
	virtual  eOperandType  getType ()  const =0;
	
	virtual  IOperand* operator +( const  IOperand &rhs) const = 0; // sum
	virtual  IOperand* operator -( const  IOperand &rhs) const = 0; // diff
	virtual  IOperand* operator *( const  IOperand &rhs) const = 0; // mul
	virtual  IOperand* operator /( const  IOperand &rhs) const = 0; // div
	virtual  IOperand* operator %( const  IOperand &rhs) const = 0; // mod
	
	virtual ~IOperand () {};
};

#endif /* IOPERAND_HPP_ */
