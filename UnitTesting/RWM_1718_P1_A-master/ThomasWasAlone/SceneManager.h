#pragma once
#include "TestScene.h"
#include "StartScene.h"
#include "EndScene.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "Level4.h"
#include "Level5.h"
#include "Level6.h"
#include "stdafx.h"

class SceneManager
{
public:
	enum Scenes
	{
		start = 0,
		level1 = 1,
		level2 = 2,
		level3 = 3,
		level4 = 4,
		level5 = 5,
		level6 = 6,
		end = 7
	};

	SceneManager();
	SceneManager(Renderer&);
	~SceneManager();
	//Switches between the scenes
	static void ChangeStates(Scenes newScene);


	Scenes GetCurrentState()
	{
		return m_currentScene;
	}
	void EventScene();
	void UpdateScene(unsigned int DeltaTime);
	void DrawScene(Renderer& renderer);

	Scene* getScene() 
	{ 
		return m_scene; 
	};

private:
	static Scenes m_currentScene;
	static Scene* m_scene;
	static vector<Scene*> m_sceneList;
};