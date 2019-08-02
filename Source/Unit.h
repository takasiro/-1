#pragma once
#include "Constant.h"
#include "Fairy.h"
#include "BaseObj.h"
#include <iostream>
using namespace std;
//�L�����N�^�[�͂�����p�����č��܂�
class Fairy;
class Unit : public BaseObj
{
protected:
	eRole	mRole;	//���̃L�����̐E��(�����l�ɕ΂���o�����邽��)
	string mName;	//���O
	int mHp;		//�̗�
	int mStr;		//��(�����p)
	int mDef;		//�h��(�����p)
	int mInt;		//����(���@�p)
	int mMnd;		//���h(���@�p)
	int mDex;		//	����
	int mAgi;		//���
	int mMove;	//�ړ���
	bool mStay;		//�s���������̔���
	int mLv;		//���x��
	int mExp;		//���݌o���l
	Fairy* mEquipSlot;//�d���̑����g

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
	Unit();
	Unit(eRole _role, string _name, int _hp, int _str, int _def, int _mnd, int _mdef,
		int _dex, int _agi, int _move, int _exp, int _lv);
	virtual ~Unit();

	Unit* GetUnit() { return this; }
	int Initialize();//����������
	int Initialize(eRole _role, string _name, int _hp, int _str, int _def, int _mnd, int _mdef,
		int _dex, int _agi, int _move, int _exp, int _lv);	//����������(�����t��)
	int Update();	//�v�Z����
	int Draw();		//�`�揈��
	int Close();	//�I������
	int StatusUp(int lv);//���x���A�b�v�̔\�͕ω�


	int LastStatus();//����␳�܂߂��ŏI�X�e�[�^�X
	int SetFairy() {
		//�o�O��̂ŃR�����g�A�E�g
		//mEquipSlot = new Fairy();
	}

};