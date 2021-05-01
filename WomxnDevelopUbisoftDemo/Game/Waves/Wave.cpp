#include "stdafx.h"
#include "Wave.h"

#include <iostream>

Wave::Wave(InsectType type, int nbInsect, sf::Vector2f position){
	this->type = type;
	this->nbInsect = nbInsect;
	this->position = position;
}

Wave::~Wave(){
}

InsectType* Wave::getType(){ return &this->type; }

int Wave::getNbInsect(){ return this->nbInsect; }

sf::Vector2f Wave::getPosition(){ return this->position; }

sf::Time Wave::getTimeToPrepare(){
	sf::Time time = sf::seconds(0.5f);
	Insect* insect = new Insect(0, 0, 0, new std::vector<Point>(), this->type);

	time = insect->getTimeForPrepare();

	delete insect;
	return time;
}

void Wave::setPosition(sf::Vector2f position) {
	this->position = position;
}

void Wave::decrementNbInsect(){
	this->nbInsect -= 1;
}

bool Wave::isDone(){
	return (this->nbInsect <= 0);
}
