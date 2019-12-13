#include "GameMgr.h"

GameMgr::GameMgr() {
	Initialize();
}

GameMgr::~GameMgr() {
	;
}

int GameMgr::Initialize() {
	mNowTurn = ENEMY_TURN;
	mTurnCount = 0;
	mStayCount = 0;
	mUnitNum = -1;
	return 0;

}

int  GameMgr::Update() {
	BaseObj::sPos  tmpPos;

	if (MIDDLECLICK == 1) {
		BaseObj::sPos tmp = GET_POSITION();
		if (MIDDLECLICK == 0) {
			BaseObj::sPos  pos = GET_POSITION();
			tmp.x -= pos.x;
			tmp.y -= pos.y;
			*INSTANCE + tmp;
		}
		return 0;
	}

	if (mNowTurn == PLAYER_TURN) {
		if ((GET_BUTTON() & MOUSE_INPUT_LEFT) && mUnitNum == -1) {
			mUnitNum = INSTANCE->CulNum(tmpPos = GET_POSITION(), PLAYER, 0);
		}
		if (mUnitNum != -1/*&&INSTANCE->GetCharaStayFlg(num)==false*/) {
			mUnitNum = INSTANCE->Update(mUnitNum);
		}
		return INSTANCE->GetStayFlg(eChara);
	}
	else {
		for (int i = 0; i < INSTANCE->GetEnemyDataSize(); i++) {
			//	INSTANCE->SetEnemyStayFlg();
			INSTANCE->GetEnemyDate(i).Update();
		}
		return INSTANCE->GetStayFlg(eEnemy);
	}

}


int  GameMgr::Update(int _turn) {
	//player.update‚Æenemy.update‚Ì–ß‚è’l‚ðŽó‚¯Žæ‚é—\’è


	if (_turn != 0) {
		if (INSTANCE->CheckStay(mNowTurn) == 1) {
		/*	if (mNowTurn == PLAYER_TURN) {
				mNowTurn *= -1;
			
				INSTANCE->InitCharaS	ayFlg();
			
			}*/
			{
				//mNowTurn *= -1;
			
				INSTANCE->InitEnemyStayFlg();
			
			}
		}


	}
	return 0;
}

int GameMgr::Draw() {
	INSTANCE->Draw();
	if (mNowTurn == PLAYER_TURN)	DrawFormatString(0, 50, GetColor(255, 255, 255), "turn PLAYER");
	else if(mNowTurn==ENEMY_TURN) 	DrawFormatString(0, 50, GetColor(255, 255, 255), "turn ENEMY");
	return 0;
}

int GameMgr::Close() {
	Initialize();
	//	INSTANCE->Close();
	return 0;
}