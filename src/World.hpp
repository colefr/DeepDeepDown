#pragma once
#include "SFML/Graphics.hpp"
#include "Tile.hpp"
#include "Player.hpp"
#include "Tile.hpp"
#include <vector>

class World {
public:
	World();
	~World();

	void Update(double& deltaTime);
	void Draw(sf::RenderWindow* window);

private:
	Player* player;
	std::vector<Tile*>* tiles;
};