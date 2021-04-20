#include "stdafx.h"
#include <iostream>
#include <string>
#include "PlayContext.h"


PlayContext::PlayContext(/*int idLvl*/){
	File *file = new File("Resources/Levels/lvl_0.txt"); // tuto

	// wave to define
	/*
	sf::FileInputStream stream;
	if (stream.open("Resources/Levels/lvl_1.txt")) {
		float *f = new float();
		stream.read(f, sizeof(float));
		std::cout << *f;
	}*/

	initEntities(emplacements);
	initEntities(flowers);
	initEntities(insects);
	initEntities(path);

	this->speedScrolling = 1.4;

	file->readMode();

	file->getFloat(&this->baseSize);

	//

	createPath(file);


	/*

	addEntity(flowers, new Flower(220, 280, this->baseSize, FlowerType::Anemone));
	addEntity(flowers, new Flower(220, 160, this->baseSize, FlowerType::Delphinium));

	addEntity(emplacements, new TowerEmplacement(220, 280, this->baseSize));
	addEntity(emplacements, new TowerEmplacement(220, 160, this->baseSize));
	addEntity(emplacements, new TowerEmplacement(220, 120, this->baseSize));
*/


	addEntity(insects, new Insect(0, 60, this->baseSize, &points, InsectType::Cricket));
	
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

	moveScreen(speed);
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

void PlayContext::render(sf::RenderTarget& target){
	target.clear(sf::Color(0, 0, 0));

	renderEntities(target, *flowers);
	renderEntities(target, *insects);
	renderEntities(target, *emplacements);
	renderEntities(target, *path);
}

void PlayContext::createPath(File* file) {
	float nbPath;

	file->getFloat(&nbPath);

	for (int i = 0; i < nbPath; i++) {
		float x, y;
		std::string orientation;

		file->getFloat(&x);
		file->getFloat(&y);

		file->getString(&orientation);

		if (orientation == "Horizontal") {
			if (i >= nbPath - 2) { points.push_back(*new Point(x + this->baseSize, y + this->baseSize)); }

			addEntity(path, new Path(x, y, this->baseSize, Orientation::Horizontal));
		}
		else if (orientation == "Vertical") {
			if (i >= nbPath - 2) { points.push_back(*new Point(x + this->baseSize, y + this->baseSize)); }

			addEntity(path, new Path(x, y, this->baseSize, Orientation::Vertical));
		}
		else if (orientation == "botLeftCorner") { //
			addEntity(path, new Path(x, y, this->baseSize, Orientation::botLeftCorner));

			points.push_back(*new Point(x + this->baseSize, y + this->baseSize));
		}
		else if (orientation == "botRightCorner") {
			addEntity(path, new Path(x, y, this->baseSize, Orientation::botRightCorner));

			points.push_back(*new Point(x + this->baseSize, y + this->baseSize));
		}
		else if (orientation == "topLeftCorner") {
			addEntity(path, new Path(x, y, this->baseSize, Orientation::topLeftCorner));

			points.push_back(*new Point(x + this->baseSize, y + this->baseSize));
		}
		else if (orientation == "topRightCorner") {
			addEntity(path, new Path(x, y, this->baseSize, Orientation::topRightCorner));

			points.push_back(*new Point(x + this->baseSize, y + this->baseSize));
		}
	}
}