#ifndef TIMECONTROLLER
#define TIMECONTROLLER

#include <iostream>
#include <SDL.h>

class TimeController
{
public:
	TimeController();
	~TimeController();

	static TimeController timeController;

	//reference values
	static const int PLAY_STATE, PAUSE_STATE;

	int timeState;
	//Last time we cheked how many ticks we were up to
	Uint32 lastUpdate;
	//delta time, in seconds (1 = 1 second, 0.5 is hald a second). Time since the last frame was rendered onto screen
	float dt; 

	//update lastUpdate and dt
	void UpdateTime();
	void pause();
	void resume();
	void reset();

private:

};

const int TimeController::PLAY_STATE = 0, TimeController::PAUSE_STATE = 1;

TimeController::TimeController()
{
	dt = 0;
	lastUpdate = 0;
	timeState = PLAY_STATE;
}

TimeController::~TimeController()
{
}

void TimeController::UpdateTime()
{
	if (timeState == PAUSE_STATE)
		dt = 0;
	else
	{
		Uint32 timeDiff = SDL_GetTicks() - lastUpdate;
		//move these milliseconds into the decimal place area  e.g. 104 ticks = 0.104 seconds
		dt = timeDiff / 1000.0; 
	}

	lastUpdate = SDL_GetTicks();
}

void TimeController::pause()
{
	timeState = PAUSE_STATE;
}

void TimeController::resume()
{
	timeState = PLAY_STATE;
}

void TimeController::reset()
{
	dt = 0;
	lastUpdate = SDL_GetTicks();
}

//builds a global timeController object for use anywhere
TimeController TimeController::timeController;

#endif // !TIMECONTROLLER

