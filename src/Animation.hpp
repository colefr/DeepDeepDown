#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Rect.hpp"
#include <string>

class Animation {
public:
	Animation(const std::string& imgPath, const sf::Vector2u& aFrameGridSize = sf::Vector2u(1, 1));
	~Animation();

	void Update(double& deltaTime);
	void Draw(sf::RenderWindow* window);

	void SetFrameRate(const int& aFramerate);
	void SetFrameIndex(const int& aFrame);

	void Play();
	void Pause();

	void Show();
	void Hide();

	sf::Sprite* GetSprite();

private:
	sf::Sprite* sprite;
	sf::Texture* animationTexture;
	sf::Vector2u frameGridSize;
	sf::Vector2u textureSize;
	sf::Vector2u frameSize;
	int frameRate;
	int frameIndex;
	int frameCount;
	bool isPlaying;
	bool isVisible;

	float elapsedTime;
};