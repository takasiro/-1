#pragma once
#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include"BaseObj.h"
#include"BaseTask.h"
#include"Mass.h"
#include"UnitMgr.h"
#include"Unit.h"
#include"fairy.h"
#include"Enemy.h"



class Load :public BaseTask {
private:
	//ファイルハンドル
	int mBaseHandle;
	int mGrowthHandle;
	int mFairyHandle;
	int mLoadtype;

	char input[256];

	//ステータス情報
	short mId;  //ID
	string mName;	  //名前
	eRole mRole;		  //そのキャラの職業(成長値に偏りを出させるため)
	int mHp;			  //体力
	int mStr;			  //力(物理用)
	int mDef;			  //防御(物理用)
	int mIntelli;		  //魔力(魔法用)
	int mMnd;			  //魔防(魔法用)
	int mDex;			  //命中
	int mAgi;			  //回避
	int mMove;			  //移動力
	char mFilePath[256];  //画像のファイルパス
	char* dummyFilePath;		  //画像ファイルパスがなかった時用のダミーファイルパス

	int mRangeMin;  //最小攻撃範囲
	int mRangeMax;  //最大攻撃範囲

	float mGrowthHp;
	float mGrowthStr;
	float mGrowthDef;
	float mGrowthIntelli;
	float mGrowthMnd;
	float mGrowthDex;
	float mGrowthAgi;

	vector<Enemy*> mEnemyMasterData;  //Enemyのマスターデータ

	BaseObj::sPos mInitPlayerPos[8];
	BaseObj::sPos mInitEnemyPos[8];

public:
	Load() { Initialize(); };
	virtual ~Load() {};

	int LoadFile(int, char*);

	int LoadData(const char* _filePath, vector<Mass>& _mass, const char* _PosFilePath);  //マップロード関数
	int LoadData(const char* _baseFilePath, const char* _growthFilePath);  //キャラクターステータスのロード関数 

	int LoadChara(int _baseHandle, int _growthHandle);
	int LoadEnemy(int _baseHandle,int _growthHandle);
	int LoadWeapon(int _baseHandle, int _growthHandle);

	vector<Enemy*>& GetEnemyMasterData() { return mEnemyMasterData; }

	int SetEnemyData();

	int Initialize();	//初期化処理
	int Update() { return 0; }		//計算処理
	int Draw() { return 0; }		//描画処理
	int Close() { return 0; }		//終了処理
};
