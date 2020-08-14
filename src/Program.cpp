#include "Program.hpp"
#include <iostream>

Program::Program() {
	window = new sf::RenderWindow(sf::VideoMode(k_WindowWidth, k_WindowHeight), "RenderWindow");
	//window->setFramerateLimit(60);
}

Program::~Program() {
	delete window;
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
}

void Program::Draw() {
	window->clear();
	window->display();
}

bool Program::RenderWindowIsOpen() {
	return window->isOpen();
}
