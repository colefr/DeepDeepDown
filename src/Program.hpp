#pragma once
#include "SFML/Graphics.hpp"

class Program {
public:
	Program();
	~Program();

	void HandleEvents();
	void Update(double deltaTime);
	void Draw();

	bool RenderWindowIsOpen();

private:
	sf::RenderWindow* window;
};