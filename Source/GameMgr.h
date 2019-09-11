#pragma once
#include"BaseTask.h"
#include"UnitMgr.h"

class GameMgr: public BaseTask{
private:
	int turn;
public:
	GameMgr();
	virtual ~GameMgr();

	virtual int Initialize();	//初期化処理
	virtual int Update();		//計算処理
	virtual int Draw();			//描画処理
	virtual int Close();		//終了処理

	
};

