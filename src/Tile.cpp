#include "Tile.hpp"

Tile::Tile(sf::Texture* texturePtr, sf::IntRect aTextureRect, sf::Vector2i aPosition, unsigned short aTileID) :
	isVisible(true)
{
	tileID = aTileID;
	position = aPosition;

	sprite = new sf::Sprite();
	sprite->setTexture(*texturePtr);
	sprite->setTextureRect(aTextureRect);
	sprite->setPosition((sf::Vector2f)aPosition);
	sprite->setOrigin(sf::Vector2f(16, 16));
}

Tile::~Tile() {
	delete sprite;
}

void Tile::Update(double& deltaTime) {
}

void Tile::Draw(sf::RenderWindow* window) {
	if (isVisible) {
		window->draw(*sprite);
	}
}

sf::Vector2i Tile::GetPosition() {
	return position;
}

Tile* Tile::GetTile() {
	return this;
}

void Tile::Show() {
	isVisible = true;
}

void Tile::Hide() {
	isVisible = false;
}
