#pragma once
#include"BaseTask.h"
#include<vector>
using namespace std;
class MapSelect :public BaseTask {
private:
	//マップ表示用の座標
	vector<vector<int>>mPos;
	int nowMap;

	virtual int Initialize() { ; }	//初期化処理
	virtual int Update() { ; }		//計算処理
	virtual int Draw() { ; }			//描画処理
	virtual int Close() { ; }		//終了処理
	int Select();//クリックされたときに起動
	int ChangeMap(int _num);

};