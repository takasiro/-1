#include "InGameScene.h"
#include"TitleScene.h"
#include"ResultScene.h"
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
	/*INSTANCE->SetCharaData(Chara(5, 6));
	INSTANCE->SetCharaData(Chara(16, 12));
	INSTANCE->SetCharaData(Chara(13, 13));
	INSTANCE->SetCharaData(Chara(15, 13));
	INSTANCE->SetCharaData(Chara(17, 13));
	INSTANCE->SetCharaData(Chara(13, 14));
	INSTANCE->SetCharaData(Chara(15, 14));
	INSTANCE->SetCharaData(Chara(17, 14));


	INSTANCE->SetEnemyData(Enemy(5, 5));*/

	Load load;
	load.LoadData("../Resource/Status/FairyBaseStatus.csv", "../Resource/Status/FairyGrowthStatus.csv");
	load.LoadData("../Resource/Status/PlayerBaseStatus.csv", "../Resource/Status/PlayerGrowthStatus.csv");
	load.LoadData("../Resource/Status/EnemyBaseStatus.csv", "../Resource/Status/EnemyGrowthStatus.csv");
	load.LoadData("../Resource/Map/map1.csv", map.GetMap(), "../Resource/Map/PlayerPos01.csv");
	load.LoadData("../Resource/Map/map1.csv", map.GetMap(), "../Resource/Map/EnemyPos01.csv");
	INSTANCE->SetMapData(map);
}

InGameScene::~InGameScene() {

}

int InGameScene::Initialize() {

	return 0;
}
int InGameScene::Update() {
	BaseObj::sPos tmpPos =  GET_POSITION();
	ui.Update();
	if (gameMgr.Update(gameMgr.Update()) == 1) {
		mISceneChanger->AddScene((BaseScene*)new ResultScene(mISceneChanger));
		return 0;
	}
	if (Keyboard::Instance()->Get(KEY_INPUT_R) == true) {
		INSTANCE->DataInit();
		mISceneChanger->AddScene((BaseScene*)new InGameScene(mISceneChanger));
		return 0;
	}
	if (MIDDLECLICK !=0) {
		BaseObj::sPos tmp = GET_POSITION();
		tmp.x -= tmpPos.x;
		tmp.y -= tmpPos.y;
		map + tmp;
	}

	return 0;
}
int InGameScene::Draw() {
	map.Draw();
	gameMgr.Draw();
	ui.Draw();
	//å„Ç≈UIÇ…à⁄êA
	//DrawBox(0, 0, 1280, 300,GetColor(50,255,50),true);

#ifdef DEBUG
	DrawFormatString(0, 0, GetColor(255, 255, 255), "InGame");
#endif
	return 0;
}
int InGameScene::Close() {
	/*gameMgr.Close();
	map.Close();*/
	return 0;
}


