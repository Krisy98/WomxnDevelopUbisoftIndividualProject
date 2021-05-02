#pragma once

#include "Engine/Entities/Entity.h"
#include "Engine/Draw/Shapes/Circle.h"
#include "Game/Entities/EntityType.h"
#include "Game/Entities/Dynamic/Seed.h"
#include "Game/Entities/Dynamic/Insect.h"

class Flower : public Entity {

public :
	Flower(sf::Vector2f position, float size, FlowerType type, Entities* enemies);
	~Flower();

	void draw(sf::RenderTarget& target) override;
	void update(sf::RenderWindow& win) override;

	void applyDifficulty(float difficultyLevel);

	void setVisibleRange(bool value);
	bool getVisibleRange();
	
	sf::Color getRangeColor();
	sf::Color getRangeOutLineColor();
	
private :
	sf::Event event;
	sf::Clock clock;

	Circle* circle;
	Circle* circleRange;

	Entities* enemies;
	Entities* seeds;

	float plantRadius;
	float rangeRadius;
	bool visibleRange;

	int damage;

	/// <summary>
	/// Set the attributes value according to the flowertype
	/// </summary>
	/// <param name="type">value from FlowerType enum</param>
	void initFromType(FlowerType type);

	/// <summary>
	/// Create a seed with his target, 
	/// if flower is charged (thank to time) 
	/// and if there is an insect in his range
	/// </summary>
	void tryShoot();

	/// <summary>
	/// Return true if there is enough second elapsed since the last seed entity created
	/// </summary>
	/// <returns></returns>
	bool isRecharged();

	/// <summary>
	/// If mouse on, show range of the flower
	/// Else make it visible
	/// </summary>
	/// <param name="mouse"></param>
	void mouseOn(sf::Vector2i mouse);

	/// <summary>
	/// Permise updating seeds
	/// Look if there is a seed that reached his target
	/// In this case, remove the seed and send damage to his target
	/// </summary>
	/// <param name="window"></param>
	void updateSeeds(sf::RenderWindow& window);
	
	void setRange(float value);
	void setDamage(float damage);

	float getDamage();
};

