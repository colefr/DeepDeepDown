#include "World.hpp"

World::World() {
	player = new Player();
	const std::string imgPath = "assets/img/stone.png";

	tiles = new std::vector<Tile*>;

	tiles->push_back(new Tile(imgPath, sf::IntRect(0, 0, 31, 31), sf::Vector2i(100, 100), 1));
	tiles->push_back(new Tile(imgPath, sf::IntRect(0, 0, 31, 31), sf::Vector2i(200, 100), 1));
	tiles->push_back(new Tile(imgPath, sf::IntRect(0, 0, 31, 31), sf::Vector2i(300, 100), 1));
	tiles->push_back(new Tile(imgPath, sf::IntRect(0, 0, 31, 31), sf::Vector2i(400, 100), 1));
	tiles->push_back(new Tile(imgPath, sf::IntRect(0, 0, 31, 31), sf::Vector2i(500, 100), 1));
	
}

World::~World() {
	delete player;

	for (int i = 0; i < tiles->size(); i++) {
		delete tiles->at(i);
	}

	delete tiles;
}

void World::Update(double& deltaTime) {
	player->Update(deltaTime);
}

void World::Draw(sf::RenderWindow* window) {
	player->Draw(window);

	for (int i = 0; i < tiles->size(); i++) {
		tiles->at(i)->Draw(window);
	}
}