#include "DxLib.h"
#include "MapSelectScene.h"

MapSelectScene::MapSelectScene() {
	for (int i = 0; i < 10; i++) {
		map.push_back(Unit{ 100.0 * i + 20,980 / 2,20,i , });
		if (i != 9)map[i].next.push_back(i + 1);
		map[i].prev.push_back(NULL + i - 1);
		//if (i == 4)map[i].next.push_back(10);

	}
}


MapSelectScene::MapSelectScene(ISceneChanger* _Changer) :BaseScene(_Changer) {

}

MapSelectScene::~MapSelectScene() {

}

int MapSelectScene::Initialize() {
	return 0;
}
int MapSelectScene::Update() {
	GetMousePoint(&MouseX, &MouseY);

	for (int j = 0; j < map[player.pos].next.size(); j++) {
		if (map[player.pos].next[j] != NULL) {
			//プレイヤーが今いる場所からつながっている場所をクリックしたらという判定
			if ((map[map[player.pos].next[j]].x - MouseX) * (map[map[player.pos].next[j]].x - MouseX) + (map[map[player.pos].next[j]].y - MouseY) *
				(map[map[player.pos].next[j]].y - MouseY) < (map[map[player.pos].next[j]].r * map[map[player.pos].next[j]].r)) {
				player.x = map[map[player.pos].next[j]].x;
				player.y = map[map[player.pos].next[j]].y;
				player.pos = map[player.pos].next[j];
			}
		}
	}
	for (int j = 0; j < map[player.pos].prev.size(); j++) {
		if (map[player.pos].prev[j] != NULL) {
			if ((map[map[player.pos].prev[j]].x - MouseX) * (map[map[player.pos].prev[j]].x - MouseX) + (map[map[player.pos].prev[j]].y - MouseY) *
				(map[map[player.pos].prev[j]].y - MouseY) <= (map[map[player.pos].prev[j]].r * map[map[player.pos].prev[j]].r)) {
				player.x = map[map[player.pos].prev[j]].x;
				player.y = map[map[player.pos].prev[j]].y;
				player.pos = map[player.pos].prev[j];
			}
		}
	}
	return 0;
}
int MapSelectScene::Draw() {
	GetMousePoint(&MouseX, &MouseY);

	//以下表示
	for (int i = 0; i < map.size(); i++) {
		DrawCircle(map[i].x, map[i].y, map[i].r, GetColor(255, 255, 255));
		for (int j = 0; j < map[i].next.size(); j++) {
			DrawLine(map[i].x, map[i].y, map[map[i].next[j]].x, map[map[i].next[j]].y, GetColor(255, 255, 255));
		}

	}
	for (int j = 0; j < map[player.pos].next.size(); j++) {
		DrawFormatString(0 + 80 * j, 30, GetColor(255, 255, 255), "ネクスト%d", map[player.pos].next[j]);
	}
	for (int j = 0; j < map[player.pos].prev.size(); j++) {
		DrawFormatString(0 + 80 * j, 60, GetColor(255, 255, 255), "プレブ%d", map[player.pos].prev[j]);
	}
	DrawFormatString(0, 0, GetColor(255, 255, 255), "現在マップ%d", player.pos);
	DrawCircle(player.x, player.y, player.r, GetColor(0, 0, 255));
	// ソフトの終了 

	return 0;
}
int MapSelectScene::Close() {
	return 0;
}


