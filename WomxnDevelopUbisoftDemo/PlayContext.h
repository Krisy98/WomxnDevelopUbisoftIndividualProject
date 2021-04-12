#pragma once
#include "Context.h"
#include "Game/Entities/Dynamic/Flower.h"
#include "Game/Entities/Dynamic/Insect.h"
#include "Game/Entities/Static/Path.h"
#include "Game/Entities/Static/TowerEmplacement.h"

class PlayContext : public Context {

public :
	PlayContext();
	virtual ~PlayContext();

	virtual void update(sf::RenderWindow& win);
	virtual void render(sf::RenderTarget& target);
	
private :
	sf::RenderWindow window;
	float speedScrolling;

	Entities* insects = (Entities*)malloc(sizeof(struct Entities));
	Entities* flowers = (Entities*)malloc(sizeof(struct Entities));
	Entities* emplacements = (Entities*)malloc(sizeof(struct Entities));
	Entities* path = (Entities*)malloc(sizeof(struct Entities));

	void addFlower(float x, float y, FlowerType type);
	void addInsect(float x, float y, Direction direction, InsectType type);
	void addTowerEmplacement(float xPosition, float yPosition);
	void addPath(float xPosition, float yPosition,Orientation orientation);

	/// <summary>
	/// update screen's view depending on the mouse position
	/// </summary>
	/// <param name="window"></param>
	void updateScreen(sf::RenderWindow& window);

	void setAllEntitiesPosition(sf::Vector2f speed);



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

