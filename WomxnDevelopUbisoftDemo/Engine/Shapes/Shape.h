#pragma once
class Shape {

public :

	virtual sf::Color getColor() = 0;
	virtual sf::Color getOutLineColor() = 0;

	virtual void setColor(sf::Color color) = 0;
	virtual void setThickness(float thickness, sf::Color color) = 0;
	virtual void setColorAndThickness(sf::Color color, float thickness, sf::Color outLineColor) = 0;

	void setPosition(float xPosition, float yPosition);
	void setPosition(sf::Vector2f position);

	sf::Vector2f getPosition();

protected :
	float xPosition,
		yPosition;

};

