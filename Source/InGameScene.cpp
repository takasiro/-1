#include "InGameScene.h"
#include<iostream>
using namespace std;
#include<vector>
#include"DxLib.h"
#include"Enemy.h"
#include"Chara.h"
#include "Load.h"


InGameScene::InGameScene() {

}

InGameScene::InGameScene(ISceneChanger* _Changer) :BaseScene(_Changer) {
	INSTANCE->SetCharaData(Chara(14, 12));
	INSTANCE->SetCharaData(Chara(16, 12));
	INSTANCE->SetCharaData(Chara(13, 13));
	INSTANCE->SetCharaData(Chara(15, 13));
	INSTANCE->SetCharaData(Chara(17, 13));
	INSTANCE->SetCharaData(Chara(13, 14));
	INSTANCE->SetCharaData(Chara(15, 14));
	INSTANCE->SetCharaData(Chara(17, 14));


	INSTANCE->SetEnemyData(Enemy(5, 5));

	Load load;
	load.LoadData("../Resource/Map/map1.csv", map.GetMap());
//	load.LoadData("../Resource/Status/PlayerBaseStatus.csv", "../Resource/Status/PlayerGrowthStatus.csv");
	INSTANCE->SetMapData(map);
}

InGameScene::~InGameScene() {

}

int InGameScene::Initialize() {
	
	return 0;
}
int InGameScene::Update() {
	gameMgr.Update(gameMgr.Update());
	
	return 0;
}
int InGameScene::Draw() {
	map.Draw();
	gameMgr.Draw();
	#ifdef DEBUG
	DrawFormatString(0,0,GetColor(255,255,255),"InGame");
	#endif
	return 0;
}
int InGameScene::Close() {
	map.Close();
	return 0;
}


