/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#ifndef FOURTHBACK_HPP
#define FOURTHBACK_HPP

#include <SFML/Graphics.hpp>
#include "Backgrounds.hpp"
#include "Game.hpp"
#include "Space.hpp"

class FourthBack : public Backgrounds
{
public:
	explicit	FourthBack(Space& p_space, Game& p_game);
	~FourthBack();

	virtual void	update(float elapsedTime);
	virtual void    display(sf::RenderWindow& m_Window) override;
	virtual void    react_colision() override;
private:
	Space&	space;
	Game&	game;
};
#endif
