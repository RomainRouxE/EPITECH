/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#ifndef BACKGROUNDS_HPP
#define BACKGROUNDS_HPP

#include <SFML/Graphics.hpp>

class Backgrounds
{
public:
	explicit		Backgrounds();
	~Backgrounds();

	virtual void		display(sf::RenderWindow& m_Window);
	virtual void	        update(float elapsedTime) = 0;

	virtual	void		react_colision() = 0;
	static inline   bool    isDestroyed(std::unique_ptr<Backgrounds>& element)
		{return element->m_Destroyed;};
protected:
	sf::Texture             bgT{};
	sf::RectangleShape      bgShape{};
	sf::Vector2f            bgSize{};
	sf::Sprite              bgS{};
	float                   bgSp{};
	float                   bgX{};

	bool			m_Destroyed{false};
};
#endif
