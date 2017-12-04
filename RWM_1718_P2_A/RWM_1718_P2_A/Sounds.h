#pragma once
#include "stdafx.h"
#include "SDL_mixer.h"

class Sounds
{
private:
	Mix_Chunk * effect = nullptr;

public:
	Sounds() {};
	Sounds(string);
	~Sounds() {};

	void Play();
};