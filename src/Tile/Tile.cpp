#include "Tile.hpp"

namespace Tile {
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


	// Empty Tile ------------------------------

	Empty::Empty(sf::Vector2f& aPosition) {
		position = aPosition;
		hitBox = sf::FloatRect(aPosition, sf::Vector2f(32, 32));
		tileType = TileType::Empty;
	}

	Empty::~Empty() {
	}

	void Empty::Draw(sf::RenderWindow* window) {
	}

	void Empty::Update(double& deltaTime) {
	}
}