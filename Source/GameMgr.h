#pragma once
#include"BaseTask.h"
#include"UnitMgr.h"

class GameMgr: public BaseTask{
private:
	int turn;
public:
	GameMgr();
	virtual ~GameMgr();

	virtual int Initialize();	//����������
	virtual int Update();		//�v�Z����
	virtual int Draw();			//�`�揈��
	virtual int Close();		//�I������

	
};

