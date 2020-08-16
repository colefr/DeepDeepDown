#pragma once
#include "SFML/Graphics.hpp"
#include "Animation.hpp"
#include <string>
#include <iostream>

class Player {
public:
	Player();
	~Player();

	void Update(double& deltaTime);
	void Draw(sf::RenderWindow* window);

	sf::Vector2f GetPosition();

	void Move(sf::Vector2f aDistance);

private:
	Animation* animation;
	float bobTime = 0;

	const std::string imgPath = "assets/img/player.png";
};