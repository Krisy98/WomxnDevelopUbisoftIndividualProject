#include "stdafx.h"
#include "Insect.h"

#include <iostream>

Insect::Insect(float xPosition, float yPosition, float size, std::vector<Point>* points, InsectType type){
	setPosition(xPosition, yPosition);
	setSize(sf::Vector2f(size, size/2));

	createBoundingBox();

	initFromType(type);

	body = new Rectangle(getXPosition(), getYPosition(), getSize().x, getSize().y);
	body->createRectangle();
	body->setColor(getColor());
	body->setRotation(360);

	this->points = points;

	if ((int)points->size() == 0) this->atHome = true;
	else this->atHome = false;
	
	setDirection(Direction::None);
}

void Insect::draw(sf::RenderTarget& target){
	target.draw(body->get());
}

void Insect::update(sf::RenderWindow& win){

	updateDirection();

	updateRotation(); // thanks to direction

	move();

	body->setPosition(getPosition()); // update pos to the shape
}

void Insect::move() {
	

	switch (getDirection()) {
		default:
		case Direction::North:
			//std::cout << "North";
			setPosition(getXPosition(), getYPosition() - getYSpeed());
			break;
		case Direction::South:
			setPosition(getXPosition(), getYPosition() + getYSpeed());
			break;
		case Direction::East:
			setPosition(getXPosition() + getXSpeed(), getYPosition());
			break;
		case Direction::West:
			setPosition(getXPosition() - getXSpeed(), getYPosition());
			break;
	}
}

void Insect::nextPoint(){
	points->pop_back();

	setDirection(Direction::None);
	updateDirection();
}

void Insect::updateDirection(){
	sf::Vector2f position = getPosition();

	if ((int)points->size() == 0) {
		atHome = true;
		return;
	}

	Point aim = points->back();

	// point courant est tj le premier point.
	// Une fois dépassé, on l'enleve du tableau

	switch (getDirection()) {
		default:
		case Direction::None :
			if (position.x == aim.getX()) {
				if (position.y < aim.getY()) setDirection(Direction::South);

				if (position.y > aim.getY()) setDirection(Direction::North);
			}

			else if (position.y == aim.getY()) {
				if (position.x < aim.getX()) setDirection(Direction::East);

				if (position.x > aim.getX()) setDirection(Direction::West);
			}
			break;

		case Direction::North :
			if (position.y <= aim.getY()) {
				nextPoint();
			}
			break;

		case Direction::South :
			if (position.y >= aim.getY()) {
				nextPoint();
			}
			break;

		case Direction::East :
			if (position.x >= aim.getX()) { 
				nextPoint();
			}
			break;

		case Direction::West :
			if (position.x <= aim.getX()) {
				nextPoint();
			}
			break;
	}
}

void Insect::updateRotation() {
	Direction direction = getDirection();
	float angle = 10;

	switch (direction) {
		default:
		case Direction::North :
			if (body->getRotation() == 0 || body->getRotation() > 270 ) {
				body->setRotation(body->getRotation() - angle);
			}
			else if (body->getRotation() < 270) {
				body->setRotation(body->getRotation() + angle);
			}
			break;

		case Direction::South:
			if (body->getRotation() < 90) {
				body->setRotation(body->getRotation() + angle);
			}
			break;

		case Direction::East:
			if (body->getRotation() >= 270 && (body->getRotation() != 0 || body->getRotation() != 360)) {
				body->setRotation(body->getRotation() + angle);
			}
			else if (body->getRotation() != 0) {
				body->setRotation(body->getRotation() - angle);
			}
			break;

		case Direction::West:
			if (body->getRotation() >= 270 && body->getRotation() != 180) {
				body->setRotation(body->getRotation() - angle);
			}
			else if (body->getRotation() != 180) {
				body->setRotation(body->getRotation() + angle);
			}
			break;
	}

}

void Insect::initFromType(InsectType type) {
	switch (type) {
	default:
	case InsectType::Aphid:
		life = 200;
		setSpeed(sf::Vector2f(0.5, 0.5));
		setColor(1, 0.4, 0.2);
		break;
	case InsectType::Cricket:
		life = 400;
		setSpeed(sf::Vector2f(1, 1));
		setColor(0.7, 0.6, 0);
		break;
	case InsectType::LadyBirdBeetles:
		life = 600;
		setSpeed(sf::Vector2f(0.5, 0.5));
		setColor(1, 0.1, 0.1);
		break;
	case InsectType::Worms:
		life = 800;
		setSpeed(sf::Vector2f(0.2, 0.2));
		setColor(1, 0.6, 0.6);
		break;
	}
}