#pragma once
#include <iostream>
#include<vector>
using namespace std;
#include "Unit.h"
#include "BaseTask.h"
#include"Singleton.h"
#include "Fairy.h"
#include "Chara.h"
#include "Enemy.h"

//シングルトンマクロ　UnitMgr::Instance()
#define INSTANCE UnitMgr::Instance()
#define PLAYER 0
#define ENEMY 1
#define FAIRY 2

/*Chara Enemy Fairyデータを一括管理するクラス
情報の取得などはこのクラスで行う*/
class UnitMgr :public BaseTask, public Singleton<UnitMgr> {
public:
	UnitMgr();
	~UnitMgr();
	friend Singleton<UnitMgr>;


private:

	vector<Chara*> CharaDate;
	vector<Enemy*> EnemyDate;
	vector<Fairy*>FairyDate;

public:
	/*キャラデータの生成
	引数 Chara型　オブジェクト*/
	int SetCharaData(Chara _chara) {
		CharaDate.emplace_back(new Chara(_chara));
		return 0;
	}
	/*エネミーデータ生成
		引数 Enemy型　オブジェクト*/
	int SetEnemyData(Enemy _chara) {
		EnemyDate.emplace_back(new Enemy(_chara));
		return 0;
	}
	/*フェアリーデータ生成
		引数 Fairy型　オブジェクト*/
	int SetFairyDate(Fairy _fairy) {
		FairyDate.emplace_back(new Fairy(_fairy));
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
	vector<Enemy*>* GetEnemyDate() { return &EnemyDate; }
	vector<Chara*>* GetCharaDate() { return &CharaDate; }
	vector<Fairy*>* GetFairyDate() { return &FairyDate; }
	/*マウスの位置からどれをクリックしたか判定する
	第一引数 sPos マウス座標
	第二引数　int 検索する種類 0 プレイヤー　1エネミー　2フェアリー*/
	int CulNum(BaseObj::sPos _arg,int _type);

	virtual int Initialize();	//初期化処理
	virtual int Update();	//計算処理
	virtual int Update(int _a);	//計算処理
	virtual int Draw();		//描画処理
	virtual int Close();		//終了処理
};