//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef SPACE_HPP
#define SPACE_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>


#include "Entities.hpp"
#include "Backgrounds.hpp"

class Space
{
public:
	Space();
	void	addBackground(std::unique_ptr<Backgrounds> element);
	void	add(std::unique_ptr<Entities> element);
	void	input();
	void	update();
	void	colisions();
	void	draw(sf::RenderWindow& m_Window);
	void	clean();
	void	empty();
private:
	std::vector<std::unique_ptr<Entities>> elements{};
	std::vector<std::unique_ptr<Backgrounds>> elementsBack{};
	sf::Clock chrono{};
};

#endif // SPACE_HPP
