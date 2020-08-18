#include "Player.hpp"

Player::Player() {
	const std::string textureImgPath = "assets/img/player.png";

	spriteTexture = new sf::Texture();
	spriteTexture->loadFromFile(textureImgPath);

	sprite = new sf::Sprite(*spriteTexture);
	sprite->setPosition(sf::Vector2f(0, 0));

	// Make the sprite's hitbox small than a tile, which makes going around corners
	// and fitting into 1-tile-wide spaces much easier
	spriteRect = new sf::FloatRect(sprite->getPosition() + sf::Vector2f(4, 4), sf::Vector2f(24, 24));
	animator = new Animator(sprite, 4);
}

Player::~Player() {
	delete animator;
	delete sprite;
	delete spriteTexture;
}

void Player::Update(double& deltaTime) {
	animator->Update(deltaTime);
}

void Player::Draw(sf::RenderWindow* window) {
	window->draw(*sprite);
}

sf::Vector2f Player::GetPosition() {
	return sprite->getPosition();
}

sf::FloatRect* Player::GetSpriteRect() {
	return spriteRect;
}

void Player::Move(sf::Vector2f aDistance) {
	sprite->move(aDistance);
	spriteRect->left += aDistance.x;
	spriteRect->top += aDistance.y;
}
