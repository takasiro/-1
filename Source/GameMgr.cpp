#include "GameMgr.h"

GameMgr::GameMgr() {
	;
}

GameMgr::~GameMgr() {
	;
}

int GameMgr::Initialize() {
	return 0;
}

int  GameMgr::Update() {

	return 0;
}


void  GameMgr::Update(int _turn) {
	//player.update��enemy.update�̖߂�l���󂯎��\��
	if (_turn == 1)mNowTurn * -1;
	
}


int GameMgr::Draw() {
	return 0;
}

int GameMgr::Close() {
	return 0;
}