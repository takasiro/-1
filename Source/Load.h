#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"Map.h"
#include"BaseTask.h"


class Load:public BaseTask {
private:

public:
	Load();
	virtual ~Load();

	void LoadMap(char*, vector<Mass>&);  //�}�b�v���[�h�֐� 

	int Initialize() { return 0; }	//����������
	int Update() { return 0; }		//�v�Z����
	int Draw() { return 0; }		//�`�揈��
	int Close() { return 0; }		//�I������
};
