#pragma once

#include "Constant.h"
#include"BaseObj.h"
#include <iostream>
using namespace std;
#include "Unit.h"
//����̃X�e�[�^�X�̃N���X


class Fairy :public BaseObj {
protected:

	string  mName;
	int mDamage;//����̍U����
	int	mMagicDamage;//���@�U����
	int	mMaxRange;//����̍ő�U���͈�
	int	mMinRange;//����̍ŏ��U���͈�

	//�ȉ��␳�Ɏg��
	int	mHp;		//�̗�
	int	mStr;		//��(�����p)
	int	mDef;		//�h��(�����p)
	int	mInt;		//����(���@�p)
	int	mMnd;		//���h(���@�p)
	int	mDex;		//	�����␳
	int	mAgi;		//���␳
	int	mMove;		//�ړ���

	//�ȉ������l�Ƃ��Ďg�p
	float GrowthHp;
	float GrowthStr;
	float GrowthDef;
	float GrowthInt;
	float GrowthMnd;
	float GrowthDex;
	float GrowthAgi;
	float GrowthMove;

public:

	Fairy();
	Fairy(Fairy&) { ; }
	Fairy(string _name, int _damage, int _maxRange, int _minRange, int _magicdamage);
	virtual ~Fairy();
	Fairy* GetPlayer() { return this; }
	int Initialize();
	int Update();
	int Draw();
	int Close();



};