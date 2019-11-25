#include"Fairy.h"
#include <iostream>
using namespace std;
Fairy::Fairy() {
	Initialize();
	SetRange(1, 2);
}


Fairy::Fairy(short _id, string _name, eRole _role, eWeapon _weapon, int _hp, int _str, int _def, int _int, int _mnd,
	int _dex, int _agi, int _move, int _exp, int _lv, int _minRange, int _maxRange) :Unit(_id, _name, _role, _weapon, _hp, _str, _def, _int, _mnd,
		_dex, _agi, _move, _exp, _lv) {
	mMaxRange = _maxRange;
	mMinRange = _minRange;
}

//Fairy::Fairy(Fairy* _tmp) {
//	;
//}

Fairy::~Fairy() {
	;
}

int Fairy::Initialize() {
	return 0;
}
int Fairy::Update() {
	return 0;
}

int Fairy::Draw() {
	return 0;
}

int Fairy::Close() {
	return 0;
}