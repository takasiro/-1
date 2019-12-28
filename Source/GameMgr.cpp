#include "GameMgr.h"
#include"Keyboard.h"
GameMgr::GameMgr() {
	Initialize();
}

GameMgr::~GameMgr() {
	;
}

int GameMgr::Initialize() {
	mNowTurn = PLAYER_TURN;
	mTurnCount = 0;
	mStayCount = 0;
	mUnitNum = -1;
	mMousePos = { 0,0 };
	mActiveNum = 0;
	return 0;

}

int  GameMgr::Update() {
	BaseObj::sPos  tmpPos;

	if (MIDDLECLICK != FALSE) {
		//*INSTANCE + mMousePos;
	}
	//debug
	//if (GET_KEY(KEY_INPUT_0) == true) {
	//	for (int i = 0; i < INSTANCE->GetEnemyDataSize(); i++) {
	//		INSTANCE->GetEnemyDate(i).SetOnActive(false);
	//	}
	//}
	//else if(GET_KEY(KEY_INPUT_1) == true){
	//	for (int i = 0; i < INSTANCE->GetCharaDataSize(); i++) {
	//		INSTANCE->GetCharaDate(i).SetOnActive(false);
	//	}
	//}

	mMousePos = GET_POSITION();

	if (mNowTurn == PLAYER_TURN) {
		if ((GET_BUTTON() & MOUSE_INPUT_LEFT) && mUnitNum == -1) {
			mUnitNum = INSTANCE->CulNum(tmpPos = GET_POSITION(), PLAYER, 0);
		}
		if (mUnitNum != -1 && INSTANCE->GetCharaDate(mUnitNum).GetOnActive() == true) {
			mUnitNum = INSTANCE->Update(mUnitNum);
		}

	}
	else {
		if (INSTANCE->GetEnemyDataSize() > mActiveNum) {
			INSTANCE->GetEnemyDate(mActiveNum).Update();
			if ((INSTANCE->GetEnemyDate(mActiveNum).GetStayFlg() == true ||
				INSTANCE->GetEnemyDate(mActiveNum).GetOnActive() == false)) mActiveNum++;
		}

	}
	return INSTANCE->GetStayFlg(eEnemy) + INSTANCE->GetStayFlg(eChara);
}


int  GameMgr::Update(int _turn) {
	//player.update‚Æenemy.update‚Ì–ß‚è’l‚ðŽó‚¯Žæ‚é—\’è

	static int count = 0;
	if (_turn != 0) {
		if (INSTANCE->CheckStay(mNowTurn) == 1) {
			if (mNowTurn == PLAYER_TURN) {
				if (INSTANCE->GetOnActive(eChara) == 1)return 1;
				mNowTurn *= -1;
				INSTANCE->InitCharaStayFlg();
				INSTANCE->SetLastMouseButton(0);
				INSTANCE->SetMouseButton(0);
				Calculator::Instance()->Initialize();
			}
			else if (mNowTurn == ENEMY_TURN) {
				if (INSTANCE->GetOnActive(eEnemy) == 1)return 2;
				if (count > 30) {
					mNowTurn *= -1;
					INSTANCE->InitEnemyStayFlg();
					INSTANCE->SetLastMouseButton(0);
					count = 0;
				}
				mActiveNum = 0;
				
				INSTANCE->SetMouseButton(0);
				Calculator::Instance()->Initialize();
				count++;
				//INSTANCE->Initialize();
			}
		}
	}
	return 0;
}

int GameMgr::Draw() {
	Calculator::Instance()->Draw();
	INSTANCE->Draw();
	if (mNowTurn == PLAYER_TURN)	DrawFormatString(0, 50, GetColor(255, 255, 255), "turn PLAYER");
	else if (mNowTurn == ENEMY_TURN) 	DrawFormatString(0, 50, GetColor(255, 255, 255), "turn ENEMY");
	return 0;
}

int GameMgr::Close() {
	Initialize();
	//	INSTANCE->Close();
	return 0;
}