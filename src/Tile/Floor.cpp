#include "Floor.hpp"

namespace Tile {
	Floor::Floor(sf::Vector2f& aPosition) :
		StaticTile(aPosition, "assets/img/stone_floor.png", TileType::Floor)
	{}

	void Floor::OnLeftClick(Cursor* cursor) {
	}

	void Floor::OnRightClick(Cursor* cursor) {
		changeTileTypeFlag = true;
		typeToChangeTo = TileType::Stone;
	}
}
