#pragma once
#include "Constant.h"
#include"Unit.h"

class Enemy :public Unit {
protected:

	

public:
	Enemy();
	Enemy(int _x, int _y);
	Enemy( char* _name, eRole _role, int _hp, int _str, int _def, int _int, int _mnd,
		int _dex, int _agi, int _move, int _exp, int _lv);
	virtual ~Enemy();

	Unit* GetEnemy() { GetUnit(); }
	int Initialize();//初期化処理
	int Initialize( char* _name, eRole _role, int _hp, int _str, int _def, int _int, int _mnd,
		int _dex, int _agi, int _move, int _exp, int _lv);	//初期化処理(引数付き)
	int Update();	//計算処理
	int Draw();		//描画処理
	int Close();	//終了処理
	int StatusUp(int lv);//レベルアップの能力変化


	int LastStatus();//武器補正含めた最終ステータス
	//バグるのでコメントアウト
	int SetFairy() {
		//バグるのでコメントアウト
		//mEquipSlot = new Fairy();
	}


};