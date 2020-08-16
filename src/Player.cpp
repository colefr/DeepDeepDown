#include "Player.hpp"

Player::Player()
{
	animation = new Animation(imgPath, sf::Vector2u(2,1));
	animation->SetFrameRate(4);

	animation->GetSprite()->setOrigin(sf::Vector2f(16.0f, 16.0f));
	animation->GetSprite()->setPosition(sf::Vector2f(320, 240));
}

Player::~Player() {
	delete animation;
}

void Player::Update(double& deltaTime) {
	animation->Update(deltaTime);

	sf::Vector2f spriteOrigin = animation->GetSprite()->getOrigin();
	sf::Vector2f spriteScale = animation->GetSprite()->getScale();

	// This bit here just adds a little "bobbing" animation
	bobTime += (2 * (float)deltaTime);
	sf::Vector2f animationOffset = sf::Vector2f(0.0f, 0.05f * -sinf(bobTime));
	animation->GetSprite()->setOrigin(spriteOrigin + animationOffset);

	sf::Vector2f scaleOffset = sf::Vector2f(0.0025f * sinf(bobTime), 0.0f);
	animation->GetSprite()->setScale(spriteScale + scaleOffset);
}

void Player::Draw(sf::RenderWindow* window) {
	animation->Draw(window);
}

sf::Vector2f Player::GetPosition() {
	return animation->GetSprite()->getPosition();
}

void Player::Move(sf::Vector2f aDistance) {
	animation->GetSprite()->move(aDistance);
}
