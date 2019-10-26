#include"UI.h"
int UI::Initialize() {
	playerNumber = 0, enemyNumber = 0;
	role = "ノージョブ";
	NameFontHandle = CreateFontToHandle(NULL, 35, 4);
	DataFontHandle = CreateFontToHandle(NULL, 25, 2);
	StatusFontHandle = CreateFontToHandle(NULL, 20, 4);
	return 0;
}

int UI::Update() {
	BaseObj::sPos  tmp;
	playerNumber = INSTANCE->CulNum(tmp = GET_POSITION(), PLAYER);

	return 0;
}

int UI::Draw() {
	if (playerNumber != -1)DrawStatus(playerNumber);

	#ifdef DEBUG
	DrawFormatString(0, 300, GetColor(255, 255, 255), "num:%d", playerNumber, TRUE);
	#endif

	return 0;
}

int UI::DrawStatus(int _num) {
	vector<Chara*>& charaStatus = INSTANCE->GetCharaDate();
	string tmpName = charaStatus[_num]->GetName();
	int tmpRole = charaStatus[_num]->GetRole();
	role=RoleType(tmpRole);


	//ステータス表示
	DrawBox(0, 0, 400, 250, GetColor(180, 140, 220), true);
	DrawFormatStringToHandle(10, 20, GetColor(255, 255, 255),NameFontHandle, "%s", tmpName.c_str());
	DrawFormatStringToHandle(10, 60, GetColor(255, 255, 255),DataFontHandle, "%s",role.c_str(),TRUE);
	DrawFormatStringToHandle(15, 90, GetColor(255, 255, 255),StatusFontHandle, "EXP:%d",00, TRUE);
	DrawFormatStringToHandle(15, 120, GetColor(255, 255, 255),DataFontHandle, "Lv.%d", charaStatus[_num]->GetLv(), TRUE);
	DrawFormatStringToHandle(100, 120, GetColor(255, 255, 255), DataFontHandle,"HP:%d/%d", charaStatus[_num]->GetStr(), charaStatus[_num]->GetStr(), TRUE);
	DrawFormatStringToHandle(15, 150, GetColor(255, 255, 255), StatusFontHandle,"攻撃:%d", charaStatus[_num]->GetStr(), TRUE);
	DrawFormatStringToHandle(120, 150, GetColor(255, 255, 255), StatusFontHandle, "防御:%d", charaStatus[_num]->GetDef(), TRUE);
	DrawFormatStringToHandle(15,  180, GetColor(255, 255, 255), StatusFontHandle, "魔法:%d", charaStatus[_num]->GetInt(), TRUE);
	DrawFormatStringToHandle(120, 180, GetColor(255, 255, 255), StatusFontHandle, "魔防:%d", charaStatus[_num]->GetMnd(), TRUE);
	DrawFormatStringToHandle(15,  210, GetColor(255, 255, 255), StatusFontHandle, "器用さ:%d", charaStatus[_num]->GetDex(), TRUE);
	DrawFormatStringToHandle(120, 210, GetColor(255, 255, 255), StatusFontHandle, "素早さ:%d", charaStatus[_num]->GetAgi(), TRUE);

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

