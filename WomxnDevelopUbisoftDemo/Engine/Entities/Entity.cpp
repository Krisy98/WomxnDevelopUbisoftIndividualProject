#include "stdafx.h"
#include "Entity.h"

void Entity::createBoundingBox(){ 
	const auto position = this->position;
	const auto size = this->size;

	SetBoundingBox(position, size); 
}


void Entity::setPosition(sf::Vector2f position){ 
	this->position = position; 
}

void Entity::setSpeed(sf::Vector2f speed){ 
	this->speed = speed; 
}

float Entity::getXSpeed(){ return this->speed.x; }

float Entity::getYSpeed(){ return this->speed.y; }

sf::Color Entity::getColor(){
	return sf::Color(static_cast<uint8_t>(this->m_rColor * 255.0f), static_cast<uint8_t>(this->m_gColor * 255.0f), static_cast<uint8_t>(this->m_bColor * 255.0f), static_cast<uint8_t>(this->m_alpha * 255.0f));
}

sf::Vector2f Entity::getPosition() { return position; }

float Entity::getXPosition() { return this->position.x; }

float Entity::getYPosition(){ return this->position.y; }

sf::Vector2f Entity::getSize() { return this->size; }

float Entity::getWidth(){ return size.x; }

float Entity::getHeight(){ return size.y; }

void Entity::setSize(sf::Vector2f size){ this->size = size; }

void Entity::setColor(double rColor, double gColor, double bColor){
	this->m_rColor = rColor;
	this->m_gColor = gColor;
	this->m_bColor = bColor;
	this->m_alpha = 1;
}

void Entity::setColor(double rColor, double gColor, double bColor, double alpha){
	this->m_rColor = rColor;
	this->m_gColor = gColor;
	this->m_bColor = bColor;
	this->m_alpha = alpha;
}


