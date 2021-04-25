#pragma once

class Point{

public :

	Point(float x, float y);
	Point();
	~Point();

	void setX(float x);
	void setY(float y);
	void set(float x, float y);
	float getX();
	float getY();

private :

	sf::Vector2f coordinates;

};

