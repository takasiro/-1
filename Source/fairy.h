#pragma once

#include "Constant.h"
#include"BaseObj.h"
#include <iostream>
using namespace std;
#include "Unit.h"
//武器のステータスのクラス


class Fairy :public BaseObj {
protected:

	string  mName;
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

	Fairy();
	Fairy(Fairy&) { ; }
	Fairy(string _name, int _damage, int _maxRange, int _minRange, int _magicdamage);
	virtual ~Fairy();
	Fairy* GetPlayer() { return this; }
	int Initialize();
	int Update();
	int Draw();
	int Close();



};