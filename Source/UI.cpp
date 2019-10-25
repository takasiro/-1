#include"UI.h"

int UI::Update() {
	BaseObj::sPos  tmp;
	num = INSTANCE->CulNum(tmp = GET_POSITION(), PLAYER);

	return 0;
}

int UI::Draw() {
	if (num != -1)DrawStatus();
	DrawFormatString(0, 120, GetColor(255, 255, 255), "num:%d", num, TRUE);

	return 0;
}

int UI::DrawStatus() {
	vector<Chara*>& charaStatus = INSTANCE->GetCharaDate();
	DrawBox(0, 0, 500, 300, GetColor(180, 140, 220), true);
	DrawFormatString(0, 160, GetColor(255, 255, 255), "‚Ó‚Ÿ‚¢‚½‚ë‚¤:%d", charaStatus[0]->GetLv(), TRUE);

	return 0;
}