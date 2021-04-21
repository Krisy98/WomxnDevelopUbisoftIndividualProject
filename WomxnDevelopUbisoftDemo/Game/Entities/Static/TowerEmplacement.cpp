#include "stdafx.h"
#include "TowerEmplacement.h"

TowerEmplacement::TowerEmplacement(float xPosition, float yPosition, float size){
	setPosition(xPosition, yPosition);
	setSize(sf::Vector2f(size + 1, size + 1));
	setColor(0.8, 0.8, 0.8, 0.3);

	createBoundingBox();

	rectangle = new Rectangle(getXPosition(), getYPosition(), getWidth(), getHeight());
	rectangle->createRectangleFlatEdge(0.1f, 0.1f);
	rectangle->setColorAndThickness(sf::Color(0, 0, 0, 0), 2.f, getColor());
}

TowerEmplacement::~TowerEmplacement(){}

void TowerEmplacement::draw(sf::RenderTarget& target){
	target.draw(rectangle->get());
}

void TowerEmplacement::update(sf::RenderWindow& win){
	rectangle->setPosition(getPosition()); // update position
}