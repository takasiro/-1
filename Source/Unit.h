#pragma once
#include "BaseObj.h"
#include <iostream>
using namespace std;
class Unit : public BaseObj
{

protected:
	typedef enum {
		eTank,
		eCaster,
		eRanger,
		eFighter
	}eRole;

	eRole	mRole;	//���̃L�����̐E��(�����l�ɕ΂���o�����邽��)
	string *mName;	//���O
	int	mHp;		//�̗�
	int	mStr;		//��(�����p)
	int	mDef;		//�h��(�����p)
	int	mMa;		//����(���@�p)
	int	mMdef;		//���h(���@�p)
	int	mDex;		//	�����␳
	int	mAgi;		//���␳
	int	mMove;		//�ړ���
	int	mFaction;	//�w�c����p
	bool mStay;		//�s���������̔���p
	int	mNextExp;	//���̃��x���܂ł̕K�v�o���l
	int	mExp;		//���݌o���l
	int	mLv;		//���x��
	// fairy mEquipSlot;
public:



	Unit();
	Unit(eRole _role, string* _name, int _hp, int _str, int _def, int _ma, int _mdef,
		int _dex, int _agi, int _move, int _faction, int _nextexp, int _exp, int _lv);
	~Unit();

	int Initialize();//����������
	int Initialize(eRole _role, string* _name, int _hp, int _str, int _def, int _ma, int _mdef,
		int _dex, int _agi, int _move, int _faction, int _nextexp, int _exp, int _lv);	//����������(�����t��)
	int Update();	//�v�Z����
	int Draw();		//�`�揈��
	int Close();	//�I������
	int StatusUp(int lv);//���x���A�b�v�̔\�͕ω�

};