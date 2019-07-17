#pragma once
#include<iostream>
using namespace std;


class Mass {
private:
	int mGrHandle;//グラフィックハンドル
	int mLandType;//地形の種類
	int mMoveCost;//移動するのに必要なコスト
public:
	Mass(int _grHandle = 0, int _landtype = 0, int _movecost = 0);
	virtual ~Mass();
	int GetType() { return mLandType; }
	int GetMoveCost() { return mMoveCost; }
};
