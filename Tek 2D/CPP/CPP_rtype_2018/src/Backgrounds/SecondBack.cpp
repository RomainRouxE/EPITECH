/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "../../include/SecondBack.hpp"

SecondBack::SecondBack(Space& p_space, Game& p_game)
	:space{p_space},
	game{p_game}
{
	bgSp = 20;
	bgT.loadFromFile("assets/b.jpg");
	bgT.setSmooth(false);
	bgT.setRepeated(true);

	bgX = bgShape.getPosition().y;
	bgSize.x = 1920;
	bgSize.y = 1080;

	bgShape.setTexture(&bgT);
	bgShape.setSize(bgSize);
	
}
SecondBack::~SecondBack(){
}

void SecondBack::update(float elapsedTime){
	if (bgX > 0){
		bgX -= bgSp * elapsedTime;
	}else{
		bgX = 1920;
	}
	bgShape.setPosition(bgX, 0);
}

void    SecondBack::display(sf::RenderWindow& m_Window){
	Backgrounds::display(m_Window);
}

void    SecondBack::react_colision(){
	if(game.processing == false){
		m_Destroyed = true;
	}
}
