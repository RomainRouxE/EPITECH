/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "../../include/FirstBack.hpp"

FirstBack::FirstBack(Space& p_space, Game& p_game)
	:space{p_space},
	 game{p_game}
{
	bgSp = 20;
	bgT.loadFromFile("assets/b.jpg");
	bgT.setSmooth(false);
	bgT.setRepeated(true);
	
	bgX = bgShape.getPosition().y;
	bgSize.x = 1921;
	bgSize.y = 1080;

	bgShape.setTexture(&bgT);
	bgShape.setSize(bgSize);
	
}
FirstBack::~FirstBack(){
}

void	FirstBack::update(float elapsedTime){
	if (bgX > -1920){
		bgX -= bgSp * elapsedTime;
	}else{
		bgX = 0;
	}
	bgShape.setPosition(bgX, 0);
}

void    FirstBack::display(sf::RenderWindow& m_Window){
	Backgrounds::display(m_Window);
}

void    FirstBack::react_colision(){
	if(game.processing == false){
		m_Destroyed = true;
	}
}
