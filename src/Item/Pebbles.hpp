#pragma once
#include "Item.hpp"

namespace Item {
	class Pebbles : public Item	{
	public:
		Pebbles(sf::Vector2f aPosition);

		void Update(double& deltaTime) override;

	public:
		float bobTime = 0.0f;
	};
}