#pragma once
#include"BaseTask.h"

class EffectMgr :public BaseTask {
public:
	EffectMgr();
	virtual ~EffectMgr();
	virtual int Initialize();	//����������
	virtual int Update();		//�v�Z����
	virtual int Draw();			//�`�揈��
	virtual int Close();		//�I������

};