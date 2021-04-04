#include "stdafx.h"
#include <iostream>
#include "PlayContext.h"


PlayContext::PlayContext(/*int idLvl*/){
	// lvl to download
	// wave to define

	this->speedScrolling = 1.4;

	initEntities(emplacements);
	initEntities(flowers);
	initEntities(insects);
	initEntities(path);

	addFlower(200, 200, FlowerType::Anemone);
	addFlower(100, 200, FlowerType::Delphinium);

	addTowerEmplacement(100, 200);
	addTowerEmplacement(200, 200);

	addPath(100, 260, "vertical");
}

PlayContext::~PlayContext(){
	deleteEntities(flowers);
	deleteEntities(insects);
	deleteEntities(emplacements);
	deleteEntities(path);
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
	updateEntities(*path, window);
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
	float width = window.getSize().x;
	float height = window.getSize().y;
	float xSpeed = 0.0;
	float ySpeed = 0.0;

	int margin = 0.03 * height;


	// case up
	if (mousePos.y <= margin && mousePos.y > 0) {
		int x = mousePos.x;

		if (mousePos.x > width / 2) {
			x = width - x;
		}

		float percent = 1 - (x / (width / 2));
		
		xSpeed = this->speedScrolling * percent;
		ySpeed = this->speedScrolling;

		if (mousePos.x > width / 2) {
			xSpeed = -xSpeed;
		}
	}

	// case down
	else if (mousePos.y >= height - margin && mousePos.y < height) {
		int x = mousePos.x;

		if (mousePos.x > width / 2) {
			x = width - x;
		}

		float percent = 1 - (x / (width / 2));

		xSpeed = this->speedScrolling * percent;
		ySpeed = -this->speedScrolling;

		if (mousePos.x > width / 2) {
			xSpeed = -xSpeed;
		}
	}

	// case left
	else if (mousePos.x <= margin && mousePos.x > 0) {
		int y = mousePos.y;

		if (mousePos.y > width / 2) {
			y = width - y;
		}

		float percent = 1 - (y / (width / 2));

		ySpeed = this->speedScrolling * percent;
		xSpeed = this->speedScrolling;

		if (mousePos.y > width / 2) {
			ySpeed = -ySpeed;
		}
	}

	// case right
	else if (mousePos.x >= width - margin && mousePos.x < width) {
		int y = mousePos.y;

		if (mousePos.y > width / 2) {
			y = width - y;
		}

		float percent = 1 - (y / (width / 2));

		ySpeed = this->speedScrolling * percent;
		xSpeed = -this->speedScrolling;

		if (mousePos.y > width / 2) {
			ySpeed = -ySpeed;
		}
	}

	sf::Vector2f speed = sf::Vector2f(xSpeed, ySpeed);

	setAllEntitiesPosition(speed);
}

void PlayContext::setAllEntitiesPosition(sf::Vector2f speed){
	setEntitiesPosition(*flowers, speed);
	setEntitiesPosition(*emplacements, speed);
	setEntitiesPosition(*insects, speed);
	setEntitiesPosition(*path, speed);
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
	renderEntities(target, *path);
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

	temp->current = new Flower(x, y, 20.f, type);
	temp->next = nullptr;
	
	while (start->next != nullptr) start = start->next;

	if (start->current == nullptr) start->current = temp->current;
	else start->next = temp;
}

void PlayContext::addTowerEmplacement(float xPosition, float yPosition){
	Entities* start = emplacements;
	Entities* temp/* = (Entities*) malloc(sizeof(struct Entities))*/ = new Entities();

	temp->current = new TowerEmplacement(xPosition, yPosition, 20.f);
	temp->next = nullptr;

	while (start->next != nullptr) start = start->next;

	if (start->current == nullptr) start->current = temp->current;
	else start->next = temp;
}

void PlayContext::addPath(float xPosition, float yPosition, const char* orientation){
	Entities* start = path;
	Entities* temp = new Entities();

	temp->current = new Path(xPosition, yPosition, 20.f, orientation);
	temp->next = nullptr;

	while (start->next != nullptr) start = start->next;

	if (start->current == nullptr) start->current = temp->current;
	else start->next = temp;
}


