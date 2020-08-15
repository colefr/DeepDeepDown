#include "World.hpp"

World::World() {
	player = new Player();	
}

World::~World() {
	delete player;
}

void World::Update(double& deltaTime) {
	player->Update(deltaTime);
}

void World::Draw(sf::RenderWindow* window) {
	player->Draw(window);
}