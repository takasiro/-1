#include "CharacterMenu.h"
#include "Fontcall.h"

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
	//Fontcall Fontcall;
	for (int i = 0; i < 8; i++) {
		test[i].Draw();
	}
	DrawFormatStringToHandle(400, 100, GetColor(255, 255, 255), mFontcall.FontNum(0), "%s", chara.GetName().c_str());
	DrawFormatStringToHandle(400, 140, GetColor(255, 255, 255), mFontcall.FontNum(0), "LV : %d",chara.GetLv());
	DrawFormatStringToHandle(500, 140, GetColor(255, 255, 255), mFontcall.FontNum(0), "EXP : 0");
	DrawFormatStringToHandle(400, 180, GetColor(255, 255, 255), mFontcall.FontNum(0), "HP : %d", chara.GetHp());
	DrawFormatStringToHandle(500, 180, GetColor(255, 255, 255), mFontcall.FontNum(0), "/ %d", chara.GetMaxHp());
	DrawFormatStringToHandle(400, 220, GetColor(255, 255, 255), mFontcall.FontNum(0), "ƒ[ƒ‹ : %d", chara.GetRole());

	DrawFormatStringToHandle(400, 300, GetColor(255, 255, 255), mFontcall.FontNum(0), "—Í : %d", chara.GetStr());
	DrawFormatStringToHandle(500, 300, GetColor(255, 255, 255), mFontcall.FontNum(0), "–‚—Í : %d", chara.GetInt());
	DrawFormatStringToHandle(400, 340, GetColor(255, 255, 255), mFontcall.FontNum(0), "–hŒä : %d", chara.GetDef());
	DrawFormatStringToHandle(500, 340, GetColor(255, 255, 255), mFontcall.FontNum(0), "–‚–h : %d", chara.GetMnd());
	DrawFormatStringToHandle(400, 380, GetColor(255, 255, 255), mFontcall.FontNum(0), "‹Z—Ê : %d", chara.GetDex());
	DrawFormatStringToHandle(500, 380, GetColor(255, 255, 255), mFontcall.FontNum(0), "‘¬‚³ : %d", chara.GetAgi());
	DrawFormatStringToHandle(400, 420, GetColor(255, 255, 255), mFontcall.FontNum(0), "ˆÚ“® : %d", chara.GetMoveRange());





	return 0;
}
int CharacterMenu::Close() {
	return 0;
}

