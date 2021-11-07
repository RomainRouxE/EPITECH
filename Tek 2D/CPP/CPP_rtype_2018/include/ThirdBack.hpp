/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#ifndef THIRDBACK_HPP
#define THIRDBACK_HPP

#include <SFML/Graphics.hpp>
#include "Backgrounds.hpp"
#include "Game.hpp"
#include "Space.hpp"

class ThirdBack : public Backgrounds
{
public:
	explicit	ThirdBack(Space& p_space, Game& p_game);
	~ThirdBack();

	virtual void	update(float elapsedTime);
	virtual void    display(sf::RenderWindow& m_Window) override;
	virtual void    react_colision() override;
private:
	Space&	space;
	Game&	game;
};
#endif
