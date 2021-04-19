#pragma once

#include "Engine/Entities/Entity.h"

struct Entities {
	Entity* current{ nullptr };
	Entities* next{ nullptr };
};

class Context {

public :
	virtual ~Context() {}; // to call destructor of the inherit classes
	virtual void update(sf::RenderWindow& win) = 0;
	virtual void render(sf::RenderTarget& target) = 0;

	/// <summary>
	/// Inizialise variable firstEntity of Entities type
	/// </summary>
	/// <param name="firstEntity"></param>
	void initEntities(Entities* firstEntity);

	/// <summary>
	/// Delete or destroy variable entities of Entities type
	/// </summary>
	/// <param name="entities"></param>
	void deleteEntities(Entities* entities);

	/// <summary>
	/// Add a entity at the last value from the variable entities of Entities type
	/// </summary>
	/// <param name="entities"></param>
	/// <param name="entity"></param>
	void addEntity(Entities* entities, Entity* entity);

	/// <summary>
	/// Render an entity
	/// </summary>
	/// <param name="target">the render target</param>
	/// <param name="entities">entities to render</param>
	void renderEntities(sf::RenderTarget& target, Entities entities);

	void updateEntities(Entities entities, sf::RenderWindow& window);

	void setEntitiesPosition(Entities entities, sf::Vector2f speed);
};

