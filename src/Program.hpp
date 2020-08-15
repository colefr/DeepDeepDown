#pragma once
#include "SFML/Graphics.hpp"
#include "World.hpp"
#include "GlobalConstants.hpp"
#include "Cursor.hpp"

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
	Cursor* cursor;
};