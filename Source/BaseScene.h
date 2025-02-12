#pragma once

#include "BaseTask.h"
#include "ISceneChanger.h"
#include "UnitMgr.h"
#include "SoundMgr.h"
#include "Fontcall.h"

class BaseScene:public BaseTask {
	
protected:
	Fontcall mFontcall;
	ISceneChanger* mISceneChanger;
public:
	BaseScene() { ; }
	BaseScene(ISceneChanger* _Changer) {
		mISceneChanger = _Changer;
	}
	
	int Initialize() { return 0; }	//初期化処理
	int Update() { return 0; }		//計算処理
	int Draw() { return 0; }			//描画処理
	int Close() { return 0; }		//終了処理
	
};