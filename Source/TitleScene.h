#pragma once
#include "BaseScene.h"
#include "ISceneChanger.h"
#include"Chara.h"
#include"Enemy.h"
#include "Map.h"
#include<vector>
class TitleScene : public BaseScene {
	vector<Chara*> chara;
	vector<Enemy*>enemy;
	Map map;
public:
	TitleScene();
	TitleScene(ISceneChanger*);
	~TitleScene();
	int Initialize();
	int Update();
	int Draw();
	int Close();


};