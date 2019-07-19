#include "InGameScene.h"
#include"DxLib.h"


InGameScene::InGameScene() {

}

InGameScene::InGameScene(ISceneChanger* _Changer) :BaseScene(_Changer) {

}

InGameScene::~InGameScene() {

}

int InGameScene::Initialize() {
	return 0;
}
int InGameScene::Update() {
	return 0;
}
int InGameScene::Draw() {
	DrawFormatString(100,100,GetColor(255,255,255),"InGame");
	return 0;
}
int InGameScene::Close() {
	return 0;
}


