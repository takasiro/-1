#pragma once
#include <iostream>
#include<vector>
using namespace std;
#include "Unit.h"
#include "BaseTask.h"

//敵と味方の情報を保持するクラス
class UnitMgr :public BaseTask {

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
	int SetCharaData(Unit* _chara) {
		EnemyDate.push_back(_chara);
		return 0;
	}
	int GetCharaData(Unit* _chara) {
		for (auto itr = CharaDate.begin; itr < CharaDate.end(); itr++) {
			if (CharaDate+itr==_chara) {
				return CharaDate + itr;
			}
		}
		return 0;
	}
	//エネミーデータの取得
	//引数Unit型ポインタ
	int GetEnemyData(Unit* _chara) {
		for (auto itr = EnemyDate.begin; itr < EnemyDate.end(); itr++) {
			if (EnemyDate + itr == _chara) {
				return EnemyDate + itr;
			}
			return 0;
		}
	}

	virtual int Initialize() { ; }	//初期化処理
	virtual int Update() {;	}	//計算処理
	virtual int Draw() {	;}			//描画処理
	virtual int Close() { ; }		//終了処理
};