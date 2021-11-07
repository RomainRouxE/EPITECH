/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "../../include/Explosion.hpp"

Explosion::Explosion(sf::Vector2f m_Posi)
	: Entities("assets/Explosion.png")
{
	m_Position = m_Posi;
	buffer.loadFromFile("assets/explosion.wav");
	son.setBuffer(buffer);
	son.play();
}

Explosion::~Explosion(){
}

void	Explosion::update(float time){
	age += time;
	if(age < LIFE_TIME)
		m_Sprite.setScale(age/LIFE_TIME, age/LIFE_TIME);
	else{
		m_Sprite.setScale(0, 0);
		m_Destroyed = true;
	}
	m_Sprite.setPosition(m_Position);
//Entities::update(time);
}

/*void	Explosion::display(sf::RenderWindow& m_Window){
  if(age < LIFE_TIME)
  Entities::display(m_Window);
  }*/

void	Explosion::react_colision(TypeEntities typeOther){
	(void)typeOther;
}
