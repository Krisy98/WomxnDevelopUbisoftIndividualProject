#pragma once

#include "Context.h";
#include "PlayContext.h"

class MainLoop : public Game {

public :
	MainLoop(); 

	void Update(float deltaTime) override;
	void Render(sf::RenderTarget& target) override;
	void RenderDebugMenu(sf::RenderTarget& target) override;
	void HandleEvent(sf::Event event) override;

	void initPlayContext();
	//void initMenuContext();
	//void initMapContext();

private :

	sf::Event event;

	Context *context;


};

