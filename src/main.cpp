//SFML Includes
#include "SFML/Graphics.hpp"
#include "SFML/System/Clock.hpp"

//stdlib Includes
#include <iostream>

//local includes
#include "Program.hpp"

int main() {
	std::cout << "Hello, Console!" << std::endl;

	Program* program = new Program();

	sf::Clock clock;
	sf::Time deltaClock;
	double deltaTime;

	while (program->RenderWindowIsOpen()) {
		// get the time it took to draw the last frame as seconds
		deltaTime = deltaClock.asSeconds();

		program->HandleEvents();
		program->Update(deltaTime);
		program->Draw();

		// restart the clock, simulatenously storing the time it took
		// to draw the last frame
		deltaClock = clock.restart();
	}

	delete program;

	return EXIT_SUCCESS;
}