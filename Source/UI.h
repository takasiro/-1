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

	int Initialize() { return 0; }	//‰Šú‰»ˆ—
	int Update();	//ŒvZˆ—
	int Draw();		//•`‰æˆ—
	int Close() { return 0; }		//I—¹ˆ—
};
