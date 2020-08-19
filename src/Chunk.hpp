#pragma once
#include "SFML/Graphics.hpp"
#include "Entity/Player.hpp"
#include "Tile/Tile.hpp"
#include "Tile/Stone.hpp"
#include "Tile/Floor.hpp"

class Chunk {
public:
	Chunk(sf::Vector2f aMidPoint);
	~Chunk();

	void Update(double& deltaTime, Player* aPlayer);
	void Draw(sf::RenderWindow* window);

	Tile::Tile* GetTileAt(sf::Vector2f aPos);
	int GetTileIndexAt(sf::Vector2f aPos);
	sf::Vector2i GetTileIndexVectorAt(sf::Vector2f aPos);
	void SetTileType(unsigned int aTileIndex, Tile::TileType type);

public:
	// Width and length of a chunk in Tiles
	const int chunkSizeInTiles = 16;
	const float tileSize = 32;
	const float chunkSizeInPixels = chunkSizeInTiles * tileSize;	

	// Maximum distance from midpoint of chunk to player for chunk to be Active
	const float activeDistance = 800;

	// Maximum distance from midpoint of chunk to player for chunk to be drawn
	const float renderDistance = 800;

	std::vector<Tile::Tile*>* tiles;

	sf::Vector2f midPoint;
	sf::FloatRect chunkBorder;

	bool isActive;
	bool isVisible;

private:
	void CheckForTileChangeFlags();
};