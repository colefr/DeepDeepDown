#include "Stone.hpp"

namespace Tile {
	Stone::Stone(sf::Vector2f& aPosition) :
		StaticTile(aPosition, "assets/img/stone.png", true)
	{
	}

	void Stone::OnLeftClick(Cursor* cursor)	{
		changeTileTypeFlag = true;
		typeToChangeTo = TileType::Floor;
	}

	void Stone::OnRightClick(Cursor* cursor) {
	}
}