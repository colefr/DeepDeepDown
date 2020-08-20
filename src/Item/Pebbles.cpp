#include "Pebbles.hpp"

namespace Item {
	Pebbles::Pebbles(sf::Vector2f aPosition) :
		Item(aPosition, ItemType::Pebbles, "assets/img/pebbles.png") {
	}

	void Pebbles::Update(double& deltaTime) {
		sf::Vector2f spriteOrigin = sprite->getOrigin();

		// This bit here just adds a little "bobbing" animation
		bobTime += (4 * (float)deltaTime);
		sf::Vector2f animationOffset = sf::Vector2f(0.0f, 0.05f * -sinf(bobTime));
		sprite->setOrigin(spriteOrigin + animationOffset);
	}
}