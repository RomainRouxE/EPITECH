//
// EPITECH PROJECT, 2018
// Federation.hpp
// File description:
// Federation.hpp
//

#include <string>
#include "WarpSystem.hpp"

#ifndef _FEDERATION_HH_
#define _FEDERATION_HH_

namespace Federation
{
	class Ship
	{
	private:
		int _length;
		int _width;
		std::string _name;
		short _maxWarp;
		WarpSystem::Core *Core;
	public:
		Ship(int length, int width, std::string name);
		~Ship();
		
		void setupCore(WarpSystem::Core *_core);
		void checkCore();
	};
	namespace Starfleet
	{
		class Captain
		{
		private:
			std::string _name;
			int _age;
		public:
			Captain(std::string);
			~Captain();
			std::string getName();
			int getAge();
			void setAge(int age);
		};
		class Ship
		{
		private:
			int _length;
			int _width;
			std::string _name;
			short _maxWarp;
			WarpSystem::Core *Core;
			Captain	*captain;
			
		public:
			Ship(int length, int width, std::string name, short maxWarp);
			~Ship();
			void setupCore(WarpSystem::Core *_core);
			void checkCore();
			void promote(Captain*);
		};
		class	Ensign
		{
		private:
			std::string _name;
		public:
			Ensign(std::string);
			~Ensign();
		};
	};
};

#endif
