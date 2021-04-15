#pragma once

#include "Engine/Entities/Entity.h"
#include "Engine/Shapes/Rectangle.h"
#include "EntityType.h"

class Insect : public Entity {

public : 
	Insect(float xPosition, float yPosition, float size, Direction direction, InsectType type);

	void draw(sf::RenderTarget& target) override;
	void update(sf::RenderWindow& win) override;



	//void draw(sf::RenderTarget& target);

private :
	Rectangle* body;
	
	float life;


	void initFromType(InsectType type);
	void move();

};

