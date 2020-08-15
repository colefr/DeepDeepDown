#include "Player.hpp"

Player::Player() {
	animation = new Animation(imgPath, sf::Vector2u(2,1));
	animation->SetFrameRate(4);

	animation->GetSprite()->setOrigin(sf::Vector2f(16.0f, 16.0f));
	animation->GetSprite()->setPosition(sf::Vector2f(320.0f, 240.0f));
	animation->GetSprite()->setScale(sf::Vector2f(2.0f, 2.0f));
}

Player::~Player() {
	delete animation;
}

void Player::Update(double& deltaTime) {
	animation->Update(deltaTime);

	// This bit here just adds a little "bobbing" animation
	bobTime += (2 * (float)deltaTime);
	animation->GetSprite()->move(sf::Vector2f(0.0f, 0.5f * -sinf(bobTime)));
}

void Player::Draw(sf::RenderWindow* window) {
	animation->Draw(window);
}