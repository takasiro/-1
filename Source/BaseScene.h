#pragma once

#include "BaseTask.h"
#include "ISceneChanger.h"

class BaseScene :public BaseTask {
protected:
	ISceneChanger* mISceneChanger;
public:
	BaseScene(ISceneChanger* _Changer) {
		mISceneChanger = _Changer;
	}

};