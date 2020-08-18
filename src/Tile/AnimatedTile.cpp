#include "AnimatedTile.hpp"

namespace Tile {
	AnimatedTile::AnimatedTile(sf::Vector2f aPosition, const std::string& aTextureFileName, float aFrameRate) :
		StaticTile(aPosition, aTextureFileName),
		animator(nullptr)
	{
		animator = new Animator(sprite, aFrameRate);
	}

	AnimatedTile::~AnimatedTile() {
		delete animator;
		delete sprite;
	}

	void AnimatedTile::Update(double& deltaTime) {
		animator->Update(deltaTime);
	}
}