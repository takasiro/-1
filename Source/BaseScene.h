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
	
	int Initialize() { return 0; }	//����������
	int Update() { return 0; }		//�v�Z����
	int Draw() { return 0; }			//�`�揈��
	int Close() { return 0; }		//�I������
	
};