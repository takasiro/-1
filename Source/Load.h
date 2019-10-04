#pragma once
#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include"BaseTask.h"
#include"Mass.h"
#include"UnitMgr.h"
#include"Unit.h"
#include"fairy.h"



class Load :public BaseTask {
private:
	int mBaseHandle;
	int mGrowthHandle;
	int mFairyHandle;
	int mLoadtype;

	char input[256];

	char name[256];	//���O
	eRole	mRole;	//���̃L�����̐E��(�����l�ɕ΂���o�����邽��)
	int mHp;		//�̗�
	int mStr;		//��(�����p)
	int mDef;		//�h��(�����p)
	int mIntelli;		//����(���@�p)
	int mMnd;		//���h(���@�p)
	int mDex;		//	����
	int mAgi;		//���
	int mMove;	//�ړ���

	int mRangeMin;  //�ŏ��U���͈�
	int mRangeMax;  //�ő�U���͈�

	double mGrowthHp;
	double mGrowthStr;
	double mGrowthDef;
	double mGrowthIntelli;
	double mGrowthMnd;
	double mGrowthDex;
	double mGrowthAgi;

public:
	Load() { Initialize(); };
	virtual ~Load() {};

	int LoadFile(int, char*);

	int LoadData(const char*, vector<Mass>&);  //�}�b�v���[�h�֐� 
	int LoadData(const char* _baseFilePath, const char* _growthFilePath, vector<Unit>& _unit);  //�L�����N�^�[�X�e�[�^�X�̃��[�h�֐� 
	int LoadData(const char* _baseFilePath, const char* _growthFilePath);  //�L�����N�^�[�X�e�[�^�X�̃��[�h�֐� 

	int LoadChara(int _baseHandle, int _growthHandle, vector<Unit>& _unit);
	int LoadChara(int _baseHandle, int _growthHandle, int _type);

	int LoadWeapon(int _baseHandle, int _growthHandle, vector<Unit>& _unit);
	int LoadWeapon(int _baseHandle, int _growthHandle,int _type);

	int Initialize();	//����������
	int Update() { return 0; }		//�v�Z����
	int Draw() { return 0; }		//�`�揈��
	int Close() { return 0; }		//�I������
};
