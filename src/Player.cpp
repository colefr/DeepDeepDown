#include "Player.hpp"

Player::Player() :
	position(sf::Vector2i(320,240))
{
	animation = new Animation(imgPath, sf::Vector2u(2,1));
	animation->SetFrameRate(4);

	animation->GetSprite()->setOrigin(sf::Vector2f(16.0f, 16.0f));
	animation->GetSprite()->setPosition(sf::Vector2f(position));
}

Player::~Player() {
	delete animation;
}

void Player::Update(double& deltaTime) {
	animation->Update(deltaTime);

	// This bit here just adds a little "bobbing" animation
	bobTime += (2 * (float)deltaTime);
	animation->GetSprite()->move(sf::Vector2f(0.0f, 0.05f * -sinf(bobTime)));
}

void Player::Draw(sf::RenderWindow* window) {
	animation->Draw(window);
}

sf::Vector2i Player::GetPosition() {
	return sf::Vector2i(animation->GetSprite()->getPosition());
}

void Player::Move(sf::Vector2i aDistance) {
	animation->GetSprite()->move((sf::Vector2f)aDistance);
}
