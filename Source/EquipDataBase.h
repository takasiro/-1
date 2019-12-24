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

//シングルトンマクロ EquipDataBase内の関数を使用するときに使ってください。　例)EquipDB->Get○○();
#define EquipDB EquipDataBase::Instance()

class EquipDataBase :public BaseTask, public Singleton<EquipDataBase> {
private:

	class EquipData {  //装備データクラス
	private:
		int id;  //ID
		int unitId;  //キャラクターID
		int equipId;  //装備品ID
	public:
		EquipData() { ; };
		EquipData(int _id, int _charaId, int _equipId) { id = _id; unitId = _charaId; equipId = _equipId; };

		//各種データの取得関数
		int GetId() { return id; }
		int GetUnitId() { return unitId; }
		int GetEquipId() { return equipId; }

		int Initialize() { return 0; }	//初期化処理
		int Close() { return 0; }		//終了処理
	};

	vector<EquipData*> charaEqData;  //装備データ配列
	vector<EquipData*> enemyEqData;  //装備データ配列

public:
	EquipDataBase() { Initialize(); };
	virtual ~EquipDataBase() {};

	friend Singleton<EquipDataBase>;

	int GetDataCount(eClass _unitType);  //装備データの数を取得

	int GetEqCount(eClass _unitType, short _charaId);  //特定キャラの装備武器数を取得
	int GetEq(eClass _unitType, short _charaId, short _eqNum);  //特定キャラの指定個数目の武器IDを取得

	void SetEquipData(eClass _unitType, short _charaId, short _equipId);  //装備データの追加

	void DeleteEq(eClass _unitType, short _charaId, short _eqId);  //特定キャラの装備データを消去

	int Initialize();	//初期化処理
	virtual int Update() { return 0; }		//計算処理
	virtual int Draw() { return 0; }		//描画処理
	virtual int Close() { return 0; }		//終了処理
};