#pragma once
#include "BaseScene.h"
#include "ISceneChanger.h"
#include "DxLib.h"
#include "Mouse.h"
#include "InGameScene.h"
class TitleScene : public BaseScene {
	
public:
	TitleScene();
	TitleScene(ISceneChanger*);
	~TitleScene();
	int Initialize();
	int Update();
	int Draw();
	int Close();


};