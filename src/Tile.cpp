#include "Tile.hpp"

Tile::Tile(const std::string& textureFile, sf::IntRect aTextureRect, sf::Vector2i aPosition, unsigned short aTileID) :
	texture(nullptr)
{
	tileID = aTileID;
	position = aPosition;

	texture = new sf::Texture();
	texture->loadFromFile(textureFile);

	sprite = new sf::Sprite();
	sprite->setTexture(*texture);
	sprite->setTextureRect(aTextureRect);
	sprite->setPosition((sf::Vector2f)aPosition);
}

Tile::~Tile() {
	delete texture;
	delete sprite;
}

void Tile::Update(double& deltaTime) {
}

void Tile::Draw(sf::RenderWindow* window) {
	window->draw(*sprite);
}