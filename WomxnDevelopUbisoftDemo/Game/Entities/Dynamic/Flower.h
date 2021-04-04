#pragma once

#include "Engine/Entities/Entity.h"
#include "Engine/Shapes/Circle.h"
#include "EntityType.h"


class Flower : public Entity {

public :
	Flower(float xPosition, float yPosition, float size, FlowerType type);
	~Flower();

	void draw(sf::RenderTarget& target) override;
	void update(sf::RenderWindow& win) override;

	void setVisibleRange(bool value);
	bool getVisibleRange();
	
	sf::Color getRangeColor();
	sf::Color getRangeOutLineColor();
	

private :
	sf::Event event; // TODO : pas de sf ici, gameplay n'interagit pas avec API. C'est que le moteur ??

	Circle* circle;
	Circle* circleRange;

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

