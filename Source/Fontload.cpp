#include "Fontcall.h"
#include <iostream>
using namespace std;
Fontcall::Fontcall() {
		Font[0] = CreateFontToHandle("HGä€∫ﬁºØ∏M-PRO", 20, 3, DX_FONTTYPE_ANTIALIASING_EDGE);
		Font[1] = CreateFontToHandle("ÉÅÉCÉäÉI", 20, 3, DX_FONTTYPE_ANTIALIASING_EDGE);
		Font[2] =  CreateFontToHandle("DragonQuestFC", 20, 3, DX_FONTTYPE_ANTIALIASING_EDGE);
}
Fontcall::~Fontcall() {
}
int Fontcall::Initialize() {
	return 0;
}
int Fontcall::Update() {
	return 0;
}
int Fontcall::Draw() {
	return 0;
}
int Fontcall::Close() {
	return 0;
}
int Fontcall::FontNum(int FontNum) {
	return Font[FontNum];
}