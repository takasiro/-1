#include "DxLib.h"
#include "Mouse.h"
#include "MapSelectScene.h"

MapSelectScene::MapSelectScene() {

}


MapSelectScene::MapSelectScene(ISceneChanger* _Changer) :BaseScene(_Changer) {

}

MapSelectScene::~MapSelectScene() {

}

int MapSelectScene::Initialize() {
	return 0;
}
int MapSelectScene::Update() {
	//マウス長押し変更
	if (LEFTCLICK != FALSE) {
		//マウス座標取得
		GetMousePoint(&MouseX, &MouseY);
			if (mouseclick == 0) {
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					if (map[i].connection[j] != -1) {
						if ((map[i].x - MouseX) * (map[i].x - MouseX) + (map[i].y - MouseY) *
							(map[i].y - MouseY) <= (map[i].r * map[i].r)) {
							if (map[i].connection[0] == state) {
								state = i;
							}
							if (map[i].connection[1] == state) {
								state = i;
							}
						}
					}
				}
			}
		}
		mouseclick = 1;
	}
	else {
		mouseclick = 0;
	}
	return 0;
}
int MapSelectScene::Draw() {

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 2; j++) {
			if (map[i].connection[j] != -1) {
				if (map[i].connection[j] == state) {
					DrawCircle(map[i].x, map[i].y, 30, GetColor(100, 100, 255), true);
					for (int k = 0; k < 4; k++) {
						DrawLine(
							map[i].x + direction[k][0],
							map[i].y + direction[k][1],
							map[map[i].connection[j]].x + direction[k][0],
							map[map[i].connection[j]].y + direction[k][1],
							GetColor(100, 255, 100));
					}
				}
				DrawLine(map[i].x, map[i].y, map[map[i].connection[j]].x, map[map[i].connection[j]].y, GetColor(0, 100, 0));
			}
		}
	}
	for (int i = 0; i < 9; i++) {
		if (i == state) {
			DrawFormatString(0, 0, GetColor(255, 255, 255), "現在マップ%d", i + 1);
			DrawCircle(map[i].x, map[i].y, 30, GetColor(255, 0, 0), true);
		}
		DrawCircle(map[i].x, map[i].y, 20, GetColor(255, 255, 255), true);
	}

	return 0;
}
int MapSelectScene::Close() {
	return 0;
}


