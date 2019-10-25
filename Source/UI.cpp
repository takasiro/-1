#include"UI.h"

int UI::Update() {
	BaseObj::sPos  tmp;
	num = INSTANCE->CulNum(tmp = GET_POSITION(), PLAYER);

	if (num != -1) {
		charaStatus = INSTANCE->GetCharaDate();
		DrawFormatString(0, 120, GetColor(255, 255, 255), "GetCharaDate", TRUE);
	}

	return 0;
}

int UI::Draw() {
	if(num!=-1)DrawStatus();
	DrawFormatString(0, 120, GetColor(255, 255, 255), "num:%d", num, TRUE);

	return 0;
}

int UI::DrawStatus() {
	DrawBox(0, 0, 500, 300, GetColor(180, 140, 220), true);
	//DrawFormatString(0, 160, GetColor(255, 255, 255), "ƒ|ƒWƒVƒ‡ƒ“x:%.0f y:%.0f", charaStatus[num].mPos.x TRUE);
	DrawFormatString(0, 160, GetColor(255, 255, 255), "‚Ó‚Ÿ‚¢‚½‚ë‚¤", TRUE);

	return 0;
}