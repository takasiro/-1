#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include"BaseTask.h"
#include"Mass.h"
class Map :public BaseTask {
private:
	//マス地形の選択用
	typedef enum terrain {
		tmp
	};
	vector<vector<Mass*>> mMap;
	vector<int> mConnect;//接続されているマップ番号を入れる
	int mMapNum;//マップ番号

public:
	Map();
	//Map(Mass*,int,int);

	virtual int Initialize() { ; }	//初期化処理
	virtual int Update() { ; }		//計算処理
	virtual int Draw() { ; }			//描画処理
	virtual int Close() { ; }		//終了処理
	//マップデータの読み込み
	int FileRead(string);

	int GetMass(int _x,int _y) { mMap[_x][_y]->GetMass(); };