#include "Program.hpp"

Program::Program() {
	window = new sf::RenderWindow(sf::VideoMode(640, 480), "Render Window");
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

void Program::Update(double deltaTime) {

}

void Program::Draw() {
	window->clear();
	window->display();
}

bool Program::RenderWindowIsOpen() {
	return window->isOpen();
}
