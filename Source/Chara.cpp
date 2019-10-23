#include"Chara.h"
Chara::Chara() {
}
Chara::Chara(char* _name, eRole _role, int _hp, int _str, int _def, int _int, int _mnd,
	int _dex, int _agi, int _move, int _exp, int _lv) :Unit(_name, _role, _hp, _str, _def, _int, _mnd,
		_dex, _agi, _move, _exp, _lv) {
	/*mColor = GetColor(0, 0, 255);
	mGrHandlesCount = 12;
	mGrHandles = new int[mGrHandlesCount];
	LoadDivGraph("../Resource/Image/Player/Chara00.png", 12, 3, 4, 64, 64, mGrHandles);
*/
	SetFairy(Fairy(), 0);
}
Chara::~Chara() {
	DeleteGraph(mGrHandle);
}

Chara::Chara(int _x, int _y) {
	mPos.x = _x ;
	mPos.y = _y ;
	SetPos(mPos);
	SetFairy(Fairy(), 0);//フェアリー適当に生成
	mMove = 4;
	mStayFlg = false;
	mOnActive = true; 
	mColor = GetColor(0, 0, 255);
	mGrHandlesCount = 12;
	mGrHandles = new int[mGrHandlesCount];
	LoadDivGraph("../Resource/Image/Player/Chara00.png", 12, 3, 4, 64, 64, mGrHandles);
}

//Chara::Chara(Unit) {
//	
//}
//
//Chara::Chara(Chara&) {
//	
//}

int Chara::Initialize() {
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
	if (mStayFlg == false)mColor = GetColor(0, 0, 255);
		else mColor = GetColor(150, 150, 150);
	//if(mGrHandle == -1)DrawBox(mPos.x, mPos.y, mPos.x + MASSSIZE, mPos.y + MASSSIZE, mColor, true);
	 //else LoadGraphScreen(mPos.x, mPos.y,"../Resource/Image/Map/map1.png",false);
	 DrawGraph(mPos.x, mPos.y, mGrHandles[3],FALSE);
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

int Chara::Move(int _x, int _y) {
	mPos.x = _x;
	mPos.y = _y;
	//ステイフラグは一時的な処理
	if (mStayFlg == false) {
		mStayFlg = true;
		mColor = GetColor(150, 150, 150);
	}
	else {
		mStayFlg = false;
		mColor = GetColor(0, 0, 255);
	}
	return 0;
}


