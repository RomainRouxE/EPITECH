/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#ifndef ENTITIES_HPP
#define ENTITIES_HPP

#include <SFML/Graphics.hpp>

enum class TypeEntities{SHIP, ENEMY, ROCKET, OTHER};

class Entities
{
public:
	explicit	Entities(std::string const& ImagePath);
	~Entities();

	virtual void		display(sf::RenderWindow& m_Window);
	virtual void		update(float elapsedTime) = 0;
 	virtual void		react_colision(TypeEntities type) = 0;

	void			testColision(Entities& eleme);
	float			CalculeDistance(sf::Vector2f m_Position) const;
	float			getRadius() const;
	static inline	bool	isDestroyed(std::unique_ptr<Entities>& element)
		{return element->m_Destroyed;};
protected:	
	//------------Entities--------------
	sf::Vector2f		m_Position{};
	sf::Sprite		m_Sprite{};
	sf::Texture		m_Texture{};
	float			m_Speed{};
	bool			m_Destroyed{false};
	TypeEntities	type{TypeEntities::OTHER};
	//-----------Backgrounds-------------
	sf::Texture             bgT{};
	sf::RectangleShape      bgShape{};
	sf::Vector2f            bgSize{};
	sf::Sprite              bgS{};
	float                   bgSp{};
	float                   bgX{};
};
#endif
