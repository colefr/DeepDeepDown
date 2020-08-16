#include "World.hpp"

World::World() {
	cursor = new Cursor();

	player = new Player();
	const std::string imgPath = "assets/img/stone.png";

	tileTexture = new sf::Texture();
	tileTexture->loadFromFile(imgPath);

	tiles = new std::vector<Tile*>;	

	// Starting Tiles
	tiles->push_back(new Tile(player->GetPosition() + sf::Vector2i(0, 0), 1));
	tiles->push_back(new Tile(tileTexture, stoneTileRect, player->GetPosition() + sf::Vector2i(0, -32), 1));
	tiles->push_back(new Tile(tileTexture, stoneTileRect, player->GetPosition() + sf::Vector2i(0, 32), 1));
	tiles->push_back(new Tile(tileTexture, stoneTileRect, player->GetPosition() + sf::Vector2i(-32, 0), 1));
	tiles->push_back(new Tile(tileTexture, stoneTileRect, player->GetPosition() + sf::Vector2i(32, 0), 1));

	std::cout << tiles->size() << " tiles." << std::endl;
}

World::~World() {
	delete player;

	for (unsigned int i = 0; i < tiles->size(); i++) {
		delete tiles->at(i);
	}

	delete tiles;
	delete tileTexture;
	delete cursor;
}

void World::Update(double& deltaTime, sf::Window* window) {
	player->Update(deltaTime);
	cursor->Update(deltaTime, window);
	for (unsigned int i = 0; i < tiles->size(); i++) {
		tiles->at(i)->Update(deltaTime);
	}

	// Left click "breaks" a tile
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		Tile* tileToUpdate = CheckTiles(cursor->GetPosition());
		if (tileToUpdate != nullptr) {
			//std::cout << "Clicked a Tile!" << std::endl;

			// This checks if there are tiles around the tile clicked on. If yes, no nothing.
			// If not, then replace empty spaces with new stone tiles.

			// Check Up
			if (CheckTiles(tileToUpdate->GetPosition() + sf::Vector2i(0, -32)) == nullptr) {
				tiles->push_back(new Tile(tileTexture, stoneTileRect, tileToUpdate->GetPosition() + sf::Vector2i(0, -32), 1));
			}

			// Check Down
			if (CheckTiles(tileToUpdate->GetPosition() + sf::Vector2i(0, 32)) == nullptr) {
				tiles->push_back(new Tile(tileTexture, stoneTileRect, tileToUpdate->GetPosition() + sf::Vector2i(0, 32), 1));
			}

			// Check Left
			if (CheckTiles(tileToUpdate->GetPosition() + sf::Vector2i(-32, 0)) == nullptr) {
				tiles->push_back(new Tile(tileTexture, stoneTileRect, tileToUpdate->GetPosition() + sf::Vector2i(-32, 0), 1));
			}

			//Check Right
			if (CheckTiles(tileToUpdate->GetPosition() + sf::Vector2i(32, 0)) == nullptr) {
				tiles->push_back(new Tile(tileTexture, stoneTileRect, tileToUpdate->GetPosition() + sf::Vector2i(32, 0), 1));
			}

			// Hide the tile, but keep it there, both for the null-tile check, and also so it
			// can be manipulated in the future
			tileToUpdate->Hide();
		}
		//std::cout << "Click! at (" << cursor->GetPosition().x << ", " << cursor->GetPosition().y << ")" << std::endl;		
	}

	// Right click "places" a tile
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
		Tile* tileToUpdate = CheckTiles(cursor->GetPosition());
		if (tileToUpdate != nullptr) {
			tileToUpdate->Show();
		}
	}

	// Player Movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		Tile* checkTilePtr = CheckTiles(player->GetPosition() + sf::Vector2i(0, -16));
		if (checkTilePtr != nullptr) {
			if (checkTilePtr->GetVisibility() == false) {
				MovePlayer(sf::Vector2f(0, -320), deltaTime);
			}
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		Tile* checkTilePtr = CheckTiles(player->GetPosition() + sf::Vector2i(-16, 0));
		if (checkTilePtr != nullptr) {
			if (checkTilePtr->GetVisibility() == false) {
				MovePlayer(sf::Vector2f(-320, 0), deltaTime);
			}
		}		
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		Tile* checkTilePtr = CheckTiles(player->GetPosition() + sf::Vector2i(0, 16));
		if (checkTilePtr != nullptr) {
			if (checkTilePtr->GetVisibility() == false) {
				MovePlayer(sf::Vector2f(0, 320), deltaTime);
			}
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		Tile* checkTilePtr = CheckTiles(player->GetPosition() + sf::Vector2i(16, 0));
		if (checkTilePtr != nullptr) {
			if (checkTilePtr->GetVisibility() == false) {
				MovePlayer(sf::Vector2f(320, 0), deltaTime);
			}
		}
	}
}

void World::Draw(sf::RenderWindow* window) {
	for (unsigned int i = 0; i < tiles->size(); i++) {
		tiles->at(i)->Draw(window);
	}

	player->Draw(window);
	cursor->Draw(window);
}

void World::MovePlayer(sf::Vector2f aDistance, double& deltaTime) {
	sf::Vector2f distance = sf::Vector2f(aDistance.x * (float)deltaTime, aDistance.y * (float)deltaTime);
	player->Move(distance);
}

Tile* World::CheckTiles(sf::Vector2i aPosition)
{
	for (unsigned int i = 0; i < tiles->size(); i++) {
		if (abs(tiles->at(i)->GetPosition().x - aPosition.x) <= 16 && abs(tiles->at(i)->GetPosition().y - aPosition.y) <= 16) {
			//std::cout << abs(tiles->at(i)->GetPosition().x - mousePos.x) << " " << abs(tiles->at(i)->GetPosition().y - mousePos.y) << std::endl;
			//std::cout << "Clicked a Tile!" << std::endl;
			return tiles->at(i)->GetTile();
		}

		else continue;
	}		
		
	//std::cout << "..." << std::endl;
	return nullptr;
}
