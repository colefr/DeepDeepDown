#include "World.hpp"

World::World() {
	cursor = new Cursor();

	player = new Entity::Player();

	chunks = new std::vector<Chunk*>;
	chunks->push_back(new Chunk(sf::Vector2f(0, 0)));

	// Starting Tiles
	chunks->at(0)->SetTileType(135, Tile::TileType::Stone);
	chunks->at(0)->SetTileType(137, Tile::TileType::Stone);
	chunks->at(0)->SetTileType(152, Tile::TileType::Stone);
	chunks->at(0)->SetTileType(120, Tile::TileType::Stone);
	chunks->at(0)->SetTileType(136, Tile::TileType::Floor);

	groundItems = new std::vector<Item::Item*>;

	inventory = new Inventory();
}

World::~World() {
	delete player;
	delete inventory;

	for (unsigned int i = 0; i < chunks->size(); i++) {
		delete chunks->at(i);
	}
	chunks->clear();
	delete chunks;

	for (unsigned int i = 0; i < groundItems->size(); i++) {
		delete groundItems->at(i);
	}
	groundItems->clear();
	delete groundItems;

	delete cursor;
}

void World::Update(double& deltaTime, sf::RenderWindow* window) {

	inventory->Update(deltaTime, player->view);
	player->Update(deltaTime);
	cursor->Update(deltaTime, window);

	CreateNewSurroundingChunks();
	
	for (unsigned int i = 0; i < chunks->size(); i++) {
		chunks->at(i)->Update(deltaTime, player);
	}

	for (unsigned int i = 0; i < groundItems->size(); i++) {
		groundItems->at(i)->Update(deltaTime);
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		sf::Vector2f mousePos = sf::Vector2f(cursor->GetPosition());
		Tile::Tile* clickedTile = GetTileAt(mousePos);

		if (clickedTile != nullptr) {
			// If Stone is broken and there are adjacent Empty tiles, the Empty tiles become Stone tiles
			if (clickedTile->type == Tile::TileType::Stone) {
				TurnSurroundingEmptyTilesToStone(clickedTile->position);
			}

			// Process OnLeftClick() events for that tile
			clickedTile->OnLeftClick(cursor);

			// Process Tile drops
			ProcessTileDrops(clickedTile);
		}
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
		sf::Vector2f mousePos = sf::Vector2f(cursor->GetPosition());
		Tile::Tile* clickedTile = GetTileAt(mousePos);

		if (clickedTile != nullptr) {
			// Process OnLeftClick() events for that tile
			clickedTile->OnRightClick(cursor);
		}
	}

	// Player Movement
	// North (-y)
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		player->Move(sf::Vector2f(0, -320), deltaTime);
		if (CheckTileCollision(player)) {
			player->Move(sf::Vector2f(0, 320), deltaTime);
		}
	}

	// South (+y)
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		player->Move(sf::Vector2f(0, 320), deltaTime);
		if (CheckTileCollision(player)) {
			player->Move(sf::Vector2f(0, -320), deltaTime);
		}
	}

	// West (-x)
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		player->Move(sf::Vector2f(-320, 0), deltaTime);
		if (CheckTileCollision(player)) {
			player->Move(sf::Vector2f(320, 0), deltaTime);
		}
	}

	// East (+x)
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		player->Move(sf::Vector2f(320, 0), deltaTime);
		if (CheckTileCollision(player)) {
			player->Move(sf::Vector2f(-320, 0), deltaTime);
		}
	}

	CheckGroundItemCollision(player);
}

void World::Draw(sf::RenderWindow* window) {	
	for (unsigned int i = 0; i < chunks->size(); i++) {
		chunks->at(i)->Draw(window);
	}

	for (unsigned int i = 0; i < groundItems->size(); i++) {
		groundItems->at(i)->Draw(window);
	}

	player->Draw(window);
	inventory->Draw(window);
	cursor->Draw(window);
}

Chunk* World::GetChunkAt(sf::Vector2f aPosition) {
	for (unsigned int i = 0; i < chunks->size(); i++) {
		if (chunks->at(i)->chunkBorder.contains(aPosition)) {
			return chunks->at(i);
		}
	}

	return nullptr;
}

Tile::Tile* World::GetTileAt(sf::Vector2f aPosition) {
	Chunk* clickedChunk = GetChunkAt(aPosition);

	// If aPosition doesn't land in a chunk, skip this section
	if (clickedChunk != nullptr) {
		int clickedTileIndex = clickedChunk->GetTileIndexAt(aPosition);

		// If for some reason landed in a chunk, but there's no tile there, skip this section too
		if (clickedTileIndex != -1) {
			return clickedChunk->tiles->at(clickedTileIndex);
		}
	}

	return nullptr;
}

int World::GetTileIndexAt(sf::Vector2f aPosition) {
	for (unsigned int i = 0; i < chunks->size(); i++) {
		if (chunks->at(i)->GetTileAt(aPosition) != nullptr) {
			return chunks->at(i)->GetTileIndexAt(aPosition);
		}
	}

	return -1;
}

void World::CreateNewSurroundingChunks() {
	sf::Vector2f chunkMidPoint = GetChunkAt(player->position)->midPoint;
	sf::Vector2f newChunkOffset;
	Chunk* testChunk = nullptr;

	// Check if there's a chunk [Direction] of the chunk the player is in
	// If there isn't, create a new empty chunk.

	// North (-y)
	newChunkOffset = sf::Vector2f(0, -512);
	testChunk = GetChunkAt(chunkMidPoint + newChunkOffset);
	if (testChunk == nullptr) {
		chunks->push_back(new Chunk(chunkMidPoint + newChunkOffset));
	}

	// South (+y)
	newChunkOffset = sf::Vector2f(0, +512);
	testChunk = GetChunkAt(chunkMidPoint + newChunkOffset);
	if (testChunk == nullptr) {
		chunks->push_back(new Chunk(chunkMidPoint + newChunkOffset));
	}

	// West (-x)
	newChunkOffset = sf::Vector2f(-512, 0);
	testChunk = GetChunkAt(chunkMidPoint + newChunkOffset);
	if (testChunk == nullptr) {
		chunks->push_back(new Chunk(chunkMidPoint + newChunkOffset));
	}

	// East(+x)
	newChunkOffset = sf::Vector2f(512, 0);
	testChunk = GetChunkAt(chunkMidPoint + newChunkOffset);
	if (testChunk == nullptr) {
		chunks->push_back(new Chunk(chunkMidPoint + newChunkOffset));
	}

	// North-West (-x, -y)
	newChunkOffset = sf::Vector2f(-512, -512);
	testChunk = GetChunkAt(chunkMidPoint + newChunkOffset);
	if (testChunk == nullptr) {
		chunks->push_back(new Chunk(chunkMidPoint + newChunkOffset));
	}

	// North-East (+x, -y)
	newChunkOffset = sf::Vector2f(+512, -512);
	testChunk = GetChunkAt(chunkMidPoint + newChunkOffset);
	if (testChunk == nullptr) {
		chunks->push_back(new Chunk(chunkMidPoint + newChunkOffset));
	}

	// South-West (-x, +y)
	newChunkOffset = sf::Vector2f(-512, +512);
	testChunk = GetChunkAt(chunkMidPoint + newChunkOffset);
	if (testChunk == nullptr) {
		chunks->push_back(new Chunk(chunkMidPoint + newChunkOffset));
	}

	// South-East (+x, +y)
	newChunkOffset = sf::Vector2f(+512, +512);
	testChunk = GetChunkAt(chunkMidPoint + newChunkOffset);
	if (testChunk == nullptr) {
		chunks->push_back(new Chunk(chunkMidPoint + newChunkOffset));
	}
}

bool World::CheckTileCollision(Entity::Entity* entity) {
	sf::FloatRect entityHitBox = entity->hitBox;

	for (unsigned int i = 0; i < chunks->size(); i++) {
		if (chunks->at(i)->chunkBorder.intersects(entityHitBox)) {
			Chunk* chunkIntersectingEntity = chunks->at(i);

			for (unsigned int j = 0; j < chunkIntersectingEntity->tiles->size(); j++) {
				if (chunkIntersectingEntity->tiles->at(j)->hitBox.intersects(entityHitBox)) {
					if (chunkIntersectingEntity->tiles->at(j)->collidesWithEntities) {
						return true;
					}
				}
			}
		}
	}

	return false;
}

void World::CheckGroundItemCollision(Entity::Entity* entity) {
	for (unsigned int i = 0; i < groundItems->size(); i++) {
		if (entity->hitBox.intersects(groundItems->at(i)->hitBox)) {
			delete groundItems->at(i);
			groundItems->erase(groundItems->begin() + i);
		}
	}
}

void World::ProcessTileDrops(Tile::Tile* aTile) {
	sf::Vector2f tilePosition = aTile->position;

	if (aTile->dropItemFlag) {
		if (aTile->itemTypeToDrop != Item::ItemType::None) {
			groundItems->push_back(Item::CreateNewItem(aTile->itemTypeToDrop, tilePosition));
		}
	}
}

void World::TurnSurroundingEmptyTilesToStone(sf::Vector2f aPosition) {
	Tile::Tile* tileToCheck = nullptr;

	// Check North (-y)
	tileToCheck = GetTileAt(aPosition + sf::Vector2f(0, -32));
	if (tileToCheck != nullptr && tileToCheck->type == Tile::TileType::Empty) {
		tileToCheck->OnWorldEvent();
	}

	// Check South (+y)
	tileToCheck = GetTileAt(aPosition + sf::Vector2f(0, +32));
	if (tileToCheck != nullptr && tileToCheck->type == Tile::TileType::Empty) {
		tileToCheck->OnWorldEvent();
	}

	// Check West (-x)
	tileToCheck = GetTileAt(aPosition + sf::Vector2f(-32, 0));
	if (tileToCheck != nullptr && tileToCheck->type == Tile::TileType::Empty) {
		tileToCheck->OnWorldEvent();
	}

	// Check East (+x)
	tileToCheck = GetTileAt(aPosition + sf::Vector2f(32, 0));
	if (tileToCheck != nullptr && tileToCheck->type == Tile::TileType::Empty) {
		tileToCheck->OnWorldEvent();
	}
}