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

	double gHp;
	double gStr;
	double gDef;
	double gIntelli;
	double gMnd;
	double gDex;
	double gAgi;

public:
	Load() {};
	virtual ~Load() {};

	int LoadFile(int, char*);

	int LoadData(const char*, vector<Mass>&);  //�}�b�v���[�h�֐� 

	int LoadData(const char* _baseFilePath, const char* _growthFilePath, vector<Unit>&);  //�L�����N�^�[�X�e�[�^�X�̃��[�h�֐� 

	int Initialize() { return 0; }	//����������
	int Update() { return 0; }		//�v�Z����
	int Draw() { return 0; }		//�`�揈��
	int Close() { return 0; }		//�I������
};
