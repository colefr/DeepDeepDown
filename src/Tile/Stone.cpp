#include "Stone.hpp"

namespace Tile {
	Stone::Stone(sf::Vector2f& aPosition) :
		StaticTile(aPosition, "assets/img/stone.png", TileType::Stone, true)
	{
	}

	void Stone::OnLeftClick(Cursor* cursor)	{
		dropItemFlag = true;
		itemTypeToDrop = Item::ItemType::Pebbles;

		changeTileTypeFlag = true;
		typeToChangeTo = TileType::Floor;
	}

	void Stone::OnRightClick(Cursor* cursor) {
	}
}