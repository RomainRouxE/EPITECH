//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

# include "../include/factory.hpp"
# include "../include/Operand.hpp"
# include "../include/gest_Error.hpp"

IOperand* Factory::createInt8(const std::string& value)
{
	if (stoi(value) > std::numeric_limits<char>::max() || stoi(value) < std::numeric_limits<char>::lowest(\
		    ))
		throw Error("Out of range => Int8", 84);
	return (new OperandInt8(value));
}

IOperand* Factory::createInt16(const std::string& value)
{
	if (stoi(value) > std::numeric_limits<short>::max() || stoi(value) < std::numeric_limits<short>::lowes\
	    t())
		throw Error("Out of range => Int16", 84);
	return (new OperandInt16(value));
}

IOperand* Factory::createInt32(const std::string& value)
{
	if (stoi(value) > std::numeric_limits<int>::max() || stoi(value) < std::numeric_limits<int>::lowest())
		throw Error("Out of range => Int32", 84);
	return (new OperandInt32(value));
}

IOperand* Factory::createFloat(const std::string& value)
{
	if (stof(value) > std::numeric_limits<float>::max() || stof(value) < std::numeric_limits<float>::lowes\
	    t())
		throw Error("Out of range => Float", 84);
	return (new OperandFloat(value));
}

IOperand* Factory::createDouble(const std::string& value)
{
	if (stod(value) > std::numeric_limits<double>::max() || stod(value) < std::numeric_limits<double>::low\
	    est())
		throw Error("Out of range => Double", 84);
	return (new OperandDouble(value));
}

IOperand* Factory::createBigDecimal(const std::string& value)
{
	if (stod(value) > std::numeric_limits<long double>::max() || stod(value) < std::numeric_limits<long do\
		    uble>::lowest())
		throw Error("Out of range => Big Decimal", 84);
	return (new OperandBigDecimal(value));
}

IOperand* Factory::createOperand(eOperandType type, const std::string& value)
{
	IOperand* operand = NULL;

	switch (type)
	{
	case Int8:
		operand = Factory::createInt8(value);
		break;
	case Int16:
		operand = Factory::createInt16(value);
		break;
	case Int32:
		operand = Factory::createInt32(value);
		break;
	case Float:
		operand = Factory::createFloat(value);
		break;
	case Double:
		operand = Factory::createDouble(value);
		break;
	case BigDecimal:
		operand = Factory::createBigDecimal(value);
		break;
	default:
		operand = NULL;
		break;
	}
	return (operand);
}
