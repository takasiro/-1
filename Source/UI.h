#pragma once
#include<iostream>
using namespace std;

#include<string>
#include<vector>
#include"BaseObj.h"
#include"BaseTask.h"
#include"Mouse.h"
#include"Mass.h"
#include"UnitMgr.h"
#include"Unit.h"
#include"fairy.h"
#include"Enemy.h"

class UI :public BaseTask {
private:
	int num;
	vector<Chara*>* charaStatus;

public:
	UI() { Initialize(); };
	virtual ~UI() {};

	int DrawStatus();

	int Initialize() { return 0; }	//初期化処理
	int Update();	//計算処理
	int Draw();		//描画処理
	int Close() { return 0; }		//終了処理
};
