#pragma once
#include "SFML/Graphics.hpp"
#include "../Cursor.hpp"
#include <string>
#include <iostream>

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

		virtual void OnLeftClick(Cursor* cursor);
		virtual void OnRightClick(Cursor* cursor);
		virtual void OnWorldEvent();

	public:
		sf::Sprite* sprite;
		sf::Texture* texture;

		sf::FloatRect hitBox;
		sf::Vector2f position;

		bool isVisible = true;
		TileType type = TileType::Empty;

		bool changeTileTypeFlag = false;
		TileType typeToChangeTo = TileType::Empty;
	};

	class Empty : public Tile {
	public:
		Empty(sf::Vector2f& aPosition);
		~Empty();

		void OnWorldEvent() override;

	public:
		TileType type = TileType::Empty;
	};
}