#pragma once

#include "Shape.h"

class Rectangle : public Shape {

public :
	Rectangle(float xPosition, float yPosition, float width, float height);
	~Rectangle();

	sf::ConvexShape get();
	sf::Vector2f getPosition() override;

	sf::Color getColor() override;
	sf::Color getOutLineColor() override;

	void setColor(sf::Color color) override;
	void setThickness(float thickness, sf::Color color) override;
	void setPosition(float xPosition, float yPosition) override;
	void setPosition(sf::Vector2f position) override;
	void setRotation(float rotation);

	void createRectangle();
	void createRectangleFlatEdge(float fractionalWidth, float fractionalHeight);

	float getRotation();

private :
	sf::ConvexShape convexShape;
	sf::Vector2f position;
	
	float width, 
		height;

};

