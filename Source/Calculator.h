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
class Enemy;
class Chara;
class Fairy;
class Calculator {


private:

	/*受けっとったマップ情報を格納する変数　*/
	static vector<Mass>* mCopyMap;
	/*受けっとったマップ情報に編集を加えるときに使う変数　*/
	static vector<int> mRangeMap;
	/*受けっとったマップ情報に編集を加えるときに使う変数　*/
	static vector<int> mTmpMap;
	//移動ルートを入れるもの
	static vector<int> mRootMap;
	/*テスト　マップサイズの読み込み*/
	static	int mMapSize;

	static int mNowMapWidth;
	static int mNowMapHeight;
	static int mCharaRange;
public:
	Calculator();
	static void Initialize();
	static void  Draw();
	/*移動コストを地形から判定して返す関数
	引数：int型　地形の種類*/
	static int SetCost(int _terrain);

	/*移動できる範囲を計算する*/
	static	int CulMoveRange(int _x, int _y, int _moveRange);
	/*移動できる範囲を計算する*/
	static	int CulMoveRange(Unit::sPos _pos, int _moveRange);
	/*敵と味方がいる位置に移動できないようにする関数
	引数
		  　第一　vector<Chara>&		キャラデータ
			第二  vector<Enemy>&	エネミーデータ
			第三　 int						自分の要素数*/
	static int  MoveJudg(vector<Chara*>& _chara, vector<Enemy*>& _enemy, int _num);

	static	void SetMap(Map& _map);

	static	void SetData(vector<Fairy*>& _fairy) { ; }
	/*そのマスが移動できるかを取得する関数
	第一引数 マップｘ座標
	第二引数 マップｙ座標*/
	static int GetMoveArea(int _x, int _y) { return mTmpMap[_y * 20 + _x]; }
	/*そのマスが移動できるかを取得する関数
	第一引数 マップ座標
	*/
	static int GetMoveArea(Unit::sPos _pos) { return mTmpMap[(int)_pos.y * 20 + (int)_pos.x]; }


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
	int HitCalculate(Unit 攻撃側ユニット,Unit 防御側ユニット);
	回避確立計算関数
	引数：
	第一引数　攻撃側ユニット
	第二引数　防御側ユニット
	戻り値：回避が成功したか
	*************************************************/
	static	int HitCalculate(Unit _Atk, Unit _def);

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
	/************************************************
	int NearCaluculate(Unit 攻撃側ユニット,Unit 防御側ユニット);
	距離計算処理
	引数：
	第一引数　敵の座標
	第二引数　
	戻り値：一番近いキャラの要素数
	*************************************************/
	static int NearCaluculate(int _x, int _y, int _range, int _index, int _area);
	/************************************************
int NearCaluculate(Unit 攻撃側ユニット,Unit 防御側ユニット);
距離計算処理
引数：
第一引数,第二引数　　敵の座標
第三引数　検索範囲
第四引数　検索するキャラの要素数
第五引数　要素数を受け取る変数のアドレス
戻り値：一番近いキャラの要素数
*************************************************/
	static int CulRange(int _x, int _y, int _range, int _index, int* _ary);
	static int RootCreate(BaseObj::sPos, vector<int> &_dir);
	static int RootCreate(int _x, int _y);
};
