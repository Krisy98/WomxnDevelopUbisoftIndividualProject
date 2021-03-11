#include "stdafx.h"
#include "Shape.h"

void Shape::setPosition(float xPosition, float yPosition){
	this->xPosition = xPosition;
	this->yPosition = yPosition;
}

void Shape::setPosition(sf::Vector2f position){
	this->xPosition = position.x;
	this->yPosition = position.y;
}

sf::Vector2f Shape::getPosition(){ return sf::Vector2f(xPosition, yPosition); }

