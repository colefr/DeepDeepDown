#include "Inventory.hpp"

Inventory::Inventory() :
	hotbar(nullptr),
	isVisible(true)
{
	hotbar = new std::vector<Item::ItemSlot*>;

	for (unsigned int i = 0; i < 10; i++) {
		sf::Vector2f hotbarPosition = sf::Vector2f(i * 48 - 240.0f + 16.0f, 180.0f);
		hotbar->push_back(new Item::ItemSlot(hotbarPosition));
	}
}

Inventory::~Inventory() {
	for (unsigned int i = 0; i < hotbar->size(); i++) {
		delete hotbar->at(i);
	}

	hotbar->clear();
	delete hotbar;
}

void Inventory::Update(double& deltaTime, sf::View* aView) {
	for (unsigned int i = 0; i < hotbar->size(); i++) {
		sf::Vector2f newPosition = aView->getCenter() + sf::Vector2f(i * 48 - 240.0f + 16.0f, 180.0f);
		hotbar->at(i)->frameSprite->setPosition(newPosition);

		if (hotbar->at(i)->item != nullptr) {
			hotbar->at(i)->item->sprite->setPosition(newPosition);
		}

		hotbar->at(i)->Update(deltaTime);
	}
}

void Inventory::Draw(sf::RenderWindow* window) {
	if (isVisible) {
		for (unsigned int i = 0; i < hotbar->size(); i++) {
			hotbar->at(i)->Draw(window);
		}
	}
}

bool Inventory::AddItem(Item::ItemType aType, char aCount) {
	for (unsigned int i = 0; i < hotbar->size(); i++) {
		if (hotbar->at(i)->type == aType && hotbar->at(i)->itemCount < 255) {			
			hotbar->at(i)->itemCount++;
			return true;
		}
	}

	return false;
}

bool Inventory::RemoveItem(Item::ItemType aType, char aCount) {
	for (unsigned int i = 0; i < hotbar->size(); i++) {
		if (hotbar->at(i)->type == aType && hotbar->at(i)->itemCount > 0) {
			hotbar->at(i)->itemCount--;
			return true;
		}
	}

	return false;
}
