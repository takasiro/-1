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
	DrawFormatString(0, 140, GetColor(255, 255, 255), "�t�@�C�^���ELv:%d", charaStatus[num]->GetLv(), TRUE);
	DrawFormatString(0, 180, GetColor(255, 255, 255), "�t�@�C�^���EStr:%d", charaStatus[num]->GetStr(), TRUE);
	DrawFormatString(0, 200, GetColor(255, 255, 255), "�t�@�C�^���EDef:%d", charaStatus[num]->GetDef(), TRUE);
	DrawFormatString(0, 220, GetColor(255, 255, 255), "�t�@�C�^���EInt:%d", charaStatus[num]->GetInt(), TRUE);
	DrawFormatString(0, 240, GetColor(255, 255, 255), "�t�@�C�^���EMnd:%d", charaStatus[num]->GetMnd(), TRUE);
	DrawFormatString(0, 260, GetColor(255, 255, 255), "�t�@�C�^���EDex:%d", charaStatus[num]->GetDex(), TRUE);

	return 0;
}