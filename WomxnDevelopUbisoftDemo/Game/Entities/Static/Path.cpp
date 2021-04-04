#include "stdafx.h"
#include "Path.h"
#include <iostream>

Path::Path(float xPosition, float yPosition, float size, const char* orientation){
	setPosition(xPosition, yPosition);
	setSize(sf::Vector2f(size, size));
	setColor(1, 1, 1, 1);

	createBoundingBox();

	this->orientation = orientation;

	if (orientation == "vertical") {
		//std::cout << "vert";

		leftLine = new Rectangle(getXPosition(), getYPosition(), 1.f, getSize().y);
		rightLine = new Rectangle(getXPosition() + getSize().x, getYPosition(), 1.f, getSize().y);
	}

	else if (orientation == "horizontal") {
		//std::cout << "hori";

		leftLine = new Rectangle(getXPosition(), getYPosition(), getSize().x, 1.f);
		rightLine = new Rectangle(getXPosition(), getYPosition() + getSize().y, getSize().x, 1.f);
	}

	leftLine->createRectangle();
	leftLine->setColorAndThickness(getColor(), 1.f, getColor());

	rightLine->createRectangle();
	rightLine->setColorAndThickness(getColor(), 1.f, getColor());

}

Path::~Path(){
}

void Path::draw(sf::RenderTarget& target){
	target.draw(leftLine->get());
	target.draw(rightLine->get());
}

void Path::update(sf::RenderWindow& win){

	sf::Vector2f position = getPosition();

	leftLine->setPosition(position);

	// update position to the shape
	if (orientation == "vertical"){
		rightLine->setPosition(sf::Vector2f(position.x + getSize().x, position.y));
	}
	else if (orientation == "horizontal") {
		rightLine->setPosition(sf::Vector2f(position.x, position.y + getSize().y));
	}
	

}
