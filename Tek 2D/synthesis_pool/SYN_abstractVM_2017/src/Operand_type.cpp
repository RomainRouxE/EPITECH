//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "../include/Operand.hpp"

Operand Operand::toString()
{
	return this->std::to_string();
}

// Int8

IOperand* OperandInt8::operator+(const IOperand &rhs) const
{
	IOperand* res;

	if (rhs.getType() > this->getType()) {
		res = Factory::createOperand(rhs.getType(), this->toString());
		return (rhs.operator+(*res));
	}
	else {
		int8_t calc = stoi(this->toString()) + stoi(rhs.toString());
		res = Factory::createOperand(this->getType(), rhs.toString());
		return (Factory::createOperand(this->getType(), std::to_string(calc)));
	}
}

IOperand* OperandInt8::operator-(const IOperand &rhs) const
{
	IOperand* res;

	if (rhs.getType() > this->getType()) {
		res = Factory::createOperand(rhs.getType(), this->toString());
		return (rhs.operator-(*res));
	}
	else {
		int8_t calc = stoi(this->toString()) - stoi(rhs.toString());
		res = Factory::createOperand(this->getType(), rhs.toString());
		return (Factory::createOperand(this->getType(), std::to_string(calc)));
	}
}

IOperand* OperandInt8::operator*(const IOperand &rhs) const
{
	IOperand* res;

	if (rhs.getType() > this->getType()) {
		res = Factory::createOperand(rhs.getType(), this->toString());
		return (rhs.operator*(*res));
	}
	else {
		int8_t calc = stoi(this->toString()) * stoi(rhs.toString());
		res = Factory::createOperand(this->getType(), rhs.toString());
		return (Factory::createOperand(this->getType(), std::to_string(calc)));
	}
}

IOperand* OperandInt8::operator/(const IOperand &rhs) const
{
	IOperand* res;

	if (rhs.getType() > this->getType()) {
		res = Factory::createOperand(rhs.getType(), this->toString());
		return (rhs.operator/(*res));
	}
	else {
		int8_t calc = stoi(this->toString()) / stoi(rhs.toString());
		res = Factory::createOperand(this->getType(), rhs.toString());
		return (Factory::createOperand(this->getType(), std::to_string(calc)));
	}
}

IOperand* OperandInt8::operator%(const IOperand &rhs) const
{
	IOperand* res;

	if (rhs.getType() > this->getType()) {
		res = Factory::createOperand(rhs.getType(), this->toString());
		return (rhs.operator%(*res));
	}
	else {
		int8_t calc = stoi(this->toString()) % stoi(rhs.toString());
		res = Factory::createOperand(this->getType(), rhs.toString());
		return (Factory::createOperand(this->getType(), std::to_string(calc)));
	}
}

// Int16

IOperand* OperandInt16::operator+(const IOperand &rhs) const
{
	IOperand* res;

	if (rhs.getType() > this->getType()) {
		res = Factory::createOperand(rhs.getType(), this->toString());
		return (rhs.operator+(*res));
	}
	else {
		int16_t calc = stoi(this->toString()) + stoi(rhs.toString());
		res = Factory::createOperand(this->getType(), rhs.toString());
		return (Factory::createOperand(this->getType(), std::to_string(calc)));
	}
}

IOperand* OperandInt16::operator-(const IOperand &rhs) const
{
	IOperand* res;

	if (rhs.getType() > this->getType()) {
		res = Factory::createOperand(rhs.getType(), this->toString());
		return (rhs.operator-(*res));
	}
	else {
		int16_t calc = stoi(this->toString()) - stoi(rhs.toString());
		res = Factory::createOperand(this->getType(), rhs.toString());
		return (Factory::createOperand(this->getType(), std::to_string(calc)));
	}
}

IOperand* OperandInt16::operator*(const IOperand &rhs) const
{
	IOperand* res;

	if (rhs.getType() > this->getType()) {
		res = Factory::createOperand(rhs.getType(), this->toString());
		return (rhs.operator*(*res));
	}
	else {
		int16_t calc = stoi(this->toString()) * stoi(rhs.toString());
		res = Factory::createOperand(this->getType(), rhs.toString());
		return (Factory::createOperand(this->getType(), std::to_string(calc)));
	}
}

IOperand* OperandInt16::operator/(const IOperand &rhs) const
{
	IOperand* res;

	if (rhs.getType() > this->getType()) {
		res = Factory::createOperand(rhs.getType(), this->toString());
		return (rhs.operator/(*res));
	}
	else {
		int16_t calc = stoi(this->toString()) / stoi(rhs.toString());
		res = Factory::createOperand(this->getType(), rhs.toString());
		return (Factory::createOperand(this->getType(), std::to_string(calc)));
	}
}

IOperand* OperandInt16::operator%(const IOperand &rhs) const
{
	IOperand*     res;

	if (rhs.getType() > this->getType()) {
		res = Factory::createOperand(rhs.getType(), this->toString());
		return (rhs.operator%(*res));
	}
	else {
		int16_t calc = stoi(this->toString()) % stoi(rhs.toString());
		res = Factory::createOperand(this->getType(), rhs.toString());
		return (Factory::createOperand(this->getType(), std::to_string(calc)));
	}
}

// Int32

IOperand* OperandInt32::operator+(const IOperand &rhs) const
{
  IOperand* res;

  if (rhs.getType() > this->getType()) {
      res = Factory::createOperand(rhs.getType(), this->toString());
      return (rhs.operator+(*res));
    }
  else {
      int32_t calc = stoi(this->toString()) + stoi(rhs.toString());
      res = Factory::createOperand(this->getType(), rhs.toString());
      return (Factory::createOperand(this->getType(), std::to_string(calc)));
    }
}

IOperand* OperandInt32::operator-(const IOperand &rhs) const
{
	IOperand* res;

	if (rhs.getType() > this->getType()) {
		res = Factory::createOperand(rhs.getType(), this->toString());
		return (rhs.operator-(*res));
	}
	else {
		int32_t calc = stoi(this->toString()) - stoi(rhs.toString());
		res = Factory::createOperand(this->getType(), rhs.toString());
		return (Factory::createOperand(this->getType(), std::to_string(calc)));
	}
}

IOperand* OperandInt32::operator*(const IOperand &rhs) const
{
  IOperand* res;

  if (rhs.getType() > this->getType()) {
      res = Factory::createOperand(rhs.getType(), this->toString());
      return (rhs.operator*(*res));
    }
  else {
      int32_t calc = stoi(this->toString()) * stoi(rhs.toString());
      res = Factory::createOperand(this->getType(), rhs.toString());
      return (Factory::createOperand(this->getType(), std::to_string(calc)));
    }
}

IOperand* OperandInt32::operator/(const IOperand &rhs) const
{
	IOperand* res;

	if (rhs.getType() > this->getType()) {
		res = Factory::createOperand(rhs.getType(), this->toString());
		return (rhs.operator/(*res));
	}
	else {
		int32_t calc = stoi(this->toString()) / stoi(rhs.toString());
		res = Factory::createOperand(this->getType(), rhs.toString());
		return (Factory::createOperand(this->getType(), std::to_string(calc)));
	}
}

IOperand* OperandInt32::operator%(const IOperand &rhs) const
{
	IOperand* res;

	if (rhs.getType() > this->getType()) {
		res = Factory::createOperand(rhs.getType(), this->toString());
		return (rhs.operator%(*res));
	}
	else {
		int32_t calc = stoi(this->toString()) % stoi(rhs.toString());
		res = Factory::createOperand(this->getType(), rhs.toString());
		return (Factory::createOperand(this->getType(), std::to_string(calc)));
	}
}

// Operandfloat

IOperand* OperandFloat::operator+(const IOperand &rhs) const
{
	IOperand* res;

	if (rhs.getType() > this->getType()) {
		res = Factory::createOperand(rhs.getType(), this->toString());
		return (rhs.operator+(*res));
	}
	else {
		float calc = stof(this->toString()) + stof(rhs.toString());
		res = Factory::createOperand(this->getType(), rhs.toString());
		return (Factory::createOperand(this->getType(), std::to_string(calc)));
	}
}

IOperand* OperandFloat::operator-(const IOperand &rhs) const
{
	IOperand* res;

	if (rhs.getType() > this->getType()) {
		res = Factory::createOperand(rhs.getType(), this->toString());
		return (rhs.operator-(*res));
	}
	else {
		float calc = stof(this->toString()) - stof(rhs.toString());
		res = Factory::createOperand(this->getType(), rhs.toString());
		return (Factory::createOperand(this->getType(), std::to_string(calc)));
	}
}

IOperand* OperandFloat::operator*(const IOperand &rhs) const
{
	IOperand* res;

	if (rhs.getType() > this->getType()) {
		res = Factory::createOperand(rhs.getType(), this->toString());
		return (rhs.operator*(*res));
	}
	else {
		float calc = stof(this->toString()) * stof(rhs.toString());
		res = Factory::createOperand(this->getType(), rhs.toString());
		return (Factory::createOperand(this->getType(), std::to_string(calc)));
	}
}

IOperand* OperandFloat::operator/(const IOperand &rhs) const
{
	IOperand* res;

	if (rhs.getType() > this->getType()) {
		res = Factory::createOperand(rhs.getType(), this->toString());
		return (rhs.operator/(*res));
	}
	else {
		float calc = stof(this->toString()) / stof(rhs.toString());
		res = Factory::createOperand(this->getType(), rhs.toString());
		return (Factory::createOperand(this->getType(), std::to_string(calc)));
	}
}

IOperand* OperandFloat::operator%(const IOperand &rhs) const
{
	IOperand* res;

	if (rhs.getType() > this->getType()) {
		res = Factory::createOperand(rhs.getType(), this->toString());
		return (rhs.operator%(*res));
	}
	else {
		float calc = std::fmod(stod(this->toString()), stod(rhs.toString()));
		res = Factory::createOperand(this->getType(), rhs.toString());
		return (Factory::createOperand(this->getType(), std::to_string(calc)));
	}
}

// OperandDouble

IOperand* OperandDouble::operator+(const IOperand &rhs) const
{
	IOperand* res;

	if (rhs.getType() > this->getType()) {
		res = Factory::createOperand(rhs.getType(), this->toString());
		return (rhs.operator+(*res));
	}
	else {
		double calc = stod(this->toString()) + stod(rhs.toString());
		res = Factory::createOperand(this->getType(), rhs.toString());
		return (Factory::createOperand(this->getType(), std::to_string(calc)));
	}
}

IOperand* OperandDouble::operator-(const IOperand &rhs) const
{
	IOperand* res;

	if (rhs.getType() > this->getType()) {
		res = Factory::createOperand(rhs.getType(), this->toString());
		return (rhs.operator-(*res));
	}
	else {
		double calc = stod(this->toString()) - stod(rhs.toString());
		res = Factory::createOperand(this->getType(), rhs.toString());
		return (Factory::createOperand(this->getType(), std::to_string(calc)));
	}
}

IOperand* OperandDouble::operator*(const IOperand &rhs) const
{
	IOperand* res;

	if (rhs.getType() > this->getType()) {
		res = Factory::createOperand(rhs.getType(), this->toString());
		return (rhs.operator*(*res));
	}
	else {
		double calc = stod(this->toString()) * stod(rhs.toString());
		res = Factory::createOperand(this->getType(), rhs.toString());
		return (Factory::createOperand(this->getType(), std::to_string(calc)));
	}
}

IOperand* OperandDouble::operator%(const IOperand &rhs) const
{
	IOperand* res;

	if (rhs.getType() > this->getType()) {
		res = Factory::createOperand(rhs.getType(), this->toString());
		return (rhs.operator%(*res));
	}
	else {
		double calc = std::fmod(stod(this->toString()), stod(rhs.toString()));
		res = Factory::createOperand(this->getType(), rhs.toString());
		return (Factory::createOperand(this->getType(), std::to_string(calc)));
	}
}

// Operanddecimal

IOperand* OperandBigDecimal::operator+(const IOperand &rhs) const
{
	IOperand* res;

	if (rhs.getType() > this->getType()) {
		res = Factory::createOperand(rhs.getType(), this->toString());
		return (rhs.operator+(*res));
	}
	else {
		long double calc = stod(this->toString()) + stod(rhs.toString());
		res = Factory::createOperand(this->getType(), rhs.toString());
		return (Factory::createOperand(this->getType(), std::to_string(calc)));
	}
}

IOperand* OperandBigDecimal::operator-(const IOperand &rhs) const
{
	IOperand*     res;

	if (rhs.getType() > this->getType()) {
		res = Factory::createOperand(rhs.getType(), this->toString());
		return (rhs.operator-(*res));
	}
	else {
		long double calc = stod(this->toString()) - stod(rhs.toString());
		res = Factory::createOperand(this->getType(), rhs.toString());
		return (Factory::createOperand(this->getType(), std::to_string(calc)));
	}
}

IOperand* OperandBigDecimal::operator*(const IOperand &rhs) const
{
	IOperand*     res;

	if (rhs.getType() > this->getType()) {
		res = Factory::createOperand(rhs.getType(), this->toString());
		return (rhs.operator*(*res));
	}
	else {
		long double calc = stod(this->toString()) * stod(rhs.toString());
		res = Factory::createOperand(this->getType(), rhs.toString());
		return (Factory::createOperand(this->getType(), std::to_string(calc)));
	}
}

IOperand* OperandBigDecimal::operator%(const IOperand &rhs) const
{
	IOperand* res;

	if (rhs.getType() > this->getType()) {
		res = Factory::createOperand(rhs.getType(), this->toString());
		return (rhs.operator%(*res));
	}
	else {
		long double calc = std::fmod(stod(this->toString()), stod(rhs.toString()));
		res = Factory::createOperand(this->getType(), rhs.toString());
		return (Factory::createOperand(this->getType(), std::to_string(calc)));
	}
}

IOperand* OperandBigDecimal::operator/(const IOperand &rhs) const
{
	IOperand*     res;

	if (rhs.getType() > this->getType()) {
		res = Factory::createOperand(rhs.getType(), this->toString());
		return (rhs.operator/(*res));
	}
	else {
		long double calc = stod(this->toString()) / stod(rhs.toString());
		res = Factory::createOperand(this->getType(), rhs.toString());
		return (Factory::createOperand(this->getType(), std::to_string(calc)));
	}
}
