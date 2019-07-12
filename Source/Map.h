#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include"BaseObj.h"
#include"Mass.h"
class Map :public BaseObj {
private:
	vector<vector<Mass>> mMap;
	vector<int> mConnect;//接続されているマップ番号を入れる
	int mMapNum;//マップ番号

public:
	Map(Mass*,int,int);
};