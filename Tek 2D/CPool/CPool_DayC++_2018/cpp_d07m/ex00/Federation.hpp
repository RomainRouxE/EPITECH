#ifndef FEDERATION_H_
# define FEDERATION_H_

#include <iostream>
#include <string>
#include "WarpSystem.hpp"

namespace Federation
{
	namespace Starfleet
	{
		class Ship
		{
		private:
			int _length;
			int _width;
			std::string _name;
			short _maxWarp;
			WarpSystem::Core *_core;
		public:
			Ship(int length, int width, std::string name, short maxWarp);
			~Ship();
			void setupCore(WarpSystem::Core *PtrToCore);
			void checkCore();
		};
	};
	
	class Ship
	{
	private:
		int _length;
		int _width;
		std::string _name;
		short _maxWarp;
		WarpSystem::Core *_core;;
	public:
		Ship(int _length, int _width, std::string name);
		~Ship();
		void setupCore(WarpSystem::Core *PtrToCore);
		void checkCore();
	};
};

#endif 
