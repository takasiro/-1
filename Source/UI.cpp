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
	DrawFormatString(0, 120, GetColor(255, 255, 255), "num:%d", num, TRUE);

	return 0;
}

int UI::DrawStatus() {
	return 0;
}