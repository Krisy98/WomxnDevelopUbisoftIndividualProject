#pragma once



// created by me


class Entity{

public :

	virtual ~Entity() {};

	void setSpeed(float xSpeed, float ySpeed);
	float getXSpeed();
	float getYSpeed();

	void setWidth(float width);
	void setHeight(float height);

	void setColor(float m_rColor, float m_gColor, float m_bColor);

	// to override
	virtual void draw(sf::RenderTarget& target) = 0;
	virtual void update() = 0;



private :
	float xPosition, 
		yPosition;

	float xSpeed,
		ySpeed;

	float width,
		height;

	float m_rColor,
		m_gColor, 
		m_bColor;

};

