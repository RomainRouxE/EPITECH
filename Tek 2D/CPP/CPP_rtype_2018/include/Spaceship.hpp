/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP

#include <SFML/Graphics.hpp>
#include "Entities.hpp"
#include "Explosion.hpp"
#include "Space.hpp"
#include "Game.hpp"

class Spaceship : public Entities
{
public:
	explicit	Spaceship(Space& p_space, Game& p_game);
	~Spaceship();

	virtual void	update(float elapsedTime) override;
	virtual void    react_colision(TypeEntities typeOther) override;
private:
	void			updateStat();

	bool			m_LeftPressed{};
	bool			m_RightPressed{};
	bool			m_UpPressed{};
	bool			m_DownPressed{};
	bool			m_Closed{};

	Space&			space;
	Game&			game;
	sf::Clock		LastShoot{};
};
#endif
