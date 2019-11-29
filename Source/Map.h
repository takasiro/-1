#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include"BaseTask.h"
#include"Mass.h"
#include "BaseObj.h"
class Map :public BaseTask {
public:
	//マス地形の選択用
	typedef enum eTerrain {
		eGrassland = 1,
		eGrass,
		eRock,
		eRiver,
		eHill,
		eVillage,
		eForest,
		eVolcanoSoil,
		eMagma,
		eVolcanoRock,
		eCaveSoil,
		eCaveRock,
		eDemonKingFloor,
		eDemonKingPillars,
		eDemonKingCarpet
	};
private:
	vector<Mass> mMap;
	vector<int> mConnect;//接続されているマップ番号を入れる
	int mMapNum;//マップ番号
	eTerrain terrain;
	unsigned int color;
	int* mGrHandles;	//グラフィックハンドル複数ある場合
	int mGrHandlesCount;	//複数ある場合の個数
	BaseObj::sPos mMapPos;//マップを表示する左上原点値
	int mMapWidth;//マップの横幅
	int mMapHeight;//マップの縦幅
public:
	Map();
	//Map(Mass*,int,int);
	virtual ~Map();
	virtual int Initialize();	//初期化処理
	virtual int Update();		//計算処理
	virtual int Draw();			//描画処理
	virtual int Close();		//終了処理


	int GetMass(int _x) { mMap[_x].GetMass(); }
	vector<Mass>& GetMap() { return mMap; }
	vector<Mass>* GetMapAdress() { return &mMap; }
	int GetMapSize() { return mMap.size(); }
	int MassDraw(int _landType);

	void operator +(BaseObj::sPos _pos) {
		mMapPos.x += _pos.x;
		mMapPos.y += _pos.y;
	}

	int GetMapWidth() { return mMapWidth; }
	int GetMapHeight() { return mMapHeight; }
};