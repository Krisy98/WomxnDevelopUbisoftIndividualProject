#pragma once
#include "Context.h"
#include "Game/Entities/Dynamic/Flower.h"
#include "Game/Entities/Dynamic/Insect.h"
#include "Game/Entities/Static/TowerEmplacement.h"


struct Entities {
	Entity* current{ nullptr };
	Entities* next{ nullptr };
};


class PlayContext : public Context {

public :
	PlayContext();
	virtual ~PlayContext();

	virtual void update(sf::RenderWindow& win);
	virtual void render(sf::RenderTarget& target);
	
	void updateEntities(Entities entities, sf::RenderWindow& window);

	/// <summary>
	/// Render (draw) a child entity
	/// </summary>
	/// <param name="target">the render target</param>
	/// <param name="entities">entities to render</param>
	void renderEntities(sf::RenderTarget& target, Entities entities);


	
private :
	sf::RenderWindow window;
	float speedScrolling;

	Entities* insects = (Entities*)malloc(sizeof(struct Entities));
	Entities* flowers = (Entities*)malloc(sizeof(struct Entities));
	Entities* emplacements = (Entities*)malloc(sizeof(struct Entities));

	void initEntities(Entities *firstEntity);
	void deleteEntities(Entities *entities);
	void addFlower(float x, float y, FlowerType type);
	void addTowerEmplacement(float xPosition, float yPosition);

	/// <summary>
	/// update screen's view depending on the mouse position
	/// </summary>
	/// <param name="window"></param>
	void updateScreen(sf::RenderWindow& window);

	void setAllEntitiesPosition(sf::Vector2f speed);
	void setEntitiesPosition(Entities entities, sf::Vector2f speed);



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

