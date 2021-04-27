#pragma once

class Shape {

public :

	virtual sf::Color getColor() = 0;
	virtual sf::Color getOutLineColor() = 0;

	virtual void setColor(sf::Color color) = 0;
	virtual void setThickness(float thickness, sf::Color color) = 0;
	void setColorAndThickness(sf::Color color, float thickness, sf::Color outLineColor);

	virtual void setPosition(float xPosition, float yPosition) = 0;
	virtual void setPosition(sf::Vector2f position) = 0;

	virtual sf::Vector2f getPosition() = 0;

};

