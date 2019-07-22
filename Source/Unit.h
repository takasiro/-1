#pragma once
#include "Constant.h"
#include "BaseObj.h"
#include "Fairy.h"
#include <iostream>
using namespace std;
//キャラクターはこれを継承して作ります
class Unit : public BaseObj
{

protected:


	eRole	mRole;	//そのキャラの職業(成長値に偏りを出させるため)
	string *mName;	//名前
	int	mHp;		//体力
	int	mStr;		//力(物理用)
	int	mDef;		//防御(物理用)
	int	mInt;		//魔力(魔法用)
	int	mMnd;		//魔防(魔法用)
	int	mDex;		//	命中補正
	int	mAgi;		//回避補正
	int	mMove;		//移動力
	bool mStay;		//行動したかの判定
	int	mLv;		//レベル
	int	mExp;		//現在経験値
	Fairy* mEquipSlot;//妖精の装備枠

public:
	Unit();
	Unit(eRole _role, string* _name, int _hp, int _str, int _def, int _mnd, int _mdef,
		int _dex, int _agi, int _move,  int _exp, int _lv);
	virtual ~Unit();

	Unit* GetPlayer() { return this; }
	int Initialize();//初期化処理
	int Initialize(eRole _role, string* _name, int _hp, int _str, int _def, int _mnd, int _mdef,
		int _dex, int _agi, int _move, int _exp, int _lv);	//初期化処理(引数付き)
	int Update();	//計算処理
	int Draw();		//描画処理
	int Close();	//終了処理
	int StatusUp(int lv);//レベルアップの能力変化
	int	LastStatus();//武器補正含めた最終ステータス
	int SetFairy(Fairy _tmpfairy) {
		mEquipSlot = new Fairy(_tmpfairy);
	}

};