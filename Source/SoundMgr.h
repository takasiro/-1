#pragma once
#include "BaseTask.h"

class SoundMgr : public BaseTask {

public:

	SoundMgr();
	virtual ~SoundMgr();
	virtual int Initialize();	//����������
	virtual int Update();		//�v�Z����
	virtual int Draw();			//�`�揈��
	virtual int Close();		//�I������
};