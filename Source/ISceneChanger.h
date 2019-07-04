#pragma once
#include "BaseScene.h"
class ISceneChanger {
public:
	virtual void AddScene(BaseScene* _next) = 0;
	virtual void ChangeScene(BaseScene* _next) = 0;
	virtual void SceneClose() = 0;
	
};