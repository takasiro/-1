#include "TitleScene.h"



TitleScene::TitleScene() {

}

TitleScene::TitleScene(ISceneChanger* _Changer):BaseScene(_Changer) {
	
}

TitleScene::~TitleScene() {

}

int TitleScene::Initialize() {
	return 0;
}
int TitleScene::Update() {
	if (GET_BUTTON() & MOUSE_INPUT_LEFT) {
		mISceneChanger->AddScene(new InGameScene);
	}
	return 0;
}
int TitleScene::Draw() {
	#ifndef DEBUG
	DrawFormatString(0,0,GetColor(255,255,255),"TitleScene");
	DrawFormatString(600, 200, GetColor(255, 255, 255), "ƒNƒŠƒbƒN‚ÅInGame");
	#endif
	return 0;
}
int TitleScene::Close() {
	return 0;
}


