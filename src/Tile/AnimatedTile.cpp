#include "AnimatedTile.hpp"

namespace Tile {
	AnimatedTile::AnimatedTile(sf::Vector2f aPosition, const std::string& aTextureFileName, float aFrameRate, bool aCollidesWithEntities) :
		StaticTile(aPosition, aTextureFileName, aCollidesWithEntities),
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