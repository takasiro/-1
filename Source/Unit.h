#pragma once
#include "Constant.h"
#include "BaseObj.h"
#include <iostream>
using namespace std;
#include <vector>
//キャラクターはこれを継承して作ります
class Unit : public BaseObj
{
	//Fairy& operator = (Fairy _tmp) {
	//	return _tmp.GetFairy();
	//}

protected:

	bool mStayFlg;		//行動したかの判定 true 行動済み　false　行動前
	int mLv;		//レベル
	int mExp;		//現在経験値

	eRole	 mRole;		//そのキャラの職業(成長値に偏りを出させるため)
	char* mName;	//名前
	int mMaXHp;		//最大体力
	int mHp;			//体力
	int mStr;			//力(物理用)
	int mDef;			//防御(物理用)
	int mInt;			//魔力(魔法用)
	int mMnd;			//魔防(魔法用)
	int mDex;			//	命中
	int mAgi;			//回避
	int mMove;		//移動力

	//以下成長値として使用
	float mGrowthHp;
	float mGrowthStr;
	float mGrowthDef;
	float mGrowthInt;
	float mGrowthMnd;
	float mGrowthDex;
	float mGrowthAgi;
	float mGrowthMove;

public:
	Unit();
	Unit(char* _name, eRole _role, int _hp, int _str, int _def, int _int, int _mnd,
		int _dex, int _agi, int _move, int _exp, int _lv);
	virtual ~Unit();

	Unit* GetUnit() { return this; }
	int Initialize();//初期化処理
	int Initialize(char* _name, eRole _role, int _hp, int _str, int _def, int _int, int _mnd,
		int _dex, int _agi, int _move, int _exp, int _lv);	//初期化処理(引数付き)
	virtual int SetGrowth(int _hp, int _str, int _def, int _int, int _mnd, int _dex, int _agi);  //成長値
	int Update();	//計算処理
	int Draw();		//描画処理
	int Close();	//終了処理
	virtual int StatusUp(int lv);//レベルアップの能力変化
	int LastStatus();//武器補正含めた最終ステータス

	bool GetStayFlg() { return mStayFlg; }

};