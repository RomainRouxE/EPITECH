//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include "../include/Engine.hpp"
#include "../include/Space.hpp"
#include "../include/Game.hpp"

Engine::Engine(){
	sf::Vector2f resolution;
	resolution.x = sf::VideoMode::getDesktopMode().width;
	resolution.y = sf::VideoMode::getDesktopMode().height;
	m_Window.create(sf::VideoMode(resolution.x, resolution.y),
			"R-type",
			sf::Style::Fullscreen);
}

void Engine::start(){
	sf::Clock clock;
	auto space = Space{};
	auto game = Game{space};
	while (m_Window.isOpen()){
		auto event = sf::Event();
		while(m_Window.pollEvent(event)){
			if(event.type == sf::Event::Closed
			   || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
				m_Window.close();
			}
			if(event.type == sf::Event::KeyPressed
			   && !game.inProcess()){
				game.StartGame();
			}
		}
		space.update();
		space.colisions();
		game.display(m_Window);
		space.draw(m_Window);
		space.clean();
	}
}
