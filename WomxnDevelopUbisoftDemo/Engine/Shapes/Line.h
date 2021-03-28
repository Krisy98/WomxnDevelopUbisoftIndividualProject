#pragma once
#include "Engine/Shapes/Shape.h"

class Line : public Shape {


public :
	Line(sf::Vector2f startPoint, sf::Vector2f endPoint);
	~Line();

	sf::Color getColor() override;
	sf::Color getOutLineColor() override;
	sf::Vertex* get();

	void setColor(sf::Color color) override;
	void setThickness(float thickness, sf::Color color) override;

private :
	sf::Vertex line[];


};

