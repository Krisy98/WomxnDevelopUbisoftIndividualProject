#include "stdafx.h"
#include "Insect.h"

Insect::Insect(float xPosition, float yPosition, float size, Direction direction, InsectType type){

	setPosition(xPosition, yPosition);
	setSize(sf::Vector2f(size, size/2)); // rectangle form

	createBoundingBox();

	initFromType(type);

	body = new Rectangle(getXPosition(), getYPosition(), getSize().x, getSize().y);
	body->createRectangle();
	body->setColor(getColor());
	
	this->direction = direction; 
}

void Insect::draw(sf::RenderTarget& target){
	target.draw(body->get());
}

void Insect::update(sf::RenderWindow& win){
	move();

	body->setPosition(getPosition()); // update pos to the shape
}

void Insect::setDirection(Direction direction){ this->direction = direction; }

void Insect::initFromType(InsectType type){
	switch (type) {
		default:
		case InsectType::Aphid :
			life = 200;
			setSpeed(sf::Vector2f(0.5, 0.5));  
			setColor(1, 0.4, 0.2);
		break;
		case InsectType::Cricket :
			life = 400;
			setSpeed(sf::Vector2f(1, 1));
			setColor(0.7, 0.6, 0);
		break;
		case InsectType::LadyBirdBeetles :
			life = 600;
			setSpeed(sf::Vector2f(0.5, 0.5)); 
			setColor(1, 0.1, 0.1);
		break;
		case InsectType::Worms :
			life = 800;
			setSpeed(sf::Vector2f(0.2, 0.2));
			setColor(1, 0.6, 0.6);
		break;
	}
}

void Insect::move(){
	switch (direction) {
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
