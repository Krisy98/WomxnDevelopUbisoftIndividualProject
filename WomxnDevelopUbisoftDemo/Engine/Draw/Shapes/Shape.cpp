#include "stdafx.h"
#include "Shape.h"

void Shape::setColorAndThickness(sf::Color color, float thickness, sf::Color outLineColor){
	setColor(color);
	setThickness(thickness, outLineColor);
}
