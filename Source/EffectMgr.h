#pragma once
#include"BaseTask.h"

class EffectMgr :public BaseTask {
public:
	EffectMgr();
	virtual ~EffectMgr();
	virtual int Initialize();	//‰Šú‰»ˆ—
	virtual int Update();		//ŒvZˆ—
	virtual int Draw();			//•`‰æˆ—
	virtual int Close();		//I—¹ˆ—

};