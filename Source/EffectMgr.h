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

	int Initialize();	//初期化処理
	int Update();		//計算処理
	int Draw();			//描画処理
	int Close();		//終了処理

	int PlayEffect(string _name, int _x, int _y);

};