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

void Insect::reduceLife(float damage){
	if (this->life - damage <= 0) {
		setLife(0);
	}
	else {
		setLife(this->life - damage);
	}
}

void Insect::applyDifficulty(float difficultyLevel){
	difficultyLevel /= 100; //percentage
	life *= difficultyLevel;
}

void Insect::move() {
	switch (getDirection()) {
		default:
		case Direction::North:
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
	indexPoints++;

	if (indexPoints < points->size() - 1) {
		setDirection(Direction::None);

		updateDirection();
	}
}

void Insect::updateDirection(){
	sf::Vector2f position = getPosition();

	if (indexPoints >= points->size() - 1) {
		atHome = true;
		return;
	}

	Point aim = points->at(indexPoints); // get first element

	switch (getDirection()) {
		default:
		case Direction::None :
			if (position.x == aim.getX() || (position.x < aim.getX() + 1 && position.x > aim.getX()) || (position.x > aim.getX() - 1 && position.x < aim.getX())) {
				if (position.y < aim.getY()) setDirection(Direction::South);

				if (position.y > aim.getY()) setDirection(Direction::North);
			}

			else if (position.y == aim.getY() || (position.y < aim.getY() + 1 && position.y > aim.getY()) || (position.y > aim.getY() - 1 && position.y < aim.getY())) {
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
				body->setRotation(body->getRotation() - angle*getYSpeed());
			}
			else if (body->getRotation() < 270) {
				body->setRotation(body->getRotation() + angle*getYSpeed());
			}
			break;

		case Direction::South:
			if (body->getRotation() < 90) {
				body->setRotation(body->getRotation() + angle*getYSpeed());
			}
			break;

		case Direction::East:
			if (body->getRotation() >= 270 && (body->getRotation() != 0 || body->getRotation() != 360)) {
				body->setRotation(body->getRotation() + angle*getXSpeed());
			}
			else if (body->getRotation() != 0) {
				body->setRotation(body->getRotation() - angle*getXSpeed());
			}
			break;

		case Direction::West:
			if (body->getRotation() >= 270 && body->getRotation() != 180) {
				body->setRotation(body->getRotation() - angle*getXSpeed());
			}
			else if (body->getRotation() != 180) {
				body->setRotation(body->getRotation() + angle*getXSpeed());
			}
			break;
	}
}

void Insect::initFromType(InsectType type) {
	switch (type) {
		default:
		case InsectType::Aphid:
			setSpeed(sf::Vector2f(0.4, 0.4));
			setColor(1, 0.4, 0.2);

			life = 500;
			timeForPrepare = sf::seconds(3.f);
			rewardPoint = 20;
			break;

		case InsectType::Cricket:
			setSpeed(sf::Vector2f(0.9, 0.9));
			setColor(0.7, 0.6, 0);

			life = 1000;
			timeForPrepare = sf::seconds(1.5f);
			rewardPoint = 35;
			break;

		case InsectType::LadyBirdBeetles:
			setSpeed(sf::Vector2f(0.5, 0.5));
			setColor(1, 0.1, 0.1);

			life = 1500;
			timeForPrepare = sf::seconds(4.f);
			rewardPoint = 50;
			break;

		case InsectType::Worms:
			setSpeed(sf::Vector2f(0.2, 0.2));
			setColor(1, 0.6, 0.6);

			life = 2000;
			timeForPrepare = sf::seconds(6.f);
			rewardPoint = 60;
			break;
		}
}

void Insect::setDirection(Direction direction) { this->direction = direction; }

void Insect::setLife(float life){ this->life = life; }

Direction Insect::getDirection() { return this->direction; }

float Insect::getLife(){ return this->life; }

sf::Time Insect::getTimeForPrepare(){ return this->timeForPrepare; }

float Insect::getRewardPoint(){ return this->rewardPoint; }
