#pragma once
#include"BaseTask.h"
#include<map>
#include "Effect.h"

class EffectMgr :public BaseTask {
private:
	std::map <string,Effect> mEffect;

public:
	EffectMgr();
	virtual ~EffectMgr();
	virtual int Initialize();	//����������
	virtual int Update();		//�v�Z����
	virtual int Draw();			//�`�揈��
	virtual int Close();		//�I������

	int PlayEffect(string _name, int _x, int _y);

};