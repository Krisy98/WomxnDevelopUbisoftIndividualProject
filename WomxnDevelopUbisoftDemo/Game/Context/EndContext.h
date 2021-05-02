#pragma once

#include "Engine/Context/Context.h"

class EndContext : public Context {

public : 
	EndContext(const char* message);
	~EndContext();

	virtual void update(sf::RenderWindow& win);
	virtual void render(sf::RenderTarget& target);
	virtual void handleEvent(sf::Event event);
	virtual bool done();

private :
	sf::Text* message;

};

