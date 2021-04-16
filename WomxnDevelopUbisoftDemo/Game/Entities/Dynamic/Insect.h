#pragma once

#include "Engine/Entities/Entity.h"
#include "EntityType.h"

#include "Engine/Shapes/Rectangle.h"
#include "Engine/Shapes/Point.h"


class Insect : public Entity {

public : 
	Insect(float xPosition, float yPosition, float size, std::vector<Point>* points, InsectType type);

	void draw(sf::RenderTarget& target) override;
	void update(sf::RenderWindow& win) override;


private :
	Rectangle* body;
	std::vector<Point>* points; // way
	float life;
	bool atHome; // false if no there no next point to go

	void initFromType(InsectType type);
	void updateDirection();
	void updateRotation();
	void move();
	void nextPoint();
};

