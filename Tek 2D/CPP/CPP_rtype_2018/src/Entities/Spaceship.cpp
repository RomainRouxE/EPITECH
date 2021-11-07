//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include "../../include/Spaceship.hpp"
#include "../../include/Rocket.hpp"

Spaceship::Spaceship(Space& p_space, Game& p_game)
	: Entities{"assets/Ship1.png"},
	  space{p_space},
	  game{p_game}
{
	type = TypeEntities::SHIP;
	m_Position.x = 500;
	m_Position.y = 500;
	m_Speed = 800;
}

Spaceship::~Spaceship(){
}

void Spaceship::updateStat(){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)
	   && LastShoot.getElapsedTime().asSeconds() > 0.1) {
		space.add(std::make_unique<Rocket>(m_Position));
		LastShoot.restart();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		m_LeftPressed = true;
	else
		m_LeftPressed = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		m_RightPressed = true;
	else
		m_RightPressed = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		m_UpPressed = true;
	else
		m_UpPressed = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		m_DownPressed = true;
	else
		m_DownPressed = false;
}


void Spaceship::update(float elapsedTime){
	sf::Vector2f window;
	window.x = sf::VideoMode::getDesktopMode().width;
	window.y = sf::VideoMode::getDesktopMode().height;
	int SpriteWidth = 99;
	int SpriteHeigth = 57;

	updateStat();
	if (!m_Destroyed){
		if (m_RightPressed){
			if (m_Position.x >= window.x - SpriteWidth)
				m_RightPressed = false;
			else
				m_Position.x += m_Speed * elapsedTime;
		}
		if (m_LeftPressed){
			if(m_Position.x <= 0)
				m_LeftPressed = false;
			else
				m_Position.x -= m_Speed * elapsedTime;
		}
		if (m_UpPressed){
			if(m_Position.y >= window.y - SpriteHeigth)
				m_UpPressed = false;
			else
				m_Position.y += m_Speed * elapsedTime;
		}
		if (m_DownPressed){
			if(m_Position.y <= 0)
				m_DownPressed = false;
			else
				m_Position.y -= m_Speed * elapsedTime;
		}
		m_Sprite.setPosition(m_Position);
	}
}

void    Spaceship::react_colision(TypeEntities typeOther){
	if(typeOther == TypeEntities::ENEMY){
		m_Destroyed = true;
		game.GameOver();
		space.add(std::make_unique<Explosion>(m_Position));
	}
}
