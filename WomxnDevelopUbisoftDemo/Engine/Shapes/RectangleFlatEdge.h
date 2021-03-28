#pragma once

#include "Shape.h"

class RectangleFlatEdge : public Shape {

public :

	RectangleFlatEdge(float xPosition, float yPosition, float width, float height, float fractionalWidth, float fractionalHeight);
	~RectangleFlatEdge();

	sf::ConvexShape get();
	sf::Vector2f getPosition() override;

	sf::Color getColor() override;
	sf::Color getOutLineColor() override;

	void setColor(sf::Color color) override;
	void setThickness(float thickness, sf::Color color) override;
	void setPosition(float xPosition, float yPosition) override;
	void setPosition(sf::Vector2f position) override;

private :
	sf::ConvexShape convexShape;
	sf::Vector2f size,
		position, 
		fractionalSizeFlatEdge;

	void create();
};

