#pragma once

#include "Engine/Entities/Entity.h"
#include "Engine/ToDraw/TextList.h"
#include "Game/Entities/EntityType.h"

//#include "Game/Entities/static/FlowerItemMenu.h"

class FlowerMenu : public Entity {

public :
	FlowerMenu(float xPosition, float yPosition);
	~FlowerMenu();

	void draw(sf::RenderTarget& target) override;
	void update(sf::RenderWindow& window) override;

	/// <summary>
	/// Return the corresponding flower's type that contains x and y coordinates
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <returns></returns>
	FlowerType* getItem(float x, float y);

private :
	sf::Font font;

	TextList* textList = new TextList(); //
	float charSize;

	void addItem(float x, float y, const char* writing);
	FlowerType toFlowerType(const char* typeStr);
};

