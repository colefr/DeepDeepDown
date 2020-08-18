#include "World.hpp"

World::World() {
	cursor = new Cursor();

	player = new Player();
	const std::string imgPath = "assets/img/stone.png";
	const std::string animImgPath = "assets/img/shiny_rock.png";

	tileTexture = new sf::Texture();
	tileTexture->loadFromFile(imgPath);

	animTexture = new sf::Texture();
	animTexture->loadFromFile(animImgPath);

	tiles = new std::vector<Tile*>;	

	// Starting Tiles
	tiles->push_back(new StaticTile(player->position, tileTexture));

	tiles->push_back(new StaticTile(player->position + sf::Vector2f(0, -32), tileTexture));
	tiles->push_back(new StaticTile(player->position + sf::Vector2f(0, 32), tileTexture));
	tiles->push_back(new StaticTile(player->position + sf::Vector2f(-32, 0), tileTexture));
	tiles->push_back(new StaticTile(player->position + sf::Vector2f(32, 0), tileTexture));

	tiles->push_back(new AnimatedTile(player->position + sf::Vector2f(-32, -32), animTexture, 1));
	tiles->push_back(new AnimatedTile(player->position + sf::Vector2f(32, -32), animTexture, 2));
	tiles->push_back(new AnimatedTile(player->position + sf::Vector2f(-32, 32), animTexture, 3));
	tiles->push_back(new AnimatedTile(player->position + sf::Vector2f(32, 32), animTexture, 4));

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
	delete animTexture;
	delete cursor;
}

void World::Update(double& deltaTime, sf::RenderWindow* window, sf::View* view) {
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
			if (CheckTiles(tileToUpdate->GetPosition() + sf::Vector2f(0, -32)) == nullptr) {
				tiles->push_back(new StaticTile(tileToUpdate->GetPosition() + sf::Vector2f(0, -32), tileTexture));
			}

			// Check Down
			if (CheckTiles(tileToUpdate->GetPosition() + sf::Vector2f(0, 32)) == nullptr) {
				tiles->push_back(new StaticTile(tileToUpdate->GetPosition() + sf::Vector2f(0, 32), tileTexture));
			}

			// Check Left
			if (CheckTiles(tileToUpdate->GetPosition() + sf::Vector2f(-32, 0)) == nullptr) {
				tiles->push_back(new StaticTile(tileToUpdate->GetPosition() + sf::Vector2f(-32, 0), tileTexture));
			}

			//Check Right
			if (CheckTiles(tileToUpdate->GetPosition() + sf::Vector2f(32, 0)) == nullptr) {
				tiles->push_back(new StaticTile(tileToUpdate->GetPosition() + sf::Vector2f(32, 0), tileTexture));
			}

			// Hide the tile, but keep it there, both for the null-tile check, and also so it
			// can be manipulated in the future
			tileToUpdate->Hide();
		}
	}

	// Right click "places" a tile
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
		Tile* tileToUpdate = CheckTiles(cursor->GetPosition());
		if (tileToUpdate != nullptr) {
			tileToUpdate->Show();
		}
	}

	// Horizontal (X-axis) Movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		MovePlayer(sf::Vector2f(-320, 0), deltaTime);
		if (CheckTileCollision(player->hitBox)) {
			MovePlayer(sf::Vector2f(320, 0), deltaTime);
		}
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		MovePlayer(sf::Vector2f(320, 0), deltaTime);
		if (CheckTileCollision(player->hitBox)) {
			MovePlayer(sf::Vector2f(-320, 0), deltaTime);
		}
	}

	// Vertical (Y-axis) Movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		MovePlayer(sf::Vector2f(0, 320), deltaTime);
		if (CheckTileCollision(player->hitBox)) {
			MovePlayer(sf::Vector2f(0, -320), deltaTime);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		MovePlayer(sf::Vector2f(0, -320), deltaTime);
		if (CheckTileCollision(player->hitBox)) {
			MovePlayer(sf::Vector2f(0, 320), deltaTime);
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

Player* World::GetPlayer() {
	return player;
}

Tile* World::CheckTiles(sf::Vector2f aPosition) {
	for (unsigned int i = 0; i < tiles->size(); i++) {
		if (tiles->at(i)->tileRect->contains(aPosition)) {
			return tiles->at(i)->GetTilePointer();
		}
	}

	return nullptr;
}

bool World::CheckTileCollision(sf::FloatRect& aRect) {
	for (unsigned int i = 0; i < tiles->size(); i++) {
		if (tiles->at(i)->tileRect->intersects(aRect)) {
			if (tiles->at(i)->GetVisibility() == true) {
				return true;
			}
		}
	}

	return false;
}
