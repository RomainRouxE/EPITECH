/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#ifndef ROCKET_HPP
#define ROCKET_HPP

#include <SFML/Audio.hpp>
#include "Entities.hpp"


class Rocket : public Entities
{
public:
	Rocket(sf::Vector2f p_position);
	~Rocket();

	virtual void	update(float elapsedTime);
	virtual void	react_colision(TypeEntities typeOther) override;
private:
	sf::SoundBuffer buffer{};
	sf::Sound	son{};
	float		speed{};
};

#endif // ROCKET_HPP
