#include "stdafx.h"
#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(float xPosition, float yPosition, float width, float height){
	setPosition(sf::Vector2f(xPosition, yPosition));
	this->width = width;
	this->height = height;
}

Rectangle::~Rectangle(){
}

sf::ConvexShape Rectangle::get(){ return this->convexShape; }

sf::Color Rectangle::getColor() { return convexShape.getFillColor(); }

sf::Color Rectangle::getOutLineColor(){ return convexShape.getOutlineColor(); }

void Rectangle::setColor(sf::Color color){ convexShape.setFillColor(color); }

void Rectangle::setThickness(float thickness, sf::Color color){
	if (thickness > 0.f) {
		convexShape.setOutlineThickness(thickness);
		convexShape.setOutlineColor(color);
	}
}

void Rectangle::setColorAndThickness(sf::Color color, float thickness, sf::Color outLineColor){
	setColor(color);
	setThickness(thickness, outLineColor);
}

void Rectangle::createRectangle(){
	float x = getPosition().x;
	float y = getPosition().y;

	convexShape.setPointCount(4);

	convexShape.setPoint(0, getPosition());
	convexShape.setPoint(1, sf::Vector2f(x + width, y));
	convexShape.setPoint(2, sf::Vector2f(x + width, y + height));
	convexShape.setPoint(3, sf::Vector2f(x, y + height));
}

void Rectangle::createRectangleFlatEdge(float fractionalWidth, float fractionalHeight){
	float x = getPosition().x;
	float y = getPosition().y;

	float edgeX = width*fractionalWidth;
	float edgeY = height*fractionalHeight;

	if (fractionalWidth >= 0.5 || fractionalHeight >= 0.5 || fractionalWidth < 0 || fractionalHeight < 0) return;

	convexShape.setPointCount(8);

	convexShape.setPoint(0, sf::Vector2f(this->xPosition, this->yPosition + edgeY / 2));
	convexShape.setPoint(1, sf::Vector2f(this->xPosition + edgeX / 2, this->yPosition));

	convexShape.setPoint(2, sf::Vector2f(this->xPosition + this->width - edgeX / 2, this->yPosition));
	convexShape.setPoint(3, sf::Vector2f(this->xPosition + this->width, this->yPosition + edgeY / 2));

	convexShape.setPoint(4, sf::Vector2f(this->xPosition + this->width, this->yPosition + this->height - edgeY / 2));
	convexShape.setPoint(5, sf::Vector2f(this->xPosition + this->width - edgeX / 2, this->yPosition + this->height));

	convexShape.setPoint(6, sf::Vector2f(this->xPosition + edgeX / 2, this->yPosition + this->height));
	convexShape.setPoint(7, sf::Vector2f(this->xPosition, this->yPosition + this->height - edgeY / 2));
}
