/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "../../include/Rocket.hpp"
//#include "GestionnaireRessources.h"

Rocket::Rocket(sf::Vector2f p_posi)
	: Entities{"assets/Rocket.png"}
{
	type = TypeEntities::ROCKET;
	m_Position = p_posi;
	speed = 1000;
	buffer.loadFromFile("assets/Rocket.wav");
	son.setBuffer(buffer);
	son.play();
}

Rocket::~Rocket(){
}

void Rocket::update(float time){
	//std::srand(std::time(NULL));
	m_Position.x += speed * time;
	m_Sprite.setPosition(m_Position);
	//if(m_Position.x <= -99){
	//m_Position.x = (1920 + 99);
	//m_Position.y = std::rand()%800;
	//m_Speed = std::rand()%80;
}

void Rocket::react_colision(TypeEntities typeOther) {
	if(typeOther != TypeEntities::SHIP) {
		m_Destroyed = true;
	}
}

