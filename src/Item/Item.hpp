#pragma once
#include "SFML/Graphics.hpp"
#include "../Cursor.hpp"

namespace Item {
	enum class ItemType {
		None = 0,
		Pebbles
	};

	class Item {
	public:
		Item(sf::Vector2f& aPosition, ItemType aType = ItemType::None, const std::string& aTextureFileName = "none", bool aIsVisible = true);
		virtual ~Item();

		virtual void Update(double& deltaTime);
		virtual void Draw(sf::RenderWindow* window);

		virtual void OnLeftClick(Cursor* cursor);
		virtual void OnRightClick(Cursor* cursor);
		virtual void OnWorldEvent();

	public:
		sf::Sprite* sprite;
		sf::Texture* texture;

		sf::Vector2f position;
		sf::FloatRect hitBox;

		ItemType type;
		bool isVisible;
		float bobTime = 0.0f;
	};

	Item* CreateNewItem(ItemType aType, sf::Vector2f aPosition);
}