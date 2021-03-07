#pragma once

// interface

class Context {

public :
	virtual ~Context() {}; // to call destructor of the inherit classes
	virtual void update() = 0;
	virtual void render(sf::RenderTarget& target) = 0;
};

