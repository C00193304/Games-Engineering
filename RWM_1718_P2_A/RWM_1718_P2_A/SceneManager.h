#pragma once
#include "Renderer.h"
#include "Scene.h"
#include "stdafx.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include"TestScene.h"
#include "StartScene.h"
#include "EndScene.h"


class SceneManager
{
public:
	enum Scenes
	{
		start = 0,
		levelselection = 10,
		level1 = 1,
		level2 = 2,
		level3 = 3,
		level4 = 7,
		level5 = 5,
		level6 = 6,
		end = 4
	};

	SceneManager();
	SceneManager(Renderer&);
	~SceneManager();
	//Switches between the scenes
	static void ChangeStates(Scenes newScene);
	void LoadNextLevel(Renderer&, Scenes);


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