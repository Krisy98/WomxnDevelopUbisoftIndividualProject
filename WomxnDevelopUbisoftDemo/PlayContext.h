#pragma once
#include "Context.h"
#include "Game/Entities/Dynamic/Flower.h"
#include "Game/Entities/Dynamic/Insect.h"
#include "Game/Entities/Static/TowerEmplacement.h"


struct Entities {
	Entity* current;
	Entities* next;
};


class PlayContext : public Context {

public :
	PlayContext(sf::Window *win);
	virtual ~PlayContext();

	virtual void update();
	virtual void render(sf::RenderTarget& target);
	
	void updateEntities(Entities entities);

	/// <summary>
	/// Render (draw) a child entity
	/// </summary>
	/// <param name="target">the render target</param>
	/// <param name="entities">entities to render</param>
	void renderEntities(sf::RenderTarget& target, Entities entities);


private :
	sf::Event event;
	sf::Window win;

	void addFlower(float x, float y, FlowerType type);

	//int nbEmplacement;

	Entities *insects = (Entities*) malloc(sizeof(struct Entities));
	Entities *flowers = (Entities *) malloc(sizeof(struct Entities));



	TowerEmplacement *emplacement;



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

