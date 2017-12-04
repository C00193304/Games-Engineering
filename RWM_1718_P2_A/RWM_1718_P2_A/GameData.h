#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <string>
#include <vector>

class GameData {
public:
	//global settings
	struct GObject
	{
		int X;
		int Y;
		int Width;
		int Height;
		std::string type;
		GObject(int x, int y, int width, int height, std::string word):
			X(x), Y(y), Height(height), Width(width),type(word)
		{
		}
	};

	static std::string fontFile;

	//level data
	//std::string menuBackgroundFile;

	//object data
	//string for sprites here.

	//level data
	static int m_playerX;
	static int m_playerY;
	static int m_maxGameObjects;
	//std::string m_levelBackgroundFile;
	static std::vector<GObject> m_gameObjectVector;
};
#endif
