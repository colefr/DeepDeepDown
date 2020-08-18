#pragma once
#include "SFML/Graphics.hpp"
#include "Tile.hpp"

namespace Tile {
	class StaticTile : public Tile {
	public:
		StaticTile();
		StaticTile(sf::Vector2f aPosition, const std::string& aTextureFileName);
		virtual ~StaticTile();

		void Update(double& deltaTime) override;
		void Draw(sf::RenderWindow* window) override;
	};
}