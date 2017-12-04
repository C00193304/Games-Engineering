#include "Sounds.h"

Sounds::Sounds(string path)
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		cout << "Error : " << Mix_GetError() << endl;
	}

	effect = Mix_LoadWAV(path.c_str());

	if (effect == nullptr)
	{
		cout << Mix_GetError() << endl;
	}

	Mix_VolumeChunk(effect, 100);
}

void Sounds::Play()
{
	Mix_PlayChannel(-1, effect, 0);
	
}