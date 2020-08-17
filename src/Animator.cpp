#include "Animator.hpp"

Animator::Animator(sf::Sprite* aTargetSprite, float aFrameRate, int aFrameIndex, bool aStartPlaying) {
	sprite = aTargetSprite;
	frameRate = aFrameRate;
	frameIndex = aFrameIndex;

	timer = new Timer((1.0f / aFrameRate), aStartPlaying);

	// Get how many frames are in the animation.
	// *** This is set up so that an animated sprite-sheet has all frames of equal width
	//	   arranged horizontally on a single line with frame 0 the left-most.
	frameCount = sprite->getTexture()->getSize().x / 32;	// SOON!!! Replace all 32's and 16's
															// with a global const TILE_SIZE !!!

	sf::IntRect textureRect = sf::IntRect(sf::Vector2i((int)aFrameIndex * 32, 0), sf::Vector2i((int)aFrameIndex * 32 + 32, 32));
	sprite->setTextureRect(textureRect);
}

Animator::~Animator() {
	delete timer;
}

void Animator::SetTargetSprite(sf::Sprite* aTargetSprite) {
	sprite = aTargetSprite;
}

void Animator::Update(double& deltaTime) {
	timer->Update(deltaTime);

	if (timer->IsDone()) {
		if (frameIndex < frameCount - 1) {
			frameIndex++;
		}

		else frameIndex = 0;

		sf::IntRect textureRect = sf::IntRect(sf::Vector2i((int)frameIndex * 32, 0), sf::Vector2i((int)frameIndex * 32 + 32, 32));
		sprite->setTextureRect(textureRect);

		timer->Restart();
	}
}

void Animator::Start() {
	timer->Start();
}

void Animator::Stop() {
	timer->Pause();
}

bool Animator::IsRunning() {
	return timer->IsRunning();
}

void Animator::SetFrameRate(float aFrameRate) {
	frameRate = aFrameRate;
}

void Animator::SetFrameIndex(int aFrameIndex) {
	frameIndex = aFrameIndex;
}

float Animator::GetFrameRate() {
	return frameRate;
}

int Animator::GetFrameIndex() {
	return frameIndex;
}

int Animator::GetFrameCount() {
	return frameCount;
}
