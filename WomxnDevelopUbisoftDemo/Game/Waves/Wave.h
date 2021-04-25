#pragma once

#include "Game/Entities/EntityType.h"
#include "Engine/ToDraw/Shapes/Point.h"

#include <list>

class Wave{

public :

	Wave(InsectType type, int nbInsect, sf::Vector2f position);
	~Wave();

	InsectType* getType();
	int getNbInsect();
	sf::Vector2f getPosition();

private :

	InsectType type;
	int nbInsect;
	sf::Vector2f position;

};