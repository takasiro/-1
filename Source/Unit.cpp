#include "Unit.h"
#include "Fairy.h"
Unit::Unit() {
	Initialize();
}
Unit::Unit(int _lv){
	mLv = _lv;
	AdjustStatus();

}
Unit::Unit(short _id, string _name, eRole _role, eWeapon _weapon, int _hp, int _str, int _def, int _int, int _mnd,
	int _dex, int _agi, int _move, int _exp, int _lv, char* _filePath) {
	Initialize(_id, _name, _role, _weapon, _hp, _str, _def, _int, _mnd, _dex, _agi, _move, _exp, _lv, _filePath);
}
int Unit::Initialize(short _id, string _name, eRole _role, eWeapon _weapon, int _hp, int _str, int _def, int _int, int _mnd,
	int _dex, int _agi, int _move, int _exp, int _lv, char* _filePath) {
	mId = _id;
	mRole = _role;
	mWeaponType = _weapon;
	mName = _name;
	mHp = mBaseHp = _hp;
	mMaXHp = mBaseMaXHp = mHp;
	mStr = mBaseStr = _str;
	mDef = mBaseDef = _def;
	mInt = mBaseInt = _int;
	mMnd = mBaseMnd = _mnd;
	mDex = mBaseDex = _dex;
	mAgi = mBaseAgi = _agi;
	mMove = mBaseMove = _move;
	mExp = _exp;
	mLv = _lv;
	mStayFlg = false;
	mMapPos.x = mPos.x / MASSSIZE;
	mMapPos.y = mPos.y / MASSSIZE;
	strcpy(mGrFilePath, _filePath);
	mHpColor = GetColor(0, 255, 0);
	mDirCount = eDOWN;
	mAnimCount = 0;
	mAnimNum = 0;
	mDir = eDOWN;
	return 0;
}

int Unit::SetGrowth(float _hp, float _str, float _def, float _int, float _mnd, float _dex, float _agi) {
	mGrowthHp = _hp;
	mGrowthStr = _str;
	mGrowthDef = _def;
	mGrowthInt = _int;
	mGrowthMnd = _mnd;
	mGrowthDex = _dex;
	mGrowthAgi = _agi;
	AdjustStatus();
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
int Unit::Move(int _dir) {
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
int Unit::Move(int _x, int _y) {
	return 0;
}




