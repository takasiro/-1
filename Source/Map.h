#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include"BaseObj.h"
#include"Mass.h"
class Map :public BaseObj {
private:
	vector<vector<Mass>> mMap;
	vector<int> mConnect;//�ڑ�����Ă���}�b�v�ԍ�������
	int mMapNum;//�}�b�v�ԍ�

public:
	Map();
	Map(Mass*,int,int);

	//�n�`�̎�ނ��l���o����
	//�����ŗ~�����ꏊ�̃}�X���w��
	int GetMassType(int _x,int _y){
		return mMap[_y][_x].GetType();
	}
	//�n�`�̏���ړ��͂��l���ł���
	//�����ŗ~�����ꏊ�̃}�X���w��
	int GetMoveCost(int _x, int _y) {
		return mMap[_y][_x].GetMoveCost();
	}
};