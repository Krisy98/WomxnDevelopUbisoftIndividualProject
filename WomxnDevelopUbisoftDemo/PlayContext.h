#pragma once
#include "Context.h"
#include "Game/Entities/Dynamic/Flower.h"
#include "Game/Entities/Dynamic/Insect.h"
#include "Game/Entities/Static/Path.h"
#include "Game/Entities/Static/TowerEmplacement.h"
#include "Engine/Entities/Entity.h"

class PlayContext : public Context {

public :
	PlayContext();
	virtual ~PlayContext();

	virtual void update(sf::RenderWindow& win);
	virtual void render(sf::RenderTarget& target);
	
private :
	sf::RenderWindow window;
	float speedScrolling;
	float sizeCase;

	Entities* insects = new Entities();
	Entities* flowers = new Entities();
	Entities* emplacements = new Entities();
	Entities* path = new Entities();


	void addEntity(Entities* entities, Entity* entity);

	/// <summary>
	/// update screen's view depending on the mouse position
	/// </summary>
	/// <param name="window"></param>
	void updateScreen(sf::RenderWindow& window);

	void setAllEntitiesPosition(sf::Vector2f speed);

	void updateInsects(sf::RenderWindow& window);




	/*
	entities :
		- flower
		- insects (enemies) // specific to the level
		- basic informations :
			- life
			- indication of the enemies direction
	*/

	// sounds

};

