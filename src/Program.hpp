#pragma once
#include "SFML/Graphics.hpp"
#include "World.hpp"

class Program {
public:
	Program();
	~Program();

	void HandleEvents();
	void Update(double &deltaTime);
	void Draw();

	bool RenderWindowIsOpen();

private:
	sf::RenderWindow* window;
	World* world;
	sf::View* view;
};