#include "pch.h"
#include "LevelLoader.h"
#include <LevelLoader.h>

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(JSONTEST, JSONRUNS)
{
	//initialise
	LevelLoader loader("GeneralGameData.json");
	EXPECT_EQ(0, GameData::m_playerX);
	//loads objects from the level1 jsonObject in the .json file including m_playerX into GameData
	loader.getGameData(1);
	EXPECT_EQ(500, GameData::m_playerX);
}

