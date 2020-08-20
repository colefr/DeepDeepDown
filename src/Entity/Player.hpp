#pragma once
#include "SFML/Graphics.hpp"
#include "../Animator.hpp"
#include "Entity.hpp"
#include <string>
#include <iostream>

namespace Entity {
	class Player : public Entity {
	public:
		Player();
		~Player();

		void Update(double& deltaTime) override;
		void Move(sf::Vector2f aDistance, double& deltaTime) override;

		sf::View* view;

	private:
		Animator* animator;
		float bobTime;
	};
}