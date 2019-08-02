#include "Unit.h"

Unit::Unit() {
	Initialize();
}
Unit::Unit(eRole _role, string* _name, int _hp, int _str, int _def, int _ma, int _mdef,
	int _dex, int _agi, int _move, int _faction, int _nextexp, int _exp, int _lv) {
	Initialize(_role, _name, _hp, _str, _def, _ma, _mdef,_dex, _agi, _move, _faction, _nextexp, _exp, _lv);
}
int Unit::Initialize(eRole _role, string* _name, int _hp, int _str, int _def, int _ma, int _mdef,
	int _dex, int _agi, int _move, int _faction, int _nextexp, int _exp, int _lv) {
	mRole = _role;
	mName = _name;
	mHp = _hp;
	mStr = _str;
	mDef = _def;
	mMa = _ma;
	mDef = _mdef;
	mDex = _dex;
	mAgi = _agi;
	mMove = _move;
	mFaction = _faction;
	mNextExp = _nextexp;
	mExp = _exp;
	mLv = _lv;
	mStay = false;
}

Unit::~Unit() {
	;
}
int Unit::Initialize() {
	return 0;
}
int Unit::Update() {
	return 0;
}

int Unit::Draw() {
	return 0;
}

int Unit::Close() {
	return 0;
}

int Unit::StatusUp(int _lv) {
	return 0;
}

