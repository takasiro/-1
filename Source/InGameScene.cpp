#include "InGameScene.h"
#include<iostream>
using namespace std;
#include<vector>
#include"DxLib.h"
#include"Enemy.h"
#include"UnitMgr.h"



InGameScene::InGameScene() {

}

InGameScene::InGameScene(ISceneChanger* _Changer) :BaseScene(_Changer) {

}

InGameScene::~InGameScene() {

}

int InGameScene::Initialize() {
	UnitMgr Unitmgr;

	return 0;
}
int InGameScene::Update() {
	return 0;
}
int InGameScene::Draw() {
	#ifdef DEBUG
	DrawFormatString(0,0,GetColor(255,255,255),"InGame");
	#endif
	return 0;
}
int InGameScene::Close() {
	return 0;
}


