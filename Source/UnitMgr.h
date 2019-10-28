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
#include"Calculator.h"
#include "Mouse.h"
#include "Button.h"

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
	Calculator cul;
	void DataInit() {
		CharaDate.clear();
		EnemyDate.clear();
		FairyDate.clear();
		CharaDate.shrink_to_fit();
		EnemyDate.shrink_to_fit();
		FairyDate.shrink_to_fit();
	}
private:
	vector<Chara*> CharaDate;
	vector<Enemy*> EnemyDate;
	vector<Fairy*>FairyDate;

	int color;
	Unit::sPos prevPos;
	Unit::sPos mousePos;
	Unit::sPos mapPos;
	int mState;
	int mouseButton;
	int lastMouseButton;

	int (UnitMgr::* Fanctions[10])(int _a);
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

	/**************************************************************************
	フェアリ－を装備させる関数
	型:int

	引数:Fairy _fairy...セットするFairyの情報
			int _index セットするキャラの要素数
	　 　int _num,…セットしたい装備欄場所
	***************************************************************************/
	int SetFairyChara(Fairy _fairy, int _index, int _num) {
		CharaDate[_index]->SetFairy(_fairy, _num);
	}

	/**************************************************************************
	成長値取得関数(chara)
	型:int

	引数:int _index setしたいキャラの要素数
	***************************************************************************/
	int SetCharaGrowth(int _index, float _hp, float _str, float _def, float _int, float _mnd, float _dex, float _agi) {
		CharaDate[_index]->SetGrowth(_hp, _str, _def, _int, _mnd, _dex, _agi);
		return 0;
	}
	/**************************************************************************
	成長値取得関数(enemy)
	型:int

	引数:int _index  setしたいエネミーの要素数
	***************************************************************************/
	int SetEnemyGrowth(int _index, float _hp, float _str, float _def, float _int, float _mnd, float _dex, float _agi) {
		EnemyDate[_index]->SetGrowth(_hp, _str, _def, _int, _mnd, _dex, _agi);
		return 0;
	}
	/**************************************************************************
	成長値取得関数(fairy)
	型:int

	引数:int _index  setしたいフェアリーの要素数
	***************************************************************************/
	int SetFairyGrowth(int _index, float _hp, float _str, float _def, float _int, float _mnd, float _dex, float _agi) {
		FairyDate[_index]->SetGrowth(_hp, _str, _def, _int, _mnd, _dex, _agi);
		return 0;
	}

	int GetCharaDataSize() { return CharaDate.size(); }
	int GetEnemyDataSize() { return EnemyDate.size(); }
	int GetFairyDataSize() { return FairyDate.size(); }

	vector<Enemy*>& GetEnemyDate() { return EnemyDate; }
	vector<Chara*>& GetCharaDate() { return CharaDate; }
	vector<Fairy*>& GetFairyDate() { return FairyDate; }

	Enemy& GetEnemyDate(int _num) { return *EnemyDate[_num]; }
	Chara& GetCharaDate(int _num) { return *CharaDate[_num]; }
	Fairy& GetFairyDate(int _num) { return *FairyDate[_num]; }

	/*マウスの位置からどれをクリックしたか判定する
	第一引数 sPos マウス座標
	第二引数　int 検索する種類 0 プレイヤー　1エネミー　2フェアリー*/
	int CulNum(BaseObj::sPos _arg, int _type);
	void SetMapData(Map& _map) { cul.SetMap(_map); }
	virtual int Initialize();	//初期化処理
	virtual int Update();	//計算処理
	virtual int Update(int _a);	//計算処理
	virtual int Draw();		//描画処理
	virtual int Close();		//終了処理
	/*全員が行動済みか判定する
	引数　int プレイヤーのターンか敵のターンか判定
	1:プレイヤーのターン
	-1:敵のターン
	戻り値 0 未行動
			 1　行動済み*/
	int CheckStay(int _turn);
	void InitCharaStayFlg() {
		for (int i = 0; i < CharaDate.size(); i++) {
			CharaDate[i]->SetStayFlg(false);
		}
	}
	void InitEnemyStayFlg() {
		for (int i = 0; i < EnemyDate.size(); i++) {
			EnemyDate[i]->SetStayFlg(false);
		}
	}

	void SetEnemyStayFlg() {
		for (int i = 0; i < EnemyDate.size(); i++) {
			EnemyDate[i]->SetStayFlg(true);
		}
	}
	/**************************************************************************
	型:void
	引数 : int _num, …セットしたい敵の要素数
	sPos _pos....セットしたい座標構造体
	***************************************************************************/
	void SetCharaPos(int _num, Unit::sPos _pos) {
		CharaDate[_num]->SetPos(_pos);
	}
	/**************************************************************************
型:void
引数: int _num,…セットしたい敵の要素数
	 sPos _pos....セットしたい座標構造体
***************************************************************************/
	void SetEnemyPos(int _num, Unit::sPos _pos) {
		EnemyDate[_num]->SetPos(_pos);
	}

	/**************************************************************************
型:int 0全員撃破していない　1全員撃破済み
引数: int _type 検索したいUnitの種類
***************************************************************************/
	int GetOnActive(int _type) {
		if(_type == eChara)	for (int i = 0; i < GetEnemyDataSize(); i++) {
			if (CharaDate[i]->GetOnActive() == true)return 0;
		}
		else if (_type == eEnemy) 	for (int i = 0; i < GetEnemyDataSize(); i++) {
			if (EnemyDate[i]->GetOnActive() == true)return 0;
		}
		return 1;
	}
	/**************************************************************************
型:int 0全員行動していない　1全員行動済み
引数: int _type 検索したいUnitの種類
***************************************************************************/
	int GetStayFlg(int _type) {
		if (_type == eChara)	for (int i = 0; i < GetCharaDataSize(); i++) {
			if (CharaDate[i]->GetStayFlg() == false)return 0;
		}
		else if (_type == eEnemy) 	for (int i = 0; i < GetEnemyDataSize(); i++) {
			if (EnemyDate[i]->GetStayFlg() == false)return 0;
		}
		return 1;
	}
	int MoveJudgeState(int);
	int MoveState(int);
	int AttackJudgeState(int);
	int AttackState(int);

};