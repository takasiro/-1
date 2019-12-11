#pragma once
#include"BaseTask.h"
#include "Singleton.h"
#include<map>
#include<vector>
#include "Load.h"
#include "Effect.h"

class EffectMgr :public BaseTask,public Singleton<EffectMgr> {
	EffectMgr();
	virtual ~EffectMgr();
	friend Singleton<EffectMgr>;
private:
	std::map <string,Effect> mEffect;
	std::vector <string> mActiveObj;

public:

	int Initialize();	//‰Šú‰»ˆ—
	int Update();		//ŒvZˆ—
	int Draw();			//•`‰æˆ—
	int Close();		//I—¹ˆ—

	int PlayEffect(string _name, int _x, int _y);

};