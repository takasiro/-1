#pragma once
#include"BaseTask.h"
#include"UnitMgr.h"
#include"BaseObj.h"
#include"Mouse.h"

class GameMgr: public BaseTask{
private:

	int mNowTurn;
	int mTurnCount;
	int mStayCount;
public:
	GameMgr();
	virtual ~GameMgr();
	virtual int Initialize();	//����������
	virtual int Update();		//�v�Z����
	virtual void Update(int _turn);		//�v�Z����
	virtual int Draw();			//�`�揈��
	virtual int Close();		//�I������

	int GetNowTrun() { return mNowTurn; }		//���݂̃^�[�������擾
	
};

