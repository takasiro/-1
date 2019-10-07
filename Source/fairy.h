#pragma once
#include <iostream>
using namespace std;
#include "Unit.h"
//����̃X�e�[�^�X�̃N���X

class Unit;
class Fairy :public  Unit {
protected:

	//char* mName;
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

	////�ȉ������l�Ƃ��Ďg�p
	//float GrowthHp;
	//float GrowthStr;
	//float GrowthDef;
	//float GrowthInt;
	//float GrowthMnd;
	//float GrowthDex;
	//float GrowthAgi;
	//float GrowthMove;

public:

	Fairy();
	//Fairy(Fairy* _tmp);
	Fairy(char* _name, eRole _role, int _hp, int _str, int _def, int _int, int _mnd,
		int _dex, int _agi, int _move, int _exp, int _lv);
	Fairy(char* _name, int _damage, int _minRange, int _maxRange, int _magicdamage);
	virtual ~Fairy();
	//Fairy& GetFairy() { return 0; }
	int Initialize();
	int Update();
	int Draw();
	int Close();



};