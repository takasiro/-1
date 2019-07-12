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
	Map();
	Map(Mass*,int,int);

	//地形の種類を獲得出来る
	//引数で欲しい場所のマスを指定
	int GetMassType(int _x,int _y){
		return mMap[_y][_x].GetType();
	}
	//地形の消費移動力を獲得できる
	//引数で欲しい場所のマスを指定
	int GetMoveCost(int _x, int _y) {
		return mMap[_y][_x].GetMoveCost();
	}
};