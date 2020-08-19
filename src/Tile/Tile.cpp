#include "Tile.hpp"

namespace Tile {
	Tile::Tile(sf::Vector2f& aPosition) :
		sprite(nullptr),
		texture(nullptr),
		position(aPosition),
		hitBox(sf::FloatRect(aPosition, sf::Vector2f(32.0f, 32.0f)))
	{}

	void Tile::Draw(sf::RenderWindow* window) {}
	void Tile::Update(double& deltaTime) {}


	// Empty Tile ------------------------------
	Empty::Empty(sf::Vector2f& aPosition) :
		Tile(aPosition)
	{}

	Empty::~Empty() {}
}