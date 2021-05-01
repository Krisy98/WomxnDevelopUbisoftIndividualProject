#pragma once

#include "Game/Entities/EntityType.h"
#include "Engine/Draw/Shapes/Point.h"
#include "Game/Entities/Dynamic/Insect.h"

#include <list>

class Wave{

public :
	Wave(InsectType type, int nbInsect, sf::Vector2f position);
	~Wave();

	InsectType* getType();
	int getNbInsect();
	sf::Vector2f getPosition();
	sf::Time getTimeToPrepare();

	void setPosition(sf::Vector2f position);

	/// <summary>
	/// get a new insect current the wave
	/// increment number of insects returned from the beginning
	/// </summary>
	/// <returns></returns>
	void decrementNbInsect();

	/// <summary>
	/// return true if the number of insect is at zero
	/// </summary>
	/// <returns></returns>
	bool isDone();

private :
	InsectType type;
	int nbInsect;
	sf::Vector2f position;
};