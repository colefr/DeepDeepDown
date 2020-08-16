#include "Player.hpp"

Player::Player() :
	nonAnimatedPosition(sf::Vector2i(320,240)),
	animationOffset(sf::Vector2f(0.0f, 0.0f))
{
	animation = new Animation(imgPath, sf::Vector2u(2,1));
	animation->SetFrameRate(4);

	animation->GetSprite()->setOrigin(sf::Vector2f(16.0f, 16.0f));
	animation->GetSprite()->setPosition(sf::Vector2f(nonAnimatedPosition));
}

Player::~Player() {
	delete animation;
}

void Player::Update(double& deltaTime) {
	animation->Update(deltaTime);

	sf::Vector2f spritePosition = animation->GetSprite()->getPosition();

	// This bit here just adds a little "bobbing" animation
	bobTime += (2 * (float)deltaTime);
	animationOffset = sf::Vector2f(0.0f, 0.05f * -sinf(bobTime));
	animation->GetSprite()->move(animationOffset);

	nonAnimatedPosition = spritePosition - animationOffset;
}

void Player::Draw(sf::RenderWindow* window) {
	animation->Draw(window);
}

sf::Vector2f Player::GetPosition() {
	return nonAnimatedPosition;
}

void Player::Move(sf::Vector2f aDistance) {
	animation->GetSprite()->move(aDistance);
}
