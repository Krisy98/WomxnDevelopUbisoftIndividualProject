#pragma once

#include "Entity.h";

class TowerEmplacement : public Entity {


public :
	TowerEmplacement(float xPosition, float yPosition);
	~TowerEmplacement();

	void initForm(float edge);

	void draw(sf::RenderTarget& target) override;
	void update() override;


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

