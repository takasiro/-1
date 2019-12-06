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
	virtual int Initialize();	//初期化処理
	virtual int Update();		//計算処理
	virtual int Draw();			//描画処理
	virtual int Close();		//終了処理

	int PlayEffect(string _name, int _x, int _y);

};