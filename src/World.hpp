#pragma once
#include "SFML/Graphics.hpp"
#include "Tile/StaticTile.hpp"
#include "Tile/AnimatedTile.hpp"
#include "Entity/Player.hpp"
#include "Cursor.hpp"
#include "Chunk.hpp"
#include <vector>

class World {
public:
	World();
	~World();

	void Update(double& deltaTime, sf::RenderWindow* window);
	void Draw(sf::RenderWindow* window);

	Player* player;
	std::vector<Chunk*>* chunks;
	Cursor* cursor;

private:
	Chunk* GetChunkAt(sf::Vector2f aPosition);
	Tile::Tile* GetTileAt(sf::Vector2f aPosition);
	int GetTileIndexAt(sf::Vector2f aPosition);

	bool CheckTileCollision(Entity* entity);

	void TurnSurroundingEmptyTilesToStone(sf::Vector2f aPosition);
};