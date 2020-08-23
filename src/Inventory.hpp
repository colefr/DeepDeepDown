#pragma once
#include "SFML/Graphics.hpp"
#include "Item/ItemSlot.hpp"

class Inventory {
public:
	Inventory();
	~Inventory();

	void Update(double& deltaTime, sf::View* aView);
	void Draw(sf::RenderWindow* window);

	bool AddItem(Item::ItemType aType, char aCount);
	bool RemoveItem(Item::ItemType aType, char aCount);

private:
	std::vector<Item::ItemSlot*>* hotbar;

	bool isVisible;
};