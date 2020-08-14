#pragma once
#include "SFML/Graphics.hpp"

class Tile {
public:
	Tile();
	~Tile();

	void Update(double& deltaTime);
	void Draw(sf::RenderWindow* window);

private:

};