#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include"BaseTask.h"
#include"Mass.h"
class Map :public BaseTask {
private:
	//�}�X�n�`�̑I��p
	typedef enum terrain {
		tmp
	};
	vector<vector<Mass*>> mMap;
	vector<int> mConnect;//�ڑ�����Ă���}�b�v�ԍ�������
	int mMapNum;//�}�b�v�ԍ�

public:
	Map();
	//Map(Mass*,int,int);

	virtual int Initialize() { ; }	//����������
	virtual int Update() { ; }		//�v�Z����
	virtual int Draw() { ; }			//�`�揈��
	virtual int Close() { ; }		//�I������
	//�}�b�v�f�[�^�̓ǂݍ���
	int FileRead(string);

	int GetMass(int _x,int _y) { mMap[_x][_y]->GetMass(); };