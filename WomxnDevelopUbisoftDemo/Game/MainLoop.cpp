#include "stdafx.h"
#include "MainLoop.h"

MainLoop::MainLoop() :
	Game{ "Flowers Survive" }
{

	initPlayContext();
}

void MainLoop::Update(float deltaTime){
	this->context->update(*getWindow());

	if (this->context->done()) { 
		switchContext(); 
		Update(deltaTime);
	}
}

void MainLoop::Render(sf::RenderTarget& target){
	this->context->render(target);
}

void MainLoop::RenderDebugMenu(sf::RenderTarget& target){
	// nothing
}

void MainLoop::HandleEvent(sf::Event event){
	this->context->handleEvent(event);
}

void MainLoop::switchContext(){
	
	if (context_str == "play") {
		PlayContext* playContext = dynamic_cast<PlayContext*>(context);
		const char* str;

		if (playContext->isLevelDone()) { str = "level success !"; }
		else { str = "level miss !"; }

		initEndContext(str);
	}
}

void MainLoop::initPlayContext(){
	this->context = new PlayContext();
	this->context_str = "play";
}

void MainLoop::initEndContext(const char* message){
	this->context = new EndContext(message);
	this->context_str = "end";
}

