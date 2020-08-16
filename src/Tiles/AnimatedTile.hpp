#pragma once
#include "SFML/Graphics.hpp"
#include "Tile.hpp"

class AnimatedTile {
public:
	AnimatedTile(sf::Texture* texturePtr, sf::IntRect aTextureRect, sf::Vector2i aPosition, unsigned short aTileID);
	~AnimatedTile();

	void Update(double& deltaTime, sf::Window* window);
	void Draw(sf::RenderWindow* window);

private:
	Tile* tile;
};