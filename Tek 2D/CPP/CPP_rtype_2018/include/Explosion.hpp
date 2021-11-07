/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#ifndef EXPLOSION_HPP
#define EXPLOSION_HPP

#include <SFML/Audio.hpp>
#include "Entities.hpp"

class Explosion : public Entities
{
public:
  	Explosion(sf::Vector2f m_Position);
	~Explosion();
	
	virtual void	update(float time) override;
	//void		start();
	virtual void    react_colision(TypeEntities typeOther) override;
	//virtual void    display(sf::RenderWindow& m_Window) override;
protected:

private:
	//bool			started{false};
	float			age{};
	static	constexpr float LIFE_TIME{0.1f};
	sf::Vector2f		position{};
	sf::SoundBuffer		buffer{};
	sf::Sound		son{};
	
};
#endif
