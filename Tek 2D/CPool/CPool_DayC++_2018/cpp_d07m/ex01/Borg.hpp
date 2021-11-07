//
// EPITECH PROJECT, 2018
// Borg.hpp
// File description:
// Borg.hpp
//

#ifndef _BORG_HH_
#define _BORG_HH_

namespace Borg
{
	class Ship
	{
	private:
		int _side;
		short _maxWarp;
		WarpSystem::Core *Core;
	public:
		Ship();
		~Ship();
		void setupCore(WarpSystem::Core *_core);
		void checkCore();
	};
};

#endif
