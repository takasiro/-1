#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"Map.h"
#include"Unit.h"	
#include"BaseTask.h"


class Load:public BaseTask {
private:

public:
	Load() {};
	virtual ~Load(){};

	//void LoadData(const char*,char*);
	void LoadData(int,char*);

	int LoadMap(const char*, vector<Mass>&);  //�}�b�v���[�h�֐� 
	
	void PlayerBase(char*, vector<Unit>&);  //�L�����N�^�[�X�e�[�^�X�̃��[�h�֐� 
	//void PlayerGrowth(char*, vector<Unit>&);  //�L�����N�^�[�����l�̃��[�h
	
	void FairyBase();
	void FairyGrowth();

	int Initialize() { return 0; }	//����������
	int Update() { return 0; }		//�v�Z����
	int Draw() { return 0; }		//�`�揈��
	int Close() { return 0; }		//�I������
};
