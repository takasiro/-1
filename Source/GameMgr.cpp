#include "GameMgr.h"

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

	mMousePos = GET_POSITION();

	if (mNowTurn == PLAYER_TURN) {
		if ((GET_BUTTON() & MOUSE_INPUT_LEFT) && mUnitNum == -1) {
			mUnitNum = INSTANCE->CulNum(tmpPos = GET_POSITION(), PLAYER, 0);
		}
		if (mUnitNum != -1 && INSTANCE->GetCharaDate(mUnitNum).GetOnActive() == true) {
			mUnitNum = INSTANCE->Update(mUnitNum);
		}
		return INSTANCE->GetStayFlg(eChara);
	}
	else {
		if (INSTANCE->GetEnemyDataSize() > mActiveNum) {
			INSTANCE->GetEnemyDate(mActiveNum).Update();
			if ((INSTANCE->GetEnemyDate(mActiveNum).GetStayFlg() == true ||
				INSTANCE->GetEnemyDate(mActiveNum).GetOnActive() == false)) mActiveNum++;
		}
		return INSTANCE->GetStayFlg(eEnemy);
	}

}


int  GameMgr::Update(int _turn) {
	//player.update‚Æenemy.update‚Ì–ß‚è’l‚ðŽó‚¯Žæ‚é—\’è


	if (_turn != 0) {
		if (INSTANCE->CheckStay(mNowTurn) == 1) {
			if (mNowTurn == PLAYER_TURN) {
				mNowTurn *= -1;

				INSTANCE->InitCharaStayFlg();

			}
			else if (mNowTurn == ENEMY_TURN) {
				mNowTurn *= -1;
				mActiveNum = 0;
				INSTANCE->InitEnemyStayFlg();

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