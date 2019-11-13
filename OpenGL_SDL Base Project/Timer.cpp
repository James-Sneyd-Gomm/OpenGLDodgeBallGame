#include "Timer.h"



Timer::Timer()
{
	PreviousTime = SDL_GetTicks();
	CurrentTime = SDL_GetTicks();
}


Timer::~Timer()
{
}


bool Timer::TimerCount(int seconds)
{
	CurrentTime = SDL_GetTicks();
	int tempTime = PreviousTime + (seconds * 1000);
	if (CurrentTime > tempTime)
	{
		PreviousTime = CurrentTime;
		return true;
	}
	else
	{
		return false;
	}

}
