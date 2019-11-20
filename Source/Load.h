#pragma once
#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include"BaseObj.h"
#include"BaseTask.h"
#include"Mass.h"
#include"UnitMgr.h"
#include"Unit.h"
#include"fairy.h"
#include"Enemy.h"



class Load :public BaseTask {
private:
	//�t�@�C���n���h��
	int mBaseHandle;
	int mGrowthHandle;
	int mFairyHandle;
	int mLoadtype;

	char input[256];

	//�X�e�[�^�X���
	short mId;  //ID
	string mName;	  //���O
	eRole mRole;		  //���̃L�����̐E��(�����l�ɕ΂���o�����邽��)
	int mHp;			  //�̗�
	int mStr;			  //��(�����p)
	int mDef;			  //�h��(�����p)
	int mIntelli;		  //����(���@�p)
	int mMnd;			  //���h(���@�p)
	int mDex;			  //����
	int mAgi;			  //���
	int mMove;			  //�ړ���
	char mFilePath[256];  //�摜�̃t�@�C���p�X
	char* dummyFilePath;		  //�摜�t�@�C���p�X���Ȃ��������p�̃_�~�[�t�@�C���p�X

	int mRangeMin;  //�ŏ��U���͈�
	int mRangeMax;  //�ő�U���͈�

	float mGrowthHp;
	float mGrowthStr;
	float mGrowthDef;
	float mGrowthIntelli;
	float mGrowthMnd;
	float mGrowthDex;
	float mGrowthAgi;

	vector<Enemy*> mEnemyMasterData;  //Enemy�̃}�X�^�[�f�[�^

	BaseObj::sPos mInitPlayerPos[8];
	BaseObj::sPos mInitEnemyPos[8];

public:
	Load() { Initialize(); };
	virtual ~Load() {};

	int LoadFile(int, char*);

	int LoadData(const char* _filePath, vector<Mass>& _mass, const char* _PosFilePath);  //�}�b�v���[�h�֐�
	int LoadData(const char* _baseFilePath, const char* _growthFilePath);  //�L�����N�^�[�X�e�[�^�X�̃��[�h�֐� 

	int LoadChara(int _baseHandle, int _growthHandle);
	int LoadEnemy(int _baseHandle,int _growthHandle);
	int LoadWeapon(int _baseHandle, int _growthHandle);

	vector<Enemy*>& GetEnemyMasterData() { return mEnemyMasterData; }

	int SetEnemyData();

	int Initialize();	//����������
	int Update() { return 0; }		//�v�Z����
	int Draw() { return 0; }		//�`�揈��
	int Close() { return 0; }		//�I������
};
