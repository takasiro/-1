#pragma once
#include "BaseScene.h"

class LoadScene : public BaseScene {

	LoadScene();
	LoadScene(ISceneChanger*);
	virtual	~LoadScene();
	int Initialize();	//����������
	int Update();		//�v�Z����
	int Draw();		//�`�揈��
	int Close();		//�I������


};