#include "Timer.hpp"

Timer::Timer(float aDuration, bool start) {
	duration = aDuration;
	isRunning = start;
	elapsedTime = 0.0f;
	isDone = false;
}

Timer::~Timer() {
}

void Timer::Update(double& deltaTime) {
	if (isRunning) {
		elapsedTime += (float)deltaTime;

		if (elapsedTime >= duration) {
			isDone = true;
			isRunning = false;
		}
	}
}

void Timer::SetDuration(float aDuration) {
	duration = aDuration;
}

void Timer::Start() {
	isRunning = true;
}

void Timer::Pause() {
	isRunning = false;
}

void Timer::ResetAndStop() {
	elapsedTime = 0.0f;
	isRunning = false;
	isDone = false;
}

void Timer::Restart() {
	elapsedTime = 0.0f;
	isRunning = true;
	isDone = false;
}

bool Timer::IsRunning() {
	return isRunning;
}

bool Timer::IsDone() {
	return isDone;
}
