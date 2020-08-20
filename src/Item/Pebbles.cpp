#include "Pebbles.hpp"

namespace Item {
	Pebbles::Pebbles(sf::Vector2f aPosition) :
		Item(aPosition, ItemType::Pebbles, "assets/img/pebbles.png") {
	}	
}