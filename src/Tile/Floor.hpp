#pragma once
#include "SFML/Graphics.hpp"
#include "StaticTile.hpp"

namespace Tile {
	class Floor : public StaticTile {
	public:
		Floor(sf::Vector2f& aPosition);

		TileType type = TileType::Floor;
	private:
	};
}