#pragma once
#include "Engine/ToDraw/Shapes/Shape.h"

class Line : public Shape {


public :
	Line(sf::Vector2f startPoint, sf::Vector2f endPoint);
	~Line();

	sf::Color getColor() override;
	sf::Color getOutLineColor() override;
	sf::Vector2f getPosition() override;
	sf::Vertex* get();

	void setColor(sf::Color color) override;
	void setThickness(float thickness, sf::Color color) override;
	void setPosition(float xPosition, float yPosition) override;
	void setPosition(sf::Vector2f position) override;

private :
	sf::Vertex points[];


};

