#pragma once

#include "Engine/Shapes/Shape.h"

class Circle : public Shape{

public :
	Circle(float xPosition, float yPosition, float radius);
	~Circle();

	sf::CircleShape get();
	sf::Color getColor() override;
	sf::Color getOutLineColor() override;
	sf::Vector2f getPosition() override;

	void setColor(sf::Color color) override;
	void setThickness(float thickness, sf::Color color) override;
	void setPosition(float xPosition, float yPosition) override;
	void setPosition(sf::Vector2f position) override;

private :
	sf::CircleShape circle;
	

};

