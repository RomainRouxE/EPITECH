//
// EPITECH PROJECT, 2018
// LittlePony.hpp
// File description:
// Little Pony header
//

#ifndef LITTLEPONY_H_
#define LITTLEPONY_H_

#include <string>
#include "Toy.hpp"

class LittlePony : public Toy
{
protected:

public:
        LittlePony(std::string title);
        virtual ~LittlePony();
        virtual void isTaken();
};

#endif /* LITTLEPONY_H_ */
