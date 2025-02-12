#pragma once
#include"Constant.h"
class BaseTask
{
public:
	BaseTask() {}
	virtual ~BaseTask() {}

	virtual int Initialize() = 0;	//初期化処理
	virtual int Update() = 0;		//計算処理
	virtual int Draw() = 0;			//描画処理
	virtual int Close() = 0;		//終了処理

};
