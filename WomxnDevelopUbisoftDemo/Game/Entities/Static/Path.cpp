#include "stdafx.h"
#include "Path.h"

Path::Path(float xPosition, float yPosition, float size, Orientation orientation){
	setPosition(xPosition, yPosition);
	setSize(sf::Vector2f(size*2.f, size*2.f));
	setColor(1, 1, 1, 1);

	createBoundingBox();

	this->orientation = orientation;

	buildPath();

	firstLine->createRectangle();
	firstLine->setColorAndThickness(getColor(), 0.5, getColor());

	secondLine->createRectangle();
	secondLine->setColorAndThickness(getColor(), 0.5, getColor());
}

Path::~Path(){
}

void Path::draw(sf::RenderTarget& target){
	target.draw(firstLine->get());
	target.draw(secondLine->get());
}

void Path::update(sf::RenderWindow& win){

	updatePosition();

}

void Path::buildPath(){
	float xPosition = getXPosition();
	float yPosition = getYPosition();

	float xSize = getSize().x;
	float ySize = getSize().y;

	switch (this->orientation) {
		default :
		case Orientation::Horizontal :
			firstLine = new Rectangle(xPosition, yPosition, xSize, 0.5);
			secondLine = new Rectangle(xPosition, yPosition + ySize, xSize, 0.5);
			break;

		case Orientation::Vertical :
			firstLine = new Rectangle(xPosition, yPosition, 0.5, ySize);
			secondLine = new Rectangle(xPosition + xSize, yPosition, 0.5, ySize);
			break;

		case Orientation::topRightCorner :
			firstLine = new Rectangle(xPosition, yPosition, xSize, 0.5);
			secondLine = new Rectangle(xPosition + xSize, yPosition, 0.5, ySize);
			break;

		case Orientation::topLeftCorner :
			firstLine = new Rectangle(xPosition, yPosition, xSize, 0.5);
			secondLine = new Rectangle(xPosition, yPosition, 0.5, ySize);
			break;

		case Orientation::botRightCorner :
			firstLine = new Rectangle(xPosition + xSize, yPosition, 0.5, ySize);
			secondLine = new Rectangle(xPosition, yPosition + ySize, xSize, 0.5);
			break;

		case Orientation::botLeftCorner :
			firstLine = new Rectangle(xPosition, yPosition, 0.5, xSize);
			secondLine = new Rectangle(xPosition, yPosition + ySize, xSize, 0.5);
			break;
	}
}

void Path::updatePosition() {
	float xPosition = getXPosition();
	float yPosition = getYPosition();

	sf::Vector2f size = getSize();

	switch (this->orientation) {
		default:
		case Orientation::Horizontal:
			firstLine->setPosition(xPosition, yPosition);
			secondLine->setPosition(xPosition, yPosition + size.y);
			break;

		case Orientation::Vertical:
			firstLine->setPosition(xPosition, yPosition);
			secondLine->setPosition(xPosition + size.x, yPosition);
			break;

		case Orientation::topRightCorner:
			firstLine->setPosition(xPosition, yPosition);
			secondLine->setPosition(xPosition + size.x, yPosition);
			break;

		case Orientation::topLeftCorner:
			firstLine->setPosition(xPosition, yPosition);
			secondLine->setPosition(xPosition, yPosition);
			break;

		case Orientation::botRightCorner:
			firstLine->setPosition(xPosition + size.x, yPosition);
			secondLine->setPosition(xPosition, yPosition + size.y);
			break;

		case Orientation::botLeftCorner:
			firstLine->setPosition(xPosition, yPosition);
			secondLine->setPosition(xPosition, yPosition + size.y);
			break;
	}

}
