#include "stdafx.h"
#include "TowerEmplacement.h"

TowerEmplacement::TowerEmplacement(float xPosition, float yPosition){
	this->xPosition = xPosition;
	this->yPosition = yPosition;

	// square emplacement
	this->width = 21.0;
	this->height = 21.0;

	this->m_rColor = 0.8;
	this->m_gColor = 0.8;
	this->m_bColor = 0.8;
	this->m_alphaColor = 0.3;

	initForm(2.f);

	this->shape.setFillColor(sf::Color(0, 0, 0, 0));
	this->shape.setOutlineThickness(2.f); 
	this->shape.setOutlineColor(sf::Color(static_cast<uint8_t>(this->m_rColor * 255.0f), static_cast<uint8_t>(this->m_gColor * 255.0f), static_cast<uint8_t>(this->m_bColor * 255.0f), static_cast<uint8_t>(this->m_alphaColor * 255.0f)));

}

TowerEmplacement::~TowerEmplacement(){}

void TowerEmplacement::initForm(float edge){
	shape.setPointCount(8);

	shape.setPoint(0, sf::Vector2f(this->xPosition, this->yPosition + edge/2));
	shape.setPoint(1, sf::Vector2f(this->xPosition + edge/2, this->yPosition));

	shape.setPoint(2, sf::Vector2f(this->xPosition + this->width - edge / 2, this->yPosition));
	shape.setPoint(3, sf::Vector2f(this->xPosition + this->width, this->yPosition + edge/2));

	shape.setPoint(4, sf::Vector2f(this->xPosition + this->width, this->yPosition + this->height - edge/2));
	shape.setPoint(5, sf::Vector2f(this->xPosition + this->width - edge / 2, this->yPosition + this->height));

	shape.setPoint(6, sf::Vector2f(this->xPosition + edge / 2, this->yPosition + this->height));
	shape.setPoint(7, sf::Vector2f(this->xPosition, this->yPosition + this->height - edge/2));
}

void TowerEmplacement::draw(sf::RenderTarget& target){
	target.draw(shape);
}

void TowerEmplacement::update(){
	// click mouse event

}



