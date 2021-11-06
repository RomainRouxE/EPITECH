//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef FACTORY_HPP_
# define FACTORY_HPP_

# include <iostream>
# include <string>
# include <limits>

# include "IOperand.hpp"
# include "Operand_type.hpp"

class   Factory
{

private:
  static IOperand* createInt8(const std::string& value);
  static IOperand* createInt16(const std::string& value);
  static IOperand* createInt32(const std::string& value);
  static IOperand* createFloat(const std::string& value);
  static IOperand* createDouble(const std::string& value);
  static IOperand* createBigDecimal(const std::string& value);

public:
	static IOperand* createOperand(eOperandType type, const std::string& value);	
	Factory() {}
	~Factory() {}
};

#endif /* Factory */
