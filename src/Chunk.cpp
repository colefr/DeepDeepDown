#include "Chunk.hpp"

Chunk::Chunk(sf::Vector2f aMidPoint) :
	tiles(nullptr),
	midPoint(aMidPoint),
	isActive(false),
	isVisible(false)
{
	// Populate the chunk with Empty tiles
	tiles = new std::vector<Tile::Tile*>;
	for (int i = 0; i < chunkSizeInTiles; i++) {
		for (int j = 0; j < chunkSizeInTiles; j++) {
			sf::Vector2f tilePosition;
			tilePosition.x = i * tileSize + (aMidPoint.x - (tileSize * chunkSizeInTiles * 0.5f));
			tilePosition.y = i * tileSize + (aMidPoint.y - (tileSize * chunkSizeInTiles * 0.5f));

			tiles->push_back(new Tile::Empty(tilePosition));
		}
	}
}

Chunk::~Chunk() {
	isVisible = false;

	for (unsigned int i = 0; i < tiles->size(); i++) {
		delete tiles->at(i);
		tiles->at(i) = nullptr;
	}

	tiles->clear();
	delete tiles;
	tiles = nullptr;
}

void Chunk::Update(double& deltaTime, Player* aPlayer) {
	sf::Vector2f playerPosition = aPlayer->position;
	sf::Vector2f deltaPlayerMidpoint = playerPosition - midPoint;
	deltaPlayerMidpoint.x *= deltaPlayerMidpoint.x;		// Square the two coordinates
	deltaPlayerMidpoint.y *= deltaPlayerMidpoint.y;
	float midPointToPlayerDistace = sqrtf(deltaPlayerMidpoint.x + deltaPlayerMidpoint.y);

	// Set the isActive and isVisible flags based on the chunk's proximity to the player
	if (midPointToPlayerDistace <= activeDistance) {
		isActive = true;
	}
	else isActive = false;

	if (midPointToPlayerDistace <= renderDistance) {
		isVisible = true;
	}
	else isVisible = false;
}

void Chunk::Draw(sf::RenderWindow* window) {
	if (isVisible) {
		for (unsigned int i = 0; i < tiles->size(); i++) {
			if (tiles->at(i)->isVisible) {
				tiles->at(i)->Draw(window);
			}
		}
	}
}

Tile::Tile* Chunk::GetTileAt(sf::Vector2f aPos) {
	// First make sure the point being checked is actually in this chunk
	if (chunkBorder.contains(aPos)) {
		sf::Vector2f posRelativeToChunk = sf::Vector2f(chunkBorder.left, chunkBorder.top) - aPos;
		unsigned int xIndex = (int)posRelativeToChunk.x / (int)tileSize;
		unsigned int yIndex = (int)posRelativeToChunk.y / (int)tileSize;

		return tiles->at(xIndex * yIndex);
	}

	return nullptr;
}
