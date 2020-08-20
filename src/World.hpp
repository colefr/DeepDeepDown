#pragma once
#include "SFML/Graphics.hpp"

#include "Tile/TileList.hpp"
#include "Entity/EntityList.hpp"
#include "Item/ItemList.hpp"

#include "Item/ItemSlot.hpp"

#include "Cursor.hpp"
#include "Chunk.hpp"
#include <vector>

class World {
public:
	World();
	~World();

	void Update(double& deltaTime, sf::RenderWindow* window);
	void Draw(sf::RenderWindow* window);

	Entity::Player* player;
	std::vector<Chunk*>* chunks;
	Cursor* cursor;
	std::vector<Item::Item*>* groundItems;

	Item::ItemSlot* testSlot;

private:
	Chunk* GetChunkAt(sf::Vector2f aPosition);
	Tile::Tile* GetTileAt(sf::Vector2f aPosition);
	int GetTileIndexAt(sf::Vector2f aPosition);

	void CreateNewSurroundingChunks();

	bool CheckTileCollision(Entity::Entity* entity);
	void CheckGroundItemCollision(Entity::Entity* entity);

	void ProcessTileDrops(Tile::Tile* aTile);
	void TurnSurroundingEmptyTilesToStone(sf::Vector2f aPosition);
};