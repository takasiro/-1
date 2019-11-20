#pragma once
#include <iostream>
using namespace std;
#include "Unit.h"
//武器のステータスのクラス

class Unit;
class Fairy :public  Unit {
protected:
	bool mWeaponFlg;//味方用か敵用化の判定　false敵 true味方
	//char* mName;
	int	mMaxRange;//武器の最大攻撃範囲
	int	mMinRange;//武器の最小攻撃範囲

	////以下補正に使う
	//int	mHp;		//体力
	//int	mStr;		//力(物理用)
	//int	mDef;		//防御(物理用)
	//int	mInt;		//魔力(魔法用)
	//int	mMnd;		//魔防(魔法用)
	//int	mDex;		//	命中補正
	//int	mAgi;		//回避補正
	//int	mMove;		//移動力

	//////以下成長値として使用
	//float GrowthHp;
	//float GrowthStr;
	//float GrowthDef;
	//float GrowthInt;
	//float GrowthMnd;
	//float GrowthDex;
	//float GrowthAgi;
	//float GrowthMove;

public:

	Fairy();
	//Fairy(Fairy* _tmp);
	Fairy(short _id,string _name, eRole _role, int _hp, int _str, int _def, int _int, int _mnd,
		int _dex, int _agi, int _move, int _exp, int _lv, int _minRange, int _maxRange);
	void SetRange(int _minRange, int _maxRange) { mMinRange = _minRange; mMaxRange = _maxRange; }
	virtual ~Fairy();
	//Fairy& GetFairy() { return 0; }
	int Initialize();
	int Update();
	int Draw();
	int Close();

	int GetRange() {
		//if(mRole !=)
	//	return mMaxRange - mMinRange;
		return mMinRange;
	}

};