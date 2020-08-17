#include "Player.hpp"

Player::Player() {
	spriteTexture = new sf::Texture();
	spriteTexture->loadFromFile(textureImgPath);

	sprite = new sf::Sprite(*spriteTexture);
	sprite->setOrigin(sf::Vector2f(16, 16));

	animator = new Animator(sprite, 2);
}

Player::~Player() {
	delete animator;
	delete sprite;
	delete spriteTexture;
}

void Player::Update(double& deltaTime) {
	animator->Update(deltaTime);

	sf::Vector2f spriteOrigin = sprite->getOrigin();
	sf::Vector2f spriteScale = sprite->getScale();

	// This bit here just adds a little "bobbing" animation
	bobTime += (2 * (float)deltaTime);
	sf::Vector2f animationOffset = sf::Vector2f(0.0f, 0.05f * -sinf(bobTime));
	sprite->setOrigin(spriteOrigin + animationOffset);

	sf::Vector2f scaleOffset = sf::Vector2f(0.0025f * sinf(bobTime), 0.0f);
	sprite->setScale(spriteScale + scaleOffset);
}

void Player::Draw(sf::RenderWindow* window) {
	window->draw(*sprite);
}

sf::Vector2f Player::GetPosition() {
	return sprite->getPosition();
}

void Player::Move(sf::Vector2f aDistance) {
	sprite->move(aDistance);
}
