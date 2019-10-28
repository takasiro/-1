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
	typedef struct {
		string tank = "タンク";
		string caster = "キャスター";
		string ranger = "レンジャー";
		string fighter = "ファイター";
	}sRole;

	int playerNumber, enemyNumber;
	string role;
	sRole roleType;
	int NameFontHandle,DataFontHandle,StatusFontHandle;

public:
	UI() { Initialize(); };
	virtual ~UI() {};

	int DrawStatus(int _num);
	string RoleType(int _type);

	int Initialize();	//初期化処理
	int Update();	//計算処理
	int Draw();		//描画処理
	int Close() { return 0; }		//終了処理
};
