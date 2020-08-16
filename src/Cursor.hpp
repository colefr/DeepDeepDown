#pragma once
#include "SFML/Graphics.hpp"
#include <string>

class Cursor {
public:
	Cursor();
	~Cursor();

	void Update(double& deltaTime, sf::RenderWindow* window);
	void Draw(sf::RenderWindow* window);

	sf::Vector2f GetPosition();

private:
	sf::Sprite* cursorSprite;
	sf::Texture* cursorTexture;
	sf::Vector2f cursorPosition;

	std::string imgPath = "assets/img/cursor_arrow.png";
};