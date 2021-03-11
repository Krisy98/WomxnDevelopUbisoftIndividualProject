#pragma once

#include "Shape.h"

class Rectangle : public Shape {

public :
	Rectangle(float xPosition, float yPosition, float width, float height);
	~Rectangle();

	sf::ConvexShape get();

	sf::Color getColor() override;
	sf::Color getOutLineColor() override;

	void setColor(sf::Color color) override;
	void setThickness(float thickness, sf::Color color) override;
	void setColorAndThickness(sf::Color color, float thickness, sf::Color outLineColor) override;


	void createRectangle();
	void createRectangleFlatEdge(float fractionalWidth, float fractionalHeight);


private :
	sf::ConvexShape convexShape;
	
	float width, 
		height;
	
};

