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

	void setPosition(sf::Vector2f position);
	void setSpeed(sf::Vector2f speed);
	void setSize(sf::Vector2f size);
	void setColor(double rColor, double gColor, double bColor);
	void setColor(double rColor, double gColor, double bColor, double alpha);

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
	sf::Vector2f position;

	sf::Vector2f speed;

	sf::Vector2f size;

	double m_rColor,
		m_gColor, 
		m_bColor,
		m_alpha;

};

