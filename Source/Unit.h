#pragma once
#include "Constant.h"
#include "Fairy.h"
#include "BaseObj.h"
#include <iostream>
using namespace std;
//キャラクターはこれを継承して作ります
class Fairy;
class Unit : public BaseObj
{
protected:
	eRole	mRole;	//そのキャラの職業(成長値に偏りを出させるため)
	string mName;	//名前
	int mHp;		//体力
	int mStr;		//力(物理用)
	int mDef;		//防御(物理用)
	int mInt;		//魔力(魔法用)
	int mMnd;		//魔防(魔法用)
	int mDex;		//	命中
	int mAgi;		//回避
	int mMove;	//移動力
	bool mStay;		//行動したかの判定
	int mLv;		//レベル
	int mExp;		//現在経験値
	Fairy* mEquipSlot;//妖精の装備枠

	//以下成長値として使用
	float GrowthHp;
	float GrowthStr;
	float GrowthDef;
	float GrowthInt;
	float GrowthMnd;
	float GrowthDex;
	float GrowthAgi;
	float GrowthMove;

public:
	Unit();
	Unit(eRole _role, string _name, int _hp, int _str, int _def, int _mnd, int _mdef,
		int _dex, int _agi, int _move, int _exp, int _lv);
	virtual ~Unit();

	Unit* GetUnit() { return this; }
	int Initialize();//初期化処理
	int Initialize(eRole _role, string _name, int _hp, int _str, int _def, int _mnd, int _mdef,
		int _dex, int _agi, int _move, int _exp, int _lv);	//初期化処理(引数付き)
	int Update();	//計算処理
	int Draw();		//描画処理
	int Close();	//終了処理
	int StatusUp(int lv);//レベルアップの能力変化


	int LastStatus();//武器補正含めた最終ステータス
	int SetFairy() {
		//バグるのでコメントアウト
		//mEquipSlot = new Fairy();
	}

};