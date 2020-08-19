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

void Entity::Move(sf::Vector2f aDistance, double& deltaTime) {
	sf::Vector2f distance = sf::Vector2f(aDistance.x * (float)deltaTime, aDistance.y * (float)deltaTime);
	position += distance;
	sprite->setPosition(position);

	hitBox.left = position.x;
	hitBox.top = position.y;
}
