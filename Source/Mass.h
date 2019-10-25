#pragma once
#include<iostream>
using namespace std;


class Mass {
private:
	int mGrHandle;//グラフィックハンドル
	int mLandType;//地形の種類
	int mMoveCost;//移動するのに必要なコスト
public:
	Mass() { ; }
	Mass(int _grHandle, int _landtype, int _movecost);
	virtual ~Mass() { ; }
	Mass* GetMass() { return this; }
	int GetLandType() { return mLandType; }
	int GetMoveCost() { return mMoveCost; }
};
