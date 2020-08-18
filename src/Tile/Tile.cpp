#include "Tile.hpp"

sf::Vector2f Tile::GetPosition() {
	return position;
}

bool Tile::GetVisibility() {
	return isVisible;
}

void Tile::Draw(sf::RenderWindow* window) {
}

void Tile::Update(double& deltaTime) {
}

Tile* Tile::GetTilePointer() {
	return this;
}

void Tile::Show() {
	isVisible = true;
}

void Tile::Hide() {
	isVisible = false;
}