#pragma once
#include "Engine/Entities/Entity.h"
#include "Engine/Draw/Shapes/Rectangle.h"

enum class Orientation {
	Horizontal,
	Vertical,
	botRightCorner,
	topRightCorner,
	botLeftCorner,
	topLeftCorner
};

class Path : public Entity {

public :
	Path(float xPosition, float yPosition, float size, Orientation orientation);
	~Path();

	void draw(sf::RenderTarget& target) override;
	void update(sf::RenderWindow& win) override;

private :
	Rectangle* firstLine{ nullptr };
	Rectangle* secondLine {nullptr};
	Orientation orientation;

	void buildPath();
	void updatePosition();
};

