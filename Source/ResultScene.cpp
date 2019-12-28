#include"ResultScene.h"
#include"InGameScene.h"
#include"UnitMgr.h"

ISceneChanger* ResultScene::mStaticISceneChanger;

ResultScene::ResultScene() {

}
ResultScene::ResultScene(ISceneChanger* _Changer) :BaseScene(_Changer) {
	mGraph = LoadGraph("../Resource/Image/Etc/Clear.png");
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
}
ResultScene::~ResultScene() {
//	StopSoundMem();
}
int ResultScene::Initialize() {
	return 0;
}

int ResultScene::ChangeScene(int _buttonNumber) {
//	mStaticISceneChanger->AddScene((BaseScene*)new TitleScene(mStaticISceneChanger));
	mStaticISceneChanger->SceneClose();
	mStaticISceneChanger->SceneClose();
	//mStaticISceneChanger->ChangeScene((BaseScene*)new TitleScene(mStaticISceneChanger));
	return 0;
}

int ResultScene::Update() {
	/*if (Keyboard::Instance()->Get(KEY_INPUT_R) == true) {
		INSTANCE->DataInit();
		mISceneChanger->ChangeScene((BaseScene*)new InGameScene(mISceneChanger));
		return 0;
	}*/
	button.Update();
	return 0;
}
int ResultScene::Draw() {
	//DrawFormatString(100, 100, GetColor(255, 255, 255), "ÉNÉäÉA");
	DrawGraph(0, 0, mGraph, true);
	button.Draw();
	return 0;
}
int ResultScene::Close() {
	return 0;
}