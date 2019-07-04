#pragma once

#include "BaseScene.h"
#include "ISceneChanger.h"
#include <iostream>
#include <stack>

class BaseMgr : public ISceneChanger {
protected:
	std::stack<BaseScene*> mScene;
public:
	void AddScene(BaseScene* _next) {
		mScene.push(_next);
	}
	void ChangeScene(BaseScene* _next) {
		SceneClose();
		AddScene(_next);
	}
	void Update() {
		mScene.top()->Update();
	}
	void Draw() {
		mScene.top()->Draw();
	}
	void SceneClose() {
		mScene.top()->Close();
		delete mScene.top();
		mScene.pop();
	}
};