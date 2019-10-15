#pragma once
#include<iostream>
using namespace std;
#include "Unit.h"
#include"Fairy.h"
#include"Constant.h"
#include"DxLib.h"
class Chara :public Unit {
private:
	vector<Fairy*> mEquipSlot;//装備枠
	unsigned int mColor;//色
public:
	Chara();
	Chara(char* _name, eRole _role, int _hp, int _str, int _def, int _int, int _mnd,
		int _dex, int _agi, int _move, int _exp, int _lv);
		
	
	Chara(int x, int y);

	//Chara(Unit);
	~Chara();
	//Chara(Chara&);

	int Initialize();//初期化処理
	int Initialize(char* _name, eRole _role, int _hp, int _str, int _def, int _int, int _mnd,
		int _dex, int _agi, int _move, int _exp, int _lv);	//初期化処理(引数付き)
	
	int Update();	//計算処理
	int Draw();		//描画処理
	int Close();	//終了処理
	/*移動処理*/
	int Move(int, int);
	int StatusUp(int lv);//レベルアップの能力変化
	int LastStatus();//武器補正含めた最終ステータス]

	//装備させる関数
	//引数 装備させるFairy型、装備させる場所
	int SetFairy(Fairy* _fairy, int _num) {
		mEquipSlot[_num] = _fairy;
		if (mEquipSlot[_num] == _fairy)return 0;
		else return 1;
	}

};