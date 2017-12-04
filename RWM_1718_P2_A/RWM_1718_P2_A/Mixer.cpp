#include "Mixer.h"
#include "SDL.h"

Mixer::Mixer(string file)
{
	// Mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		cout << "Error : " << Mix_GetError() << endl;
	}

	Music = Mix_LoadMUS(file.c_str());

	if (Music == nullptr)
	{
		cout << Mix_GetError() << endl;
	}

	Mix_VolumeMusic(100);
	Mix_PlayMusic(Music, -1);
}