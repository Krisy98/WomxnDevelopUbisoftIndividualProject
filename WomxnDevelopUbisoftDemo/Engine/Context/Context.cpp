#include "stdafx.h"
#include "Context.h"
#include <iostream>

void Context::initEntities(Entities* firstEntity) {
	firstEntity->current = nullptr;
	firstEntity->next = nullptr;
}

void Context::deleteEntities(Entities* entities) {
	while (entities->current != nullptr) {
		delete entities->current;
		entities = entities->next;
	}
	delete entities;
}

void Context::renderEntities(sf::RenderTarget& target, Entities entities) {
	Entities start = entities;

	if (start.current != nullptr) start.current->drawEntity(target);

	while (start.next != nullptr) {
		start = *start.next;
		start.current->drawEntity(target);
	}
}

void Context::updateEntities(Entities entities, sf::RenderWindow& win) {
	Entities start = entities;

	if (start.current != nullptr) start.current->updateEntity(win);

	while (start.next != nullptr) {
		start = *start.next;
		start.current->updateEntity(win);
	}
}

void Context::setEntitiesPosition(Entities entities, sf::Vector2f speed) {
	Entities start = entities;

	if (start.current != nullptr) {
		sf::Vector2f oldPos = start.current->getPosition();
		sf::Vector2f newPos = sf::Vector2f(oldPos.x + speed.x, oldPos.y + speed.y);

		start.current->setPosition(newPos);
	}

	while (start.next != nullptr) {
		start = *start.next;
		sf::Vector2f oldPos = start.current->getPosition();
		sf::Vector2f newPos = sf::Vector2f(oldPos.x + speed.x, oldPos.y + speed.y);

		start.current->setPosition(newPos);
	}
}

void Context::addEntity(Entities* entities, Entity* entity) {
	Entities* start = entities;
	Entities* temp = new Entities();

	temp->current = entity;
	temp->next = nullptr;

	while (start->next != nullptr) start = start->next;

	if (start->current == nullptr) start->current = temp->current;
	else start->next = temp;
}