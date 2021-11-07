//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef ENEMYONE_HPP
#define ENEMYONE_HPP

#include <SFML/Graphics.hpp>
#include "Entities.hpp"
#include "Space.hpp"
#include "Game.hpp"

class EnemyOne : public Entities
{
public:
	explicit	EnemyOne(Space& p_space, Game& p_game);
	~EnemyOne();

	virtual void	update(float elapsedTime);
	virtual void    react_colision(TypeEntities typeOther) override;
private:
	Space&		space;
	Game&		game;
};
#endif
