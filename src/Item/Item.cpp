#include "Item.hpp"
#include "ItemList.hpp"

namespace Item {
	Item::Item(sf::Vector2f& aPosition, ItemType aType, const std::string& aTextureFileName, bool aIsVisible) :
		sprite(new sf::Sprite()),
		texture(new sf::Texture()),
		position(aPosition),
		hitBox(sf::FloatRect(aPosition, sf::Vector2f(32.0f,32.0f))),
		type(aType),
		isVisible(aIsVisible)
	{
		if (aTextureFileName != "none") {
			texture->loadFromFile(aTextureFileName);
			sprite->setTexture(*texture);
			sprite->setPosition(aPosition);
		}
	}

	Item::~Item() {
		delete sprite;
		delete texture;
	}

	void Item::Update(double& deltaTime) {
		
		// This bit here just adds a little "bobbing" animation
		if (isVisible) {
			sf::Vector2f spriteOrigin = sprite->getOrigin();
			bobTime += (4 * (float)deltaTime);
			sf::Vector2f animationOffset = sf::Vector2f(0.0f, 0.05f * -sinf(bobTime));
			sprite->setOrigin(spriteOrigin + animationOffset);
		}
	}

	void Item::Draw(sf::RenderWindow* window) {
		if (isVisible) {
			window->draw(*sprite);
		}
	}

	void Item::OnLeftClick(Cursor* cursor) {
	}

	void Item::OnRightClick(Cursor* cursor)	{
	}

	void Item::OnWorldEvent() {
	}

	Item* CreateNewItem(ItemType aType, sf::Vector2f aPosition)	{
		switch (aType)
		{
		case ItemType::None:
			return nullptr;
			break;

		case ItemType::Pebbles:
			return new Pebbles(aPosition);
			break;

		default:
			return nullptr;
			break;
		}
	}
}