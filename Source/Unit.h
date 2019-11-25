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
	int mId;//�Ǘ��pID 0~9�L�����@10~19�G�l�~�[�@20~�ȍ~����?
	bool mStayFlg;		//�s���������̔��� true �s���ς݁@false�@�s���O
	int mLv;		//���x��
	int mExp;		//���݌o���l

	sPos mMapPos;
	eRole	 mRole;		//���̃L�����̐E��(�����l�ɕ΂���o�����邽��)
	eWeapon mWeaponType;//����̎��(Fairy�݂̂Ŏg�p)
	string mName;	//���O
	int mMaXHp;		//�ő�̗�
	int mHp;			//�̗�
	int mStr;			//��(�����p)
	int mDef;			//�h��(�����p)
	int mInt;			//����(���@�p)
	int mMnd;			//���h(���@�p)
	int mDex;			//	����
	int mAgi;			//���
	int mMove;		//�ړ���

	//int mEquipSlot[4]; //�����g�@�}�l�[�W���[��Fairy�z��̗v�f��������
	//int mEquipNum; //���������Ă�����̂�����
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
	Unit(short _id,string _name, eRole _role, eWeapon _weapon,int _hp, int _str, int _def, int _int, int _mnd,
		int _dex, int _agi, int _move, int _exp, int _lv);
	virtual ~Unit();

	Unit* GetUnit() { return this; }
	int Initialize();//����������
	int Initialize(short _id,string _name, eRole _role, eWeapon _weapon, int _hp, int _str, int _def, int _int, int _mnd,
		int _dex, int _agi, int _move, int _exp, int _lv);	//����������(�����t��)
	virtual int SetGrowth(float _hp, float _str, float _def, float _int, float _mnd, float _dex, float _agi);  //�����l
	int Update();	//�v�Z����
	int Draw();		//�`�揈��
	int Close();	//�I������
	virtual int Move(int, int);
	virtual int StatusUp(int lv);//���x���A�b�v�̔\�͕ω�
	int LastStatus();//����␳�܂߂��ŏI�X�e�[�^�X
	//�s���������󂯎�� ture:�s���ς� false:�s���O
	bool GetStayFlg() { return mStayFlg; }
	void SetStayFlg(bool _flg) { mStayFlg = _flg; }
	int GetMoveRange() { return mMove; }

	string GetName() { return mName; }

	int GetLv() { return mLv; }

	int GetHp() { return mHp; }
	int GetMaxHp() { return mMaXHp; }
	int GetGrowthHp() { return mGrowthHp; }

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

	int GetAgi() { return mAgi; }
	float GetGrowthAgi() { return mGrowthAgi; }

	int GetRole() { return mRole; }

	int GetExp() { return mExp; }

	sPos GetMapPos() { return mMapPos; }

	//virtual	int GetEquip(int _num) { return mEquipSlot[_num]; }

	//virtual int GetEquipNum() { return mEquipNum; }

	//virtual void SetEquipNum(int _num) { mEquipNum = _num; }
	////��������ꏊ�@����������̗v�f��
	//virtual void SetEquipSlot(int _num, int _index) { mEquipSlot[_num] = _index; }

	//���Ƃ��ɑ������֐��ǂ�����g���Ă��\
	virtual void SetPos(sPos _pos) {
		mPos.x = _pos.x * MASSSIZE;
		mPos.y = _pos.y * MASSSIZE;
		mMapPos.x = _pos.x;
		mMapPos.y = _pos.y;
		
	}

	virtual void SetPos(int _x, int _y) {
		mPos.x = _x * MASSSIZE;
		mPos.y = _y * MASSSIZE;
		mMapPos.x = _x;
		mMapPos.y = _y;
	}

	virtual void AdjustStatus() {
		mHp = mHp + mGrowthHp * mLv;
		mMaXHp = mMaXHp + mGrowthHp * mLv;
		mStr = mStr + mGrowthStr * mLv;
		mDef = mDef + mGrowthDef * mLv;
		mInt = mInt + mGrowthInt * mLv;
		mMnd = mMnd + mGrowthMnd * mLv;
		mDex = mDex + mGrowthDex * mLv;
		mAgi = mAgi + mGrowthAgi * mLv;
	}

	void operator + (sPos _pos) {
		mPos.x += _pos.x;
		mPos.y += _pos.y;
	}
	//�_���[�W��^����֐�
	virtual int Damage(int _damage) {
		mHp -= _damage;
		if (mHp < 0) {
			mHp = 0;
			return Dead();
		}
		else return 0;
	}

	virtual int Dead() {
		SetOnActive(false);
		SetStayFlg(true);
		//�l���o���l
		return 50;
	}
};