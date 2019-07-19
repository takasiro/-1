#pragma once
#include "BaseObj.h"
#include "Constant.h"
#include <iostream>
using namespace std;
//����̃X�e�[�^�X�̃N���X
class Fairy :public BaseObj {
protected:

	string  mName;
	int mDamage;//����̍U����
	int	mMagicDamage;//���@�U����
	int	mRange;//����̍U���͈�
	//�ȉ��␳�Ɏg��
	int	mHp;		//�̗�
	int	mStr;		//��(�����p)
	int	mDef;		//�h��(�����p)
	int	mInt;		//����(���@�p)
	int	mMnd;		//���h(���@�p)
	int	mDex;		//	�����␳
	int	mAgi;		//���␳
	int	mMove;		//�ړ���

public:

	Fairy();
	Fairy(Fairy&) { ; }
	Fairy(string _name, int _damage, int _range, int _magicdamage);
	virtual ~Fairy();
	Fairy* GetPlayer() { return this; }
	int Initialize();
	int Update();
	int Draw();
	int Close();

};