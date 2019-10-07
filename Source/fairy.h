#pragma once
#include <iostream>
using namespace std;
#include "Unit.h"
//武器のステータスのクラス

class Unit;
class Fairy :public  Unit {
protected:

	//char* mName;
	int mDamage;//武器の攻撃力
	int	mMagicDamage;//魔法攻撃力
	int	mMaxRange;//武器の最大攻撃範囲
	int	mMinRange;//武器の最小攻撃範囲

	//以下補正に使う
	int	mHp;		//体力
	int	mStr;		//力(物理用)
	int	mDef;		//防御(物理用)
	int	mInt;		//魔力(魔法用)
	int	mMnd;		//魔防(魔法用)
	int	mDex;		//	命中補正
	int	mAgi;		//回避補正
	int	mMove;		//移動力

	////以下成長値として使用
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
	Fairy(char* _name, eRole _role, int _hp, int _str, int _def, int _int, int _mnd,
		int _dex, int _agi, int _move, int _exp, int _lv);
	Fairy(char* _name, int _damage, int _minRange, int _maxRange, int _magicdamage);
	virtual ~Fairy();
	//Fairy& GetFairy() { return 0; }
	int Initialize();
	int Update();
	int Draw();
	int Close();



};