#include "stdafx.h"
#include "FlowerMenu.h"
#include "Game/Entities/EntityType.h"

#include <iostream>

FlowerMenu::FlowerMenu(float xPosition, float yPosition){

	if (!this->font.loadFromFile("Resources/Fonts/champagne_and_limousines.ttf")) {
		std::cout << "Fail to load file !" << std::endl;
	}

	setPosition(xPosition, yPosition);

	float xPosItem = getXPosition();
	float yPosItem = getYPosition();

	charSize = 20.f;

	for (int i = 0; i < nbFlower; i++) { 
		addItem(xPosItem, yPosItem, flowerStr[i]); 
		yPosItem += charSize + 5;
	}
}

FlowerMenu::~FlowerMenu(){
	delete textList;
}

void FlowerMenu::draw(sf::RenderTarget& target){
	textList->draw(target);
}

void FlowerMenu::update(sf::RenderWindow& win){

}

FlowerType* FlowerMenu::getItem(float x, float y){
	Texts* temp = textList->getTexts();
	FlowerType* type = new FlowerType();

	while (temp->current != nullptr) {
		sf::Text* text = temp->current;
		float posX = text->getPosition().x;
		float posY = text->getPosition().y;

		if (x > posX && x < posX + 90 && y > posY && y < posY + text->getCharacterSize()) {
			std::string str = text->getString().toAnsiString();
			const char* typeStr = str.c_str();
			
			*type = toFlowerType(typeStr);
			return type;
		}

		if (temp->next != nullptr) temp = temp->next;
		else break;
	}
	return nullptr;
}

void FlowerMenu::addItem(float x, float y, const char* writing){
	sf::Text* text = new sf::Text();

	text->setFont(font);
	text->setString(writing);

	text->setPosition(x, y);
	text->setCharacterSize(charSize);

	text->setFillColor(sf::Color::Red);

	textList->addText(text);
}

FlowerType FlowerMenu::toFlowerType(const char* typeStr){
	std::string string = std::string(typeStr);

	if (string == "Anemone") { return FlowerType::Anemone; }

	if (string == "Hyacinth") return FlowerType::Hyacinth;

	if (string == "Pansy") return FlowerType::Pansy;

	if (string == "Rose") return FlowerType::Rose;

	if (string == "Delphinium") return FlowerType::Delphinium;

	return FlowerType();
}
