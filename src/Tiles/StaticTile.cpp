#include "StaticTile.hpp"

StaticTile::StaticTile(sf::Vector2f aPosition, sf::Texture* aTexture)
{
	position = aPosition;

	sprite = new sf::Sprite();
	sprite->setPosition(aPosition);
	sprite->setTexture(*aTexture);

	tileRect = new sf::FloatRect(aPosition, sf::Vector2f(32, 32));
}

StaticTile::~StaticTile() {
	delete sprite;
	delete tileRect;
}

void StaticTile::Update(double& deltaTime) {
}

void StaticTile::Draw(sf::RenderWindow* window) {
	if (isVisible) {
		window->draw(*sprite);
	}
}
