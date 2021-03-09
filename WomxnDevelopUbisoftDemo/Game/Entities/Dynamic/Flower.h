#pragma once

#include "Engine/Entities/Entity.h"
#include "EntityType.h"
#include "Engine/Shapes/Shape.h"

class Flower : public Entity {

public :
	Flower(float xPosition, float yPosition, FlowerType type);
	~Flower();

	void draw(sf::RenderTarget& target) override;
	void update(sf::RenderWindow& win) override;

	void setVisibleRange(bool value);
	bool getVisibleRange();
	
	sf::Color getRangeColor();
	sf::Color getRangeOutLineColor();
	

private :
	Shape shaper;
	sf::Event event;

	sf::CircleShape circle;
	sf::CircleShape circleRange;


	float plantRadius; 
	float rangeRadius; 

	//int damage;

	bool visibleRange;



	/// <summary>
	/// Set the attributes value according to the flowertype
	/// </summary>
	/// <param name="type">value from FlowerType enum</param>
	void initFromType(FlowerType type);

	void setRange(float value);

};

