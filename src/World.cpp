#include "World.hpp"

World::World() {
	cursor = new Cursor();

	player = new Player();
	const std::string imgPath = "assets/img/stone.png";

	tiles = new std::vector<Tile*>;

	sf::IntRect stoneTileRect = sf::IntRect(0, 0, 32, 32);

	// Starting Tiles
	tiles->push_back(new Tile(imgPath, stoneTileRect, sf::Vector2i((int)player->GetPosition().x + 32, (int)player->GetPosition().y), 1));
	tiles->push_back(new Tile(imgPath, stoneTileRect, sf::Vector2i((int)player->GetPosition().x, (int)player->GetPosition().y + 32), 1));
	tiles->push_back(new Tile(imgPath, stoneTileRect, sf::Vector2i((int)player->GetPosition().x - 32, (int)player->GetPosition().y), 1));
	tiles->push_back(new Tile(imgPath, stoneTileRect, sf::Vector2i((int)player->GetPosition().x, (int)player->GetPosition().y - 32), 1));

	std::cout << tiles->size() << " tiles." << std::endl;
}

World::~World() {
	delete player;

	for (unsigned int i = 0; i < tiles->size(); i++) {
		delete tiles->at(i);
	}

	delete tiles;
	delete cursor;
}

void World::Update(double& deltaTime, sf::Window* window) {
	player->Update(deltaTime);

	cursor->Update(deltaTime, window);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		Tile* tileToUpdate = CheckTiles(cursor->GetPosition());
		if (tileToUpdate != nullptr) {
			//std::cout << "Clicked a Tile!" << std::endl;
		}
		//std::cout << "Click! at (" << cursor->GetPosition().x << ", " << cursor->GetPosition().y << ")" << std::endl;

		//On click
		//-> Check what tile is under the mouse cursor
		//	--> If it's a void tile, do nothing
		//	--> If it's a stone tile, turn it into an air tile and
		//			spawn stone tiles orthogonally where there are other
		//			void tiles (i.e. don't fill in "air" tiles).
	}	
}

void World::Draw(sf::RenderWindow* window) {
	player->Draw(window);
	cursor->Draw(window);

	for (unsigned int i = 0; i < tiles->size(); i++) {
		tiles->at(i)->Draw(window);
	}
}

Tile* World::CheckTiles(sf::Vector2i mousePos)
{
	for (unsigned int i = 0; i < tiles->size(); i++) {
		if (abs(tiles->at(i)->GetPosition().x - mousePos.x) <= 16 && abs(tiles->at(i)->GetPosition().y - mousePos.y) <= 16) {
			//std::cout << abs(tiles->at(i)->GetPosition().x - mousePos.x) << " " << abs(tiles->at(i)->GetPosition().y - mousePos.y) << std::endl;
			//std::cout << "Clicked a Tile!" << std::endl;
			return tiles->at(i)->GetTile();
		}

		else continue;
	}		
		
	//std::cout << "..." << std::endl;
	return nullptr;
}
