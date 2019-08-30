#pragma once
#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include"BaseTask.h"
#include"Mass.h"	
#include"Unit.h"



class Load :public BaseTask {
private:
	int baseHandle;
	int growthHandle;

	char input[256];

	char name[256];	//名前
	eRole	role;	//そのキャラの職業(成長値に偏りを出させるため)
	int hp;		//体力
	int str;		//力(物理用)
	int def;		//防御(物理用)
	int intelli;		//魔力(魔法用)
	int mnd;		//魔防(魔法用)
	int dex;		//	命中
	int agi;		//回避
	int move;	//移動力

	double gHp;
	double gStr;
	double gDef;
	double gIntelli;
	double gMnd;
	double gDex;
	double gAgi;

public:
	Load() {};
	virtual ~Load() {};

	int LoadFile(int, char*);

	int LoadData(const char*, vector<Mass>&);  //マップロード関数 

	int LoadData(const char* _baseFilePath, const char* _growthFilePath, vector<Unit>&);  //キャラクターステータスのロード関数 

	int Initialize() { return 0; }	//初期化処理
	int Update() { return 0; }		//計算処理
	int Draw() { return 0; }		//描画処理
	int Close() { return 0; }		//終了処理
};
