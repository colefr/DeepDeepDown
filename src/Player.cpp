#include "Player.hpp"

Player::Player() {
	playerTexture = new sf::Texture;
	playerTexture->loadFromFile(imgPath);

	playerSprite = new sf::Sprite();
	playerSprite->setTexture(*playerTexture);

	playerSprite->setOrigin(sf::Vector2f(16.0f, 16.0f));
	playerSprite->setPosition(sf::Vector2f(320.0f, 240.0f));
	playerSprite->setScale(sf::Vector2f(2.0f, 2.0f));
}

Player::~Player() {
	delete playerSprite;
	delete playerTexture;
}

void Player::Update(double& deltaTime) {

	// This bit here just adds a little "bobbing" animation
	bobTime += (2 * deltaTime);
	playerSprite->move(sf::Vector2f(0.0f, 0.5 * -sin(bobTime)));
}

void Player::Draw(sf::RenderWindow* window) {
	window->draw(*playerSprite);
}