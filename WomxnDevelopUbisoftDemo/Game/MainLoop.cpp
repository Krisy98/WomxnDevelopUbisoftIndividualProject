#include "stdafx.h"
#include "MainLoop.h"

MainLoop::MainLoop() :
	Game{ "Flowers Survive" }
{

	initPlayContext();
}

void MainLoop::Update(float deltaTime){
	this->context->update(*getWindow());
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

void MainLoop::initPlayContext(){
	
	this->context = new PlayContext();

}
