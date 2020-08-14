#pragma once
#include "SFML/Graphics.hpp"
#include "GlobalConstants.hpp"
#include <string>
#include <iostream>

const std::string imgPath = "assets/img/player.png";

class Player {
public:
	Player();
	~Player();

	void Update(double& deltaTime);
	void Draw(sf::RenderWindow* window);

private:
	sf::Sprite* playerSprite;
	sf::Texture* playerTexture;

	float bobTime = 0;
};