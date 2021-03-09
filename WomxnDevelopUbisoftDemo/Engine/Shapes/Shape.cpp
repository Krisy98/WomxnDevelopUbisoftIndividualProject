#include "stdafx.h"
#include "Shape.h"

sf::CircleShape Shape::getCircle(float xPosition, float yPosition, float radius) {
	sf::CircleShape circle;

	circle.setPosition(sf::Vector2f(xPosition, yPosition));
	circle.setRadius(radius);

	return circle;
}

sf::RectangleShape Shape::getRectangle(float xPosition, float yPosition, float width, float height){
	sf::RectangleShape rectangle;

	rectangle.setPosition(sf::Vector2f(xPosition, yPosition));
	rectangle.setSize(sf::Vector2f(width, height));

	return rectangle;
}

sf::CircleShape Shape::setColor(sf::CircleShape circle, sf::Color color, float thickness, sf::Color outLineColor){
	circle.setFillColor(color);

	if (thickness > 0.f) {
		circle.setOutlineThickness(thickness);
		circle.setOutlineColor(outLineColor);
	}
	return circle;
}

sf::RectangleShape Shape::setColor(sf::RectangleShape rectangle, sf::Color color, float thickness, sf::Color outLineColor){
	rectangle.setFillColor(color);

	if (thickness > 0.f) {
		rectangle.setOutlineThickness(thickness);
		rectangle.setOutlineColor(outLineColor);
	}
	return rectangle;
}

