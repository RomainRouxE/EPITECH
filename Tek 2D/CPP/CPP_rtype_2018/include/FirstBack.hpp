/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#ifndef FIRSTBACK_HPP
#define FIRSTBACK_HPP

#include <SFML/Graphics.hpp>
#include "Backgrounds.hpp"
#include "Game.hpp"
#include "Space.hpp"

class FirstBack : public Backgrounds
{
public:
	explicit	FirstBack(Space& p_space, Game& p_game);
	~FirstBack();

	virtual void	update(float elapsedTime);
	virtual void    display(sf::RenderWindow& m_Window) override;
	virtual void    react_colision() override;
private:
	Space&	space;
	Game&	game;
};
#endif
