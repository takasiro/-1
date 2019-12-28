#pragma once
#include "BaseScene.h"
#include "GameMgr.h"
#include "ISceneChanger.h"
#include "Constant.h"
#include "Map.h"
#include "TitleScene.h"

class GameOverScene : public BaseScene {
	//デバック用
private:
	int mGraph;
	static ISceneChanger* mStaticISceneChanger;
	Button button;
public:
	GameOverScene();
	GameOverScene(ISceneChanger*);
	~GameOverScene();
	int Initialize();
	int Update();
	int Draw();
	int Close();

	static int ChangeScene(int _buttonNumber);
};