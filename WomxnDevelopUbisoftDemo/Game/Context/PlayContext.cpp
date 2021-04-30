#include "stdafx.h"
#include <SFML/System.hpp>
#include "../utils/magic_enum/include/magic_enum.hpp"
#include <iostream>
#include <string>
#include "PlayContext.h"

PlayContext::PlayContext(/*int idLvl*/){
	File *file = new File("Assets/levels\\lvl_0.txt");

	initEntities(emplacements);
	initEntities(flowers);
	initEntities(insects);
	initEntities(path);

	this->speedScrolling = 1.4f;

	file->readMode();
	file->getFloat(&this->baseSize);

	createPath(file);
	createEmplacements(file);
	createWaves(file);

	this->flowerMenu = nullptr;


	//
	addEntity(insects, new Insect(0, 60, this->baseSize, &points, InsectType::LadyBirdBeetles));
	//


	file->close();
}

PlayContext::~PlayContext(){
	deleteEntities(flowers);
	deleteEntities(insects);
	deleteEntities(emplacements);
	deleteEntities(path);
}

void PlayContext::update(sf::RenderWindow& window){
	updateScreen(window);

	updateEntities(*flowers, window);
	updateEntities(*insects, window);
	updateEntities(*emplacements, window);
	updateEntities(*path, window);

	if (this->flowerMenu != nullptr) this->flowerMenu->update(window);

	updateInsects();

}

void PlayContext::render(sf::RenderTarget& target) {
	target.clear(sf::Color(0, 0, 0));

	renderEntities(target, *flowers);
	renderEntities(target, *insects);
	renderEntities(target, *emplacements);
	renderEntities(target, *path);

	if (this->flowerMenu != nullptr) this->flowerMenu->draw(target);

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

		if (mousePos.x > width / 2) { x = width - x; }

		float percent = 1 - (x / (width / 2));
		
		xSpeed = this->speedScrolling * percent;
		ySpeed = this->speedScrolling;

		if (mousePos.x > width / 2) { xSpeed = -xSpeed; }
	}

	// case down
	else if (mousePos.y >= height - margin && mousePos.y < height) {
		int x = mousePos.x;

		if (mousePos.x > width / 2) { x = width - x; }

		float percent = 1 - (x / (width / 2));

		xSpeed = this->speedScrolling * percent;
		ySpeed = -this->speedScrolling;

		if (mousePos.x > width / 2) { xSpeed = -xSpeed; }
	}

	// case left
	else if (mousePos.x <= margin && mousePos.x > 0) {
		int y = mousePos.y;

		if (mousePos.y > width / 2) { y = width - y; }

		float percent = 1 - (y / (width / 2));

		ySpeed = this->speedScrolling * percent;
		xSpeed = this->speedScrolling;

		if (mousePos.y > width / 2) { ySpeed = -ySpeed; }
	}

	// case right
	else if (mousePos.x >= width - margin && mousePos.x < width) {
		int y = mousePos.y;

		if (mousePos.y > width / 2) { y = width - y; }

		float percent = 1 - (y / (width / 2));

		ySpeed = this->speedScrolling * percent;
		xSpeed = -this->speedScrolling;

		if (mousePos.y > width / 2) { ySpeed = -ySpeed; }
	}

	sf::Vector2f speed = sf::Vector2f(xSpeed, ySpeed);

	moveScreen(speed);
}

void PlayContext::updateInsects(){
	Entities* temp = insects;

	while (temp->current != nullptr) {
		Insect* insect = dynamic_cast<Insect*>(temp->current);

		if (insect->getLife() <= 0) {
			removeEntity(insects, insect);
		}

		if (temp->next != nullptr) temp = temp->next;
		else break;
	}
}

void PlayContext::moveScreen(sf::Vector2f speed){
	setEntitiesPosition(*flowers, speed);
	setEntitiesPosition(*emplacements, speed);
	setEntitiesPosition(*insects, speed);
	setEntitiesPosition(*path, speed);

	for (int i = 0; i < (int) points.size(); i++) {
		points[i].set(points[i].getX() + speed.x, points[i].getY() + speed.y);
	}
}

bool PlayContext::isAEmplacementClicked(float xMouse, float yMouse){
	Entities start = *emplacements;

	if (start.current == nullptr) { return false; }

	if (start.current->Contains(xMouse, yMouse)) {
		setFlowerMenu(start.current);
		return true;
	}

	while (start.next != nullptr) {
		start = *start.next;

		if (start.current->Contains(xMouse, yMouse)) {
			setFlowerMenu(start.current);
			return true;
		}
	}
	return false;
}

bool PlayContext::isAFlowerSelected(float xMouse, float yMouse){
	if (flowerMenu != nullptr) {
		FlowerType* flowerType = flowerMenu->getItem(xMouse, yMouse);

		if (flowerType != nullptr) {
			float x = flowerMenu->getXPosition();
			float y = flowerMenu->getYPosition() - baseSize;
			
			std::cout << "(insects != nullptr) : " << (insects != nullptr) << std::endl; //

			addEntity(flowers, new Flower(sf::Vector2f(x, y), baseSize, *flowerType, insects));
			return true;
		}
		else flowerMenu = nullptr;
	}
	return false;
}

void PlayContext::handleEvent(sf::Event event){
	if (event.type == sf::Event::MouseButtonPressed) {
		if (event.mouseButton.button == sf::Mouse::Left) {
			
			if (isAEmplacementClicked(event.mouseButton.x, event.mouseButton.y)) {}
			else if (isAFlowerSelected(event.mouseButton.x, event.mouseButton.y)) {}
			
		}
	}
}

void PlayContext::setFlowerMenu(Entity* entity) {
	float xPosition = entity->getXPosition();
	float yPosition = entity->getYPosition() + entity->getSize().y;

	if (flowerMenu != nullptr) {
		if (xPosition == flowerMenu->getXPosition() && yPosition == flowerMenu->getYPosition()) {
			this->flowerMenu = nullptr;
		}
		else this->flowerMenu = new FlowerMenu(xPosition, yPosition);
	}
	else this->flowerMenu = new FlowerMenu(xPosition, yPosition);
}

void PlayContext::createPath(File* file) {
	float nbPath;

	file->getFloat(&nbPath);

	for (int i = 0; i < nbPath; i++) {
		float x, y;
		std::string orientation;

		constexpr auto& entries = magic_enum::enum_entries<Orientation>();
		constexpr int size = magic_enum::enum_count<Orientation>();

		file->getFloat(&x);
		file->getFloat(&y);

		file->getString(&orientation);

		for (int j = 0; j < size; j++) {

			if (entries[j].second == orientation) {
				if ((orientation == "Horizontal" || orientation == "Vertical") && i >= nbPath - 1) {
					points.push_back(*new Point(x + this->baseSize, y + this->baseSize));
				}
				else {
					points.push_back(*new Point(x + this->baseSize, y + this->baseSize));
				}
				addEntity(path, new Path(x, y, this->baseSize, entries[j].first));
			}
		}
	}
}

void PlayContext::createEmplacements(File* file) {
	float nbEmplacement;

	file->getFloat(&nbEmplacement);

	for (int i = 0; i < nbEmplacement; i++) {
		float x, y;

		file->getFloat(&x);
		file->getFloat(&y);

		addEntity(emplacements, new TowerEmplacement(x, y, this->baseSize));
	}
}

void PlayContext::createWaves(File* file){

	std::cout << file->hasNextLine() << std::endl;

	while (file->hasNextLine()) {
		float xPos, yPos;
		std::string strType;
		int nbInsect;

		file->getFloat(&xPos);
		file->getFloat(&yPos);

		file->getString(&strType);

		file->getInt(&nbInsect);

		constexpr auto& entries = magic_enum::enum_entries<InsectType>();
		constexpr int size = magic_enum::enum_count<InsectType>();

		for (int i = 0; i < size; i++) {
			if (entries[i].second == strType) {
				waves.push_back(*new Wave(entries[i].first, nbInsect, sf::Vector2f(xPos, yPos)));
			}
		}
	}
}
