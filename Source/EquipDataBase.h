#pragma once
#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include"BaseObj.h"
#include"BaseTask.h"
#include"Mass.h"
#include"UnitMgr.h"
#include"Unit.h"
#include"fairy.h"
#include"Enemy.h"

class EquipDataBase :public BaseTask {
private:

	class EquipData {
	private:
		int id;  //ID
		int charaId;  //キャラクターID
		int equipId;  //装備品ID
	public:
		EquipData(int _id, int _charaId, int _equipId) { id = _id; charaId = _charaId; equipId = _equipId; };

		int GetId() { return id; }
		int GetCharaId() { return charaId; }
		int GetEquipId() { return equipId; }

		int Initialize() { return 0; }	//初期化処理
		int Close() { return 0; }		//終了処理
	};

	vector<EquipData*> eqData;

public:
	EquipDataBase() { Initialize(); };
	virtual ~EquipDataBase() {};

	void SetEquipData(int _charaId, int _equipId) { eqData.emplace_back(new EquipData(eqData.size()+1, _charaId, _equipId)); };

	int GetEqCount(int _charaId);  //データベースにキャラナンバーiがいくつあるか
	int GetEq(int _charaId, int _eqNum);  //i番目のキャラのj個目の装備
	void DeleteEq(int _charaId, int _eqId);  //キャラiのjを装備解除　エラー処理も

	int Initialize();	//初期化処理
	int Update() { return 0; }		//計算処理
	int Draw() { return 0; }		//描画処理
	int Close() { return 0; }		//終了処理
};