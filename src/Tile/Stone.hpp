#pragma once
#include "SFML/Graphics.hpp"
#include "StaticTile.hpp"
#include <string>

namespace Tile {
	class Stone : public StaticTile {
	public:
		Stone(sf::Vector2f& aPosition);

		void OnLeftClick(Cursor* cursor) override;
		void OnRightClick(Cursor* cursor) override;

	public:
		TileType type = TileType::Stone;
	};
}