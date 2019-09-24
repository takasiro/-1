#pragma once
#include"BaseTask.h"
#include"UnitMgr.h"

class GameMgr: public BaseTask{
private:
	int mNowTurn;
	int mTurnCount;
public:
	GameMgr();
	virtual ~GameMgr();
	virtual int Initialize();	//初期化処理
	virtual int Update();		//計算処理
	virtual void Update(int _turn);		//計算処理
	virtual int Draw();			//描画処理
	virtual int Close();		//終了処理

	int GetNowTrun() { return mNowTurn; }		//現在のターン数を取得
	
};

