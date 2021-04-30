#pragma once

#include "Engine/Entities/Entity.h"
#include "Game/Entities/Dynamic/Insect.h"

#include "Engine/Draw/Shapes/Circle.h"

class Seed : public Entity {

public :
	Seed(sf::Vector2f position, extern Insect& target);
	~Seed();

	void draw(sf::RenderTarget& target) override;
	void update(sf::RenderWindow& win) override;

	bool isAchieved();

	Insect* getTarget();

private :
	Circle* circle = nullptr;
	Insect* target;

	void initCircle();
	void updateSpeed();
};

