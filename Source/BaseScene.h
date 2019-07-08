#pragma once

#include "BaseTask.h"
#include "ISceneChanger.h"

class BaseScene:public BaseTask {
	
protected:
	ISceneChanger* mISceneChanger;
public:
	BaseScene(){}
	BaseScene(ISceneChanger* _Changer) {
		mISceneChanger = _Changer;
	}
	
	int Initialize() { return 0; }	//‰Šú‰»ˆ—
	int Update() { return 0; }		//ŒvZˆ—
	int Draw() { return 0; }			//•`‰æˆ—
	int Close() { return 0; }		//I—¹ˆ—
	
};