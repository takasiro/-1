#include"Chara.h"
Chara::Chara() {
}

Chara::~Chara() {
	;
}

Chara::Chara(int _x, int _y) {
	mPos.x = _x*MASSSIZE;
	mPos.y = _y* MASSSIZE;
	mStayFlg = false;


}

//Chara::Chara(Unit) {
//	
//}
//
//Chara::Chara(Chara&) {
//	
//}

int Chara::Chara::Initialize() {
	return 0;
}
int Chara::Initialize(char* _name, eRole _role, int _hp, int _str, int _def, int _int, int _mnd,
	int _dex, int _agi, int _move, int _exp, int _lv) {

	return 0;
}
int Chara::Update() {
	mC.x = mPos.x * 64 + 64 / 2;
	mC.y = mPos.y * 64 + 64 / 2;
	if (mStayFlg == true) return 1;
	else return 0;
}
int Chara::Draw() {

	DrawBox(mPos.x, mPos.y, mPos.x+MASSSIZE,mPos.y+MASSSIZE, GetColor(0, 0, 255),true);
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

