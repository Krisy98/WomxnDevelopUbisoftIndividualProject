#pragma once

#include "Engine/Entities/Entity.h"
#include "Engine/Shapes/Rectangle.h"

class TowerEmplacement : public Entity {


public :
	TowerEmplacement(float xPosition, float yPosition);
	~TowerEmplacement();


	void draw(sf::RenderTarget& target) override;
	void update(sf::RenderWindow& win) override;


private :

	Rectangle* rectangle;

	float m_rColor,
		m_gColor,
		m_bColor,
		m_alphaColor;

};

