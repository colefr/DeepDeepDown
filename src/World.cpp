#include "World.hpp"

World::World() {
	cursor = new Cursor();

	player = new Player();
	const std::string imgPath = "assets/img/stone.png";

	tileTexture = new sf::Texture();
	tileTexture->loadFromFile(imgPath);

	tiles = new std::vector<Tile*>;	

	// Starting Tiles
	tiles->push_back(new Tile(tileTexture, stoneTileRect, sf::Vector2i((int)player->GetPosition().x, (int)player->GetPosition().y), 0));
	tiles->push_back(new Tile(tileTexture, stoneTileRect, sf::Vector2i((int)player->GetPosition().x + 32, (int)player->GetPosition().y), 1));
	tiles->push_back(new Tile(tileTexture, stoneTileRect, sf::Vector2i((int)player->GetPosition().x, (int)player->GetPosition().y + 32), 1));
	tiles->push_back(new Tile(tileTexture, stoneTileRect, sf::Vector2i((int)player->GetPosition().x - 32, (int)player->GetPosition().y), 1));
	tiles->push_back(new Tile(tileTexture, stoneTileRect, sf::Vector2i((int)player->GetPosition().x, (int)player->GetPosition().y - 32), 1));

	tiles->at(0)->Hide();
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

	// Left click "breaks" a tile
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		Tile* tileToUpdate = CheckTiles(cursor->GetPosition());
		if (tileToUpdate != nullptr) {
			//std::cout << "Clicked a Tile!" << std::endl;

			// This checks if there are tiles around the tile clicked on. If yes, no nothing.
			// If not, then replace empty spaces with new stone tiles.

			// Check Up
			if (CheckTiles(tileToUpdate->GetPosition() + sf::Vector2i(0, -32)) == nullptr) {
				tiles->push_back(new Tile(tileTexture, stoneTileRect, tileToUpdate->GetPosition() + sf::Vector2i(0,-32), 1));
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
