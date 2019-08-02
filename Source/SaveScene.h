#pragma once
#include "BaseScene.h"
class SaveScene :public BaseScene {
public:
	SaveScene();
	SaveScene(ISceneChanger*);
	~SaveScene();
	int Initialize();
	int Update();
	int Draw();
	int Close();
};