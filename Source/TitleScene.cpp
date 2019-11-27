#include "TitleScene.h"
#include "Load.h"
#include"Map.h"

int ChangeScene(int _num) {
	mISceneChanger->AddScene((BaseScene*)new InGameScene(mISceneChanger));
	return 0;
}

TitleScene::TitleScene() {
	Initialize();
}

TitleScene::TitleScene(ISceneChanger* _Changer) :BaseScene(_Changer) {

	mTitleGraphHandle = LoadGraph("../Resource/Image/Title.png");  //タイトル画像読み込み

	for (int i = 0; i < 3; i++) {  //ボタン画像読み込み
		button[i].SetGrHandleCount(3);
		button[i].SetGrHandles(new int[button[i].GetGrHandleCount() ]);
		button[i].GetGrHandles()[0] = LoadGraph("../Resource/Image/StartButton01.png");
		button[i].GetGrHandles()[1] = LoadGraph("../Resource/Image/StartButton03.png");
		button[i].GetGrHandles()[2] = LoadGraph("../Resource/Image/StartButton02.png");
		button[i].SetPosY(200+i * 200);
		button[i].SetOnClick(&ChangeScene);
		button[i].SetMyNum(i);
	}



}

TitleScene::~TitleScene() {

	for (int i = 0; i < 3; i++) {  //ボタン画像のメモリ解放
		for (int j = 0; j < 3; j++) {
			DeleteGraph(button[i].GetGrHandles()[j]);
		}
		delete[] button[i].GetGrHandles();
	}

	DeleteGraph(mTitleGraphHandle);  //タイトル画像のメモリ解放
}

int TitleScene::Initialize() {

	mTitleGraphHandle = LoadGraph("../Resource/Image/Title.png");
	return 0;
}
int TitleScene::Update() {
	return 0;
}
int TitleScene::Draw() {

	DrawGraph(0, 0, mTitleGraphHandle, FALSE);
	for(int i=0;i<3;i++)button[i].Draw();

	return 0;
}


int TitleScene::Close() {
	return 0;
}



