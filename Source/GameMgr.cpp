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
	int num = 0;
	if (Mouse::GET_BUTTON() == MOUSE_INPUT_LEFT) {
		num = INSTANCE->CulNum(tmp = Mouse::GET_POSITION(), PLAYER);
	}
	if(num!=-1)INSTANCE->Update(num);
	INSTANCE->Update();
	INSTANCE->SetCharaData(Chara(10, 10));
	return 0;
}


void  GameMgr::Update(int _turn) {
	//player.update‚Æenemy.update‚Ì–ß‚è’l‚ðŽó‚¯Žæ‚é—\’è
	if (_turn == 1)mNowTurn * -1;
	INSTANCE->Update();
}


int GameMgr::Draw() {
	INSTANCE->Draw();
	return 0;
}

int GameMgr::Close() {
	return 0;
}