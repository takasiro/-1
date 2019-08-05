#pragma once
#include "BaseScene.h"
#include "ISceneChanger.h"
#include "Constant.h"
class InGameScene : public BaseScene {

public:
	InGameScene();
	InGameScene(ISceneChanger*);
	~InGameScene();
	int Initialize();
	int Update();
	int Draw();
	int Close();


};