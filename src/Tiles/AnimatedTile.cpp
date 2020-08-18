#include "AnimatedTile.hpp"

AnimatedTile::AnimatedTile(sf::Vector2f aPosition, sf::Texture* aTexture, float aFrameRate) :
	StaticTile(aPosition, aTexture),
	animator(nullptr)
{
	animator = new Animator(sprite, aFrameRate);
}

AnimatedTile::~AnimatedTile() {
	delete animator;
	delete sprite;
	delete tileRect;
}

void AnimatedTile::Update(double& deltaTime) {
	animator->Update(deltaTime);
}