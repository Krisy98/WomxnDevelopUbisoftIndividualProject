#include "stdafx.h"
#include "Path.h"

Path::Path(float xPosition, float yPosition, float size, Orientation orientation){
	setPosition(xPosition, yPosition);
	setSize(sf::Vector2f(size*2, size*2));
	setColor(1, 1, 1, 1);

	createBoundingBox();

	this->orientation = orientation;

	if (orientation == Orientation::Vertical) {
		leftLine = new Rectangle(getXPosition(), getYPosition(), 0.5, getSize().y);
		rightLine = new Rectangle(getXPosition() + getSize().x, getYPosition(), 0.5, getSize().y);
	}

	else if (orientation == Orientation::Horizontal) {
		leftLine = new Rectangle(getXPosition(), getYPosition(), getSize().x, 0.5);
		rightLine = new Rectangle(getXPosition(), getYPosition() + getSize().y, getSize().x, 0.5);
	}

	leftLine->createRectangle();
	leftLine->setColorAndThickness(getColor(), 0.5, getColor());

	rightLine->createRectangle();
	rightLine->setColorAndThickness(getColor(), 0.5, getColor());
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
	if (orientation == Orientation::Vertical){
		rightLine->setPosition(sf::Vector2f(position.x + getSize().x, position.y));
	}
	else if (orientation == Orientation::Horizontal) {
		rightLine->setPosition(sf::Vector2f(position.x, position.y + getSize().y));
	}
	
}
