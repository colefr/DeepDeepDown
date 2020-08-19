#include "StaticTile.hpp"

namespace Tile {
	StaticTile::StaticTile(sf::Vector2f aPosition, const std::string& aTextureFileName, bool aCollidesWithEntities) :
		Tile(aPosition, aCollidesWithEntities)
	{
		texture = new sf::Texture();
		texture->loadFromFile(aTextureFileName);

		sprite = new sf::Sprite();
		sprite->setPosition(aPosition);
		sprite->setTexture(*texture);
	}

	StaticTile::~StaticTile() {
		delete sprite;
		delete texture;
	}

	void StaticTile::Update(double& deltaTime) {
	}

	void StaticTile::Draw(sf::RenderWindow* window) {
		if (isVisible) {
			window->draw(*sprite);
		}
	}
}