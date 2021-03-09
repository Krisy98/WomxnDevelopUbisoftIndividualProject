#include "stdafx.h"
#include <iostream>
#include "PlayContext.h"


PlayContext::PlayContext(){

	flowers->current = nullptr;
	flowers->next = nullptr;

	insects->current = nullptr;
	insects->next = nullptr;


	addFlower(200, 200, FlowerType::Anemone);
	addFlower(100, 200, FlowerType::Delphinium);

	this->emplacement = new TowerEmplacement(200, 200);
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

	delete emplacement;
}


void PlayContext::update(sf::RenderWindow& win){
	// movement
	// collision

	updateEntities(*flowers, win);

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

	this->emplacement->draw(target);
}


void PlayContext::renderEntities(sf::RenderTarget& target, Entities entities){
	Entities start = entities;

	if (start.current != nullptr) start.current->draw(target);

	while (start.next != nullptr) {
		start = *start.next;
		start.current->draw(target);
	}
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