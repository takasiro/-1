#include "TitleScene.h"
#include "Button.h"


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
	
	return 0;
}
int TitleScene::Draw() {
	Button button;
	button.Draw();
	return 0;
}
int TitleScene::Close() {
	return 0;
}


