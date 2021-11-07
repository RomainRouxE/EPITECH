/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "../include/Space.hpp"

Space::Space()
{
}

void Space::addBackground(std::unique_ptr<Backgrounds> element){
	elementsBack.push_back(std::move(element));
}

void Space::add(std::unique_ptr<Entities> element) {
	elements.push_back(std::move(element));
}

void Space::update() {
	auto timeLoop = chrono.restart().asSeconds();
	for (auto& element : elementsBack){
		element->update(timeLoop);
	}
	for (auto i{0u}; i < elements.size(); ++i){
		elements[i]->update(timeLoop);
	}
}

void Space::colisions(){
	for (auto i{0u}; i<elements.size(); ++i){
		for (auto j{0u}; j<elements.size(); ++j) {
			if (i != j){
				elements[i]->testColision(*elements[j]);
			}
		}
	}
}

void Space::draw(sf::RenderWindow& m_Window){
	for (auto& element : elementsBack){
		element->display(m_Window);
	}
	for (auto& element : elements){
		element->display(m_Window);
	}
	m_Window.display();
}

void Space::clean() {
	auto endTab = std::remove_if(std::begin(elements),
				     std::end(elements),
				     Entities::isDestroyed);
	elements.erase(endTab, std::end(elements));
	auto endTabBack = std::remove_if(std::begin(elementsBack),
					 std::end(elementsBack),
					 Backgrounds::isDestroyed);
	elementsBack.erase(endTabBack, std::end(elementsBack));
}

void Space::empty() {
	elements.clear();
	elementsBack.clear();
}
