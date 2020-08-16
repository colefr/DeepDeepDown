#include "Tile.hpp"

Tile::Tile(sf::Vector2f aPosition, unsigned short aTileID) :
	sprite(nullptr),
	isVisible(false),
	position(aPosition),
	tileID(aTileID)
{
}

Tile::Tile(sf::Texture* texturePtr, sf::IntRect aTextureRect, sf::Vector2f aPosition, unsigned short aTileID) :
	sprite(nullptr),
	isVisible(true),
	position(aPosition),
	tileID(aTileID)
{
	sprite = new sf::Sprite();
	sprite->setTexture(*texturePtr);
	sprite->setTextureRect(aTextureRect);

	sprite->setPosition((sf::Vector2f)position);
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

sf::Vector2f Tile::GetPosition() {
	return position;
}

Tile* Tile::GetTile() {
	return this;
}

sf::Sprite* Tile::GetSprite() {
	return sprite;
}

bool Tile::GetVisibility() {
	return isVisible;
}

void Tile::Show() {
	isVisible = true;
}

void Tile::Hide() {
	isVisible = false;
}
