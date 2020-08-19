#pragma once
#include "SFML/Graphics.hpp"

class Entity {
public:
	Entity(sf::Vector2f aPosition, sf::Vector2f aSize, const std::string& aTextureFilePath, bool aIsVisible = true);
	virtual ~Entity();

	virtual void Update(double& deltaTime);
	virtual void Draw(sf::RenderWindow* window);

	sf::Sprite* sprite;
	sf::Texture* texture;

	sf::FloatRect hitBox;
	sf::Vector2f position;

	bool isVisible;
};