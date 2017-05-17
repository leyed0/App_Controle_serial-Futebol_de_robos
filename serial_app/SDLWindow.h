#pragma once
#include "SDL.h"
class SDLWindow
{
private:
	bool IsRunning = true, Isbusy = false, JoystickConnected = false;
	unsigned int Deadzone[6]; //deadzone for each axys
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
	unsigned int Joystick_255(int);
	void JoystickSetDZ(int, int);
};