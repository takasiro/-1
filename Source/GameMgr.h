#pragma once
#include"BaseTask.h"
#include"UnitMgr.h"
#include"BaseObj.h"
#include"Mouse.h"

class GameMgr: public BaseTask{
private:
	BaseObj::sPos mMousePos;
	int mNowTurn;//現在のターン
	int mTurnCount;
	int mStayCount;
	int mUnitNum;
	int mActiveNum;
public:
	GameMgr();
	virtual ~GameMgr();
	virtual int Initialize();	//初期化処理
	virtual int Update();		//計算処理
	virtual int Update(int _turn);		//計算処理
	virtual int Draw();			//描画処理
	virtual int Close();		//終了処理

	int GetNowTrun() { return mNowTurn; }		//現在のターン数を取得
	
};

