/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "../../include/FourthBack.hpp"

FourthBack::FourthBack(Space& p_space, Game& p_game)
	:space{p_space},
	 game{p_game}
{
	bgSp = 30;
	bgT.loadFromFile("assets/Pla.png");
	bgT.setSmooth(false);
	bgT.setRepeated(true);

	bgX = bgShape.getPosition().y - 500;
	bgSize.x = 300;
	bgSize.y = 300;

	bgShape.setTexture(&bgT);
	bgShape.setSize(bgSize);
}
FourthBack::~FourthBack(){
}

void	FourthBack::update(float elapsedTime){
	if (bgX > -1920){
		bgX -= bgSp * elapsedTime;
	}else{
		bgX = 3850;
	}
	bgShape.setPosition(bgX, 650);
}

void    FourthBack::display(sf::RenderWindow& m_Window){
	Backgrounds::display(m_Window);
}

void    FourthBack::react_colision(){
	if(game.processing == false){
		m_Destroyed = true;
	}
}


