#pragma once

#include "BaseScene.h"
#include <iostream>
#include <stack>

class BaseMgr {
protected:
	std::stack<BaseScene*> m_Scene;
public:
	void AddScene(BaseScene* next) {
		m_Scene.push(next);
	}
	void ChangeScene(BaseScene* next) {
		Close();
		AddScene(next);
	}
	void Update() {
		m_Scene.top()->Update();
	}
	void Draw() {
		m_Scene.top()->Draw();
	}
	void Close() {
		m_Scene.top()->Close();
		delete m_Scene.top();
		m_Scene.pop();
	}
};