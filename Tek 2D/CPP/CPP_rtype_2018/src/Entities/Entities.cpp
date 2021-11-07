/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "../../include/Spaceship.hpp"
#include<cstdlib>
#include<ctime>
#include<cmath>

Entities::Entities(std::string const& ImagePath){
	m_Texture.loadFromFile(ImagePath);
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setScale(sf::Vector2f(3, 3));
}

Entities::~Entities(){
}

void	Entities::display(sf::RenderWindow& m_Window){
	m_Window.draw(m_Sprite);
}

float	Entities::getRadius() const {
	return m_Sprite.getLocalBounds().height/2.f +33;
}

float	Entities::CalculeDistance(sf::Vector2f Player_Posi) const{
	sf::Vector2f vector;
	vector.x = (m_Position.x - Player_Posi.x);
	vector.y = (m_Position.y - Player_Posi.y);
	return sqrt(vector.x * vector.x + vector.y * vector.y);
}

void	Entities::testColision(Entities& others){
	auto distance = CalculeDistance(others.m_Position);
	if (distance < getRadius() + others.getRadius())
		react_colision(others.type);
}
