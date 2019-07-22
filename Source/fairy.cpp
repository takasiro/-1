#include"Fairy.h"
#include <iostream>
using namespace std;
Fairy::Fairy() {
	Initialize();
}
Fairy::Fairy(string _name, int _damage, int _range, int _magicdamage) {
	mName = _name;
	mDamage = _damage;
	mRange = _range;
	mMagicDamage = _magicdamage;
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