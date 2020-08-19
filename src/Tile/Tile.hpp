#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include <iostream>
#include "../Entity/Player.hpp"

namespace Tile {
	enum class TileType {
		Empty = 0,
		Floor,
		Stone
	};

	class Tile {
	public:
		Tile(sf::Vector2f& aPosition);

		virtual void Draw(sf::RenderWindow* window);
		virtual void Update(double& deltaTime);

		sf::Sprite* sprite;
		sf::Texture* texture;

		sf::FloatRect hitBox;
		sf::Vector2f position;

		bool isVisible = true;
		TileType type = TileType::Empty;
	};

	class Empty : public Tile {
	public:
		Empty(sf::Vector2f& aPosition);
		~Empty();

		TileType type = TileType::Empty;
	};
}