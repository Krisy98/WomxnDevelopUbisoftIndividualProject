#pragma once



// created by me


class Entity : public BoxCollideable {

public :

	// to override
	virtual void draw(sf::RenderTarget& target) = 0;
	virtual void update(sf::RenderWindow& win) = 0;


protected :
	/// <summary>
	/// Create its bounding box. Must position and size yet be defined to success
	/// </summary>
	void createBoundingBox();

	void setPosition(float x, float y);
	void setSpeed(float xSpeed, float ySpeed);
	void setWidth(float width);
	void setHeight(float height);
	void setColor(double m_rColor, double m_gColor, double m_bColor);

	sf::Vector2f getPosition();
	float getXPosition();
	float getYPosition();
	sf::Vector2f getSize();
	float getWidth();
	float getHeight();
	float getXSpeed();
	float getYSpeed();
	sf::Color getColor();

private :
	float xPosition, 
		yPosition;

	float xSpeed,
		ySpeed;

	float width,
		height;

	double m_rColor,
		m_gColor, 
		m_bColor;

};

