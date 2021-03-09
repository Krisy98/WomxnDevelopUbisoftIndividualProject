#pragma once

#include "Engine/Entities/Entity.h"

class TowerEmplacement : public Entity {


public :
	TowerEmplacement(float xPosition, float yPosition);
	~TowerEmplacement();

	void initForm(float edge);

	void draw(sf::RenderTarget& target) override;
	void update(sf::RenderWindow& win) override;


private :

	sf::ConvexShape shape;


	float xPosition,
		yPosition;

	float width,
		height;


	float m_rColor,
		m_gColor,
		m_bColor,
		m_alphaColor;

};

