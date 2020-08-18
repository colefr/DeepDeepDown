#pragma once
#include "SFML/Graphics.hpp"
#include "../Animator.hpp"
#include "Entity.hpp"
#include <string>
#include <iostream>

class Player : public Entity {
public:
	Player();
	~Player();

	void Update(double& deltaTime);
	void Move(sf::Vector2f aDistance);

private:
	Animator* animator;
	float bobTime;
};