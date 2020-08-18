#pragma once
#include "SFML/Graphics.hpp"
#include "Tile/Tile.hpp"

class Chunk {
public:
	Chunk(sf::Vector2f aMidPoint);
	~Chunk();

	void Update(double& deltaTime, Player* aPlayer);
	void Draw(sf::RenderWindow* window);

	Tile::Tile* GetTileAt(sf::Vector2f aPos);

public:
	// Width and length of a chunk in Tiles
	const int chunkSizeInTiles = 16;
	const float tileSize = 32;

	// Maximum distance from midpoint of chunk to player for chunk to be Active
	const float activeDistance = 400;

	// Maximum distance from midpoint of chunk to player for chunk to be drawn
	const float renderDistance = 400;

	std::vector<Tile::Tile*>* tiles;

	sf::Vector2f midPoint;
	sf::FloatRect chunkBorder;

	bool isActive;
	bool isVisible;
};