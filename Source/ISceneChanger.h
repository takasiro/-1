#pragma once
#include "BaseScene.h"
#include"Keyboard.h"
class BaseScene;
class ISceneChanger {
public:
	
	~ISceneChanger() {}
	//デバッグ中
	virtual void AddScene(BaseScene* _next) = 0;
	virtual void ChangeScene(BaseScene* _next) = 0;
	virtual void ChangeScene(BaseScene _next) = 0;
	virtual void SceneClose() = 0;

};