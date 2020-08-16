#pragma once
#include "SFML/Graphics.hpp"
#include "Tiles/Tile.hpp"
#include "Player.hpp"
#include "Cursor.hpp"
#include <vector>

class World {
public:
	World();
	~World();

	void Update(double& deltaTime, sf::Window* window);
	void Draw(sf::RenderWindow* window);

	void MovePlayer(sf::Vector2i aDistance, double& deltaTime);

private:
	Player* player;
	std::vector<Tile*>* tiles;
	Cursor* cursor;
	Tile* CheckTiles(sf::Vector2i mousePos);

	sf::Texture* tileTexture;
	sf::IntRect stoneTileRect = sf::IntRect(0, 0, 32, 32);
};