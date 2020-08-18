#include "Entity.hpp"

void Entity::Draw(sf::RenderWindow* window) {
	window->draw(*sprite);
}
