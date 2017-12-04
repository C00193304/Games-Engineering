#pragma once
#include "stdafx.h"
#include "SDL_mixer.h"

// For background music

class Mixer
{
private:
	Mix_Music * Music;

public:
	Mixer() {};
	Mixer(string file);
	~Mixer() {};;
};