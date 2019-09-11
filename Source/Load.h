#pragma once
#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include"BaseTask.h"
#include"Mass.h"	
#include"Unit.h"



class Load :public BaseTask {
private:
	int baseHandle;
	int growthHandle;
	int FairyHandle;

	char input[256];

	char name[256];	//���O
	eRole	role;	//���̃L�����̐E��(�����l�ɕ΂���o�����邽��)
	int hp;		//�̗�
	int str;		//��(�����p)
	int def;		//�h��(�����p)
	int intelli;		//����(���@�p)
	int mnd;		//���h(���@�p)
	int dex;		//	����
	int agi;		//���
	int move;	//�ړ���

	int rangeMin;  //�ŏ��U���͈�
	int rangeMax;  //�ő�U���͈�

	double gHp;
	double gStr;
	double gDef;
	double gIntelli;
	double gMnd;
	double gDex;
	double gAgi;

public:
	Load() { Initialize(); };
	virtual ~Load() {};

	int LoadFile(int, char*);

	int LoadData(const char*, vector<Mass>&);  //�}�b�v���[�h�֐� 
	int LoadData(const char* _baseFilePath, const char* _growthFilePath, vector<Unit>& _unit);  //�L�����N�^�[�X�e�[�^�X�̃��[�h�֐� 

	int LoadChara(int _baseHandle, int _growthHandle, vector<Unit>& _unit);
	int LoadWeapon(int _baseHandle, int _growthHandle, vector<Unit>& _unit);

	int Initialize();	//����������
	int Update() { return 0; }		//�v�Z����
	int Draw() { return 0; }		//�`�揈��
	int Close() { return 0; }		//�I������
};
