//
// EPITECH PROJECT, 2018
// WarpSystem.hpp
// File description:
// WarpSystem.hpp
//

#include <string>

#ifndef _WARP_SYSTEM_HH_
#define _WARP_SYSTEM_HH_

namespace WarpSystem
{
	class QuantumReactor
	{
		bool _stability;
		
	public:
		bool isStable();
		void setStability(bool);
		QuantumReactor();
		~QuantumReactor();
	};
	
	class Core
	{
		QuantumReactor *_coreReactor;
		
	public:
		Core(QuantumReactor *coreReactor);
		~Core();
		
		WarpSystem::QuantumReactor* checkReactor();
	};
};

#endif
