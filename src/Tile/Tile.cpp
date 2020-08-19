#include "Tile.hpp"

namespace Tile {
	Tile::Tile(sf::Vector2f& aPosition, bool aCollidesWithEntities) :
		sprite(nullptr),
		texture(nullptr),
		position(aPosition),
		collidesWithEntities(aCollidesWithEntities),
		hitBox(sf::FloatRect(aPosition, sf::Vector2f(32.0f, 32.0f)))
	{}

	void Tile::Draw(sf::RenderWindow* window) {}
	void Tile::Update(double& deltaTime) {}

	void Tile::OnLeftClick(Cursor* cursor) {}
	void Tile::OnRightClick(Cursor* cursor)	{}
	void Tile::OnWorldEvent() {}


	// Empty Tile ------------------------------
	Empty::Empty(sf::Vector2f& aPosition) :
		Tile(aPosition)
	{}

	Empty::~Empty() {}

	void Empty::OnWorldEvent() {
		changeTileTypeFlag = true;
		typeToChangeTo = TileType::Stone;
	}
}