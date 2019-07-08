#pragma once
#include "BaseScene.h"
#include "ISceneChanger.h"
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