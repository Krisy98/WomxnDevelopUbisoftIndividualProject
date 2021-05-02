#include "stdafx.h"
#include "EndContext.h"

#include <iostream>

EndContext::EndContext(const char* message){
	sf::Font font;
	this->message = new sf::Text();

	if (!font.loadFromFile("Assets/fonts\\champagne_and_limousines.ttf")) {
		std::cout << "error to load file for font" << std::endl;
	}

	this->message->setFont(font);
	this->message->setString(message);
	this->message->setPosition(sf::Vector2f(20.f, 20.f));
	this->message->setCharacterSize(30.f);
	this->message->setFillColor(sf::Color::Magenta);
}

EndContext::~EndContext() {
}

void EndContext::update(sf::RenderWindow& win){
	if (this->message->getPosition() == sf::Vector2f(0.f, 0.f)) {
		this->message->setPosition(win.getSize().x / 2.f, win.getSize().y / 2.f);
	}
	
}

void EndContext::render(sf::RenderTarget& target){
	target.clear(sf::Color(0, 0, 0));

	//std::cout << "render ; message : " << (message == nullptr) << std::endl;

	//target.draw(*message); // error
}

void EndContext::handleEvent(sf::Event event){

}

bool EndContext::done(){
	return false;
}
