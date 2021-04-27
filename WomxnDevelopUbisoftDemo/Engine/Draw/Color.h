#pragma once
class Color{

public :
	Color();
	~Color();

	sf::Color getColor(float r, float g, float b);
	sf::Color getColor(float r, float g, float b, float alpha);
	sf::Color getColor();

private :
	sf::Color* color;

};

