#include "stdafx.h"
#include "Flower.h"


Flower::Flower(float xPosition, float yPosition, FlowerType type){
	setPosition(xPosition, yPosition);
	this->plantRadius = 20.0/2;
	this->visibleRange = false;

	initFromType(type);

	circle.setPosition(sf::Vector2f(getXPosition(), getYPosition()));
	circle.setRadius(this->plantRadius);
	
	circle.setFillColor(sf::Color(0, 0, 0, 0));
	circle.setOutlineThickness(1.f); // 1px wide 
	circle.setOutlineColor(getColor());

	//
	circleRange.setPosition(sf::Vector2f(getXPosition() + plantRadius - rangeRadius, getYPosition() + plantRadius - rangeRadius));
	circleRange.setRadius(this->rangeRadius);

	circleRange.setFillColor(sf::Color(0, 255, 255, 1));
	circleRange.setOutlineThickness(1.f); // 1px wide 
	circleRange.setOutlineColor(sf::Color(0, 255, 255, 0.3));
}

Flower::~Flower(){
}


void Flower::update(){
	// collision
	
}

void Flower::draw(sf::RenderTarget& target) {
	target.draw(circle);

	if (this->visibleRange) target.draw(circleRange);
}

void Flower::setVisibleRange(bool value){ this->visibleRange = value; }

bool Flower::getVisibleRange(){ return this->visibleRange; }

/*
bool Flower::isOnMouseMoved(sf::Window *win){
	while (win->pollEvent(event)) {
		printf("event poll ! ");
		switch (event.type) {

			case sf::Event::MouseMoved :
				printf("mouseMoved ! ");
				return true;

			case sf::Event::MouseButtonPressed :
				printf("mouse pressed ");
				break;

			default:
				break;
		}
	}
	printf("no event ...");
	return false;
}
*/

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
			setRange(20);
			break;
	}
}
