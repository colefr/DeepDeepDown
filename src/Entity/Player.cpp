#include "Player.hpp"

namespace Entity {
	Player::Player() :
		Entity(sf::Vector2f(4.0f, 4.0f), sf::Vector2f(24.0f, 24.0f), "assets/img/player.png"),
		animator(new Animator(sprite, 4)),
		bobTime(0.0f),
		view(new sf::View(sf::Vector2f(16.0f, 16.0f), sf::Vector2f(640.0f, 480.0f)))
	{
		sprite->setOrigin(sf::Vector2f(4.0f, 4.0f));
		//view->zoom(0.75f);
	}

	Player::~Player() {
		delete animator;
		delete view;
	}

	void Player::Update(double& deltaTime) {
		animator->Update(deltaTime);
		position = sprite->getPosition();
		hitBox.left = position.x;
		hitBox.top = position.y;

		sf::Vector2f spriteOrigin = sprite->getOrigin();

		// This bit here just adds a little "bobbing" animation
		bobTime += (2 * (float)deltaTime);
		sf::Vector2f animationOffset = sf::Vector2f(0.0f, 0.05f * -sinf(bobTime));
		sprite->setOrigin(spriteOrigin + animationOffset);
	}

	void Player::Draw(sf::RenderWindow* window) {
		window->setView(*view);
		window->draw(*sprite);
	}

	void Player::Move(sf::Vector2f aDistance, double& deltaTime) {
		sf::Vector2f distance = sf::Vector2f(aDistance.x * (float)deltaTime, aDistance.y * (float)deltaTime);
		position += distance;
		sprite->setPosition(position);

		hitBox.left = position.x;
		hitBox.top = position.y;

		view->setCenter(position + sf::Vector2f(hitBox.width * 0.5f, hitBox.height * 0.5f));
	}
}