#include "Stone.hpp"

namespace Tile {
	Stone::Stone(sf::Vector2f& aPosition) :
		StaticTile(aPosition, "assets/img/stone.png")
	{
	}
}