#include "stdafx.h"
#include <iostream>
#include "PlayContext.h"


PlayContext::PlayContext(/*int idLvl*/){
	// lvl to download
	// wave to define

	this->speedScrolling = 2.f;

	initEntities(emplacements);
	initEntities(flowers);
	initEntities(insects);

	addFlower(200, 200, FlowerType::Anemone);
	addFlower(100, 200, FlowerType::Delphinium);

	addTowerEmplacement(100, 200);
	addTowerEmplacement(200, 200);
}

PlayContext::~PlayContext(){
	deleteEntities(flowers);
	deleteEntities(insects);
	deleteEntities(emplacements);
}

void PlayContext::initEntities(Entities* firstEntity) {
	firstEntity->current = nullptr;
	firstEntity->next = nullptr;
}

void PlayContext::deleteEntities(Entities *entities){
	while (entities->current != nullptr) {
		delete entities->current;
		entities = entities->next;
	}
	delete entities;
}

void PlayContext::update(sf::RenderWindow& window){
	updateScreen(window);

	// movement
	// collision

	updateEntities(*flowers, window);
	updateEntities(*emplacements, window);

}

void PlayContext::updateEntities(Entities entities, sf::RenderWindow& win) {
	Entities start = entities;

	if (start.current != nullptr) start.current->update(win);

	while (start.next != nullptr) {
		start = *start.next;
		start.current->update(win);
	}
}

void PlayContext::updateScreen(sf::RenderWindow& window) {
	sf::Vector2i mousePos = sf::Mouse::getPosition(window); // get position mouse
	int marginHeight = 0.05 * window.getSize().y;

	

	if (mousePos.y < marginHeight) {

		std::cout << "." << std::endl;

		// case x == width/2
		sf::Vector2f speed = sf::Vector2f(0, speedScrolling);
		
		setAllEntitiesPosition(speed);
	}
}

void PlayContext::setAllEntitiesPosition(sf::Vector2f speed){
	setEntitiesPosition(*flowers, speed);
	setEntitiesPosition(*emplacements, speed);
	setEntitiesPosition(*insects, speed);
}

void PlayContext::setEntitiesPosition(Entities entities, sf::Vector2f speed){
	Entities start = entities;

	if (start.current != nullptr) {
		sf::Vector2f oldPos = start.current->getPosition();
		sf::Vector2f newPos = sf::Vector2f(oldPos.x + speed.x, oldPos.y + speed.y);

		start.current->setPosition(newPos);
	}

	while (start.next != nullptr) {
		start = *start.next;
		sf::Vector2f oldPos = start.current->getPosition();
		sf::Vector2f newPos = sf::Vector2f(oldPos.x + speed.x, oldPos.y + speed.y);

		start.current->setPosition(newPos);
	}
}

void PlayContext::render(sf::RenderTarget& target){
	target.clear(sf::Color(0, 0, 0));

	renderEntities(target, *flowers);
	renderEntities(target, *emplacements);
}


void PlayContext::renderEntities(sf::RenderTarget& target, Entities entities){
	Entities start = entities;

	if (start.current != nullptr) start.current->draw(target);

	while (start.next != nullptr) {
		start = *start.next;
		start.current->draw(target);
	}
}

void PlayContext::addFlower(float x, float y, FlowerType type) {
	Entities* start = flowers;
	Entities* temp/* = (Entities*) malloc(sizeof(struct Entities))*/ = new Entities();

	temp->current = new Flower(x, y, type);
	temp->next = nullptr;
	
	while (start->next != nullptr) start = start->next;

	if (start->current == nullptr) start->current = temp->current;
	else start->next = temp;
}

void PlayContext::addTowerEmplacement(float xPosition, float yPosition){
	Entities* start = emplacements;
	Entities* temp/* = (Entities*) malloc(sizeof(struct Entities))*/ = new Entities();

	temp->current = new TowerEmplacement(xPosition, yPosition);
	temp->next = nullptr;

	while (start->next != nullptr) start = start->next;

	if (start->current == nullptr) start->current = temp->current;
	else start->next = temp;
}


