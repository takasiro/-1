#include "UnitMgr.h"
UnitMgr::UnitMgr() {
	prevPos = { 0 };
	mousePos = { 0 };
	mapPos = { 0 };
	mState = 0;
	mouseButton = 0;
	lastMouseButton = 0;
	color = GetColor(255, 255, 225);
	//Fanctions[0] = &UnitMgr::MoveJudgeState;
	//Fanctions[1] = &UnitMgr::MoveState;
	//Fanctions[2] = &UnitMgr::AttackJudgeState;
	//Fanctions[3] = &UnitMgr::AttackState;

}
UnitMgr::~UnitMgr() {
	Initialize();
	CharaDate.shrink_to_fit();
	EnemyDate.shrink_to_fit();
	FairyDate.shrink_to_fit();
}
int UnitMgr::Initialize() {
	Calculator::Initialize();
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
//int UnitMgr::MoveJudgeState(int _a) {
//	if (_a == -1)return _a;
//	if (mState < -1)return mState = -1;
//	//Initialize();
//	Calculator::CulMoveRange(prevPos.x = CharaDate[_a]->GetPosX() / MASSSIZE, prevPos.y = CharaDate[_a]->GetPosY() / MASSSIZE, CharaDate[_a]->GetMoveRange());
//	Calculator::MoveJudg(GetCharaDate(), GetEnemyDate(), _a);
//	color = GetColor(0, 0, 255);
//	mState += 1;
//	return _a;
//}
//
//int UnitMgr::MoveState(int _a) {
//
//	if (RIGHTCLICK != FALSE && mouseButton != lastMouseButton) {
//		Initialize();
//		mState -= 1;
//	}
//	if (LEFTCLICK != FALSE && mouseButton != lastMouseButton) {
//		mousePos = GET_POSITION();
//		mapPos = GET_POSITION();
//		mapPos.x /= MASSSIZE;
//		mapPos.y /= MASSSIZE;
//		if (Calculator::GetMoveArea(mapPos.x, mapPos.y) == 1) {
//			CharaDate[_a]->Move(mapPos);
//			CharaDate[_a]->Update();
//			Calculator::Initialize();
//			mState++;
//			return _a;
//		}
//	}
//	return _a;
//}
//
//int UnitMgr::AttackJudgeState(int _a) {
//
//
//	Calculator::CulMoveRange(CharaDate[_a]->GetPosX() / MASSSIZE, CharaDate[_a]->GetPosY() / MASSSIZE, 1);
//	color = GetColor(255, 0, 0);
//	if (RIGHTCLICK != FALSE && mouseButton != lastMouseButton) {
//		CharaDate[_a]->Move(prevPos);
//		CharaDate[_a]->SetStayFlg(false);
//		Initialize();
//	}
//
//
//
//	if (LEFTCLICK != FALSE && mouseButton != lastMouseButton) {
//		mousePos = GET_POSITION();
//		mapPos = mousePos;
//		mapPos.x /= MASSSIZE;
//		mapPos.y /= MASSSIZE;
//		if (Calculator::GetMoveArea(mapPos.x, mapPos.y) == 1) {
//			int tmp = INSTANCE->CulNum(mousePos, ENEMY);
//
//			if (tmp == -1) {
//				CharaDate[_a]->SetStayFlg(true);
//				Initialize();
//				mState = -1;
//				return mState;
//			}
//			else {
//				mState++;
//			}
//		}
//	}
//	//	state++;
//
//	return _a;
//}
//
//int UnitMgr::AttackState(int _a) {
//	int tmp = 0;
//	tmp = INSTANCE->CulNum(mousePos, ENEMY);
//	int damage = 0;
//	//Calculator::HitCalculate(*CharaDate[_a],*EnemyDate[tmp]);
//	if (CharaDate[_a]->GetRole() == eCaster)damage =Calculator::MagicDamageCalculate(*CharaDate[_a], *EnemyDate[tmp]);
//	else damage = Calculator::PhysicalDamageCalculate(*CharaDate[_a], *EnemyDate[tmp]);
//	
//	EnemyDate[tmp]->Damage(damage);
//	if (EnemyDate[tmp]->GetOnActive() == false)EnemyDate[tmp]->SetStayFlg(true);
//	//EnemyDate[tmp]->SetOnActive(false);
//	Initialize();
//	CharaDate[_a]->SetStayFlg(true);
//	mState = -1;
//	return mState;
//}
int UnitMgr::Update(int _a) {
	BaseObj::sPos tmpPos = GET_POSITION();
	static int  hoge = 0;
	typedef enum {
		eMoveJudg = -1,
		eMove,
		eAttackJudg,
		eAttack
	};
	mouseButton = GET_BUTTON();



	if (mState < 0) {
		lastMouseButton = mouseButton;
		//_a = -1;
		Initialize();
		return -1;
	}
	else {
		;
		hoge = CharaDate[_a]->Update(_a);// (this->*Fanctions[mState])(_a);
		lastMouseButton = mouseButton;
		return hoge;
	}


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

}


int UnitMgr::Draw() {
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 20; j++) {
			if (Calculator::GetMoveArea(j, i) != -1) {
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
	Initialize();
	CharaDate.shrink_to_fit();
	EnemyDate.shrink_to_fit();
	FairyDate.shrink_to_fit();
	return 0;
}

int UnitMgr::CulMapNum(BaseObj::sPos _arg, int _type) {
	//プレイヤー検索
	Unit::sPos tmpPos;
	if (_type == PLAYER) {
		for (int i = 0; i < CharaDate.size(); i++) {
			if (CharaDate[i]->GetOnActive() != true || CharaDate[i]->GetStayFlg() != false)continue;
			tmpPos = CharaDate[i]->GetMapPos();
			if ((_arg.x == tmpPos.x) && (_arg.y == tmpPos.y))
				return i;
		}
	}
	//敵検索
	else if (_type == ENEMY) {
		for (int i = 0; i < EnemyDate.size(); i++) {
			if (EnemyDate[i]->GetOnActive() != true || EnemyDate[i]->GetStayFlg() != false)continue;
			tmpPos = EnemyDate[i]->GetMapPos();
			if ((_arg.x == tmpPos.x) && (_arg.y == tmpPos.y))
				return i;
		}
	}
	else {
		for (int i = 0; i < FairyDate.size(); i++) {
			if (FairyDate[i]->GetOnActive() != true)continue;
			if (_arg.x / MASSSIZE == FairyDate[i]->GetPosX() &&
				_arg.y / MASSSIZE == FairyDate[i]->GetPosY())
				return i;
		}
	}
	return -1;
}

int UnitMgr::CulWorldNum(BaseObj::sPos _arg, int _type) {
	//プレイヤー検索
	Unit::sPos tmpPos;
	if (_type == PLAYER) {
		for (int i = 0; i < CharaDate.size(); i++) {
			if (CharaDate[i]->GetOnActive() != true || CharaDate[i]->GetStayFlg() != false)continue;
			tmpPos = CharaDate[i]->GetmPos();
			if ((_arg.x > tmpPos.x) && (_arg.x < tmpPos.x + MASSSIZE) &&
				(_arg.y > tmpPos.y) && (_arg.y < tmpPos.y + MASSSIZE))
				return i;
		}
	}
	//敵検索
	else if (_type == ENEMY) {
		for (int i = 0; i < EnemyDate.size(); i++) {
			if (EnemyDate[i]->GetOnActive() != true || EnemyDate[i]->GetStayFlg() != false)continue;
			tmpPos = EnemyDate[i]->GetmPos();
			if ((_arg.x > tmpPos.x) && (_arg.x < tmpPos.x + MASSSIZE) &&
				(_arg.y > tmpPos.y) && (_arg.y < tmpPos.y + MASSSIZE))
				return i;
		}
	}
	else {
		for (int i = 0; i < FairyDate.size(); i++) {
			if (FairyDate[i]->GetOnActive() != true)continue;
			if (_arg.x / MASSSIZE == FairyDate[i]->GetPosX() &&
				_arg.y / MASSSIZE == FairyDate[i]->GetPosY())
				return i;
		}
	}
	return -1;
}

int UnitMgr::CulUiNum(BaseObj::sPos _arg, int _type) {
	//プレイヤー検索
	Unit::sPos tmpPos;
	if (_type == PLAYER) {
		for (int i = 0; i < CharaDate.size(); i++) {
			if (CharaDate[i]->GetOnActive() != true)continue;
			tmpPos = CharaDate[i]->GetmPos();
			if ((_arg.x > tmpPos.x) && (_arg.x < tmpPos.x + MASSSIZE) &&
				(_arg.y > tmpPos.y) && (_arg.y < tmpPos.y + MASSSIZE))
				return i;
		}
	}
	//敵検索
	else if (_type == ENEMY) {
		for (int i = 0; i < EnemyDate.size(); i++) {
			if (EnemyDate[i]->GetOnActive() != true)continue;
			tmpPos = EnemyDate[i]->GetmPos();
			if ((_arg.x > tmpPos.x) && (_arg.x < tmpPos.x + MASSSIZE) &&
				(_arg.y > tmpPos.y) && (_arg.y < tmpPos.y + MASSSIZE))
				return i;
		}
	}
	else {
		for (int i = 0; i < FairyDate.size(); i++) {
			if (FairyDate[i]->GetOnActive() != true)continue;
			if (_arg.x / MASSSIZE == FairyDate[i]->GetPosX() &&
				_arg.y / MASSSIZE == FairyDate[i]->GetPosY())
				return i;
		}
	}
	return -1;
}

int UnitMgr::CulNum(BaseObj::sPos _arg, int _type, int _serchFlg) {
	if (_serchFlg == 0) {
		return	CulWorldNum(_arg, _type);
	}
	else if (_serchFlg == 1) {
		return	CulMapNum(_arg, _type);
	}
	else if (_serchFlg == 2) {
		return	CulUiNum(_arg, _type);
	}
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

void UnitMgr::SetMapData(Map& _map) {
	Calculator::SetMap(_map);
}

