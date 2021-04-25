#include "stdafx.h"
#include "Circle.h"

Circle::Circle(float xPosition, float yPosition, float radius){
	this->circle.setPosition(sf::Vector2f(xPosition, yPosition));
	this->circle.setRadius(radius);
}

Circle::~Circle(){
}

void Circle::setColor(sf::Color color){ circle.setFillColor(color); }

void Circle::setThickness(float thickness, sf::Color color){
	if (thickness > 0.f) {
		circle.setOutlineThickness(thickness);
		circle.setOutlineColor(color);
	}
}

void Circle::setPosition(float xPosition, float yPosition){
	sf::Vector2f newPos = sf::Vector2f(xPosition, yPosition);
	circle.setPosition(newPos);
}

void Circle::setPosition(sf::Vector2f position){ circle.setPosition(position); }

sf::CircleShape Circle::get() { return circle; }

sf::Color Circle::getColor(){ return circle.getFillColor(); }

sf::Color Circle::getOutLineColor(){ return this->circle.getOutlineColor(); }

sf::Vector2f Circle::getPosition(){ return this->circle.getPosition(); }


