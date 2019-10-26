#pragma once
#include "BaseScene.h"
#include "GameMgr.h"
#include "ISceneChanger.h"
#include "Constant.h"
#include "Map.h"

class ResultScene : public BaseScene {
	//�f�o�b�N�p
private:

public:
	ResultScene();
	ResultScene(ISceneChanger*);
	~ResultScene();
	int Initialize();
	int Update();
	int Draw();
	int Close();


};