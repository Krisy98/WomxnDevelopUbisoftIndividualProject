#pragma once

#include "Entity.h"
#include "EntityType.h"

class Insect : public Entity {

public : 
	Insect(float xPosition, float yPosition, InsectType type);
	~Insect();

	void initialization(InsectType type);


private :

	float xPosition,
		yPosition;

	float xSpeed,
		ySpeed;

	float width,
		height;


};

