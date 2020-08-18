#pragma once
#include "SFML/Graphics.hpp"

class Entity {
public:
	sf::Sprite* sprite;
	sf::Texture* texture;

	sf::FloatRect hitBox;
	sf::Vector2f position;

	bool isVisible;
};