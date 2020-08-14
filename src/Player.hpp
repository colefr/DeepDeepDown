#pragma once
#include "SFML/Graphics.hpp"

class Player {
public:
	Player();
	~Player();

	void Update(double& deltaTime);
	void Draw(sf::RenderWindow* window);

private:
};