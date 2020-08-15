#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include <iostream>

class Tile {
public:
	Tile(sf::Texture* texturePtr, sf::IntRect aTextureRect, sf::Vector2i aPosition, unsigned short aTileID);
	~Tile();

	void Update(double& deltaTime);
	void Draw(sf::RenderWindow* window);

	sf::Vector2i GetPosition();
	Tile* GetTile();

	void Show();
	void Hide();

private:
	unsigned short tileID;
	sf::Vector2i position;
	sf::Sprite* sprite;
	bool isVisible;
};