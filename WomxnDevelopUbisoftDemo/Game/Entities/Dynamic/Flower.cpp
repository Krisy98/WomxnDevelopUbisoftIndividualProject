#include "stdafx.h"
#include "Flower.h"


Flower::Flower(float xPosition, float yPosition, FlowerType type){
	setPosition(xPosition, yPosition);
	this->plantRadius = 20.0/2;
	this->visibleRange = false;

	initFromType(type);


	circle = shaper.getCircle(getXPosition(), getYPosition(), this->plantRadius);

	circle = shaper.setColor(circle, sf::Color(0, 0, 0, 0), 1.f, getColor());


	circleRange = shaper.getCircle(getXPosition() + plantRadius - rangeRadius, getYPosition() + plantRadius - rangeRadius, this->rangeRadius);

	circleRange = shaper.setColor(circleRange, sf::Color(0, 255, 255, 0.8), 1.f, sf::Color(0, 255, 255, 1));
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
