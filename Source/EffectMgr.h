#pragma once
#include"BaseTask.h"
#include<map>
#include "Effect.h"

class EffectMgr :public BaseTask {
private:
	std::map <string,Effect> mEffect;

public:
	EffectMgr();
	virtual ~EffectMgr();
	virtual int Initialize();	//‰Šú‰»ˆ—
	virtual int Update();		//ŒvZˆ—
	virtual int Draw();			//•`‰æˆ—
	virtual int Close();		//I—¹ˆ—

	int PlayEffect(string _name, int _x, int _y);

};