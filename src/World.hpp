#pragma once
#include "SFML/Graphics.hpp"
#include "Tile.hpp"
#include "Player.hpp"
#include "Tile.hpp"
#include "Cursor.hpp"
#include <vector>

class World {
public:
	World();
	~World();

	void Update(double& deltaTime, sf::Window* window);
	void Draw(sf::RenderWindow* window);

private:
	Player* player;
	std::vector<Tile*>* tiles;
	Cursor* cursor;
	Tile* CheckTiles(sf::Vector2i mousePos);
};