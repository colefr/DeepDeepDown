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
	sf::Vector2f animationOffset;
	sf::Vector2f actualPosition;
	sf::Vector2f nonAnimatedPosition;

	const std::string imgPath = "assets/img/player.png";
};