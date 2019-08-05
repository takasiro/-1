#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"Map.h"
#include"Unit.h"	
#include"BaseTask.h"


class Load:public BaseTask {
private:

public:
	Load() {};
	virtual ~Load(){};

	//void LoadData(const char*,char*);
	void LoadData(int,char*);

	int LoadMap(const char*, vector<Mass>&);  //マップロード関数 
	
	void PlayerBase(char*, vector<Unit>&);  //キャラクターステータスのロード関数 
	//void PlayerGrowth(char*, vector<Unit>&);  //キャラクター成長値のロード
	
	void FairyBase();
	void FairyGrowth();

	int Initialize() { return 0; }	//初期化処理
	int Update() { return 0; }		//計算処理
	int Draw() { return 0; }		//描画処理
	int Close() { return 0; }		//終了処理
};
