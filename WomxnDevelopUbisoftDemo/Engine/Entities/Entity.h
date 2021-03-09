#pragma once



// created by me


class Entity{

public :

	virtual ~Entity() {};

	// to override
	virtual void draw(sf::RenderTarget& target) = 0;
	virtual void update() = 0;


	//
	//sf::Event event;
	//bool isOnMouseMoved(sf::Window* win);



protected :

	void setPosition(float x, float y);
	void setSpeed(float xSpeed, float ySpeed);
	void setWidth(float width);
	void setHeight(float height);
	void setColor(double m_rColor, double m_gColor, double m_bColor);

	
	float getXPosition();
	float getYPosition();
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

