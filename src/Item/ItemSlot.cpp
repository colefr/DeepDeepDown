#include "ItemSlot.hpp"

namespace Item {
	ItemSlot::ItemSlot(sf::Vector2f aPosition, ItemType aType, unsigned char aItemCount) :
		item(CreateNewItem(aType, aPosition)),
		frameTexture(new sf::Texture()),
		frameSprite(new sf::Sprite()),
		hitBox(sf::FloatRect(aPosition, sf::Vector2f(48.0f, 48.0f))),
		type(aType),
		itemCount(aItemCount)
	{
		frameTexture->loadFromFile("assets/img/item_slot.png");
		frameSprite->setTexture(*frameTexture);
		frameSprite->setPosition(aPosition - sf::Vector2f(4.0f, 4.0f));
	}

	ItemSlot::~ItemSlot() {
		delete frameSprite;
		delete frameTexture;
	}

	void ItemSlot::Update(double& deltaTime) {
		item->Update(deltaTime);
	}

	void ItemSlot::Draw(sf::RenderWindow* window) {
		window->draw(*frameSprite);
		item->Draw(window);
	}
}