#include "StaticTile.hpp"

namespace Tile {
	StaticTile::StaticTile() {
	}

	StaticTile::StaticTile(sf::Vector2f aPosition, const std::string& aTextureFileName)
	{
		position = aPosition;

		texture = new sf::Texture();
		texture->loadFromFile(aTextureFileName);

		sprite = new sf::Sprite();
		sprite->setOrigin(sf::Vector2f(16, 16));
		sprite->setPosition(aPosition);
		sprite->setTexture(*texture);

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