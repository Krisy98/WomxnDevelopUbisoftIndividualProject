#pragma once
class Shape {

public :

	virtual void setColor(sf::Color color) = 0;
	virtual void setThickness(float thickness, sf::Color color) = 0;
	virtual void setColorAndThickness(sf::Color color, float thickness, sf::Color outLineColor) = 0;
};

