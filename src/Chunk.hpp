#pragma once
#include "SFML/Graphics.hpp"
#include "Tile/Tile.hpp"

class Chunk {
public:
	Chunk();
	~Chunk();

	std::vector<Tile::Tile*> tiles;

	sf::Vector2f midPoint;
	sf::FloatRect chunkBorder;
};