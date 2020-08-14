#pragma once
#include "SFML/Graphics.hpp"
#include "Tile.hpp"

class World {
public:
	World();
	~World();

	void Update(double& deltaTime);
	void Draw(sf::RenderWindow* window);

private:

};