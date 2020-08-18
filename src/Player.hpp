#pragma once
#include "SFML/Graphics.hpp"
#include "Animator.hpp"
#include <string>
#include <iostream>

class Player {
public:
	Player();
	~Player();

	void Update(double& deltaTime);
	void Draw(sf::RenderWindow* window);

	sf::Vector2f GetPosition();
	sf::FloatRect* GetSpriteRect();

	void Move(sf::Vector2f aDistance);

private:
	sf::Sprite* sprite;
	sf::Texture* spriteTexture;
	Animator* animator;
	sf::FloatRect* spriteRect;
};