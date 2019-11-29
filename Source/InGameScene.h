#pragma once
#include "BaseScene.h"
#include "GameMgr.h"
#include "ISceneChanger.h"
#include "Constant.h"
#include "Map.h"
#include "UI.h"

class InGameScene : public BaseScene {
	//デバック用
private:
	Map map;
	GameMgr gameMgr;
	UI ui;
public:
	InGameScene();
	InGameScene(ISceneChanger*);
	~InGameScene();
	int Initialize();
	int Update();
	int Draw();
	int Close();


};