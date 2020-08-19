#include "Entity.hpp"

Entity::Entity(sf::Vector2f aPosition, sf::Vector2f aSize, const std::string& aTextureFilePath, bool aIsVisible) :
	sprite(new sf::Sprite()),
	texture(new sf::Texture()),
	position(aPosition),
	isVisible(aIsVisible),
	hitBox(sf::FloatRect(aPosition, aSize))
{
	texture->loadFromFile(aTextureFilePath);

	sprite->setPosition(aPosition);
	sprite->setTexture(*texture);
}

Entity::~Entity() {
	delete sprite;
	delete texture;
}

void Entity::Update(double& deltaTime) {
}

void Entity::Draw(sf::RenderWindow* window) {
	window->draw(*sprite);
}
