#pragma once
#include "Constant.h"
#include "BaseObj.h"
#include <iostream>
using namespace std;
#include <vector>
//�L�����N�^�[�͂�����p�����č��܂�
class Unit : public BaseObj
{
	//Fairy& operator = (Fairy _tmp) {
	//	return _tmp.GetFairy();
	//}

protected:

	bool mStayFlg;		//�s���������̔��� true �s���ς݁@false�@�s���O
	int mLv;		//���x��
	int mExp;		//���݌o���l

	eRole	 mRole;		//���̃L�����̐E��(�����l�ɕ΂���o�����邽��)
	char* mName;	//���O
	int mMaXHp;		//�ő�̗�
	int mHp;			//�̗�
	int mStr;			//��(�����p)
	int mDef;			//�h��(�����p)
	int mInt;			//����(���@�p)
	int mMnd;			//���h(���@�p)
	int mDex;			//	����
	int mAgi;			//���
	int mMove;		//�ړ���

	//�ȉ������l�Ƃ��Ďg�p
	float mGrowthHp;
	float mGrowthStr;
	float mGrowthDef;
	float mGrowthInt;
	float mGrowthMnd;
	float mGrowthDex;
	float mGrowthAgi;
	float mGrowthMove;

public:
	Unit();
	Unit(char* _name, eRole _role, int _hp, int _str, int _def, int _int, int _mnd,
		int _dex, int _agi, int _move, int _exp, int _lv);
	virtual ~Unit();

	Unit* GetUnit() { return this; }
	int Initialize();//����������
	int Initialize(char* _name, eRole _role, int _hp, int _str, int _def, int _int, int _mnd,
		int _dex, int _agi, int _move, int _exp, int _lv);	//����������(�����t��)
	virtual int SetGrowth(int _hp, int _str, int _def, int _int, int _mnd, int _dex, int _agi);  //�����l
	int Update();	//�v�Z����
	int Draw();		//�`�揈��
	int Close();	//�I������
	virtual int StatusUp(int lv);//���x���A�b�v�̔\�͕ω�
	int LastStatus();//����␳�܂߂��ŏI�X�e�[�^�X

	bool GetStayFlg() { return mStayFlg; }

};