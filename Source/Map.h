#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include"BaseObj.h"
#include"Mass.h"
#include "BaseObj.h"
#include"Mouse.h"
class Map :public BaseObj {
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

	/*BaseObj::sPos operator =(BaseObj::sPos _pos) {
		BaseObj::sPos returnPos;
		returnPos = _pos;
		return returnPos;
	}*/

	/*BaseObj::sPos operator +(BaseObj::sPos _pos) {
		BaseObj::sPos returnPos;
		BaseObj::sPos tmpPos = GET_POSITION();

		returnPos = {
			mMapPos.x += (tmpPos.x - _pos.x),
			mMapPos.y += (tmpPos.y - _pos.y),
		};
		return returnPos;
	}*/

	int GetMapWidth() { return mMapWidth; }
	int GetMapHeight() { return mMapHeight; }
};