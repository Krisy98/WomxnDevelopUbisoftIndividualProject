#include "stdafx.h"
#include "Physics.h"

float Physics::distance(sf::Vector2f A, sf::Vector2f B){
	return std::sqrt( std::pow(A.x - B.x, 2) + std::pow(A.y - B.y, 2) ) ;
}
