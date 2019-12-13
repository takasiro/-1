#pragma once
#include "Constant.h"
#include "BaseObj.h"
#include"SoundMgr.h"
#include <iostream>
using namespace std;
#include <vector>

//キャラクターはこれを継承して作ります

class Unit : public BaseObj
{
	//Fairy& operator = (Fairy _tmp) {
	//	return _tmp.GetFairy();
	//}

protected:
	double mHpPercent;
	unsigned int mHpColor;//体力色

	int mId;//管理用ID 0~9キャラ　10~19エネミー　20~以降武器?
	bool mStayFlg;		//行動したかの判定 true 行動済み　false　行動前
	int mLv;		//レベル
	int mExp;		//現在経験値

	sPos mMapPos;
	vector<int> mDir;

	eRole	 mRole;		//そのキャラの職業(成長値に偏りを出させるため)
	eWeapon mWeaponType;//武器の種類(Fairyのみで使用)
	string mName;	//名前
	int mMaXHp;		//最大体力
	int mHp;			//体力
	int mStr;			//力(物理用)
	int mDef;			//防御(物理用)
	int mInt;			//魔力(魔法用)
	int mMnd;			//魔防(魔法用)
	int mDex;			//	命中
	int mAgi;			//回避
	int mMove;		//移動力

	int mBaseMaXHp;		//最大体力
	int mBaseHp;			//体力
	int mBaseStr;			//力(物理用)
	int mBaseDef;			//防御(物理用)
	int mBaseInt;			//魔力(魔法用)
	int mBaseMnd;			//魔防(魔法用)
	int mBaseDex;			//	命中
	int mBaseAgi;			//回避
	int mBaseMove;		//移動力

	//int mEquipSlot[4]; //装備枠　マネージャーのFairy配列の要素数を持つ
	//int mEquipNum; //今装備しているものを持つ
	//以下成長値として使用
	float mGrowthHp;
	float mGrowthStr;
	float mGrowthDef;
	float mGrowthInt;
	float mGrowthMnd;
	float mGrowthDex;
	float mGrowthAgi;

public:
	Unit();
	Unit(short _id, string _name, eRole _role, eWeapon _weapon, int _hp, int _str, int _def, int _int, int _mnd,
		int _dex, int _agi, int _move, int _exp, int _lv, char* _filePath);
	virtual ~Unit();

	Unit* GetUnit() { return this; }
	int Initialize();//初期化処理
	int Initialize(short _id, string _name, eRole _role, eWeapon _weapon, int _hp, int _str, int _def, int _int, int _mnd,
		int _dex, int _agi, int _move, int _exp, int _lv, char* _filePath);	//初期化処理(引数付き)
	virtual int SetGrowth(float _hp, float _str, float _def, float _int, float _mnd, float _dex, float _agi);  //成長値
	int Update();	//計算処理
	int Draw();		//描画処理
	int Close();	//終了処理
	virtual int Move(int, int);
	virtual int StatusUp(int lv);//レベルアップの能力変化
	int LastStatus();//武器補正含めた最終ステータス
	//行動したか受け取る ture:行動済み false:行動前
	bool GetStayFlg() { return mStayFlg; }
	void SetStayFlg(bool _flg) { mStayFlg = _flg; }
	int GetMoveRange() { return mMove; }

	string GetName() { return mName; }

	int GetLv() { return mLv; }

	int GetHp() { return mHp; }
	int GetMaxHp() { return mMaXHp; }
	int GetGrowthHp() { return mGrowthHp; }

	int GetStr() { return mStr; }
	float GetGrowthStr() { return mGrowthStr; }

	int GetDef() { return mDef; }
	float GetGrowthDef() { return mGrowthDef; }

	int GetInt() { return mInt; }
	float GetGrowthInt() { return mGrowthInt; }

	int GetMnd() { return mMnd; }
	float GetGrowthMnd() { return mGrowthMnd; }

	int GetDex() { return mDex; }
	float GetGrowthDex() { return mGrowthDex; }

	int GetAgi() { return mAgi; }
	float GetGrowthAgi() { return mGrowthAgi; }

	int GetRole() { return mRole; }

	int GetExp() { return mExp; }

	sPos GetMapPos() { return mMapPos; }

	//virtual	int GetEquip(int _num) { return mEquipSlot[_num]; }

	//virtual int GetEquipNum() { return mEquipNum; }

	//virtual void SetEquipNum(int _num) { mEquipNum = _num; }
	////装備する場所　装備するもの要素数
	//virtual void SetEquipSlot(int _num, int _index) { mEquipSlot[_num] = _index; }

	//ｘとｙに代入する関数どちらを使っても可能
	virtual void SetPos(sPos _pos) {
		mPos.x = _pos.x * MASSSIZE;
		mPos.y = _pos.y * MASSSIZE;
		mMapPos.x = _pos.x;
		mMapPos.y = _pos.y;

	}

	virtual void SetPos(int _x, int _y) {
		mPos.x = _x * MASSSIZE;
		mPos.y = _y * MASSSIZE;
		mMapPos.x = _x;
		mMapPos.y = _y;
	}

	virtual void AdjustStatus() {
		mHp = mBaseHp + mGrowthHp * mLv;
		mMaXHp = mBaseMaXHp + mGrowthHp * mLv;
		mStr = mBaseStr + mGrowthStr * mLv;
		mDef = mBaseDef + mGrowthDef * mLv;
		mInt = mBaseInt + mGrowthInt * mLv;
		mMnd = mBaseMnd + mGrowthMnd * mLv;
		mDex = mBaseDex + mGrowthDex * mLv;
		mAgi = mBaseAgi + mGrowthAgi * mLv;
	}

	void operator + (sPos _pos) {
		mPos.x += _pos.x;
		mPos.y += _pos.y;
	}
	//ダメージを与える関数
	virtual int Damage(int _damage) {
		SoundMgr::Instance()->PlaySE("SE01");
		mHp -= _damage;
		if (mHp < 0) {
			mHp = 0;
			return Dead();
		}
		else return 0;
	}

	virtual int Dead() {
		SetOnActive(false);
		SetStayFlg(true);
		//獲得経験値
		return 50;
	}

	virtual void HpBar() {
		mHpPercent = (double)mHp / (double)mMaXHp;
		if (mHpPercent >= 0.7)mHpColor = GetColor(0, 255, 0);
		else	if (mHpPercent < 0.7 && mHpPercent>0.3)mHpColor = GetColor(255, 255, 0);
		else if (mHpPercent <= 0.3)mHpColor = GetColor(255, 0, 0);

		if (mHpPercent > 1.0000)mHpPercent = 1.00000;
	}
};