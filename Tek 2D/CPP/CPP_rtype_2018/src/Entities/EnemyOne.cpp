//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include<random>
#include "../../include/EnemyOne.hpp"
#include "../../include/Explosion.hpp"

EnemyOne::EnemyOne(Space& p_space, Game& p_game)
	: Entities{"assets/En.png"},
	  space{p_space},
	  game{p_game}
{
	type = TypeEntities::ENEMY;
	auto generator = std::random_device{}();
	std::mt19937 rand_engine(generator);
	auto distributionPosition =
		std::uniform_real_distribution<float>{1920, 800};
	m_Position = {distributionPosition(rand_engine),
		      distributionPosition(rand_engine)};
	m_Speed = 400;
}

EnemyOne::~EnemyOne(){
}

void EnemyOne::update(float elapsedTime){
	std::srand(std::time(NULL));
	m_Position.x -= m_Speed * elapsedTime;
	m_Sprite.setPosition(m_Position);
	if(m_Position.x <= -99){
		m_Position.x = (1920 + 99);
		m_Position.y = std::rand()%800;
	}
}

void    EnemyOne::react_colision(TypeEntities typeOther){
	if(typeOther == TypeEntities::ROCKET){
		m_Destroyed = true;
		game.addPoints(m_Sprite.getScale().x * 100);
		space.add(std::make_unique<Explosion>(m_Position));
		space.add(std::make_unique<EnemyOne>(space, game));
	}
}
