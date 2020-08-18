#include "Player.hpp"

Player::Player() :
	bobTime(0.0f)
{
	const std::string textureImgPath = "assets/img/player.png";

	texture = new sf::Texture();
	texture->loadFromFile(textureImgPath);

	sprite = new sf::Sprite(*texture);
	sprite->setOrigin(sf::Vector2f(16, 16));
	sprite->setPosition(sf::Vector2f(0, 0));

	// Make the sprite's hitbox small than a tile, which makes going around corners
	// and fitting into 1-tile-wide spaces much easier
	hitBox = sf::FloatRect(sprite->getPosition() - sf::Vector2f(12, 12), sf::Vector2f(24, 24));
	animator = new Animator(sprite, 4);
}

Player::~Player() {
	delete animator;
	delete sprite;
	delete texture;
}

void Player::Update(double& deltaTime) {
	animator->Update(deltaTime);
	position = sprite->getPosition();

	sf::Vector2f spriteOrigin = sprite->getOrigin();
	sf::Vector2f spriteScale = sprite->getScale();

	// This bit here just adds a little "bobbing" animation
	bobTime += (2 * (float)deltaTime);
	sf::Vector2f animationOffset = sf::Vector2f(0.0f, 0.05f * -sinf(bobTime));
	sprite->setOrigin(spriteOrigin + animationOffset);

	sf::Vector2f scaleOffset = sf::Vector2f(0.0025f * sinf(bobTime), 0.0f);
	sprite->setScale(spriteScale + scaleOffset);
}

void Player::Move(sf::Vector2f aDistance) {
	sprite->move(aDistance);
	hitBox.left += aDistance.x;
	hitBox.top += aDistance.y;
}
