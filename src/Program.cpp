#include "Program.hpp"
#include <iostream>

Program::Program() {
	window = new sf::RenderWindow(sf::VideoMode(640, 480), "RenderWindow");
	window->setFramerateLimit(60);
	window->setMouseCursorVisible(false);

	world = new World();
	cursor = new Cursor();
}

Program::~Program() {
	delete window;
	delete world;
	delete cursor;
}

void Program::HandleEvents() {
	sf::Event event;
	while (window->pollEvent(event)) {
		switch (event.type)
		{
		default:
			break;

		case sf::Event::Closed:
			window->close();
		}
	}
}

void Program::Update(double &deltaTime) {
	//std::cout << "deltaTime = " << (float)deltaTime << "s" << std::endl;
	//std::cout << "FPS = " << (int)(1 / deltaTime) << std::endl;
	world->Update(deltaTime);

	cursor->Update(deltaTime, window);
}

void Program::Draw() {
	window->clear();
	world->Draw(window);
	cursor->Draw(window);
	window->display();
}

bool Program::RenderWindowIsOpen() {
	return window->isOpen();
}
