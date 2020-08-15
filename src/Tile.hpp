#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include <iostream>

class Tile {
public:
	Tile(const std::string& textureFile, sf::IntRect aTextureRect, sf::Vector2i aPosition, unsigned short aTileID);
	~Tile();

	void Update(double& deltaTime);
	void Draw(sf::RenderWindow* window);

	sf::Vector2i GetPosition();
	Tile* GetTile();

private:
	unsigned short tileID;
	sf::Vector2i position;
	sf::Texture* texture;
	sf::Sprite* sprite;
};