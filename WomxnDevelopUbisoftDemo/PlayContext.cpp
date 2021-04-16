#include "stdafx.h"
#include <iostream>
#include "PlayContext.h"


PlayContext::PlayContext(/*int idLvl*/){
	// lvl to download
	// wave to define

	this->speedScrolling = 1.4;
	this->baseSize = 20.f;

	initEntities(emplacements);
	initEntities(flowers);
	initEntities(insects);
	initEntities(path);

	//

	points.push_back(*new Point(200, 300));
	points.push_back(*new Point(300, 300));
	points.push_back(*new Point(300, 200));
	points.push_back(*new Point(120, 200));
	points.push_back(*new Point(120, 300));


	//

	addEntity(flowers, new Flower(200, 200, this->baseSize, FlowerType::Anemone));
	addEntity(flowers, new Flower(200, 100, this->baseSize, FlowerType::Delphinium));

	addEntity(emplacements, new TowerEmplacement(200, 200, this->baseSize));
	addEntity(emplacements, new TowerEmplacement(200, 100, this->baseSize));

	addEntity(path, new Path(100, 280, this->baseSize, Orientation::Vertical));
	addEntity(path, new Path(100, 240, this->baseSize, Orientation::Vertical));
	addEntity(path, new Path(100, 200, this->baseSize, Orientation::topLeftCorner));
	addEntity(path, new Path(140, 200, this->baseSize, Orientation::Horizontal));

	addEntity(insects, new Insect(0, 300, this->baseSize, &points, InsectType::Cricket));

}

PlayContext::~PlayContext(){
	deleteEntities(flowers);
	deleteEntities(insects);
	deleteEntities(emplacements);
	deleteEntities(path);
}

void PlayContext::update(sf::RenderWindow& window){
	//updateScreen(window);

	// movement
	// collision

	updateEntities(*flowers, window);

	updateEntities(*insects, window);

	//updateInsects(window);

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

void PlayContext::updateInsects(sf::RenderWindow& window){
	/*
	Entities refInsects = *insects;
	Entities refPath = *path;

	updateEntities(*insects, window);

	if (refInsects.current == nullptr || refPath.current == nullptr) { // if no insect or no path
		return;
	}

	while (refInsects.current != nullptr) {
		refPath = *path;

		while (refPath.current != nullptr) {
			Direction directionInsect = refInsects.current->getDirection();
			float distance = this->sizeCase;
			
			switch (directionInsect){ // we check current path for the current insect
				default:
				case Direction::North:
					
					//std::cout << "actual : North" << std::endl;

					if (refPath.current->Contains(refInsects.current->getXPosition(), refInsects.current->getYPosition())) { // if we find it

						std::cout << "we found the current path" << std::endl;

						if (refPath.next == nullptr) break;
						
						// we check if insect need to change his direction to still in the complete path
						if (!refPath.next->current->Contains(refInsects.current->getXPosition(), refInsects.current->getYPosition() - distance)) {

							// we look at East
							if (refPath.next->current->Contains(refInsects.current->getXPosition() + distance, refInsects.current->getYPosition())) {
								std::cout << "change to EAST - ";
								refInsects.current->setDirection(Direction::East);
							}
							 
							// then West
							if (refPath.next->current->Contains(refInsects.current->getXPosition() - distance, refInsects.current->getYPosition())) {
								std::cout << "change to WEST - ";
								refInsects.current->setDirection(Direction::West);
							}

						}
					}
					
					break;
				case Direction::South:
					if (refPath.current->Contains(refInsects.current->getXPosition(), refInsects.current->getYPosition())) {

						if (refPath.next == nullptr) break;

						// we check if insect need to change his direction to still in the complete path
						if (!refPath.next->current->Contains(refPath.next->current->getXPosition(), refPath.next->current->getYPosition() + distance)) {


						}
					}
					break;
				case Direction::East:
					if (refPath.current->Contains(refInsects.current->getXPosition(), refInsects.current->getYPosition())) {

						if (refPath.next == nullptr) break;

						// we check if insect need to change his direction to still in the complete path
						if (!refPath.next->current->Contains(refPath.next->current->getXPosition() + distance, refPath.next->current->getYPosition())) {



						}
					}
					break;
				case Direction::West:
					if (refPath.current->Contains(refInsects.current->getXPosition(), refInsects.current->getYPosition())) {

						if (refPath.next == nullptr) break;

						// we check if insect need to change his direction to still in the complete path
						if (!refPath.next->current->Contains(refPath.next->current->getXPosition() - distance, refPath.next->current->getYPosition())) {



						}
					}
					break;
			}
			
			if (refPath.next == nullptr) break;

			refPath = *refPath.next;
		}

		if (refInsects.next == nullptr) break;

		refInsects = *refInsects.next;
	}
	*/
}

void PlayContext::render(sf::RenderTarget& target){
	target.clear(sf::Color(0, 0, 0));

	renderEntities(target, *flowers);
	renderEntities(target, *insects);
	renderEntities(target, *emplacements);
	renderEntities(target, *path);
}