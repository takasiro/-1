#include"ResultScene.h"
#include"InGameScene.h"
#include"UnitMgr.h"
ResultScene::ResultScene() {

}
ResultScene::ResultScene(ISceneChanger*) {

}
ResultScene::~ResultScene() {

}
int ResultScene::Initialize() {
	return 0;
}
int ResultScene::Update() {
	/*if (Keyboard::Instance()->Get(KEY_INPUT_R) == true) {
		INSTANCE->DataInit();
		mISceneChanger->ChangeScene((BaseScene*)new InGameScene(mISceneChanger));
		return 0;
	}*/
	return 0;
}
int ResultScene::Draw() {
	DrawFormatString(100, 100, GetColor(255, 255, 255), "ƒNƒŠƒA");
	return 0;
}
int ResultScene::Close() {
	return 0;
}