#pragma once
#include<iostream>
using namespace std;
#include "Unit.h"
#include"Constant.h"
#include"DxLib.h"
class Chara :public Unit {


public:
	Chara();
	Chara(eRole _role, char* _name, int _hp, int _str, int _def, int _int, int _mnd,
		int _dex, int _agi, int _move, int _exp, int _lv);
	Chara(int x, int y);
	
	Chara(Unit);
	~Chara();
	Chara(Chara&);

	int Initialize();//初期化処理
	int Initialize(eRole _role, char* _name, int _hp, int _str, int _def, int _int, int _mnd,
		int _dex, int _agi, int _move, int _exp, int _lv);	//初期化処理(引数付き)
	int Update();	//計算処理
	int Draw();		//描画処理
	int Close();	//終了処理
	int StatusUp(int lv);//レベルアップの能力変化
	int LastStatus();//武器補正含めた最終ステータス

};