/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#ifndef SECONDBACK_HPP
#define SECONDBACK_HPP

#include <SFML/Graphics.hpp>
#include "Backgrounds.hpp"
#include "Game.hpp"
#include "Space.hpp"

class SecondBack : public Backgrounds
{
public:
	explicit	SecondBack(Space& p_space, Game& p_game);
	~SecondBack();

	virtual void	update(float elapsedTime);
	virtual void    display(sf::RenderWindow& m_Window) override;
	virtual void    react_colision() override;
private:
	Space&	space;
	Game&	game;
};
#endif
