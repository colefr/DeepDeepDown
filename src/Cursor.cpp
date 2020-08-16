#include "Cursor.hpp"
#include "SFML/Window/Mouse.hpp"

Cursor::Cursor() {
	cursorSprite = new sf::Sprite();
	cursorTexture = new sf::Texture();

	cursorTexture->loadFromFile(imgPath);
	cursorSprite->setTexture(*cursorTexture);
}

Cursor::~Cursor() {
	delete cursorSprite;
	delete cursorTexture;
}

void Cursor::Update(double& deltaTime, sf::RenderWindow* window) {
	cursorPosition = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
	cursorSprite->setPosition(sf::Vector2f(cursorPosition));
}

void Cursor::Draw(sf::RenderWindow* window) {
	window->draw(*cursorSprite);
}

sf::Vector2f Cursor::GetPosition() {
	return cursorPosition;
}
