#include "stdafx.h"
#include "Entity.h"

#include <iostream>

void Entity::createBoundingBox(){ 
	const auto position = sf::Vector2f(this->position.x + size.x/2, this->position.y + size.y/2);
	//const auto position = sf::Vector2f(this->position.x, this->position.y);
	const auto size = this->size;

	SetCenter(position);

	SetBoundingBox(position, size); 
}

void Entity::move(){
	float xPosition = getXPosition() + getXSpeed();
	float yPosition = getYPosition() + getYSpeed();
	setPosition(xPosition, yPosition);
}


void Entity::drawEntity(sf::RenderTarget& target){
	draw(target); // child
}

void Entity::updateEntity(sf::RenderWindow& window){
	update(window);
}

void Entity::setPosition(float x, float y){
	setPosition(sf::Vector2f(x, y));
}

void Entity::setPosition(sf::Vector2f position){
	this->position = position;
	createBoundingBox();
}

void Entity::setSpeed(sf::Vector2f speed){ 
	this->speed = speed; 
}

void Entity::setSize(sf::Vector2f size) { this->size = size; }

void Entity::setColor(double rColor, double gColor, double bColor) {
	this->m_rColor = rColor;
	this->m_gColor = gColor;
	this->m_bColor = bColor;
	this->m_alpha = 1;
}

void Entity::setColor(double rColor, double gColor, double bColor, double alpha) {
	this->m_rColor = rColor;
	this->m_gColor = gColor;
	this->m_bColor = bColor;
	this->m_alpha = alpha;
}

float Entity::getXSpeed(){ return this->speed.x; }

float Entity::getYSpeed(){ return this->speed.y; }

sf::Color Entity::getColor(){
	return sf::Color(static_cast<uint8_t>(this->m_rColor * 255.0f), static_cast<uint8_t>(this->m_gColor * 255.0f), static_cast<uint8_t>(this->m_bColor * 255.0f), static_cast<uint8_t>(this->m_alpha * 255.0f));
}

sf::Vector2f Entity::getPosition() { return position; }

void Entity::getPosition(sf::Vector2f& position){
	position = this->position;
}

float Entity::getXPosition() { return this->position.x; }

float Entity::getYPosition(){ return this->position.y; }

sf::Vector2f Entity::getSize() { return this->size; }

sf::Vector2f Entity::getCenter(){ return GetCenter(); }

float Entity::getWidth(){ return size.x; }

float Entity::getHeight(){ return size.y; }