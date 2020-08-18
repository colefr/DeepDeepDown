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
		sf::Vector2f GetPosition();
		bool GetVisibility();

		void Show();
		void Hide();

		virtual void Draw(sf::RenderWindow* window);
		virtual void Update(double& deltaTime);

		Tile* GetTilePointer();

		sf::Sprite* sprite = nullptr;
		sf::Texture* texture = nullptr;
		sf::FloatRect hitBox;
		sf::Vector2f position;
		bool isVisible = true;
		TileType tileType = TileType::Empty;
	};

	class Empty : public Tile {
	public:
		Empty(sf::Vector2f& aPosition);
		~Empty();

		void Draw(sf::RenderWindow* window) override;
		void Update(double& deltaTime) override;
	};
}