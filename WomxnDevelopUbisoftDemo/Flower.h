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

	// mouse move, or just mouse on
	
	
private :
	void initFromType(FlowerType type);
	void setColor(double r, double g, double b);
	void setRange(float value);

	sf::Event event;

	sf::CircleShape circle;
	sf::CircleShape circleRange;

	float xPosition, 
		yPosition;

	float plantRadius; 

	float rangeRadius; 

	//int damage;

	double m_rColor,
		m_gColor,
		m_bColor;

	bool visibleRange;


	

};

