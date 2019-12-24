#pragma once
#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include"BaseObj.h"
#include"BaseTask.h"
#include"UnitMgr.h"
#include"Unit.h"
#include"fairy.h"
#include"Enemy.h"
#include"EquipDataBase.h"

class Equip :public BaseTask {

private:


public:
	Equip() { Initialize(); };
	virtual ~Equip() {};

	int Initialize();	//‰Šú‰»ˆ—
	int Update() { return 0; }		//ŒvZˆ—
	int Draw() { return 0; }		//•`‰æˆ—
	int Close() { return 0; }		//I—¹ˆ—
};