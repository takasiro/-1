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
	return 0;

}

int  GameMgr::Update() {
	BaseObj::sPos  tmp;
	static int num = -1;



	if ((GET_BUTTON() & MOUSE_INPUT_LEFT) && num == -1) {
		num = INSTANCE->CulNum(tmp = GET_POSITION(), PLAYER);
	}
	if (num != -1)num = INSTANCE->Update(num);
	return INSTANCE->CheckStay(mNowTurn);

	
}


void  GameMgr::Update(int _turn) {
	//player.update‚Æenemy.update‚Ì–ß‚è’l‚ðŽó‚¯Žæ‚é—\’è
	if (_turn == 1)mNowTurn *= -1;
	if (mNowTurn == ENEMY_TURN&& LEFTCLICK==0) {
		mNowTurn *= -1;
		INSTANCE->InitCharaStayFlg();
	}

}


int GameMgr::Draw() {
	INSTANCE->Draw();
	DrawFormatString(0, 50, GetColor(255, 255, 255), "turn %d", mNowTurn);
	return 0;
}

int GameMgr::Close() {
	return 0;
}