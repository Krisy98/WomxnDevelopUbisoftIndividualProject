#include "stdafx.h"
#include "Entity.h"

void Entity::createBoundingBox(){ 
	const auto position = sf::Vector2f(xPosition, yPosition);
	const auto size = sf::Vector2f(width, height);

	SetBoundingBox(position, size); 
}

void Entity::setPosition(float x, float y){
	this->xPosition = x;
	this->yPosition = y;
}

void Entity::setSpeed(float xSpeed, float ySpeed){
	this->xSpeed = xSpeed;
	this->ySpeed = ySpeed;
}

float Entity::getXSpeed(){ return this->xSpeed; }

float Entity::getYSpeed(){ return this->ySpeed; }

sf::Color Entity::getColor(){
	return sf::Color(static_cast<uint8_t>(this->m_rColor * 255.0f), static_cast<uint8_t>(this->m_gColor * 255.0f), static_cast<uint8_t>(this->m_bColor * 255.0f));
}

sf::Vector2f Entity::getPosition(){ return sf::Vector2f(xPosition, yPosition); }

float Entity::getXPosition(){ return this->xPosition; }

float Entity::getYPosition(){ return this->yPosition; }

sf::Vector2f Entity::getSize(){ return sf::Vector2f(width, height); }

float Entity::getWidth(){ return width; }

float Entity::getHeight(){ return height; }

void Entity::setWidth(float width){ this->width = width; }

void Entity::setHeight(float height){ this->height = height; }

void Entity::setColor(double m_rColor, double m_gColor, double m_bColor){
	this->m_rColor = m_rColor;
	this->m_gColor = m_gColor;
	this->m_bColor = m_bColor;
}



/*
bool Entity::isOnMouseMoved(sf::Window* win) {
	while (win->waitEvent(event)) {
		printf("event poll ! ");
		switch (event.type) {

		case sf::Event::MouseMoved:
			printf("mouseMoved ! ");
			return true;

		case sf::Event::MouseButtonPressed:
			printf("mouse pressed ");
			break;

		default:
			break;
		}
	}
	printf("no event ...");
	return false;
}
*/


