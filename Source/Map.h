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
	Map(Mass*,int,int);
};