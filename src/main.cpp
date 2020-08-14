#include "SFML/Graphics.hpp"
#include <iostream>

int main() {
	std::cout << "Hello, Console!" << std::endl;

	sf::RenderWindow window(sf::VideoMode(640, 480), "Empty Window");

	while (window.isOpen()) {
		
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		window.display();
	}

	return EXIT_SUCCESS;
}