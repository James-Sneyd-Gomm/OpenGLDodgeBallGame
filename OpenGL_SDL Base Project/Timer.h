#ifndef TIMER_H
#define TIMER_H
#include <SDL.h>

class Timer
{
public:
	Timer();
	~Timer();
	bool TimerCount(int seconds);
private:
	int CurrentTime;
	int PreviousTime;
};


#endif // !TIMER_H



