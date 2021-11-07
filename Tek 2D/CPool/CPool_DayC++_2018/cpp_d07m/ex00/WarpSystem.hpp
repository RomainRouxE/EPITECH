//
// EPITECH PROJECT, 2018
// WarpSystem.hpp
// File description:
// WarpSystem.hpp
//

#ifndef WARPSYSTEM_H_
#define WARPSYSTEM_H_

#include <string>
#include <iostream>

namespace WarpSystem
{
	class QuantumReactor
	{
	private:
		bool _stability;
	public:
		QuantumReactor();
		~QuantumReactor();
		bool isStable();
		void setStability(bool);
	};
	
	class Core
	{
	private:
		QuantumReactor	*_coreReactor;
	public:
		Core(QuantumReactor *coreReactor);
		~Core();
		QuantumReactor *checkReactor();
	};
};

#endif
