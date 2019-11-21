#pragma once
#include "BaseTask.h"

class SoundMgr : public BaseTask {

public:

	SoundMgr();
	virtual ~SoundMgr();
	virtual int Initialize();	//初期化処理
	virtual int Update();		//計算処理
	virtual int Draw();			//描画処理
	virtual int Close();		//終了処理
};