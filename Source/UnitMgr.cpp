#include "UnitMgr.h"

UnitMgr::UnitMgr() {
	prevPos = { 0 };
	mousePos = { 0 };
	mapPos = { 0 };
	mState = 0;
	mouseButton = 0;
	lastMouseButton = 0;
	color = GetColor(255, 255, 225);
	Fanctions[0] = &UnitMgr::MoveJudgeState;
	Fanctions[1] = &UnitMgr::MoveState;
	Fanctions[2] = &UnitMgr::AttackJudgeState;
	Fanctions[3] = &UnitMgr::AttackState;

}
UnitMgr::~UnitMgr() {
	;
}
int UnitMgr::Initialize() {
	INSTANCE->cul.Initialize();
	lastMouseButton = 0;
	mouseButton = 0;
	mState = 0;
	mousePos = { 0,0 };
	mapPos = { 0,0 };
	return 0;
}
int UnitMgr::Update() {
	for (int i = 0; i < CharaDate.size(); i++) {
		if (CharaDate[i]->GetStayFlg() == true)continue;
		CharaDate[i]->Update();
	}
	for (int i = 0; i < EnemyDate.size(); i++) {
		EnemyDate[i]->Update();
	}
	return 0;
}
int UnitMgr::MoveJudgeState(int _a) {
	if (_a == -1)return _a;
	if (mState < -1)return mState = -1;
	//Initialize();
	cul.CulMoveRange(prevPos.x = CharaDate[_a]->GetPosX() / MASSSIZE, prevPos.y = CharaDate[_a]->GetPosY() / MASSSIZE, CharaDate[_a]->GetMoveRange());
	cul.MoveJudg(GetCharaDate(), GetEnemyDate(), _a);
	color = GetColor(0, 0, 255);
	mState += 1;
	return mState;
}

int UnitMgr::MoveState(int _a) {

	if (RIGHTCLICK != FALSE && mouseButton != lastMouseButton) {
		Initialize();
		mState -= 1;
	}
	if (LEFTCLICK != FALSE && mouseButton != lastMouseButton) {
		mousePos = GET_POSITION();
		mapPos = GET_POSITION();
		mapPos.x /= MASSSIZE;
		mapPos.y /= MASSSIZE;
		if (cul.GetMoveArea(mapPos.x, mapPos.y) == 1) {
			CharaDate[_a]->Move((int)mapPos.x * MASSSIZE, (int)mapPos.y * MASSSIZE);
			CharaDate[_a]->Update();
			INSTANCE->cul.Initialize();
			return mState++;
		}
	}
}

int UnitMgr::AttackJudgeState(int _a) {
	INSTANCE->cul.CulMoveRange(CharaDate[_a]->GetPosX() / MASSSIZE, CharaDate[_a]->GetPosY() / MASSSIZE, CharaDate[_a]->GetFairy(0).GetRange());
	color = GetColor(255, 0, 0);
	if (RIGHTCLICK != FALSE && mouseButton != lastMouseButton) {
		CharaDate[_a]->Move((int)prevPos.x * MASSSIZE, (int)prevPos.y * MASSSIZE);
		CharaDate[_a]->SetStayFlg(false);
		Initialize();
	}
	if (LEFTCLICK != FALSE && mouseButton != lastMouseButton) {

		mousePos = GET_POSITION();
		mapPos = mousePos;
		mapPos.x /= MASSSIZE;
		mapPos.y /= MASSSIZE;
		if (cul.GetMoveArea(mapPos.x, mapPos.y) == 1) {
			int tmp = INSTANCE->CulNum(mousePos, ENEMY);
			if (tmp == -1) {
				CharaDate[_a]->SetStayFlg(true);
				Initialize();
				return mState = -1;
			}
			else {
				mState++;
			}
		}
	}
	//	state++;
	return mState;
}

int UnitMgr::AttackState(int _a) {
	int tmp = 0;
	tmp = INSTANCE->CulNum(mousePos, ENEMY);

	EnemyDate[tmp]->SetOnActive(false);
	Initialize();
	CharaDate[_a]->SetStayFlg(true);
	mState = -1;
	return 0;
}
int UnitMgr::Update(int _a) {
	typedef enum {
		eMoveJudg = -1,
		eMove,
		eAttackJudg,
		eAttack
	};
	mouseButton = GET_BUTTON();
	if (mState < 0) {
		_a = -1;
		Initialize();
	}
	else (this->*Fanctions[mState])(_a);

	lastMouseButton = mouseButton;
	return _a;
	////static int state = -1;
	////static Unit::sPos prevPos = { 0,0 };
	////Unit::sPos mousePos;
	////Unit::sPos mapPos;
	////int mouseButton = 0;
	////static int lastMouseButton = 0;

	////エラー処理 何も触れていなかったら

	//mouseButton = GET_BUTTON();

	//if (RIGHTCLICK != FALSE) {
	//	if (state < -1)state = -1;
	//	INSTANCE->cul.Initialize();
	//	return state;
	//}

	//if (state == eMoveJudg) {

	//	state++;
	//}
	//else if (state == eMove) {

	//}
	//else	if (state == eAttackJudg) {	//一時的な処理

	//else if (state == eAttack) {

	//	//state++;
	//}

	/*else if () {
	if (RIGHTCLICK != 0) {
	CharaDate[_a]->Move(prevPos.x , prevPos.y );
		state--;
	}
	攻撃処理
	}*/
	/*if (RIGHTCLICK != 0) {
		INSTANCE->cul.Initialize();
		state = -1;
		return state;
	}*/
	//for (int i = 0; i < EnemyDate.size(); i++) {
	//	EnemyDate[i]->Update();
	//}
	//DrawFormatString(0, 0, color, "state =  %d", state);

	return _a;
}


int UnitMgr::Draw() {
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 20; j++) {
			if (cul.GetMoveArea(j, i) != -1 ) {
				DrawBox(j * MASSSIZE, i * MASSSIZE, j * MASSSIZE + MASSSIZE - 1, i * MASSSIZE + MASSSIZE - 1, color, true);
			}
		}
	}
	for (int i = 0; i < CharaDate.size(); i++) {
		CharaDate[i]->Draw();
	}
	for (int i = 0; i < EnemyDate.size(); i++) {
		EnemyDate[i]->Draw();
	}


	return 0;
}
int UnitMgr::Close() {
	return 0;
}

int UnitMgr::CulNum(BaseObj::sPos _arg, int _type) {
	//プレイヤー検索
	if (_type == PLAYER) {
		for (int i = 0; i < CharaDate.size(); i++) {
			if (CharaDate[i]->GetStayFlg() != false)continue;
			if ((_arg.x > CharaDate[i]->GetPosX()) && (_arg.x < CharaDate[i]->GetPosX() + MASSSIZE) &&
				(_arg.y > CharaDate[i]->GetPosY()) && (_arg.y < CharaDate[i]->GetPosY() + MASSSIZE))
				return i;
		}
	}
	//敵検索
	else if (_type == ENEMY) {
		for (int i = 0; i < EnemyDate.size(); i++) {
			if (EnemyDate.size() == 0)break;
			if ((_arg.x > EnemyDate[i]->GetPosX()) && (_arg.x < EnemyDate[i]->GetPosX() + MASSSIZE) &&
				(_arg.y > EnemyDate[i]->GetPosY()) && (_arg.y < EnemyDate[i]->GetPosY() + MASSSIZE))
				return i;
		}
	}
	else {
		for (int i = 0; i < FairyDate.size(); i++) {
			if (FairyDate.size() == 0)break;
			if (_arg.x / MASSSIZE == FairyDate[i]->GetPosX() &&
				_arg.y / MASSSIZE == FairyDate[i]->GetPosY())
				return i;
		}
	}
	return -1;
}

int UnitMgr::CheckStay(int _turn) {
	bool tmpFlg = false;
	if (_turn == PLAYER_TURN) {
		for (int i = 0; i < CharaDate.size(); i++) {
			if (CharaDate[i]->GetStayFlg() != true)return 0;
		}
	}
	if (_turn == ENEMY_TURN) {
		for (int i = 0; i < EnemyDate.size(); i++) {
			if (EnemyDate[i]->GetStayFlg() != true)return 0;
		}
	}
	return 1;
}

