#pragma once
#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include"BaseTask.h"
#include"Mass.h"
#include"UnitMgr.h"
#include"Unit.h"
#include"fairy.h"



class Load :public BaseTask {
private:
	int mBaseHandle;
	int mGrowthHandle;
	int mFairyHandle;
	int mLoadtype;

	char input[256];

	char name[256];	//名前
	eRole	mRole;	//そのキャラの職業(成長値に偏りを出させるため)
	int mHp;		//体力
	int mStr;		//力(物理用)
	int mDef;		//防御(物理用)
	int mIntelli;		//魔力(魔法用)
	int mMnd;		//魔防(魔法用)
	int mDex;		//	命中
	int mAgi;		//回避
	int mMove;	//移動力

	int mRangeMin;  //最小攻撃範囲
	int mRangeMax;  //最大攻撃範囲

	double mGrowthHp;
	double mGrowthStr;
	double mGrowthDef;
	double mGrowthIntelli;
	double mGrowthMnd;
	double mGrowthDex;
	double mGrowthAgi;

public:
	Load() { Initialize(); };
	virtual ~Load() {};

	int LoadFile(int, char*);

	int LoadData(const char*, vector<Mass>&);  //マップロード関数 
	int LoadData(const char* _baseFilePath, const char* _growthFilePath, vector<Unit>& _unit);  //キャラクターステータスのロード関数 
	int LoadData(const char* _baseFilePath, const char* _growthFilePath);  //キャラクターステータスのロード関数 

	int LoadChara(int _baseHandle, int _growthHandle, vector<Unit>& _unit);
	int LoadChara(int _baseHandle, int _growthHandle, int _type);

	int LoadWeapon(int _baseHandle, int _growthHandle, vector<Unit>& _unit);
	int LoadWeapon(int _baseHandle, int _growthHandle,int _type);

	int Initialize();	//初期化処理
	int Update() { return 0; }		//計算処理
	int Draw() { return 0; }		//描画処理
	int Close() { return 0; }		//終了処理
};
