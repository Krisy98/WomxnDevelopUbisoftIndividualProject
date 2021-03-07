#pragma once
#include "Context.h"
#include "Flower.h"
#include "TowerEmplacement.h"
#include "Insect.h"




struct Entities {
	Entity* current;
	Entities* next;
};


class PlayContext : public Context {

public :
	PlayContext();
	virtual ~PlayContext();

	virtual void update();
	virtual void render(sf::RenderTarget& target);

	// update
	void updateEntities(Entities entities);

	// render
	void renderEntities(sf::RenderTarget& target, Entities entities);


private :

	void addFlower(float x, float y, FlowerType type);

	//int nbEmplacement;

	Entities *insects = (Entities*) malloc(sizeof(struct Entities));
	Entities *flowers = (Entities *) malloc(sizeof(struct Entities));


	TowerEmplacement *emplacement;



	/*
	entities :
		- flower
		- visible way
		- unvisible way
		- insects (enemies) // specific to the level
		- basic informations :
			- life
			- indication of the enemies direction
	*/

	// sounds

};

