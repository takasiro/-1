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

	class EquipData {  //装備データクラス
	private:
		int id;  //ID
		int charaId;  //キャラクターID
		int equipId;  //装備品ID
	public:
		EquipData() { ; };
		EquipData(int _id, int _charaId, int _equipId) { id = _id; charaId = _charaId; equipId = _equipId; };

		//各種データの取得関数
		int GetId() { return id; }
		int GetCharaId() { return charaId; }
		int GetEquipId() { return equipId; }

		int Initialize() { return 0; }	//初期化処理
		int Close() { return 0; }		//終了処理
	};

	vector<EquipData*> eqData;  //装備データ配列

public:
	EquipDataBase() { Initialize(); };
	virtual ~EquipDataBase() {};


	int GetEqCount(int _charaId);  //特定キャラの装備武器数を取得
	int GetEq(int _charaId, int _eqNum);  //特定キャラの指定個数目の武器IDを取得

	void SetEquipData(int _charaId, int _equipId);  //装備データの追加

	void DeleteEq(int _charaId, int _eqId);  //特定キャラの装備データを消去

	int Initialize();	//初期化処理
	int Update() { return 0; }		//計算処理
	int Draw() { return 0; }		//描画処理
	int Close() { return 0; }		//終了処理
};