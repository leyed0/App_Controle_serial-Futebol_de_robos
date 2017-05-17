#include "SDLWindow.h"



SDLWindow::SDLWindow()
{
}

SDLWindow::~SDLWindow()
{
	JoystickDisconnect();
	SDL_Quit();
	//throw gcnew System::NotImplementedException();
}

bool SDLWindow::Busy()
{
	return Isbusy;
}

void SDLWindow::MainLoop() {
	Isbusy = true;
	/*SDL_HapticRumblePlay(JoystickFeedback, 0.75, 500);*/
	if (SDL_PollEvent(&Event) != 0) {
		if (Event.type.Equals(SDL_JOYAXISMOTION)) {
			if (Event.jaxis.axis == 0) {
				SDL_HapticRumblePlay(JoystickFeedback, (float) abs(SDL_JoystickGetAxis(Joystick, 0)) / 32767 , 0);
				//SDL_HapticRumblePlay(JoystickFeedback, 0.75, 500);
			}
		}
	}
	Isbusy = false;
}

bool SDLWindow::Start()
{
	if (SDL_Init(SDL_INIT_JOYSTICK | SDL_INIT_HAPTIC) < 0) return false;
	return true;
}

int SDLWindow::JoystickCount()
{
	SDL_JoystickUpdate();
	return (int)SDL_NumJoysticks();
}

int SDLWindow::JoystickGetAxis(int axis)
{
	return SDL_JoystickGetAxis(Joystick, axis);
}

bool SDLWindow::JoystickConnect(int index)
{
	JoystickConnected = true;
	Joystick = SDL_JoystickOpen(index);
	JoystickFeedback = SDL_HapticOpenFromJoystick(Joystick);
	if(Joystick == NULL || JoystickFeedback == NULL) return false;
	if (SDL_HapticRumbleInit(JoystickFeedback)<0) return false;
	return true;
}

void SDLWindow::JoystickDisconnect() {
	SDL_HapticClose(JoystickFeedback);
	SDL_JoystickClose(Joystick);
	Joystick = NULL;
	JoystickFeedback = NULL;
}

unsigned int SDLWindow::Joystick_255(int axis)
{
	unsigned int ret;
	if(ret = SDL_JoystickGetAxis(Joystick, axis) - Deadzone[axis]<=0) return 0;
	else return ret / 128.3;
}

void SDLWindow::JoystickSetDZ(int axis, int val) {
	Deadzone[axis] = val * 128.4980392156863;
}
