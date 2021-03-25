#include "stdafx.h"
#include <iostream>
#include "PlayContext.h"


PlayContext::PlayContext(/*int idLvl*/){
	// entities creation
	// lvl to download
	// wave to define

	

	initEntities(emplacements);
	initEntities(flowers);
	initEntities(insects);


	addFlower(200, 200, FlowerType::Anemone);
	addFlower(100, 200, FlowerType::Delphinium);

	addTowerEmplacement(100, 200);
	addTowerEmplacement(200, 200);
}

PlayContext::~PlayContext(){
	while (flowers->current != nullptr) {
		delete flowers->current;
		flowers = flowers->next;
	}

	while (insects->current != nullptr) {
		delete insects->current;
		insects = insects->next;
	}

	while (emplacements->current != nullptr) {
		delete emplacements->current;
		emplacements = emplacements->next;
	}
}


void PlayContext::update(sf::RenderWindow& win){
	// movement
	// collision

	updateEntities(*flowers, win);
	updateEntities(*emplacements, win);

}

void PlayContext::updateEntities(Entities entities, sf::RenderWindow& win) {
	Entities start = entities;

	if (start.current != nullptr) start.current->update(win);

	while (start.next != nullptr) {
		start = *start.next;
		start.current->update(win);
	}
}


void PlayContext::render(sf::RenderTarget& target){
	target.clear(sf::Color(0, 0, 0));

	renderEntities(target, *flowers);
	renderEntities(target, *emplacements);
}


void PlayContext::renderEntities(sf::RenderTarget& target, Entities entities){
	Entities start = entities;

	if (start.current != nullptr) start.current->draw(target);

	while (start.next != nullptr) {
		start = *start.next;
		start.current->draw(target);
	}
}

void PlayContext::initEntities(Entities *firstEntity){
	firstEntity->current = nullptr;
	firstEntity->next = nullptr;
}

void PlayContext::addFlower(float x, float y, FlowerType type) {
	Entities* start = flowers;
	Entities* temp = (Entities*) malloc(sizeof(struct Entities));

	temp->current = new Flower(x, y, type);
	temp->next = nullptr;
	
	while (start->next != nullptr) start = start->next;

	if (start->current == nullptr) start->current = temp->current;
	else start->next = temp;
}

void PlayContext::addTowerEmplacement(float xPosition, float yPosition){
	Entities* start = emplacements;
	Entities* temp = (Entities*) malloc(sizeof(struct Entities));

	temp->current = new TowerEmplacement(xPosition, yPosition);
	temp->next = nullptr;

	while (start->next != nullptr) start = start->next;

	if (start->current == nullptr) start->current = temp->current;
	else start->next = temp;
}
