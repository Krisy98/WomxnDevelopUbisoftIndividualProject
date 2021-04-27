#include "stdafx.h"
#include "Line.h"

Line::Line(sf::Vector2f startPoint, sf::Vector2f endPoint){
	points[2] = { startPoint, endPoint };
}

Line::~Line(){}

sf::Color Line::getColor(){ return points->color; }

sf::Color Line::getOutLineColor(){ return sf::Color(); }

sf::Vector2f Line::getPosition(){
	return sf::Vector2f();
}

sf::Vertex* Line::get(){ return this->points; }

void Line::setColor(sf::Color color){ points->color = color; }

void Line::setThickness(float thickness, sf::Color color){}

void Line::setPosition(float xPosition, float yPosition){

}

void Line::setPosition(sf::Vector2f position){
	
}

//void Line::setColorAndThickness(sf::Color color, float thickness, sf::Color outLineColor){ setColor(color); }
