#include "stdafx.h"
#include "Context.h"

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

	if (start.current != nullptr) start.current->draw(target);

	while (start.next != nullptr) {
		start = *start.next;
		start.current->draw(target);
	}
}

void Context::updateEntities(Entities entities, sf::RenderWindow& win) {
	Entities start = entities;

	if (start.current != nullptr) start.current->update(win);

	while (start.next != nullptr) {
		start = *start.next;
		start.current->update(win);
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