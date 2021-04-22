#pragma once

#include "Engine/Entities/Entity.h"

class FlowerMenu : public Entity {

public :
	FlowerMenu(float xPosition, float yPosition);
	~FlowerMenu();

	void draw(sf::RenderTarget& target) override;
	void update(sf::RenderWindow& win) override;

private :
	sf::Font font;
	sf::Text text;

	sf::Vector2f position;
};

