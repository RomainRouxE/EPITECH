#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include <fstream>
#include "../include/Game.hpp"
#include "../include/Spaceship.hpp"
#include "../include/EnemyOne.hpp"
#include "../include/FirstBack.hpp"
#include "../include/SecondBack.hpp"
#include "../include/ThirdBack.hpp"
#include "../include/FourthBack.hpp"
#include "../include/font.hpp"


using namespace std::string_literals;

Game::Game(Space& p_space)
	: space{p_space}
{
	textureMenu.loadFromFile("assets/R-typeMenu.png");
	spriteMenu.setTexture(textureMenu);
	police.loadFromMemory(Air_Americana_ttf, Air_Americana_ttf_size);
	textScore.setFont(police);
	textScore.move(0,30);
}

void Game::StartGame() {
	processing = true;
	score = 0;
	refreshText();
	
	space.addBackground(std::make_unique<SecondBack>(space, *this));
	space.addBackground(std::make_unique<FirstBack>(space, *this));
	space.addBackground(std::make_unique<ThirdBack>(space, *this));
	space.addBackground(std::make_unique<FourthBack>(space, *this));
	
	space.add(std::make_unique<Spaceship>(space, *this));
	space.add(std::make_unique<EnemyOne>(space, *this));
	space.add(std::make_unique<EnemyOne>(space, *this));
	space.add(std::make_unique<EnemyOne>(space, *this));
}

void Game::addPoints(int points) {
	score += points;
	refreshText();
}

void Game::GameOver() {
	processing = false;
	space.empty();
}

void Game::display(sf::RenderWindow& m_Window) const {
	if(processing == false)
		m_Window.draw(spriteMenu);
	m_Window.draw(textScore);
}

void Game::refreshText() {
	textScore.setString("Score : "s + std::to_string(score));
}
