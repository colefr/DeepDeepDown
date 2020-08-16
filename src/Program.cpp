#include "Program.hpp"
#include <iostream>

Program::Program() {
	window = new sf::RenderWindow(sf::VideoMode(640, 480), "Render Window");
	window->setFramerateLimit(60);
	window->setMouseCursorVisible(false);

	world = new World();

	view = new sf::View(window->getView());
	view->zoom(0.5f);
}

Program::~Program() {
	delete window;
	delete world;
	delete view;
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
	world->Update(deltaTime, window, view);
	sf::Vector2f playerPosition = sf::Vector2f(world->GetPlayer()->GetPosition());
	view->setCenter(playerPosition);
}

void Program::Draw() {
	window->clear();
	window->setView(*view);
	world->Draw(window);
	window->display();
}

bool Program::RenderWindowIsOpen() {
	return window->isOpen();
}
