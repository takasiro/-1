#include"Fairy.h"
#include <iostream>
using namespace std;
Fairy::Fairy() {
	Initialize();
}
Fairy::Fairy(char* _name, int _damage, int _maxRange, int _minRange, int _magicdamage) {
	mName = _name;
	mDamage = _damage;
	mMaxRange = _maxRange;
	mMinRange = _minRange;
	mMagicDamage = _magicdamage;
}

Fairy::Fairy(Fairy* _tmp) {
	;
}

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