#include "StaticTile.hpp"

namespace Tile {
	StaticTile::StaticTile(sf::Vector2f aPosition, sf::Texture* aTexture)
	{
		position = aPosition;

		sprite = new sf::Sprite();
		sprite->setOrigin(sf::Vector2f(16, 16));
		sprite->setPosition(aPosition);
		sprite->setTexture(*aTexture);

		hitBox = sf::FloatRect(aPosition - sf::Vector2f(16, 16), sf::Vector2f(32, 32));
	}

	StaticTile::~StaticTile() {
		delete sprite;
	}

	void StaticTile::Update(double& deltaTime) {
	}

	void StaticTile::Draw(sf::RenderWindow* window) {
		if (isVisible) {
			window->draw(*sprite);
		}
	}
}