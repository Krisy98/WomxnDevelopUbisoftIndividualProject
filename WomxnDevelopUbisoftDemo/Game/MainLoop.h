#pragma once

#include "Engine/Context/Context.h";
#include "Game/Context/PlayContext.h"
#include "Game/Context/EndContext.h"

#include <iostream>
#include <string>

class MainLoop : public Game {

public :
	MainLoop(); 

	void Update(float deltaTime) override;
	void Render(sf::RenderTarget& target) override;
	void RenderDebugMenu(sf::RenderTarget& target) override;
	void HandleEvent(sf::Event event) override;

	void switchContext();

	void initPlayContext();
	void initEndContext(const char* message);
	//void initMenuContext();
	//void initMapContext();

private :
	sf::Event event;
	Context *context;
	std::string context_str;
};

