#pragma once

#include "Engine/Entities/Entity.h"
#include "Engine/Shapes/Rectangle.h"
#include "Engine/Direction.h"
#include "EntityType.h"

class Insect : public Entity {

public : 
	Insect(float xPosition, float yPosition, float size, Direction direction, InsectType type);

	void draw(sf::RenderTarget& target) override;
	void update(sf::RenderWindow& win) override;

	void setDirection(Direction direction);
	


private :
	Rectangle* body;

	Direction direction;
	
	float life;


	void initFromType(InsectType type);
	void move();

};

