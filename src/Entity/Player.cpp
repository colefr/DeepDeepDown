#include "Player.hpp"

Player::Player() :
	Entity(sf::Vector2f(2.0f, 2.0f), sf::Vector2f(28.0f, 28.0f), "assets/img/player.png"),
	animator(new Animator(sprite, 4)),
	bobTime(0.0f)
{
	sprite->setOrigin(sf::Vector2f(2.0f, 2.0f));
}

Player::~Player() {
	delete animator;
}

void Player::Update(double& deltaTime) {
	animator->Update(deltaTime);
	position = sprite->getPosition();

	sf::Vector2f spriteOrigin = sprite->getOrigin();

	// This bit here just adds a little "bobbing" animation
	bobTime += (2 * (float)deltaTime);
	sf::Vector2f animationOffset = sf::Vector2f(0.0f, 0.05f * -sinf(bobTime));
	sprite->setOrigin(spriteOrigin + animationOffset);
}

void Player::Move(sf::Vector2f aDistance) {
	sprite->move(aDistance);
	hitBox.left += aDistance.x;
	hitBox.top += aDistance.y;
}
