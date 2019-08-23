#pragma once
#include <iostream>
#include<vector>
using namespace std;
#include "Unit.h"
#include "BaseTask.h"
#include"Singleton.h"
//敵と味方の情報を保持するクラス
class UnitMgr :public BaseTask, public Singleton<UnitMgr> {
public:
	UnitMgr() { ; }
	friend Singleton<UnitMgr>;


private:

	vector<Unit*> CharaDate;
	vector<Unit*> EnemyDate;

public:
	//キャラデータの追加・生成
	//引数Unit型ポインタ
	int SetCharaData(Unit* _chara) {
		CharaDate.push_back(_chara);
		return 0;
	}
	//エネミーデータの取得
	//引数Unit型ポインタ
	int SetEnemyData(Unit* _chara) {
		EnemyDate.push_back(_chara);
		return 0;
	}
	//int GetCharaData(Unit* _chara) {
	//	for (auto itr = CharaDate.begin; itr < CharaDate.end(); itr++) {
	//		if (CharaDate+itr==_chara) {
	//			return CharaDate + itr;
	//		}
	//	}
	//	return 0;
	//}
	////エネミーデータの取得
	////引数Unit型ポインタ
	//int GetEnemyData(Unit* _chara) {
	//	for (auto itr = EnemyDate.begin; itr < EnemyDate.end(); itr++) {
	//		if (EnemyDate + itr == _chara) {
	//			return EnemyDate + itr;
	//		}
	//		return 0;
	//	}
	//}
	vector<Unit*>& GetEnemyDate() { return EnemyDate; }
	vector<Unit*>& GetCharaDate() { return CharaDate; }
	virtual int Initialize() { return 0; }	//初期化処理
	virtual int Update() { return 0; }	//計算処理
	virtual int Draw() { return 0; }			//描画処理
	virtual int Close() { return 0; }		//終了処理
};