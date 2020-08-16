#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include <iostream>
#include "../Player.hpp"

class Tile {
public:
	Tile(sf::Vector2f aPosition, unsigned short aTileID);
	Tile(sf::Texture* texturePtr, sf::IntRect aTextureRect, sf::Vector2f aPosition, unsigned short aTileID);
	virtual ~Tile();

	void Update(double& deltaTime);
	void Draw(sf::RenderWindow* window);

	sf::Vector2f GetPosition();
	Tile* GetTile();
	sf::Sprite* GetSprite();
	bool GetVisibility();

	void Show();
	void Hide();

private:
	unsigned short tileID;
	sf::Vector2f position;
	sf::Sprite* sprite;
	bool isVisible;
};