#pragma once
#include "Constant.h"
#include "BaseObj.h"
#include "Fairy.h"
#include <iostream>
using namespace std;
//�L�����N�^�[�͂�����p�����č��܂�
class Unit : public BaseObj
{

protected:


	eRole	mRole;	//���̃L�����̐E��(�����l�ɕ΂���o�����邽��)
	string *mName;	//���O
	int	mHp;		//�̗�
	int	mStr;		//��(�����p)
	int	mDef;		//�h��(�����p)
	int	mInt;		//����(���@�p)
	int	mMnd;		//���h(���@�p)
	int	mDex;		//	�����␳
	int	mAgi;		//���␳
	int	mMove;		//�ړ���
	bool mStay;		//�s���������̔���
	int	mLv;		//���x��
	int	mExp;		//���݌o���l
	Fairy* mEquipSlot;//�d���̑����g

public:
	Unit();
	Unit(eRole _role, string* _name, int _hp, int _str, int _def, int _mnd, int _mdef,
		int _dex, int _agi, int _move,  int _exp, int _lv);
	virtual ~Unit();

	Unit* GetPlayer() { return this; }
	int Initialize();//����������
	int Initialize(eRole _role, string* _name, int _hp, int _str, int _def, int _mnd, int _mdef,
		int _dex, int _agi, int _move, int _exp, int _lv);	//����������(�����t��)
	int Update();	//�v�Z����
	int Draw();		//�`�揈��
	int Close();	//�I������
	int StatusUp(int lv);//���x���A�b�v�̔\�͕ω�
	int	LastStatus();//����␳�܂߂��ŏI�X�e�[�^�X
	int SetFairy(Fairy _tmpfairy) {
		mEquipSlot = new Fairy(_tmpfairy);
	}

};