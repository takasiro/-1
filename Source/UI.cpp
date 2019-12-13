#include"UI.h"
int UI::Initialize() {
	playerNumber = 0, enemyNumber = 0;
	role = "ƒm[ƒWƒ‡ƒu";
	NameFontHandle = CreateFontToHandle(NULL, 35, 4);
	DataFontHandle = CreateFontToHandle(NULL, 25, 2);
	StatusFontHandle = CreateFontToHandle(NULL, 20, 4);
	return 0;
}

int UI::Update() {
	BaseObj::sPos  tmp;
	playerNumber = INSTANCE->CulNum(tmp = GET_POSITION(), PLAYER,2);
	enemyNumber = INSTANCE->CulNum(tmp = GET_POSITION(), ENEMY,2);

	return 0;
}

int UI::Draw() {
	if (playerNumber != -1)DrawCharaStatus(playerNumber);
	if (enemyNumber != -1)DrawEnemyStatus(enemyNumber);


	#ifdef DEBUG
	DrawFormatString(0, 300, GetColor(255, 255, 255), "num:%d", playerNumber, TRUE);
	DrawFormatString(0, 320, GetColor(255, 255, 255), "num:%d", enemyNumber, TRUE);
	#endif

	return 0;
}

int UI::DrawCharaStatus(int _num) {
	vector<Chara*>& charaStatus = INSTANCE->GetCharaDate();
	string tmpName = charaStatus[_num]->GetName();
	int tmpRole = charaStatus[_num]->GetRole();
	role=RoleType(tmpRole);


	//ƒXƒe[ƒ^ƒX•\Ž¦
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
	DrawBox(0, 0, 400, 250, GetColor(180, 140, 220), true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	DrawFormatStringToHandle(10, 20, GetColor(255, 255, 255),NameFontHandle, "%s", tmpName.c_str());
	DrawFormatStringToHandle(10, 60, GetColor(255, 255, 255),DataFontHandle, "%s",role.c_str(),TRUE);
	DrawFormatStringToHandle(15, 90, GetColor(255, 255, 255),StatusFontHandle, "EXP:%d",00, TRUE);
	DrawFormatStringToHandle(15, 120, GetColor(255, 255, 255),DataFontHandle, "Lv.%d", charaStatus[_num]->GetLv(), TRUE);
	DrawFormatStringToHandle(100, 120, GetColor(255, 255, 255), DataFontHandle, "HP:%d/%d", charaStatus[_num]->GetHp(), charaStatus[_num]->GetMaxHp(), TRUE);
	DrawFormatStringToHandle(15, 150, GetColor(255, 255, 255), StatusFontHandle,"UŒ‚:%d", charaStatus[_num]->GetStr(), TRUE);
	DrawFormatStringToHandle(120, 150, GetColor(255, 255, 255), StatusFontHandle, "–hŒä:%d", charaStatus[_num]->GetDef(), TRUE);
	DrawFormatStringToHandle(15,  180, GetColor(255, 255, 255), StatusFontHandle, "–‚–@:%d", charaStatus[_num]->GetInt(), TRUE);
	DrawFormatStringToHandle(120, 180, GetColor(255, 255, 255), StatusFontHandle, "–‚–h:%d", charaStatus[_num]->GetMnd(), TRUE);
	DrawFormatStringToHandle(15,  210, GetColor(255, 255, 255), StatusFontHandle, "Ší—p‚³:%d", charaStatus[_num]->GetDex(), TRUE);
	DrawFormatStringToHandle(120, 210, GetColor(255, 255, 255), StatusFontHandle, "‘f‘‚³:%d", charaStatus[_num]->GetAgi(), TRUE);

	return 0;
}

int UI::DrawEnemyStatus(int _num) {
	vector<Enemy*>& enemyStatus = INSTANCE->GetEnemyDate();
	string tmpName = enemyStatus[_num]->GetName();
	int tmpRole = enemyStatus[_num]->GetRole();
	role = RoleType(tmpRole);

	//ƒXƒe[ƒ^ƒX•\Ž¦
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
	DrawBox(0, 0, 400, 250, GetColor(180, 140, 220), true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	DrawFormatStringToHandle(10, 20, GetColor(255, 255, 255), NameFontHandle, "%s", tmpName.c_str());
	DrawFormatStringToHandle(10, 60, GetColor(255, 255, 255), DataFontHandle, "%s", role.c_str(), TRUE);
	DrawFormatStringToHandle(15, 90, GetColor(255, 255, 255), StatusFontHandle, "EXP:%d", 00, TRUE);
	DrawFormatStringToHandle(15, 120, GetColor(255, 255, 255), DataFontHandle, "Lv.%d", enemyStatus[_num]->GetLv(), TRUE);
	DrawFormatStringToHandle(100, 120, GetColor(255, 255, 255), DataFontHandle, "HP:%d/%d", enemyStatus[_num]->GetMaxHp(), enemyStatus[_num]->GetHp(), TRUE);
	DrawFormatStringToHandle(15, 150, GetColor(255, 255, 255), StatusFontHandle, "UŒ‚:%d", enemyStatus[_num]->GetStr(), TRUE);
	DrawFormatStringToHandle(120, 150, GetColor(255, 255, 255), StatusFontHandle, "–hŒä:%d", enemyStatus[_num]->GetDef(), TRUE);
	DrawFormatStringToHandle(15, 180, GetColor(255, 255, 255), StatusFontHandle, "–‚–@:%d", enemyStatus[_num]->GetInt(), TRUE);
	DrawFormatStringToHandle(120, 180, GetColor(255, 255, 255), StatusFontHandle, "–‚–h:%d", enemyStatus[_num]->GetMnd(), TRUE);
	DrawFormatStringToHandle(15, 210, GetColor(255, 255, 255), StatusFontHandle, "Ší—p‚³:%d", enemyStatus[_num]->GetDex(), TRUE);
	DrawFormatStringToHandle(120, 210, GetColor(255, 255, 255), StatusFontHandle, "‘f‘‚³:%d", enemyStatus[_num]->GetAgi(), TRUE);

	return 0;
}


string UI::RoleType(int _type) {
	switch (_type) {
	case eTank: return roleType.tank; break;
	case eCaster: return roleType.caster; break;
	case eRanger: return roleType.ranger; break;
	case eFighter: return roleType.fighter;  break;
	}
}

