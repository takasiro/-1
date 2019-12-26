#include "TitleScene.h"
#include "Load.h"
#include"Map.h"

ISceneChanger* TitleScene::mStaticISceneChanger;

int TitleScene::ChangeScene(int _buttonNumber) {
	switch (_buttonNumber) {
	case 0:
		//InGameScene移行
		mStaticISceneChanger->AddScene((BaseScene*)new InGameScene(mStaticISceneChanger));
		break;
	case 1:
		//なんかのSceneに移行
		//mStaticISceneChanger->AddScene((BaseScene*)new CharacterMenu(mStaticISceneChanger));
		break;
	case 2:
		//ゲーム終了とかそんなん
		DxLib_End() ; 
		break;
	default:
		//エラー処理とか
		break;
	}
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
		button[i].GetGrHandles()[0] = LoadGraph("../Resource/Image/Button/StartButton01.png");
		button[i].GetGrHandles()[1] = LoadGraph("../Resource/Image/Button/StartButton02.png");
		button[i].GetGrHandles()[2] = LoadGraph("../Resource/Image/Button/StartButton03.png");
		button[i].SetPosX(475);
		button[i].SetPosY(625+i * 100);
		button[i].SetOnClick(&ChangeScene);
		button[i].SetMyNum(i);
		button[i].Initialize();
	}

	//未実装シーンへのボタンは灰色表示にしています
		//未実装シーンへのボタンは灰色表示にしています
	button[1].GetGrHandles()[0] = LoadGraph("../Resource/Image/Button/CharaMenuButton02.png");
	button[1].GetGrHandles()[1] = LoadGraph("../Resource/Image/Button/CharaMenuButton02.png");
	button[1].GetGrHandles()[2] = LoadGraph("../Resource/Image/Button/CharaMenuButton02.png");

	button[2].GetGrHandles()[0] = LoadGraph("../Resource/Image/Button/QuitButton01.png");
	button[2].GetGrHandles()[1] = LoadGraph("../Resource/Image/Button/QuitButton02.png");
	button[2].GetGrHandles()[2] = LoadGraph("../Resource/Image/Button/QuitButton03.png");


	mStaticISceneChanger = mISceneChanger;

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
	for (int i = 0; i < 3; i++)button[i].Update();
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



