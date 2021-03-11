#include "stdafx.h"
#include "TowerEmplacement.h"

TowerEmplacement::TowerEmplacement(float xPosition, float yPosition){
	setPosition(sf::Vector2f(xPosition, yPosition));


	setSize(sf::Vector2f(21.f, 21.f));

	this->m_rColor = 0.8;
	this->m_gColor = 0.8;
	this->m_bColor = 0.8;
	this->m_alphaColor = 0.3;

	setColor(0.8, 0.8, 0.8, 0.3);


	rectangle = new Rectangle(getXPosition(), getYPosition(), getWidth(), getHeight());
	rectangle->createRectangleFlatEdge(0.1f, 0.1f);
	rectangle->setColorAndThickness(sf::Color(0, 0, 0, 0), 2.f, sf::Color(static_cast<uint8_t>(this->m_rColor * 255.0f), static_cast<uint8_t>(this->m_gColor * 255.0f), static_cast<uint8_t>(this->m_bColor * 255.0f), static_cast<uint8_t>(this->m_alphaColor * 255.0f)));

}

TowerEmplacement::~TowerEmplacement(){}



void TowerEmplacement::draw(sf::RenderTarget& target){
	target.draw(rectangle->get());
}

void TowerEmplacement::update(sf::RenderWindow& win){
	// click mouse event

}



