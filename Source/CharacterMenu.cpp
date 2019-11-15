#include "CharacterMenu.h"


Chara CharacterMenu::chara;

int dummy(int _num) { return 0; }
int SelectChara(int _num) {
	CharacterMenu::SetCharaData(UnitMgr::Instance()->GetCharaDate(_num));
	return 0;
}

CharacterMenu::CharacterMenu()
{
}

CharacterMenu::CharacterMenu(ISceneChanger* _Changer) :BaseScene(_Changer) {
	for (int i = 0; i < 8; i++) {
		test[i].SetPosY(i * 105 + 120);
		test[i].SetPosX(20);
		test[i].SetOnClick(&SelectChara);
	}
	
}


CharacterMenu::~CharacterMenu()
{
}


int CharacterMenu::Initialize() {
	return 0;
}
int CharacterMenu::Update() {
	for (int i = 0; i < 8; i++) {
		test[i].Update();
	}
	return 0;
}
int CharacterMenu::Draw() {
	for (int i = 0; i < 8; i++) {
		test[i].Draw();
	}
	return 0;
}
int CharacterMenu::Close() {
	return 0;
}

