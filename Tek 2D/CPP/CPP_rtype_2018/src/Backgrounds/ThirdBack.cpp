/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "../../include/ThirdBack.hpp"

ThirdBack::ThirdBack(Space& p_space, Game& p_game)
	:space{p_space},
	 game{p_game}
{
	bgSp = 25;
	bgT.loadFromFile("assets/Ga.png");
	bgT.setSmooth(false);
	bgT.setRepeated(true);

	bgX = bgShape.getPosition().y + 1920;
	bgSize.x = 1024;
	bgSize.y = 1024;

	bgShape.setTexture(&bgT);
	bgShape.setSize(bgSize);
}
ThirdBack::~ThirdBack(){
}

void ThirdBack::update(float elapsedTime){
	if (bgX > -1920){
		bgX -= bgSp * elapsedTime;
	}else{
		bgX = 3840;
	}
	bgShape.setPosition(bgX, 0);
}

void    ThirdBack::display(sf::RenderWindow& m_Window){
	Backgrounds::display(m_Window);
}

void    ThirdBack::react_colision(){
	if(game.processing == false){
		m_Destroyed = true;
	}
}
