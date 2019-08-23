#include "Unit.h"

Unit::Unit() {
	Initialize();
}
Unit::Unit(eRole _role, char* _name, int _hp, int _str, int _def, int _int, int _mnd,
	int _dex, int _agi, int _move, int _exp, int _lv) {
	Initialize(_role, _name, _hp, _str, _def, _int, _mnd, _dex, _agi, _move, _exp, _lv);
}
int Unit::Initialize(eRole _role, char* _name, int _hp, int _str, int _def, int _int, int _mnd,
	int _dex, int _agi, int _move, int _exp, int _lv) {
	mRole = _role;
	mName = _name;
	mHp = _hp;
	mStr = _str;
	mDef = _def;
	mInt = _int;
	mMnd = _mnd;
	mDex = _dex;
	mAgi = _agi;
	mMove = _move;
	mExp = _exp;
	mLv = _lv;
	mStay = false;
	return 0;
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

int Unit::LastStatus() {
	return 0;
}

