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
	
public:
	Unit();
	Unit(char* _name, eRole _role, int _hp, int _str, int _def, int _int, int _mnd,
		int _dex, int _agi, int _move, int _exp, int _lv);
	virtual ~Unit();

	Unit* GetUnit() { return this; }
	int Initialize();//����������
	int Initialize(char* _name, eRole _role, int _hp, int _str, int _def, int _int, int _mnd,
		int _dex, int _agi, int _move, int _exp, int _lv);	//����������(�����t��)
	virtual int SetGrowth(float _hp, float _str, float _def, float _int, float _mnd, float _dex, float _agi);  //�����l
	int Update();	//�v�Z����
	int Draw();		//�`�揈��
	int Close();	//�I������
	virtual int Move(int,int);
	virtual int StatusUp(int lv);//���x���A�b�v�̔\�͕ω�
	int LastStatus();//����␳�܂߂��ŏI�X�e�[�^�X
	//�s���������󂯎�� ture:�s���ς� false:�s���O
	bool GetStayFlg() { return mStayFlg; }
	void SetStayFlg(bool _flg) {  mStayFlg = _flg; }
	int GetMoveRange() { return mMove; }

	int GetLv() { return mLv; }

	int GetStr() { return mStr; }
	float GetGrowthStr() { return mGrowthStr; }

	int GetDef() { return mDef; }
	float GetGrowthDef() { return mGrowthDef; }

	int GetInt() { return mInt; }
	float GetGrowthInt() { return mGrowthInt; }

	int GetMnd() { return mMnd; }
	float GetGrowthMnd() { return mGrowthMnd; }

	int GetDex() { return mDex; }
	float GetGrowthDex() { return mGrowthDex; }

	int GetRole() { return mRole; }
	
	//���Ƃ��ɑ������֐��ǂ�����g���Ă��\
	virtual void SetPos(sPos _pos) {
		mPos.x = _pos.x*MASSSIZE;
		mPos.y = _pos.y*MASSSIZE;
	}

	virtual void SetPos(int _x,int _y) {
		mPos.x = _x * MASSSIZE;
		mPos.y = _y * MASSSIZE;
	}
};