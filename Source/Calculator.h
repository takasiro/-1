#pragma once
#include<iostream>
using namespace std;
#include<vector>

#include"Map.h"
#include"Constant.h"
#include"DxLib.h"	
#include "UnitMgr.h"


/*計算を行うクラス
主に移動範囲の計算や攻撃範囲の計算など*/
class Calculator {


private:
	typedef enum Direction {
		eUP,
		eRIGHT,
		eDOWN,
		eLEFT
	}dir;
	/*受けっとったマップ情報を格納する変数　*/
	static vector<Mass>* mCopyMap;
	/*受けっとったマップ情報に編集を加えるときに使う変数　*/
	static vector<int> mTmpMap;
	/*テスト　マップサイズの読み込み*/
	static	int mMapSize;

public:
	Calculator();
	static void Initialize();
	/*移動コストを地形から判定して返す関数
	引数：int型　地形の種類*/
	static int SetCost(int _terrain);

	/*移動できる範囲を計算する*/
	static	int CulMoveRange(int _x, int _y, int _moveRange);
	/*敵と味方がいる位置に移動できないようにする関数
	引数
		  　第一　vector<Chara>&		キャラデータ
			第二  vector<Enemy>&	エネミーデータ
			第三　 int						自分の要素数*/
	static int  MoveJudg(vector<Chara*>& _chara, vector<Enemy*>& _enemy, int _num);

	static	void SetMap(Map& _map);

	static	void SetData(vector<Fairy*>& _fairy) { ; }
	/*そのマスが移動できるかを取得する関数
	第一引数 int x軸
	第二引数 int y軸*/
	static int GetMoveArea(int _x, int _y) { return mTmpMap[_y * 20 + _x]; }


	/************************************************
	int PhysicalDamageCalculate(Unit 攻撃側ユニット,Unit 防御側ユニット);
	物理ダメージ計算関数
	引数：
	第一引数　攻撃側ユニット
	第二引数　防御側ユニット
	戻り値：ダメージ量
	ダメージはマイナスにはならない
	*************************************************/
	static int PhysicalDamageCalculate(Unit _Atk, Unit _def);

	/************************************************
	int EvasionCalculate(Unit 攻撃側ユニット,Unit 防御側ユニット);
	回避確立計算関数
	引数：
	第一引数　攻撃側ユニット
	第二引数　防御側ユニット
	戻り値：回避が成功したか
	*************************************************/
	static	int EvasionCalculate(Unit _Atk, Unit _def);

	/************************************************
	int MagicDamageCalculate(Unit 攻撃側ユニット,Unit 防御側ユニット);
	魔法ダメージ計算関数
	引数：
	第一引数　攻撃側ユニット
	第二引数　防御側ユニット
	戻り値：ダメージ量
	ダメージはマイナスにはならない
	*************************************************/
	static int MagicDamageCalculate(Unit _Atk, Unit _def);
};
