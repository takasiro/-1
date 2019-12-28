#pragma once
#include<iostream>
using namespace std;
#include <numeric>
#include<vector>
#include"Singleton.h"
#include"Map.h"
#include"Constant.h"
#include"DxLib.h"	
#include "UnitMgr.h"
#include"BaseObj.h"
/*計算を行うクラス
主に移動範囲の計算や攻撃範囲の計算など*/
class Enemy;
class Chara;
class Fairy;

class UnitMgr;

class Calculator : public BaseObj, public Singleton<Calculator> {


private:
	int debugcount;
	/*受けっとったマップ情報を格納する変数　*/
	vector<Mass>* mCopyMap;
	/*受けっとったマップ情報に編集を加えるときに使う変数　*/
	vector<int> mRangeMap;
	/*受けっとったマップ情報に編集を加えるときに使う変数　*/
	vector<int> mTmpMap;
	//移動ルートを入れるもの
	vector<int> mRootMap;
	/*テスト　マップサイズの読み込み*/
	int mMapSize;
	BaseObj::sPos _issuPos;
	int mNowMapWidth;
	int mNowMapHeight;
	int mCharaRange;
	int mRangeArray[8];
	int mTargetNum;//移動目標とする味方キャラ
	unsigned int mColor;
public:
	friend Singleton<Calculator>;

	Calculator();
	virtual	~Calculator();
	virtual	int Initialize();
	virtual	int Update();
	virtual	int  Draw();
	virtual	int Close();
	friend Singleton<Calculator>;
	void AddIssuPos(BaseObj::sPos _pos);
	/*色設定関数
	第一引数　赤　0～255
	第二引数　緑　0～255
	第三引数　青　0～255
	*/
	void SetColor(int _r, int _b, int _g) {
		mColor = GetColor(_r, _b, _g);
	}
	/*移動コストを地形から判定して返す関数
	引数：int型　地形の種類*/
	int SetCost(int _terrain);

	/*移動できる範囲を計算する*/
	int CulMoveRange(int _x, int _y, int _moveRange);
	/*移動できる範囲を計算する*/
	int CulMoveRange(Unit::sPos _pos, int _moveRange);
	/*敵と味方がいる位置に移動できないようにする関数
	引数
		  　第一　vector<Chara>&		キャラデータ
			第二  vector<Enemy>&	エネミーデータ
			第三　 int						自分の要素数*/
	int  MoveJudg(vector<Chara*>& _chara, vector<Enemy*>& _enemy, int _num);
	int MoveJudg(BaseObj::sPos _pos);
	void SetMap(Map& _map);

	void SetData(vector<Fairy*>& _fairy) { ; }
	/*そのマスが移動できるかを取得する関数
	第一引数 マップｘ座標
	第二引数 マップｙ座標*/
	int GetMoveArea(int _x, int _y) { return mTmpMap[_y * 20 + _x]; }
	/*そのマスが移動できるかを取得する関数
	第一引数 マップ座標
	*/
	int GetMoveArea(Unit::sPos _pos) {
		return mTmpMap[(int)_pos.y * 20 + (int)_pos.x];
	}


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
	int HitCalculate(Unit 攻撃側ユニット,Unit 防御側ユニット);
	回避確立計算関数
	引数：
	第一引数　攻撃側ユニット
	第二引数　防御側ユニット
	戻り値：回避が成功したか
	*************************************************/
	int HitCalculate(Unit _Atk, Unit _def);

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
	/************************************************
	int NearCaluculate(Unit 攻撃側ユニット,Unit 防御側ユニット);
	距離計算処理
	引数：
	第一引数　敵の座標
	第二引数　
	戻り値：一番近いキャラの要素数
	*************************************************/
	int NearCaluculate(int _x, int _y, int _range, int _index, int _area);
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
	int CulRange(int _x, int _y, int _range, int _index, int* _ary);
	int RootCreate(BaseObj::sPos, vector<int>& _dir);
	int RootCreate(int _x, int _y);

	int CreateDir(BaseObj::sPos _pos, vector<int>& _dir);

	int ActivetMove() {
		return accumulate(mRootMap.begin(), mRootMap.end(), 0);
	}
};
