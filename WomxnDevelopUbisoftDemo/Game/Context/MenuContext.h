#pragma once

#include "Engine/Context/Context.h"

class MenuContext : public Context {

public :
	MenuContext();
	~MenuContext();

	virtual void update(sf::RenderWindow& win);
	virtual void render(sf::RenderTarget& target);
	virtual void handleEvent(sf::Event event);

};

