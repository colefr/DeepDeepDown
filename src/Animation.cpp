#include "Animation.hpp"

Animation::Animation(const std::string& imgPath, const sf::Vector2u& aFrameGridSize) :
	frameGridSize(aFrameGridSize),
	frameRate(0),
	frameIndex(0),
	frameCount(0),
	isPlaying(true),
	isVisible(true),
	elapsedTime(0.0f)
{
	animationTexture = new sf::Texture;
	animationTexture->loadFromFile(imgPath);

	textureSize = animationTexture->getSize();
	frameSize = sf::Vector2u(textureSize.x / frameGridSize.x, textureSize.y / frameGridSize.y);

	frameCount = frameGridSize.x * frameGridSize.y;

	sprite = new sf::Sprite();
	sprite->setTexture(*animationTexture);
	sf::IntRect textureRect = sf::IntRect(0, 0, frameSize.x, frameSize.y);
	sprite->setTextureRect(textureRect);
}

Animation::~Animation() {
	delete sprite;
	delete animationTexture;
}

void Animation::Update(double& deltaTime) {
	if (isPlaying && frameRate != 0) {
		elapsedTime += deltaTime;

		if (elapsedTime >= 1.0 / (2 * frameRate)) {

			if (frameIndex <= frameCount) frameIndex++;
			else frameIndex = 0;

			sf::Vector2u frameGridIndex;
			frameGridIndex.x = frameIndex / frameGridSize.x;
			frameGridIndex.y = frameIndex % frameGridSize.y;

			sf::IntRect textureRect = sf::IntRect(frameGridIndex.x * frameSize.x, frameGridIndex.y * frameSize.y, frameSize.x, frameSize.y);
			sprite->setTextureRect(textureRect);

			elapsedTime = 0;
		}
	}
}

void Animation::Draw(sf::RenderWindow* window) {
	if (isVisible) {
		window->draw(*sprite);
	}
}

void Animation::SetFrameRate(const int& aFramerate) {
	frameRate = aFramerate;
}

void Animation::SetFrameIndex(const int& aFrame) {
	frameIndex = aFrame;
}

void Animation::Play() {
	isPlaying = true;
}

void Animation::Pause() {
	isPlaying = false;
}

void Animation::Show() {
	isVisible = true;
}

void Animation::Hide() {
	isVisible = false;
}

sf::Sprite* Animation::GetSprite() {
	return sprite;
}
