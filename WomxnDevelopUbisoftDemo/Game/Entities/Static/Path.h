#pragma once

#include "Engine/Entities/Entity.h"
#include "Engine/Shapes/Rectangle.h"

enum class Orientation {
	Horizontal,
	Vertical
};

class Path : public Entity {

public :

	Path(float xPosition, float yPosition, float size, Orientation orientation);
	~Path();

	void draw(sf::RenderTarget& target) override;
	void update(sf::RenderWindow& win) override;


private :

	//Line* leftLine {nullptr}; // or up if orientation is horizontal
	//Line* rightLine {nullptr}; // or down if orientation is horizontal

	Rectangle* leftLine{ nullptr }; // or up if orientation is horizontal
	Rectangle* rightLine {nullptr}; // or down if orientation is horizontal

	Orientation orientation;

};

