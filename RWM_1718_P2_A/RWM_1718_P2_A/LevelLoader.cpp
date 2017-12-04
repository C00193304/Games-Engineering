#include "stdafx.h"
#include "LevelLoader.h"


int GameData::m_playerX;
int GameData::m_playerY;
int GameData::m_maxGameObjects;
std::vector<GameData::GObject> GameData::m_gameObjectVector;
std::string GameData::fontFile;
	
////////////////////////////////////////////////////////////
LevelLoader::LevelLoader(std::string const & filename)
{

	loadJSONData(filename);
	m_value = JSON::Parse(m_JSONData.c_str());
	if (NULL == m_value)
	{
		std::string s("Could not parse json in " + filename);
		throw std::exception(s.c_str());
	}
}

////////////////////////////////////////////////////////////
LevelLoader::~LevelLoader() {
	delete m_value;
}

////////////////////////////////////////////////////////////
void LevelLoader::load(std::string const & filename)
{
	loadJSONData(filename);
	m_value = JSON::Parse(m_JSONData.c_str());
	if (NULL == m_value)
	{
		std::string s("Could not parse json in " + filename);
		throw std::exception(s.c_str());
	}
	
}

////////////////////////////////////////////////////////////
void LevelLoader::loadJSONData(std::string const & filename)
{
	m_JSONData.clear();

	// Loads all the data in the file into a std::string.
	std::ifstream myfile(filename);
	std::string line;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			m_JSONData.append(line);
		}
		myfile.close();
	}
	else
	{
		std::string errorMessage = "Could not open " + filename + " exiting!";
		std::cout << "Could not open " + filename + " exiting!" << std::endl;
		throw std::exception(errorMessage.c_str());
	}
}

////////////////////////////////////////////////////////////
void LevelLoader::loadMenuData()
{
	// Retrieve the main (root) object
	JSONObject root = getTopLevelJSONObject();

	JSONObject menuData = root[L"general_game_data"]->AsObject();
	// Locate the menu font file.	
	JSONObject globalSettings = menuData[L"global_settings"]->AsObject();
	m_menuData.m_MenuFontFile = wStringToString(globalSettings[L"font_file"]->AsString());

	JSONObject mainMenu = menuData[L"main_menu_items"]->AsObject();
	JSONArray menuItems = mainMenu[L"menu_items"]->AsArray();
	for (unsigned int i = 0; i < menuItems.size(); i++)
	{
		JSONObject object = menuItems[i]->AsObject();
		m_menuData.m_mainMenuVec.push_back(MenuData::MObject(object[L"Width"]->AsNumber(), object[L"Height"]->AsNumber(), object[L"x"]->AsNumber(), object[L"y"]->AsNumber(),
			wStringToString(object[L"text"]->AsString())));
	}
}

////////////////////////////////////////////////////////////
void LevelLoader::loadLevelData(int level)
{
	
	m_gameData.m_gameObjectVector.clear();
	// Retrieve the main (root) object
	JSONObject root = getTopLevelJSONObject();

	JSONObject gameData = root[L"general_game_data"]->AsObject();
	// Load the time to place towers field and related text settings.
	JSONObject globalSettings = gameData[L"global_settings"]->AsObject();
	m_gameData.fontFile = wStringToString(globalSettings[L"font_file"]->AsString());
	//use level to find the correct object in the json
	std::string word("level" + std::to_string(level));
	std::wstring wWord;
	wWord.assign(word.begin(), word.end());
	JSONObject m_level = gameData[wWord]->AsObject();
	//m_gameData.m_levelBackgroundFile = wStringToString(m_level[L"level_background_file"]->AsString());
	m_gameData.m_maxGameObjects = m_level[L"max_game_objects"]->AsNumber();
	m_gameData.m_playerX = m_level[L"player_x"]->AsNumber();
	m_gameData.m_playerY = m_level[L"player_y"]->AsNumber();
	JSONArray gameObjects = m_level[L"GameObjects"]->AsArray();
	for (unsigned int i = 0; i < gameObjects.size(); i++)
	{
		JSONObject object = gameObjects[i]->AsObject();
		m_gameData.m_gameObjectVector.push_back(GameData::GObject(object[L"x"]->AsNumber(), object[L"y"]->AsNumber(), 
			object[L"Width"]->AsNumber(), object[L"Height"]->AsNumber(),
			wStringToString(object[L"Type"]->AsString())));
	}
}

////////////////////////////////////////////////////////////
MenuData const & LevelLoader::getMenuData() const
{
	return m_menuData;
}

GameData & LevelLoader::getGameData(int level)
{
	loadLevelData(level);
	return m_gameData;
}

////////////////////////////////////////////////////////////
JSONObject LevelLoader::getTopLevelJSONObject() {
	// Retrieve the main (root) object
	JSONObject root;

	if (m_value->IsObject() == false)
	{
		throw std::exception("Problem with root element in json file, exiting");
	}
	root = m_value->AsObject();

	return root;
}

////////////////////////////////////////////////////////////
std::string LevelLoader::wStringToString(std::wstring const & wstr)
{
	std::string s(wstr.begin(), wstr.end());
	return s;
}

