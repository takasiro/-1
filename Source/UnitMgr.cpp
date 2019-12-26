#include "UnitMgr.h"
#include"Calculator.h"
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


}


int UnitMgr::Draw() {
	
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
	Calculator::Instance()->SetMap(_map);
}

