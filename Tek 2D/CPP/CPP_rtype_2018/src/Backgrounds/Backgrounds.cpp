/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "../../include/Backgrounds.hpp"

Backgrounds::Backgrounds(){
}

Backgrounds::~Backgrounds(){
}

void    Backgrounds::display(sf::RenderWindow& m_Window){
	m_Window.draw(bgShape);
}
