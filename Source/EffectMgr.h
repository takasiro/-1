#pragma once
#include"BaseTask.h"
#include "Singleton.h"
#include<map>
#include<vector>
#include "Load.h"
#include "Effect.h"

class EffectMgr :public BaseTask,public Singleton<EffectMgr> {
	EffectMgr();
	virtual ~EffectMgr();
	friend Singleton<EffectMgr>;
private:
	std::map <string,Effect> mEffect;
	std::vector <string> mActiveObj;

public:

	int Initialize();	//����������
	int Update();		//�v�Z����
	int Draw();			//�`�揈��
	int Close();		//�I������

	int PlayEffect(string _name, int _x, int _y);

};