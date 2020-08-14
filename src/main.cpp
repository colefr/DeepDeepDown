//SFML Includes
#include "SFML/Graphics.hpp"

//stdlib Includes
#include <iostream>

//local includes
#include "Program.hpp"

int main() {
	std::cout << "Hello, Console!" << std::endl;

	Program program;

	while (program.RenderWindowIsOpen()) {
		
		program.HandleEvents();
		program.Update(0.0);
		program.Draw();
	}

	return EXIT_SUCCESS;
}