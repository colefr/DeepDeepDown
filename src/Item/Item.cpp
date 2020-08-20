#include "Item.hpp"

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
}