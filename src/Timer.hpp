#pragma once

class Timer {
public:
	Timer(float aDuration, bool start = false);
	~Timer();

	void Update(double& deltaTime);

	void SetDuration(float aDuration);
	void Start();
	void Pause();
	void ResetAndStop();
	void Restart();

	bool IsRunning();
	bool IsDone();

private:
	float duration;
	float elapsedTime;
	bool isRunning;
	bool isDone;
};