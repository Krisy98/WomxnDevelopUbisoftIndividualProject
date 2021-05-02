#pragma once

#include "Engine/Context/Context.h"
#include "Engine/Draw/Shapes/Point.h"
#include "Engine/File.h"
#include "Game/Entities/static/FlowerMenu.h"
#include "Game/Waves/Wave.h"

// Entities
#include "Game/Entities/Dynamic/Flower.h"
#include "Game/Entities/Dynamic/Insect.h"
#include "Game/Entities/Static/Path.h"
#include "Game/Entities/Static/TowerEmplacement.h"
#include "Engine/Entities/Entity.h"

#include <list>

class PlayContext : public Context {

public :
	PlayContext();
	virtual ~PlayContext();

	virtual void update(sf::RenderWindow& win);
	virtual void render(sf::RenderTarget& target);
	virtual void handleEvent(sf::Event event);
	virtual bool done();

	bool isLevelDone();
	
private :
	float speedScrolling;
	float baseSize;
	std::vector<Point> points; // path to follow
	std::vector<Wave> waves; 
	FlowerMenu *flowerMenu = nullptr;

	Entities* insects = new Entities();
	Entities* flowers = new Entities();
	Entities* emplacements = new Entities();
	Entities* path = new Entities();

	sf::Clock clock;

	/// <summary>
	/// update screen's view depending on the mouse position
	/// </summary>
	/// <param name="window"></param>
	void updateScreen(sf::RenderWindow& window);

	/// <summary>
	/// Test if there is an insect with no life and in this case remove it
	/// </summary>
	void lookForDeadInsect();

	/// <summary>
	/// Update position for all physics elements,
	/// That make sure to keep correct coordinates
	/// when player want to move into the screen
	/// </summary>
	/// <param name="speed"></param>
	void moveScreen(sf::Vector2f speed);

	/// <summary>
	/// test and return true if there is a tower emplacement clicked on by the mouse
	/// If it found it, call setFlowerMenu to update it correctly
	/// </summary>
	/// <param name="xMouse"></param>
	/// <param name="yMouse"></param>
	/// <returns></returns>
	bool isAEmplacementClicked(float xMouse, float yMouse);

	/// <summary>
	/// test and return true if there is a item of flowerMenu clicked on by the mouse
	/// </summary>
	/// <param name="xMouse"></param>
	/// <param name="yMouse"></param>
	/// <returns></returns>
	bool isAFlowerSelected(float xMouse, float yMouse);

	/// <summary>
	/// update the current wave which insect will be dropped
	/// </summary>
	void nextWave();

	/// <summary>
	/// Add an insect with correct condition of time
	/// </summary>
	void dropInsect();
	 
	/// <summary>
	/// Create a path way from a file that define the level
	/// To be used correctly, the cursor need to be at the right place
	/// First, it read the number of path entity
	/// Then create them 
	/// </summary>
	void createPath(File* file);

	/// <summary>
	/// Create every emplacement for flower entities from a file
	/// To be used correctly, the cursor need to be at the right place
	/// </summary>
	void createEmplacements(File* file);

	/// <summary>
	/// Create wave that define the level from a file
	/// The cursor need to be at the right emplacement
	/// </summary>
	/// <param name="file"></param>
	void createWaves(File* file);

	/// <summary>
	/// The entity param must be a TowerEmplacement entity
	/// This function create or remove a flowerMenu from the entity
	/// </summary>
	/// <param name="entity"></param>
	void setFlowerMenu(Entity* entity);

};

