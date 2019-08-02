#include "fairy.h"

fairy::fairy() {
	Initialize();
}
fairy::fairy(string *_name,int _damage, int _range, int _weight, int _magicdamage) {
	mName = _name;
	mDamage = _damage;
	mRange = _range;
	mWeight = _weight;
	mMagicDamage = _magicdamage;
}

fairy::~fairy() {
	;
}

int fairy::Initialize() {
	return 0;
}
int fairy::Update() {
	return 0;
}

int fairy::Draw() {
	return 0;
}

int fairy::Close() {
	return 0;
}