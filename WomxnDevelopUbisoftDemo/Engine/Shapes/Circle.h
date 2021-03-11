#pragma once

#include "Engine/Shapes/Shape.h"

class Circle : public Shape{

public :
	Circle(float xPosition, float yPosition, float radius);
	~Circle();

	sf::CircleShape get();
	sf::Color getColor() override;
	sf::Color getOutLineColor() override;

	void setColor(sf::Color color) override;
	void setThickness(float thickness, sf::Color color) override;
	void setColorAndThickness(sf::Color color, float thickness, sf::Color outLineColor) override;

private :
	sf::CircleShape circle;
	

};

