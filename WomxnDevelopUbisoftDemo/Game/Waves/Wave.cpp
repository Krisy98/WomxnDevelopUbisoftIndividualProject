#include "stdafx.h"
#include "Wave.h"

Wave::Wave(InsectType type, int nbInsect, sf::Vector2f position){
	this->type = type;
	this->nbInsect = nbInsect;
	this->position = position;
}

Wave::~Wave(){
}

InsectType* Wave::getType(){ return &this->type; }

int Wave::getNbInsect(){ return this->nbInsect; }

sf::Vector2f Wave::getPosition(){ return this->position; }
