#include "AnimatedTile.hpp"

AnimatedTile::AnimatedTile(sf::Texture* texturePtr, sf::IntRect aTextureRect, sf::Vector2i aPosition, unsigned short aTileID) {
	//tile = new Tile(texturePtr, aTextureRect, aPosition, aTileID);
}

AnimatedTile::~AnimatedTile() {
	delete tile;
}

void AnimatedTile::Update(double& deltaTime, sf::Window* window) {
}

void AnimatedTile::Draw(sf::RenderWindow* window) {
	tile->Draw(window);
}
