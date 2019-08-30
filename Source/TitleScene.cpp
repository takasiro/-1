#include "TitleScene.h"
#include "Load.h"
#include"Map.h"

TitleScene::TitleScene() {
}

TitleScene::TitleScene(ISceneChanger* _Changer) :BaseScene(_Changer) {
	chara.emplace_back(new Chara(14, 12));
	chara.emplace_back(new Chara(16, 12));
	chara.emplace_back(new Chara(13, 13));
	chara.emplace_back(new Chara(15, 13));
	chara.emplace_back(new Chara(17, 13));
	chara.emplace_back(new Chara(13, 14));
	chara.emplace_back(new Chara(15, 14));
	chara.emplace_back(new Chara(17, 14));

	enemy.emplace_back(new Enemy(5, 5));
	
	Load load;
	load.LoadData("C:/Users/takag/デスクトップ/slg/slg/Resource/Map/map1.csv",map.GetMap());
}

TitleScene::~TitleScene() {

}

int TitleScene::Initialize() {
	return 0;
}
int TitleScene::Update() {
	for (int i = 0; i < chara.size(); i++) {
		chara[i]->Update();
	}
	for (int i = 0; i < enemy.size(); i++) {
		enemy[i]->Update();
	}
	return 0;
}
int TitleScene::Draw() {
	map.Draw();
	for (int i = 0; i < chara.size(); i++) {
		chara[i]->Draw();
	}
	for (int i = 0; i < enemy.size(); i++) {
		enemy[i]->Draw();
	}
	return 0;
}
int TitleScene::Close() {
	return 0;
}


