#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"Map.h"
#include"BaseTask.h"


class Load:public BaseTask {
private:

public:
	Load();
	virtual ~Load();

	void LoadMap(char*, vector<Mass>&);  //マップロード関数 

	int Initialize() { return 0; }	//初期化処理
	int Update() { return 0; }		//計算処理
	int Draw() { return 0; }		//描画処理
	int Close() { return 0; }		//終了処理
};
