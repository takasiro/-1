#include"ResultScene.h"

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
	return 0;
}
int ResultScene::Draw() {
	DrawFormatString(100, 100, GetColor(255, 255, 255), "�N���A");
	return 0;
}
int ResultScene::Close() {
	return 0;
}