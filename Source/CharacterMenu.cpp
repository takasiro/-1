#include "CharacterMenu.h"


Chara CharacterMenu::chara;

int dummy(int _num) { return 0; }
int SelectChara(int _num) {
	CharacterMenu::SetCharaData(UnitMgr::Instance()->GetCharaDateC(_num));
	return 0;
}

CharacterMenu::CharacterMenu()
{
}

CharacterMenu::CharacterMenu(ISceneChanger* _Changer) :BaseScene(_Changer) {
	Load load;
	load.LoadData("../Resource/Status/PlayerBaseStatus.csv", "../Resource/Status/PlayerGrowthStatus.csv");
	load.LoadData("../Resource/Status/EnemyBaseStatus.csv", "../Resource/Status/EnemyGrowthStatus.csv");


	for (int i = 0; i < 8; i++) {
		test[i].SetPosY(i * 105 + 120);
		test[i].SetPosX(20);
		test[i].SetOnClick(&SelectChara);
		test[i].SetMyNum(i);
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
	DrawFormatString(400, 100, GetColor(255, 255, 255), "%s", chara.GetName().c_str());
	DrawFormatString(400, 140, GetColor(255, 255, 255), "LV : %d", chara.GetLv());
	DrawFormatString(500, 140, GetColor(255, 255, 255), "EXP : 0");
	DrawFormatString(400, 180, GetColor(255, 255, 255), "HP : %d", chara.GetHp());
	DrawFormatString(500, 180, GetColor(255, 255, 255), "/ %d",chara.GetMaxHp());
	DrawFormatString(400, 220, GetColor(255, 255, 255), "ƒ[ƒ‹ : %d", chara.GetRole());

	DrawFormatString(400, 300, GetColor(255, 255, 255), "—Í : %d", chara.GetStr());
	DrawFormatString(500, 300, GetColor(255, 255, 255), "–‚—Í : %d", chara.GetInt());
	DrawFormatString(400, 340, GetColor(255, 255, 255), "–hŒä : %d", chara.GetDef());
	DrawFormatString(500, 340, GetColor(255, 255, 255), "–‚–h : %d", chara.GetMnd());
	DrawFormatString(400, 380, GetColor(255, 255, 255), "‹Z—Ê : %d", chara.GetDex());
	DrawFormatString(500, 380, GetColor(255, 255, 255), "‘¬‚³ : %d", chara.GetAgi());
	DrawFormatString(400, 420, GetColor(255, 255, 255), "ˆÚ“® : %d", chara.GetMoveRange());





	return 0;
}
int CharacterMenu::Close() {
	return 0;
}

