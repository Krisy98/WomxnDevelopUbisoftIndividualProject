#include "stdafx.h"
#include "Entity.h"

/*
Entity::Entity(float xPosition, float yPosition, float width, float height){

	this->xPosition = xPosition;
	this->yPosition = yPosition;

	this->width = width;
	this->height = height;

	this->xSpeed = 0;
	this->ySpeed = 0;

	this->m_rColor = 0;
	this->m_gColor = 0;
	this->m_bColor = 0;
}
*/

void Entity::setSpeed(float xSpeed, float ySpeed){
	this->xSpeed = xSpeed;
	this->ySpeed = ySpeed;
}

float Entity::getXSpeed(){ return this->xSpeed; }

float Entity::getYSpeed(){ return this->ySpeed; }

void Entity::setWidth(float width){
	this->width = width;
}

void Entity::setHeight(float height){
	this->height = height;
}

// how to use it
void Entity::setColor(float m_rColor, float m_gColor, float m_bColor){
	

	this->m_rColor = m_rColor;
	this->m_gColor = m_gColor;
	this->m_bColor = m_bColor;
}




