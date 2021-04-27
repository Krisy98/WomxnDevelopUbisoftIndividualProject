#include "stdafx.h"
#include "Point.h"

Point::Point(float x, float y){
	set(x, y);
}

Point::Point(){
	set(0.f, 0.f);
}

Point::~Point(){
}

void Point::setX(float x){ coordinates.x = x; }

void Point::setY(float y){ coordinates.y = y; }

void Point::set(float x, float y){ coordinates = sf::Vector2f(x, y); }

float Point::getX(){ return coordinates.x; }

float Point::getY(){ return coordinates.y; }
