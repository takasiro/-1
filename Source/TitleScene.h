#pragma once
#include "BaseScene.h"
#include "ISceneChanger.h"
#include"Chara.h"
#include<vector>
class TitleScene : public BaseScene {
	vector<Chara*> chara;
public:
	TitleScene();
	TitleScene(ISceneChanger*);
	~TitleScene();
	int Initialize();
	int Update();
	int Draw();
	int Close();


};