#include "stdafx.h"
#include "Flower.h"
#include "Engine/Physics/Physics.h"

#include <iostream>

Flower::Flower(sf::Vector2f position, float size, FlowerType type, Entities* enemies){
	setPosition(position);

	this->plantRadius = size/2;
	this->visibleRange = false;

	setSize(sf::Vector2f(size, size));

	this->enemies = enemies;
	this->seeds = new Entities();
	this->seeds->current = nullptr;
	this->seeds->next = nullptr;

	createBoundingBox();

	initFromType(type);

	circle = new Circle(getXPosition(), getYPosition(), plantRadius);
	circle->setColorAndThickness(sf::Color(0, 0, 0, 0), 1.f, getColor());

	circleRange = new Circle(getXPosition() + plantRadius - rangeRadius, getYPosition() + plantRadius - rangeRadius, rangeRadius);
	circleRange->setColorAndThickness(getRangeColor(), 1.f, getRangeOutLineColor());
}

Flower::~Flower(){
	delete this->circle;
	delete this->circleRange;

	delete this->enemies;
}

void Flower::update(sf::RenderWindow& window){
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);

	// update position to the shapes
	circle->setPosition(getPosition()); 
	circleRange->setPosition(getXPosition() + plantRadius - rangeRadius, getYPosition() + plantRadius - rangeRadius);

	mouseOn(mousePos); 
	tryShoot();

	updateSeeds(window);
}

void Flower::updateSeeds(sf::RenderWindow& window) {
	Entities* temp = seeds;

	while (temp->current != nullptr) {
		Seed* seed = dynamic_cast<Seed*>(temp->current);

		seed->update(window);

		if (seed->isAchieved()) {
			seed->getTarget()->reduceLife(getDamage());
			temp->current = nullptr;
		}

		if (temp->next != nullptr) temp = temp->next;
		else break;
	}
}

void Flower::applyDifficulty(float difficultyLevel){
	difficultyLevel /= 100; //percentage
	this->damage *= difficultyLevel;
}

void Flower::draw(sf::RenderTarget& target) {
	Entities* temp = seeds;
	target.draw(circle->get());

	if (this->visibleRange) target.draw(circleRange->get());

	while (temp->current != nullptr) {
		temp->current->draw(target);

		if (temp->next != nullptr) temp = temp->next;
		else break;
	}
}

void Flower::setVisibleRange(bool value){ this->visibleRange = value; }

bool Flower::getVisibleRange(){ return this->visibleRange; }

sf::Color Flower::getRangeColor(){ return sf::Color(static_cast<uint8_t>(0.0f), static_cast<uint8_t>(255.0f), static_cast<uint8_t>(255.0f), static_cast<uint8_t>(0.1 * 255.0f)); }

sf::Color Flower::getRangeOutLineColor(){ return sf::Color(static_cast<uint8_t>(255.0f), static_cast<uint8_t>(255.0f), static_cast<uint8_t>(255.0f), static_cast<uint8_t>(255.0f)); }

void Flower::setRange(float value){ this->rangeRadius = value; }

void Flower::setDamage(float damage){ this->damage = damage; }

float Flower::getDamage(){ return this->damage; }

void Flower::mouseOn(sf::Vector2i mouse){
	if (mouse.x >= getXPosition() && mouse.x <= getXPosition() + getWidth() &&
		mouse.y >= getYPosition() && mouse.y <= getYPosition() + getHeight()) {
		setVisibleRange(true);
	}
	else {
		setVisibleRange(false);
	}
}

void Flower::tryShoot(){
	Entities* targets = enemies;

	if (enemies == nullptr || enemies->current == nullptr) { return; }

	while (targets->current != nullptr) {
		float distance = Physics::distance(getCenter(), targets->current->getPosition());

		if (distance < rangeRadius && isRecharged()) {
			Entities* toAdd = new Entities();
			Insect* insect = dynamic_cast<Insect*>(targets->current);

			toAdd->current = new Seed(getCenter(), *insect);
			toAdd->next = nullptr;

			if (seeds->current == nullptr) seeds = toAdd;
			else {
				toAdd->next = seeds;
				seeds = toAdd;
			}
			
			clock.restart();
			return;
		}
		if (targets->next != nullptr) targets = targets->next;
		else break;
	}
}

bool Flower::isRecharged(){ return (clock.getElapsedTime().asSeconds() >= 2.f); }

void Flower::initFromType(FlowerType type) {
	switch (type) {
		default:
		case FlowerType::Anemone:
			setColor(1, 1, 1);
			setRange(70);
			setDamage(100);
			break;

		case FlowerType::Hyacinth:
			setColor(0.7, 0.7, 0.7);
			setRange(80);
			setDamage(200);
			break;

		case FlowerType::Pansy:
			setColor(0.3, 0.7, 1);
			setRange(70);
			setDamage(300);
			break;

		case FlowerType::Rose:
			setColor(1, 0.5, 1);
			setRange(70);
			setDamage(400);
			break;

		case FlowerType::Delphinium:
			setColor(1, 0.2, 0.2);
			setRange(100);
			setDamage(500);
			break;
	}
}
