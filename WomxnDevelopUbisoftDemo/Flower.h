#pragma once

#include "Entity.h"
#include "EntityType.h"

class Flower : public Entity {

public :
	Flower(float xPosition, float yPosition, FlowerType type);
	~Flower();

	void draw(sf::RenderTarget& target) override;
	void update() override;

	void setVisibleRange(bool value);
	bool getVisibleRange();

	
	//bool isOnMouseMoved(sf::Window *win);
	
private :

	/// <summary>
	/// Set the attributes value according to the flowertype
	/// </summary>
	/// <param name="type">value from FlowerType enum</param>
	void initFromType(FlowerType type);

	void setRange(float value);

	sf::Event event;

	sf::CircleShape circle;
	sf::CircleShape circleRange;


	float plantRadius; 

	float rangeRadius; 

	//int damage;

	

	bool visibleRange;


	

};
