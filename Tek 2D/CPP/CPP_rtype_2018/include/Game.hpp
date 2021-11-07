/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Space.hpp"
#include <memory>
#include <exception>

class Game
{
public:
	Game(Space& p_espace);

	void		StartGame();
	void		GameOver();
	void		 addPoints(int points);
	inline bool	inProcess() const { return processing; };
	void		display(sf::RenderWindow& m_Window) const;
	bool		processing{false};
private:
	void refreshText();
	void refreshBestScore();

	Space&		space;

	int score{};
	sf::Text textScore{};
	sf::Sprite	spriteMenu{};
	sf::Texture     textureMenu{};
	sf::Font police{};
};

#endif // GAME_HPP

