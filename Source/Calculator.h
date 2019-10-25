#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include"BaseTask.h"
#include"Map.h"
#include"Constant.h"
#include"Chara.h"
#include "Enemy.h"
#include "Unit.h"
#include"DxLib.h"	

/*計算を行うクラス
主に移動範囲の計算や攻撃範囲の計算など*/
class Calculator {
private:
	/*受けっとったマップ情報を格納する変数　*/
	vector<Mass>* mCopyMap;
	/*受けっとったマップ情報に編集を加えるときに使う変数　*/
	vector<int> mTmpMap;
	typedef enum eDirection {
		UP,
		RIGHT,
		DOWN,
		LEFT
	};
	/*テスト　マップサイズの読み込み*/
	int mMapSize;
public:
	Calculator();

	void Initialize();
	/*移動コストを地形から判定して返す関数
	引数：int型　地形の種類*/
	int SetCost(int _terrain);

	/*移動できる範囲を計算する*/
	int CulMoveRange(int _x, int _y, int _moveRange);
	/*敵と味方がいる位置に移動できないようにする関数
	引数
		  　第一　vector<Chara>&		キャラデータ
			第二  vector<Enemy>&	エネミーデータ
			第三　 int						自分の要素数*/
	int MoveJudg(vector<Chara*>& _chara, vector<Enemy*>& _enemy, int _num);

	void SetMap(Map& _map) {
		mCopyMap = _map.GetMapAdress();
		mMapSize = _map.GetMapSize();
		mTmpMap = vector<int>(mMapSize, -1);
		printf("%d", mTmpMap.size());
	}
	/*そのマスが移動できるかを取得する関数
	第一引数 int x軸
	第二引数 int y軸*/
	int GetMoveArea(int _x, int _y) { return mTmpMap[_y * 20 + _x]; }


	/************************************************
	int PhysicalDamageCalculate(Unit 攻撃側ユニット,Unit 防御側ユニット);
	物理ダメージ計算関数
	引数：
	第一引数　攻撃側ユニット
	第二引数　防御側ユニット
	戻り値：ダメージ量
	ダメージはマイナスにはならない
	*************************************************/
	int PhysicalDamageCalculate(Unit _Atk, Unit _def);

	/************************************************
	int MagicDamageCalculate(Unit 攻撃側ユニット,Unit 防御側ユニット);
	魔法ダメージ計算関数
	引数：
	第一引数　攻撃側ユニット
	第二引数　防御側ユニット
	戻り値：ダメージ量
	ダメージはマイナスにはならない
	*************************************************/
	int MagicDamageCalculate(Unit _Atk, Unit _def);
};
