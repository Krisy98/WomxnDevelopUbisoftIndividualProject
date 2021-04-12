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

	void initEntities(Entities* firstEntity);
	void deleteEntities(Entities* entities);

	/// <summary>
	/// Render an entity
	/// </summary>
	/// <param name="target">the render target</param>
	/// <param name="entities">entities to render</param>
	void renderEntities(sf::RenderTarget& target, Entities entities);

	void updateEntities(Entities entities, sf::RenderWindow& window);

	void setEntitiesPosition(Entities entities, sf::Vector2f speed);
};

