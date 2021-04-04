#include "stdafx.h"
#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(float xPosition, float yPosition, float width, float height){
	this->position = sf::Vector2f(xPosition, yPosition);
	this->width = width;
	this->height = height;
}

Rectangle::~Rectangle(){
}

sf::ConvexShape Rectangle::get(){ return this->convexShape; }

sf::Vector2f Rectangle::getPosition(){
	return this->position;
}

sf::Color Rectangle::getColor() { return convexShape.getFillColor(); }

sf::Color Rectangle::getOutLineColor(){ return convexShape.getOutlineColor(); }

void Rectangle::setColor(sf::Color color){ convexShape.setFillColor(color); }

void Rectangle::setThickness(float thickness, sf::Color color){
	if (thickness > 0.f) {
		convexShape.setOutlineThickness(thickness);
		convexShape.setOutlineColor(color);
	}
}

void Rectangle::setPosition(float xPosition, float yPosition){
	setPosition(sf::Vector2f(xPosition, yPosition));
}

void Rectangle::setPosition(sf::Vector2f position){
	this->position = position;
	convexShape.setPosition(position);
}

void Rectangle::createRectangle(){
	float x = getPosition().x;
	float y = getPosition().y;

	convexShape.setPointCount(4);

	convexShape.setPoint(0, sf::Vector2f(0, 0));
	convexShape.setPoint(1, sf::Vector2f(width, 0));
	convexShape.setPoint(2, sf::Vector2f(width, height));
	convexShape.setPoint(3, sf::Vector2f(0, height));

	convexShape.setPosition(getPosition()); // set the correct position
}

void Rectangle::createRectangleFlatEdge(float fractionalWidth, float fractionalHeight){
	float x = getPosition().x;
	float y = getPosition().y;

	float edgeX = width*fractionalWidth;
	float edgeY = height*fractionalHeight;

	if (fractionalWidth >= 0.5 || fractionalHeight >= 0.5 || fractionalWidth < 0 || fractionalHeight < 0) return;

	convexShape.setPointCount(8);

	convexShape.setPoint(0, sf::Vector2f(0, edgeY / 2));
	convexShape.setPoint(1, sf::Vector2f(edgeX / 2, 0));

	convexShape.setPoint(2, sf::Vector2f(this->width - edgeX / 2, 0));
	convexShape.setPoint(3, sf::Vector2f(this->width, edgeY / 2));

	convexShape.setPoint(4, sf::Vector2f(this->width, this->height - edgeY / 2));
	convexShape.setPoint(5, sf::Vector2f(this->width - edgeX / 2, this->height));

	convexShape.setPoint(6, sf::Vector2f(edgeX / 2, this->height));
	convexShape.setPoint(7, sf::Vector2f(0, this->height - edgeY / 2));


	convexShape.setPosition(getPosition()); // set the correct position

	//std::cout << "xPos : " << convexShape.getPosition().x << std::endl;
}
