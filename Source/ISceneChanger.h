#pragma once
#include "BaseScene.h"

class BaseScene;
class ISceneChanger {
public:
	
	~ISceneChanger() {}
	//�f�o�b�O��
	virtual void AddScene(BaseScene* _next) = 0;
	virtual void ChangeScene(BaseScene* _next) = 0;
	virtual void SceneClose() = 0;

};