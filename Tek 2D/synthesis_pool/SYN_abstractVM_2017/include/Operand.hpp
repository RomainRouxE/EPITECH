//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef OPERAND_HPP_
# define OPERAND_HPP_

# include <iostream>
# include <typeinfo>
# include <cmath>
# include "IOperand.hpp"
# include "Factory.hpp"

class           OperandInt8 : public IOperand
{

public:
  OperandInt8(const std::string &v) { this->value = v; this->type = eOperandType::Int8; }
  virtual ~OperandInt8() {}

private:
  std::string   value;
  eOperandType  type;

public:
  IOperand* operator+(const IOperand &rhs) const;
  IOperand* operator-(const IOperand &rhs) const;
  IOperand* operator*(const IOperand &rhs) const;
  IOperand* operator/(const IOperand &rhs) const;
  IOperand* operator%(const IOperand &rhs) const;
  std::string toString() const { return (this->value); }
  eOperandType getType() const { return (this->type); }
};

class           OperandInt16 : public IOperand
{

public:
  OperandInt16(const std::string &v) { this->value = v; this->type = eOperandType::Int16; }
  virtual ~OperandInt16() {}

private:
  std::string   value;
  eOperandType  type;

public:
  IOperand* operator+(const IOperand &rhs) const;
  IOperand* operator-(const IOperand &rhs) const;
  IOperand* operator*(const IOperand &rhs) const;
  IOperand* operator/(const IOperand &rhs) const;
  IOperand* operator%(const IOperand &rhs) const;
  std::string toString() const { return (this->value); }
  eOperandType getType() const { return (this->type); }
};

class           OperandInt32 : public IOperand
{

public:
  OperandInt32(const std::string &v) { this->value = v; this->type = eOperandType::Int32; }
  virtual ~OperandInt32() {}

private:
  std::string   value;
  eOperandType  type;

public:
  IOperand* operator+(const IOperand &rhs) const;
  IOperand* operator-(const IOperand &rhs) const;
  IOperand* operator*(const IOperand &rhs) const;
  IOperand* operator/(const IOperand &rhs) const;
  IOperand* operator%(const IOperand &rhs) const;
  std::string toString() const { return (this->value); }
  eOperandType getType() const { return (this->type); }
};

class           OperandFloat : public IOperand
{

public:
  OperandFloat(const std::string &v) { this->value = v; this->type = eOperandType::Float; }
  virtual ~OperandFloat() {}

private:
  std::string   value;
  eOperandType  type;

public:
  IOperand* operator+(const IOperand &rhs) const;
  IOperand* operator-(const IOperand &rhs) const;
  IOperand* operator*(const IOperand &rhs) const;
  IOperand* operator/(const IOperand &rhs) const;
  IOperand* operator%(const IOperand &rhs) const;
  std::string toString() const { return (this->value); }
  eOperandType getType() const { return (this->type); }
};

class           OperandBigDecimal : public IOperand
{

public:
  OperandBigDecimal(const std::string &v) { this->value = v; this->type = eOperandType::BigDe\
cimal; }
  virtual ~OperandBigDecimal() {}

private:
  std::string   value;
  eOperandType  type;

public:
  IOperand* operator+(const IOperand &rhs) const;
  IOperand* operator-(const IOperand &rhs) const;
  IOperand* operator*(const IOperand &rhs) const;
  IOperand* operator/(const IOperand &rhs) const;
  IOperand* operator%(const IOperand &rhs) const;
  std::string toString() const { return (this->value); }
  eOperandType getType() const { return (this->type); }
};

class           OperandDouble : public IOperand
{

public:
  OperandDouble(const std::string &v) { this->value = v; this->type = eOperandType::Double; }
  virtual ~OperandDouble() {}

private:
  std::string   value;
  eOperandType  type;

public:
  IOperand* operator+(const IOperand &rhs) const;
  IOperand* operator-(const IOperand &rhs) const;
  IOperand* operator*(const IOperand &rhs) const;
  IOperand* operator/(const IOperand &rhs) const;
  IOperand* operator%(const IOperand &rhs) const;
  std::string toString() const { return (this->value); }
  eOperandType getType() const { return (this->type); }
};

#endif 
