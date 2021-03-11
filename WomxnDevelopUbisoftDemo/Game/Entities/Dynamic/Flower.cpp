#include "stdafx.h"
#include <iostream>
#include "Flower.h"


Flower::Flower(float xPosition, float yPosition, FlowerType type){
	setPosition(sf::Vector2f(xPosition, yPosition));

	this->plantRadius = 10.f;
	this->visibleRange = false;

	setSize(sf::Vector2f(20.f, 20.f));

	createBoundingBox();

	initFromType(type);

	circle = new Circle(getXPosition(), getYPosition(), plantRadius);
	circle->setColorAndThickness(sf::Color(0, 0, 0, 0), 1.f, getColor());

	circleRange = new Circle(getXPosition() + plantRadius - rangeRadius, getYPosition() + plantRadius - rangeRadius, rangeRadius);
	circleRange->setColorAndThickness(getRangeColor(), 1.f, getRangeOutLineColor());
}

Flower::~Flower(){
}

void Flower::update(sf::RenderWindow& window){
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);

	
	// collision

	
	if (mousePos.x >= getXPosition() && mousePos.x <= getXPosition() + getWidth() &&
		mousePos.y >= getYPosition() && mousePos.y <= getYPosition() + getHeight())
		setVisibleRange(true);
	else
		setVisibleRange(false);

		
}

void Flower::draw(sf::RenderTarget& target) {
	target.draw(circle->get());

	if (this->visibleRange) target.draw(circleRange->get());
}

void Flower::setVisibleRange(bool value){ this->visibleRange = value; }

bool Flower::getVisibleRange(){ return this->visibleRange; }

sf::Color Flower::getRangeColor(){ return sf::Color(static_cast<uint8_t>(0.0f), static_cast<uint8_t>(255.0f), static_cast<uint8_t>(255.0f), static_cast<uint8_t>(0.1 * 255.0f)); }

sf::Color Flower::getRangeOutLineColor(){ return sf::Color(static_cast<uint8_t>(255.0f), static_cast<uint8_t>(255.0f), static_cast<uint8_t>(255.0f), static_cast<uint8_t>(255.0f)); }

void Flower::setRange(float value){ this->rangeRadius = value; }

void Flower::initFromType(FlowerType type) {
	switch (type) {
		default:
		case FlowerType::Anemone:
			setColor(1, 1, 1);
			setRange(20);
			break;

		case FlowerType::Hyacinth:
			setColor(0.7, 0.7, 0.7);
			setRange(20);
			break;

		case FlowerType::Pansy:
			setColor(0.3, 0.7, 1);
			setRange(20);
			break;

		case FlowerType::Rose:
			setColor(1, 0.5, 1);
			setRange(20);
			break;

		case FlowerType::Delphinium:
			setColor(1, 0.2, 0.2);
			setRange(40);
			break;
	}
}
