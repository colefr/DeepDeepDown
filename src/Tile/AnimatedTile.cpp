#include "AnimatedTile.hpp"

namespace Tile {
	AnimatedTile::AnimatedTile(sf::Vector2f aPosition, const std::string& aTextureFileName, float aFrameRate, TileType aType, bool aCollidesWithEntities) :
		StaticTile(aPosition, aTextureFileName, aType, aCollidesWithEntities),
		animator(new Animator(sprite, aFrameRate))
	{}

	AnimatedTile::~AnimatedTile() {
		delete animator;
		delete sprite;
	}

	void AnimatedTile::Update(double& deltaTime) {
		animator->Update(deltaTime);
	}
}