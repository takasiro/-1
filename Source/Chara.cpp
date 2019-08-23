#include"Chara.h"
#include"Unit.h"

Chara::Chara() {
	;
}

Chara::~Chara() {
	;
}

Chara::Chara(int _x, int _y) {
	mPos.x = _x;
	mPos.y = _y;
	mWidth = 64;
	mHeight = 64;
	
	
}

Chara::Chara(Unit) {
	;
}

Chara::Chara(Chara&) {
	;
}

int Chara::Chara::Initialize() {
	return 0;
}
int Chara::Initialize(eRole _role, char* _name, int _hp, int _str, int _def, int _mnd, int _mdef,
	int _dex, int _agi, int _move, int _exp, int _lv) {

	return 0;
}
int Chara::Update() {
	mC.x = mPos.x * 64+64/2;
	mC.y = mPos.y * 64 + 64 / 2;
	return 0;
}
int Chara::Draw() {

	DrawCircle(mC.x,mC.y,32,GetColor(255,255,255));
	return 0;
}
int Chara::Close() {
	return 0;
}
int Chara::StatusUp(int lv) {
	return 0;
}
int Chara::LastStatus() {
	return 0;
}