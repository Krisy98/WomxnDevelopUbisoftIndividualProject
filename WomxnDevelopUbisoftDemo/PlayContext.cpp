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

	addPath(0, 230, Orientation::Horizontal);
	addPath(40, 230, Orientation::Horizontal);
	addPath(180, 230, Orientation::Horizontal);

	addInsect(0, 250, Direction::East, InsectType::Cricket);
}

PlayContext::~PlayContext(){
	deleteEntities(flowers);
	deleteEntities(insects);
	deleteEntities(emplacements);
	deleteEntities(path);
}

void PlayContext::update(sf::RenderWindow& window){
	updateScreen(window);

	// movement
	// collision

	updateEntities(*flowers, window);

	updateEntities(*insects, window);

	updateEntities(*emplacements, window);
	updateEntities(*path, window);
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

void PlayContext::render(sf::RenderTarget& target){
	target.clear(sf::Color(0, 0, 0));

	renderEntities(target, *flowers);
	renderEntities(target, *insects);
	renderEntities(target, *emplacements);
	renderEntities(target, *path);
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

void PlayContext::addInsect(float x, float y, Direction direction, InsectType type){
	Entities* start = insects;
	Entities* temp = new Entities();

	temp->current = new Insect(x, y, 20.f, direction, type);
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

void PlayContext::addPath(float xPosition, float yPosition, Orientation orientation){
	Entities* start = path;
	Entities* temp = new Entities();

	temp->current = new Path(xPosition, yPosition, 20.f, orientation);
	temp->next = nullptr;

	while (start->next != nullptr) start = start->next;

	if (start->current == nullptr) start->current = temp->current;
	else start->next = temp;
}
