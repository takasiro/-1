#include"GameOverScene.h"
#include"InGameScene.h"
#include"UnitMgr.h"

ISceneChanger* GameOverScene::mStaticISceneChanger;

GameOverScene::GameOverScene() {

}
GameOverScene::GameOverScene(ISceneChanger* _Changer) :BaseScene(_Changer) {
	mGraph = LoadGraph("../Resource/Image/Etc/GameOver.png");
	button.SetGrHandleCount(3);
	button.SetGrHandles(new int[button.GetGrHandleCount()]);
	button.GetGrHandles()[0] = LoadGraph("../Resource/Image/Button/TitleButton01.png");
	button.GetGrHandles()[1] = LoadGraph("../Resource/Image/Button/TitleButton02.png");
	button.GetGrHandles()[2] = LoadGraph("../Resource/Image/Button/TitleButton03.png");
	button.SetPosX(475);
	button.SetPosY(625);
	button.SetOnClick(&ChangeScene);
	button.SetMyNum(0);
	button.Initialize();

	mStaticISceneChanger = mISceneChanger;
	SoundMgr::Instance()->PlayBGM("bgm_maoudamashii_orchestra19");
	ChangeVolumeSoundMem(255 * 50 / 100, SoundMgr::Instance()->GetBGM("bgm_maoudamashii_orchestra19"));

}
GameOverScene::~GameOverScene() {

}
int GameOverScene::Initialize() {
	return 0;
}

int GameOverScene::ChangeScene(int _buttonNumber) {
	StopSoundMem(SoundMgr::Instance()->GetBGM("bgm_maoudamashii_orchestra19"));
	mStaticISceneChanger->SceneClose();
	mStaticISceneChanger->SceneClose();
	return 0;
}

int GameOverScene::Update() {
	/*if (Keyboard::Instance()->Get(KEY_INPUT_R) == true) {
		INSTANCE->DataInit();
		mISceneChanger->ChangeScene((BaseScene*)new InGameScene(mISceneChanger));
		return 0;
	}*/
	button.Update();
	return 0;
}
int GameOverScene::Draw() {
	//DrawFormatString(100, 100, GetColor(255, 255, 255), "ÉNÉäÉA");
	DrawGraph(0, 0, mGraph, true);
	button.Draw();
	return 0;
}
int GameOverScene::Close() {
	return 0;
}