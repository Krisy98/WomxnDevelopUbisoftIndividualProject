#pragma once

#include "Engine/Entities/Entity.h"
#include "Engine/Draw/Shapes/Rectangle.h"

class TowerEmplacement : public Entity {

public :
	TowerEmplacement(float xPosition, float yPosition, float size);
	~TowerEmplacement();

	void draw(sf::RenderTarget& target) override;
	void update(sf::RenderWindow& win) override;

private :
	Rectangle* rectangle;
};

