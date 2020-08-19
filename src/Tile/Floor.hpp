#pragma once
#include "SFML/Graphics.hpp"
#include "StaticTile.hpp"

namespace Tile {
	class Floor : public StaticTile {
	public:
		Floor(sf::Vector2f& aPosition);

		void OnLeftClick(Cursor* cursor) override;
		void OnRightClick(Cursor* cursor) override;

	public:
		TileType type = TileType::Floor;
	};
}