#include "stdafx.h"
#include "FlowerMenu.h"

#include <iostream>

FlowerMenu::FlowerMenu(){

	if (this->font.loadFromFile("Resources/Fonts/champagne_and_limousines.ttf")) {

		std::cout << "success ! ";

	}




}

FlowerMenu::~FlowerMenu(){
}
