#include "stdafx.h"
#include "Color.h"

Color::Color(){
	this->color = new sf::Color();
}

Color::~Color(){
	delete this->color;
}

sf::Color Color::getColor(float r, float g, float b){
	return sf::Color(
		static_cast<uint8_t>(r * 255.0f), 
		static_cast<uint8_t>(g * 255.0f), 
		static_cast<uint8_t>(b * 255.0f), 
		255.0f
	);
}

sf::Color Color::getColor(float r, float g, float b, float alpha){
	return sf::Color(
		static_cast<uint8_t>(r * 255.0f), 
		static_cast<uint8_t>(g * 255.0f), 
		static_cast<uint8_t>(b * 255.0f), 
		static_cast<uint8_t>(alpha * 255.0f)
	);
}

sf::Color Color::getColor(){
	return *this->color;
}
