#pragma once
#include<iostream>
using namespace std;
#include "Unit.h"
#include"Fairy.h"
#include"Constant.h"
#include"DxLib.h"

class Chara :public Unit {
private:
	//要改造
	double mHpPercent;
	unsigned int mColor;//色
	unsigned int mHpColor;//体力色
	int mState;
	int MoveJudgeState(int _A);
	int MoveState(int _a);
	int AttackJudgeState(int _a);
	int AttackState(int _a);
	int (Chara::* Fanctions[10])(int _a);
public:
	Chara();
	Chara(short _id,string _name, eRole _role, eWeapon _weapon ,int _hp, int _str, int _def, int _int, int _mnd,
		int _dex, int _agi, int _move, int _exp, int _lv);
		
	
	Chara(int x, int y);

	//Chara(Unit);
	~Chara();
	//Chara(Chara&);

	int Initialize();//初期化処理
	int Initialize(short _id,string _name, eRole _role, eWeapon _weapon, int _hp, int _str, int _def, int _int, int _mnd,
		int _dex, int _agi, int _move, int _exp, int _lv);	//初期化処理(引数付き)
	
	int Update();	//計算処理
	int Update(int _num);	//計算処理
	int Draw();		//描画処理
	int Close();	//終了処理
	/*移動処理*/
	int Move(Unit::sPos _pos);
	int StatusUp(int lv);//レベルアップの能力変化
	int LastStatus();//武器補正含めた最終ステータス]

	/*装備させる関数
	引数 Fairy _fairy 装備させるフェアリー情報、
	int _num 装備させる場所*/
	/*int SetFairy(Fairy _fairy, int _num) {
		mEquipSlot.emplace_back(new Fairy(_fairy));
		return 0;
	}*/
	/*装備されているものの情報を取得する関数
	引数 int _num 装備されている場所*/
	/*Fairy GetFairy(int _num) {
		if (_num<0 && _num >mEquipSlot.size()) {
			;
		}
		else return *mEquipSlot[_num];
	}*/

	/*void operator + (sPos _pos) {
		mPos.x += _pos.x;
		mPos.y += _pos.y;
	}*/

};