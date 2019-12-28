#pragma once
#include "BaseScene.h"
#include "GameMgr.h"
#include "ISceneChanger.h"
#include "Constant.h"
#include "Map.h"
#include "TitleScene.h"

class ResultScene : public BaseScene {
	//デバック用
private:
	int mGraph;
	static ISceneChanger* mStaticISceneChanger;
	Button button;
public:
	ResultScene();
	ResultScene(ISceneChanger*);
	~ResultScene();
	int Initialize();
	int Update();
	int Draw();
	int Close();

	static int ChangeScene(int _buttonNumber);
};