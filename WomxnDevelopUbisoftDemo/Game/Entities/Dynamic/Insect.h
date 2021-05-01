#pragma once

#include "Engine/Entities/Entity.h"
#include "Game/Entities/EntityType.h"

#include "Engine/Draw/Shapes/Rectangle.h"
#include "Engine/Draw/Shapes/Point.h"


class Insect : public Entity {

public : 
	Insect(float xPosition, float yPosition, float size, std::vector<Point>* points, InsectType type);

	void draw(sf::RenderTarget& target) override;
	void update(sf::RenderWindow& win) override;

	void reduceLife(float damage);
	void applyDifficulty(float difficultyLevel);

	float getLife();

	sf::Time getTimeForPrepare();

private :
	Rectangle* body;
	std::vector<Point>* points; // way
	int indexPoints = 0;
	float life;
	bool atHome; // false if no there no next point to go
	Direction direction;
	sf::Time timeForPrepare;

	void initFromType(InsectType type);
	void updateDirection();
	void updateRotation();
	void move();

	/// <summary>
	/// Delete the first point from the global variable of points
	/// And set the new corresponding direction
	/// </summary>
	void nextPoint();

	void setDirection(Direction direction);
	void setLife(float life);
	Direction getDirection();
};