//
// EPITECH PROJECT, 2018
// WarpSystem.cpp
// File description:
// WarpSystem.cpp
//

#include "WarpSystem.hpp"

WarpSystem::QuantumReactor::QuantumReactor()
{
	this->_stability = true;
}

WarpSystem::QuantumReactor::~QuantumReactor()
{
	
}

bool	WarpSystem::QuantumReactor::isStable()
{
	return (this->_stability);
}

void	WarpSystem::QuantumReactor::setStability(bool stability)
{
	this->_stability = stability;
}

WarpSystem::Core::Core(QuantumReactor *core)
{
	this->_coreReactor = core;
}

WarpSystem::Core::~Core()
{
	
}

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor()
{
	return (this->_coreReactor);
}
