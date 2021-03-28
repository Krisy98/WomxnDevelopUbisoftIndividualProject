#include "stdafx.h"
#include "RectangleFlatEdge.h"

RectangleFlatEdge::RectangleFlatEdge(float xPosition, float yPosition, float width, float height, float fractionalWidth, float fractionalHeight){
	this->position = sf::Vector2f(xPosition, yPosition);
	this->size = sf::Vector2f(width, height);
	this->fractionalSizeFlatEdge = sf::Vector2f(fractionalWidth, fractionalHeight);

	create();
}

RectangleFlatEdge::~RectangleFlatEdge(){ }

sf::ConvexShape RectangleFlatEdge::get(){ return this->convexShape; }

sf::Vector2f RectangleFlatEdge::getPosition(){ return this->position; }

sf::Color RectangleFlatEdge::getColor(){ return convexShape.getFillColor(); }

sf::Color RectangleFlatEdge::getOutLineColor(){ return convexShape.getOutlineColor(); }

void RectangleFlatEdge::setColor(sf::Color color){ convexShape.setFillColor(color); }

void RectangleFlatEdge::setThickness(float thickness, sf::Color color){
	if (thickness > 0.f) {
		convexShape.setOutlineThickness(thickness);
		convexShape.setOutlineColor(color);
	}
}

void RectangleFlatEdge::setPosition(float xPosition, float yPosition){ setPosition(sf::Vector2f(xPosition, yPosition)); }

void RectangleFlatEdge::setPosition(sf::Vector2f position){
	this->position = position;
	create(); // update
}

void RectangleFlatEdge::create(){
	float x = getPosition().x;
	float y = getPosition().y;

	float edgeX = size.x * fractionalSizeFlatEdge.x;
	float edgeY = size.y * fractionalSizeFlatEdge.y;

	if (fractionalSizeFlatEdge.x >= 0.5 || fractionalSizeFlatEdge.y >= 0.5 || fractionalSizeFlatEdge.x < 0 || fractionalSizeFlatEdge.y < 0) return;

	
	convexShape.setPointCount(8);

	convexShape.setPoint(0, sf::Vector2f(x, y + edgeY / 2));
	convexShape.setPoint(1, sf::Vector2f(x + edgeX / 2, y));

	convexShape.setPoint(2, sf::Vector2f(x + size.x - edgeX / 2, y));
	convexShape.setPoint(3, sf::Vector2f(x + size.x, y + edgeY / 2));

	convexShape.setPoint(4, sf::Vector2f(x + size.x, y + size.y - edgeY / 2));
	convexShape.setPoint(5, sf::Vector2f(x + size.x - edgeX / 2, y + size.y));

	convexShape.setPoint(6, sf::Vector2f(x + edgeX / 2, y + size.y));
	convexShape.setPoint(7, sf::Vector2f(x, y + size.y - edgeY / 2));
}
