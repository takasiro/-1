#pragma once
#include <iostream>
using namespace std;
#include "Unit.h"
//ํฬXe[^XฬNX


class Fairy :public  Unit {
protected:
	bool mWeaponFlg;//ก๛pฉGpปฬป่@falseG trueก๛
	//char* mName;
	int	mMaxRange;//ํฬลๅUออ
	int	mMinRange;//ํฬลฌUออ

	////ศบโณษgค
	//int	mHp;		//ฬอ
	//int	mStr;		//อ(จp)
	//int	mDef;		//hไ(จp)
	//int	mInt;		//อ(@p)
	//int	mMnd;		//h(@p)
	//int	mDex;		//	ฝโณ
	//int	mAgi;		//๑๐โณ
	//int	mMove;		//ฺฎอ

	//////ศบฌทlฦตฤgp
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
	Fairy(short _id, string _name, eRole _role, eWeapon _weapon, int _hp, int _str, int _def, int _int, int _mnd,
		int _dex, int _agi, int _move, int _exp, int _lv, char* _filePath, int _minRange, int _maxRange);
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