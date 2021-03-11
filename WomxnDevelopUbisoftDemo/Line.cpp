#include "stdafx.h"
#include "Line.h"

Line::Line(sf::Vector2f startPoint, sf::Vector2f endPoint){
	line[2] = { startPoint, endPoint };
}

Line::~Line(){}

sf::Color Line::getColor(){ return line->color; }

sf::Color Line::getOutLineColor(){ return sf::Color(); }

sf::Vertex* Line::get(){ return this->line; }

void Line::setColor(sf::Color color){ line->color = color; }

void Line::setThickness(float thickness, sf::Color color){}

void Line::setColorAndThickness(sf::Color color, float thickness, sf::Color outLineColor){ setColor(color); }
