#include "stdafx.h"
#include "FlowerMenu.h"

#include <iostream>

FlowerMenu::FlowerMenu(float xPosition, float yPosition){

	if (!this->font.loadFromFile("Resources/Fonts/champagne_and_limousines.ttf")) {
		std::cout << "Fail to load file !" << std::endl;
	}

	setPosition(xPosition, yPosition);

	text.setFont(font);
	text.setString("HELLO WORLD !");
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::Green);

	text.setPosition(getPosition());
}

FlowerMenu::~FlowerMenu(){
}

void FlowerMenu::draw(sf::RenderTarget& target){
	target.draw(text);
}

void FlowerMenu::update(sf::RenderWindow& win){

}
