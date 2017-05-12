#pragma once
#include "SDL.h"
class SDLWindow
{
private:
	bool IsRunning = true, Isbusy = false, JoystickConnected = false;
	SDL_Joystick *Joystick = NULL;
	SDL_Event Event;
	SDL_Haptic *JoystickFeedback = NULL;
public:
	SDLWindow();
	~SDLWindow();
	bool Busy();
	void MainLoop();
	bool Start();
	int JoystickCount();
	int JoystickGetAxis(int);
	bool JoystickConnect(int);
	void JoystickDisconnect();
};