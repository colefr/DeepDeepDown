#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include <iostream>
#include "../Player.hpp"

class Tile {
public:
	sf::Vector2f GetPosition();
	bool GetVisibility();

	void Show();
	void Hide();

	virtual void Draw(sf::RenderWindow* window);
	virtual void Update(double& deltaTime);

	Tile* GetTilePointer();

	sf::Sprite* sprite;
	sf::FloatRect* tileRect;
	sf::Vector2f position;
	bool isVisible = true;
};