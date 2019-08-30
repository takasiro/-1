#include"Enemy.h"
#include"Unit.h"
Enemy::Enemy() {
	;
}

Enemy::Enemy(int _x, int _y) {
	mPos.x = _x;
	mPos.y = _y;
	mWidth = 64;
	mHeight = 64;
}

Enemy::Enemy( char* _name, eRole _role, int _hp, int _str, int _def, int _int, int _mnd,
	int _dex, int _agi, int _move, int _exp, int _lv) : Unit( _name, _role, _hp, _str, _def,  _int,  _mnd, _dex, _agi, _move, _exp, _lv) {
	;
}

Enemy:: ~Enemy() {
	;
}

int Enemy::Initialize() {
	return 0;
}

int Enemy::Initialize( char* _name, eRole _role, int _hp, int _str, int _def, int _int, int _mnd,
	int _dex, int _agi, int _move, int _exp, int _lv) {
	return 0;
}

int Enemy::Update() {
	mC.x = mPos.x * 64 + 64 / 2;
	mC.y = mPos.y * 64 + 64 / 2;
	return 0;
}

int Enemy::Draw() {
	DrawCircle(mC.x, mC.y, 32, GetColor(255, 0, 0));
	return 0;
}

int Enemy::Close() {
	return 0;
}

int Enemy::StatusUp(int lv) {
	return 0;
}

int Enemy::LastStatus() {
	return 0;
}