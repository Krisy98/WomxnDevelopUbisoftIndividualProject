#pragma once

#include "Engine/Direction.h"

class Entity : public BoxCollideable {

public :

	virtual void draw(sf::RenderTarget& target) = 0;
	virtual void update(sf::RenderWindow& win) = 0;

	void drawEntity(sf::RenderTarget& target);
	void updateEntity(sf::RenderWindow& window);

	void setPosition(float x, float y);
	void setPosition(sf::Vector2f position);
	void setDirection(Direction direction);

	sf::Vector2f getPosition();
	float getXPosition();
	float getYPosition();
	Direction getDirection();

protected :
	/// <summary>
	/// Create its bounding box. Must position and size yet be defined to success
	/// </summary>
	void createBoundingBox();

	void setSpeed(sf::Vector2f speed);
	void setSize(sf::Vector2f size);
	void setColor(double rColor, double gColor, double bColor);
	void setColor(double rColor, double gColor, double bColor, double alpha);
	

	sf::Vector2f getSize();
	float getWidth();
	float getHeight();
	float getXSpeed();
	float getYSpeed();
	sf::Color getColor();

private :
	sf::Vector2f position;
	sf::Vector2f speed;
	sf::Vector2f size;

	double m_rColor,
		m_gColor, 
		m_bColor,
		m_alpha;

	Direction direction;
};

