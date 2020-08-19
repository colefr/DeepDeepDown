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

	void Update(double& deltaTime, sf::RenderWindow* window, sf::View* view);
	void Draw(sf::RenderWindow* window);

	Player* GetPlayer();

private:
	Player* player;
	//std::vector<Tile::Tile*>* tiles;
	std::vector<Chunk*>* chunks;
	Cursor* cursor;

	void MovePlayer(sf::Vector2f aDistance, double& deltaTime);

	Chunk* GetChunkAt(sf::Vector2f aPosition);
	Tile::Tile* GetTileAt(sf::Vector2f aPosition);
	int GetTileIndexAt(sf::Vector2f aPosition);

	/*Tile::Tile* CheckTiles(sf::Vector2f mousePos);
	bool CheckTileCollision(sf::FloatRect& aRect);*/
};