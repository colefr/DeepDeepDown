#pragma once
#include "Item.hpp"

namespace Item {
	class ItemSlot {
	public:
		ItemSlot(sf::Vector2f aPosition, ItemType aType = ItemType::None, unsigned char aItemCount = 0);
		~ItemSlot();

		void Update(double& deltaTime);
		void Draw(sf::RenderWindow* window);

		Item* item;
		sf::Texture* frameTexture;
		sf::Sprite* frameSprite;

		sf::FloatRect hitBox;

		ItemType type;
		unsigned char itemCount;
	};
}