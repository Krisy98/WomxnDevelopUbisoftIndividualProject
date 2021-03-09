#pragma once
class Shape {

public :

	/// <summary>
	/// Create and return a circle in the right position and radius
	/// </summary>
	/// <param name="xPosition"></param>
	/// <param name="yPosition"></param>
	/// <param name="radius"></param>
	/// <returns></returns>
	sf::CircleShape getCircle(float xPosition, float yPosition, float radius);

	/// <summary>
	/// Create and return a rectangle in the right position and dimension
	/// </summary>
	/// <param name="xPosition"></param>
	/// <param name="yPosition"></param>
	/// <param name="width"></param>
	/// <param name="height"></param>
	/// <returns></returns>
	sf::RectangleShape getRectangle(float xPosition, float yPosition, float width, float height);
	
	/// <summary>
	/// Return the concerned circle with the right color
	/// </summary>
	/// <param name="circle">the circle to change</param>
	/// <param name="color">fill color to use</param>
	/// <param name="thickness">outline thickness</param>
	/// <param name="outLineColor">outline color</param>
	/// <returns></returns>
	sf::CircleShape setColor(sf::CircleShape circle, sf::Color color, float thickness, sf::Color outLineColor);

	/// <summary>
	/// Return the concerned rectangle with the right color
	/// </summary>
	/// <param name="rectangle"></param>
	/// <param name="color"></param>
	/// <param name="thickness"></param>
	/// <param name="outLineColor"></param>
	/// <returns></returns>
	sf::RectangleShape setColor(sf::RectangleShape rectangle, sf::Color color, float thickness, sf::Color outLineColor);


};

