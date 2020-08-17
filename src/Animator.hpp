#pragma once
#include "SFML/Graphics.hpp"
#include "Timer.hpp"

class Animator {
public:
	Animator(sf::Sprite* aTargetSprite, float aFrameRate, int aFrameIndex = 0, bool aStartPlaying = true);
	~Animator();

	void SetTargetSprite(sf::Sprite* aTargetSprite);

	void Update(double& deltaTime);

	void Start();
	void Stop();
	bool IsRunning();

	void SetFrameRate(float aFrameRate);
	void SetFrameIndex(int aFrameIndex);
	float GetFrameRate();
	int GetFrameIndex();
	
	int GetFrameCount();

private:
	sf::Sprite* sprite;
	Timer* timer;
	float frameRate;
	int frameIndex;
	int frameCount;
};