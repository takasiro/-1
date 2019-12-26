#pragma once
#include"BaseTask.h"
#include"UnitMgr.h"
#include"BaseObj.h"
#include"Mouse.h"

class GameMgr: public BaseTask{
private:
	BaseObj::sPos mMousePos;
	int mNowTurn;//���݂̃^�[��
	int mTurnCount;
	int mStayCount;
	int mUnitNum;
	int mActiveNum;
public:
	GameMgr();
	virtual ~GameMgr();
	virtual int Initialize();	//����������
	virtual int Update();		//�v�Z����
	virtual int Update(int _turn);		//�v�Z����
	virtual int Draw();			//�`�揈��
	virtual int Close();		//�I������

	int GetNowTrun() { return mNowTurn; }		//���݂̃^�[�������擾
	
};

