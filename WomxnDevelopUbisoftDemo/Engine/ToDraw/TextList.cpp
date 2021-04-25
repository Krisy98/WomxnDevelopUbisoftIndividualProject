#include "stdafx.h"
#include "TextList.h"

#include <iostream>

TextList::TextList(){
	texts->id = -1;
	texts->current = nullptr;
	texts->next = nullptr;
}

TextList::~TextList(){
	delete texts->current;
	delete texts->next;

	delete texts;
}

/*
sf::Text TextList::getText(int id){
	Texts* temp = texts;
	
	while (temp->current != nullptr) {
		if (temp->id == id) return *temp->current;
		if (temp->next != nullptr) temp = temp->next;
		else break;
	}

	sf::Text* text;

	text->setString("");

	return *text;
}
*/


const char* TextList::getCChar(float x, float y){
	Texts* temp = texts;

	while (temp->current != nullptr) {

		//std::cout << "x : " << temp->current->getPosition().x << " width : " << std::endl;

		if (temp->next != nullptr) temp = temp->next;
		else break;
	}



	return nullptr;
}

Texts* TextList::getTexts(){ return texts; }

void TextList::setText(const char* text, int id){
	Texts* temp = texts;

	while (temp->current != nullptr) {

		if (texts->id == id) {
			texts->current->setString(text);
		}

		if (texts->next != nullptr) texts = texts->next;
		else break;
	}
}

void TextList::addText(sf::Text* text){
	Texts* temp = texts;
	Texts* atEnd = new Texts();

	atEnd->current = text;
	atEnd->next = nullptr;

	while (temp->next != nullptr) { temp = temp->next; }
	
	if (temp->current == nullptr) {
		temp->current = atEnd->current;
		//std::cout << temp->current->getString().toAnsiString() << std::endl;
		return;
	}
	else { temp->next = atEnd; }
}

void TextList::draw(sf::RenderTarget& target){
	Texts* temp = texts;

	if (temp->current != nullptr) target.draw(*temp->current);

	//std::cout << (temp->current == nullptr) << std::endl;

	while (temp->next != nullptr) {
		temp = temp->next;
		target.draw(*temp->current);
	}
}
