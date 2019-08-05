#include"Chara.h"
#include"Unit.h"

Chara::Chara() {
	;
}

Chara::Chara(eRole _role, string _name, int  _hp, int  _str, int  _def, int  _mnd, int  _mdef,
	int _dex, int _agi, int _move, int  _exp, int  _lv) :Unit(_role,  _name, _hp,  _str,  _def,  _mnd,  _mdef, _dex,  _agi,  _move,  _exp,  _lv) {
	;
}

Chara:: ~Chara() {
	;
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
int Chara::Initialize(eRole _role, string _name, int _hp, int _str, int _def, int _mnd, int _mdef,
	int _dex, int _agi, int _move, int _exp, int _lv) {
	return 0;
}
int Chara::Update() {
	return 0;
}
int Chara::Draw() {
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