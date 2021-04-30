#include "stdafx.h"
#include "Seed.h"

#include "Engine/Physics/Physics.h"

#include <iostream>

Seed::Seed(sf::Vector2f position, extern Insect& target){
	setPosition(position);
	setSize(sf::Vector2f(10, 10));

	createBoundingBox();

	this->target = &target;

	initCircle();

	setSpeed(sf::Vector2f(1.f, 1.f));
}

Seed::~Seed(){
	delete this->circle;
}

void Seed::draw(sf::RenderTarget& target){
	if (this->circle != nullptr) {
		target.draw(this->circle->get());
	}
}

void Seed::update(sf::RenderWindow& win){
	if (this->circle != nullptr) {
		this->circle->setPosition(getPosition());
	}
	
	updateSpeed();

	move();
}

void Seed::initCircle(){
	this->circle = new Circle(getXPosition(), getYPosition(), getSize().x/2);
	this->circle->setColor(sf::Color::Green);
}

void Seed::updateSpeed(){
	float xSpeed, ySpeed;
	float distance = Physics::distance(getPosition(), target->getPosition());

	ySpeed = getYPosition() - target->getYPosition();
	ySpeed = -ySpeed;

	xSpeed = getXPosition() - target->getXPosition();
	xSpeed = -xSpeed;
	
	if (distance > 15) {
		ySpeed /= 4;
		xSpeed /= 4;
	}
	setSpeed(sf::Vector2f(xSpeed, ySpeed));
}

bool Seed::isAchieved(){
	sf::Vector2f pos = getPosition();
	float range = 0.2f;

	if (pos.x >= target->getXPosition() - range && pos.x <= target->getXPosition() + range &&
		pos.y >= target->getYPosition() - range && pos.y <= target->getYPosition() + range) {
		return true;
	}
	return false;
}

Insect* Seed::getTarget(){ return this->target; }
