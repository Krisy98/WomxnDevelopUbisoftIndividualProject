#pragma once

#include "Context.h";
#include "PlayContext.h"

class MainLoop : public Game {

public :
	MainLoop(); 

	void Update(float deltaTime) override;
	void Render(sf::RenderTarget& target) override;
	void RenderDebugMenu(sf::RenderTarget& target) override;

	void initPlayContext();
	//void initMenuContext();
	//void initMapContext();

private :

	sf::Event event;
	const char* title = "Flowers Survive";

	Context *context = new PlayContext();  // first context of the program


};
