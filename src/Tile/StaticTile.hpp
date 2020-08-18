#pragma once
#include "SFML/Graphics.hpp"
#include "Tile.hpp"

namespace Tile {
	class StaticTile : public Tile {
	public:
		StaticTile(sf::Vector2f aPosition, sf::Texture* aTexture);
		virtual ~StaticTile();

		void Update(double& deltaTime) override;
		void Draw(sf::RenderWindow* window) override;
	};
}