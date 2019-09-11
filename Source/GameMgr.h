#pragma once
#include"BaseTask.h"
#include"UnitMgr.h"

class GameMgr: public BaseTask{
private:
	int turn;
public:
	GameMgr();
	virtual ~GameMgr();

	virtual int Initialize();	//‰Šú‰»ˆ—
	virtual int Update();		//ŒvZˆ—
	virtual int Draw();			//•`‰æˆ—
	virtual int Close();		//I—¹ˆ—

	
};

