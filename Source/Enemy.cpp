#include"Enemy.h"
#include "Calculator.h"
#include"Keyboard.h"
Enemy::Enemy() {
	;
}

Enemy::Enemy(int _x, int _y) {
	mPos.x = _x;
	mPos.y = _y;
	SetPos(mPos);
	mWidth = 64;
	mHeight = 64;
	mOnActive = true;
	mGrHandlesCount = 12;
	mGrHandles = new int[mGrHandlesCount];
	LoadDivGraph("../Resource/Image/Enemy/Enemy001.png", 12, 3, 4, 64, 64, mGrHandles);
	/*for (int i = 0; i < 4; i++)mEquipSlot[i] = i;
	mEquipNum = 0;*/
}

Enemy::Enemy(short _id, string _name, eRole _role, eWeapon _weapon, int _hp, int _str, int _def, int _int, int _mnd,
	int _dex, int _agi, int _move, int _exp, int _lv, char* _filePath) : Unit(_id, _name, _role, _weapon, _hp, _str, _def, _int, _mnd, _dex, _agi, _move, _exp, _lv, _filePath) {
	mGrHandlesCount = 12;
	mGrHandles = new int[mGrHandlesCount];
	LoadDivGraph(_filePath, 12, 3, 4, 64, 64, mGrHandles);
	Fanctions[0] = &Enemy::MoveJudgeState;
	Fanctions[1] = &Enemy::MoveState;
	Fanctions[2] = &Enemy::AttackJudgeState;
	Fanctions[3] = &Enemy::AttackState;
	mState = 2;
	mTargeNum = 0;
	mDir = 2;
	mMoveDir = -1;
	/*for (int i = 0; i < 4; i++)mEquipSlot[i] = i;
	mEquipNum = 0;*/
}

Enemy:: ~Enemy() {
	;
}

int Enemy::Initialize() {
	mMoveDir = -1;
	mDirArray.clear();
	mDirCount = 0;
	mAnimCount = 0;
	mAnimNum = 0;
	return 0;
}

int Enemy::Initialize(char* _name, eRole _role, eWeapon _weapon, int _hp, int _str, int _def, int _int, int _mnd,
	int _dex, int _agi, int _move, int _exp, int _lv, char* _filePath) {
	return 0;
}

int Enemy::Update() {
	int hoge = 0;
	if (mStayFlg == false)hoge = (this->*Fanctions[mState])(mTargeNum);
	mC.x = mPos.x * 64 + 64 / 2;
	mC.y = mPos.y * 64 + 64 / 2;
	return hoge;
}

int Enemy::Draw() {

	/*if (mStayFlg == false)mColor = GetColor(0, 0, 255);
	else mColor = GetColor(150, 150, 150);*/
	//if(mGrHandle == -1)DrawBox(mPos.x, mPos.y, mPos.x + MASSSIZE, mPos.y + MASSSIZE, mColor, true);
	 //else LoadGraphScreen(mPos.x, mPos.y,"../Resource/Image/Map/map1.png",false);
	if (mOnActive == true) {
		/*	if (mStayFlg == false)*/ DrawGraph(mPos.x, mPos.y, mGrHandles[mDir/*+ mAnimCount % 20*/], TRUE);
		//else DrawGraph(mPos.x, mPos.y, mGrHandles2[2], TRUE);
		HpBar();
	}

	//	if (mOnActive == true) DrawGraph(mPos.x, mPos.y, mGrHandles[1], TRUE); //DrawBox(mPos.x, mPos.y, mPos.x + MASSSIZE, mPos.y + MASSSIZE, GetColor(255, 0, 0),true);
	return 0;
}

int Enemy::Close() {
	return 0;
}

int Enemy::StatusUp(int lv) {
	return 0;
}

int Enemy::LastStatus() {
	return 0;
}
int Enemy::Move(Unit::sPos _unit) {
	mPos.x = _unit.x * MASSSIZE;
	mPos.y = _unit.y * MASSSIZE;
	mMapPos.x = _unit.x;
	mMapPos.y = _unit.y;
	return 0;
}

int Enemy::Move(int _dir) {
	if (_dir == eUP && mPos.y + MASSSIZE > 0)mPos.y--;
	else	if (_dir == eDOWN && mPos.y + MASSSIZE < WINDOW_HEIGHT)mPos.y++;
	else if (_dir == eRIGHT && mPos.x + MASSSIZE < WINDOW_WIDTH)mPos.x++;
	else if (_dir == eLEFT && mPos.x + MASSSIZE > 0)mPos.x--;
	else return 1;
	/*mPos.x = _unit.x * MASSSIZE;
	mPos.y = _unit.y * MASSSIZE;*/
	mMapPos.x = mPos.x / MASSSIZE;
	mMapPos.y = mPos.y / MASSSIZE;
	//mDir = mDirArray[mAnimNum];
	return 0;
}


int Enemy::MoveJudgeState(int _a) {
	if (_a == -1)return _a;
	if (mState < -1)return mState = -1;
	//Initialize();

	/*if (GET_KEY(KEY_INPUT_1 == 1)) {*/
	for (int i = 0; i < INSTANCE->GetCharaDataSize(); i++) {
		if (INSTANCE->GetCharaDate(i).GetOnActive() == false)continue;
		Calculator::Instance()->Initialize();
		Calculator::Instance()->CulRange(mMapPos.x, mMapPos.y, 0, i, &mTargeNum);
	}
	//}

	/*if(GET_KEY(KEY_INPUT_2 == 1))*/Calculator::Instance()->Initialize();
	/*if(GET_KEY(KEY_INPUT_3 == 1))*/Calculator::Instance()->CulRange(mMapPos.x, mMapPos.y, 0, mTargeNum, &mTargeNum);
	/*if(GET_KEY(KEY_INPUT_4 == 1))*/Calculator::Instance()->RootCreate(INSTANCE->GetCharaDate(mTargeNum).GetMapPos(), mDirArray);
	//Calculator::Instance()->CreateDir(mMapPos, mDirArray);
	/*Calculator::RootCreate(INSTANCE->GetCharaDate(mTargeNum).GetMapPos().x,
		INSTANCE->GetCharaDate(mTargeNum).GetMapPos().y, this);*/
		//Calculator::RootCreate(INSTANCE->GetCharaDate(mTargeNum).GetMapPos().x,
			//INSTANCE->GetCharaDate(mTargeNum).GetMapPos().y, this);
		//Calculator::NearCaluculate();
	//	INSTANCE->SetColor(0, 0, 255);
	/*if (GET_KEY(KEY_INPUT_5 == 1))*/mState++;
	return _a;
}

int Enemy::MoveState(int _a) {
	////ˆÚ“®‚Í‚Å‚«‚é
	if (mDirArray.size() != mMove)mDirArray.resize(mMove);
	if (mMoveDir == -1) mDir = mMoveDir = Calculator::Instance()->MoveJudg(mMapPos);
	if (mMoveDir == -2)goto init;
	if (mAnimNum < mMove && mDirArray[mAnimNum] != -2) {
		//mDir = mDirArray[mAnimNum];
		

		if (Move(mMoveDir) == 0) {
			mAnimCount++;
			if (mAnimCount > 63) {
				mAnimCount = 0;
				mAnimNum++;
				mDir = mMoveDir = Calculator::Instance()->MoveJudg(mMapPos);
			}
		}
		else {
			init:
			Calculator::Instance()->Initialize();
			mAnimCount = 0;
			mAnimNum = 0;
			mDir = 2;
			mMoveDir = -1;
			Initialize();
			mState++;
			return _a;
		}
	}

	else {
		Calculator::Instance()->Initialize();
		mAnimCount = 0;
		mAnimNum = 0;
		mDir = 2;
		Initialize();
		mState++;
		return _a;
	}

	return _a;
}

int Enemy::AttackJudgeState(int _a) {
	Calculator::Instance()->Initialize();
	Calculator::Instance()->CulMoveRange(mMapPos.x, mMapPos.y, 2);
	INSTANCE->SetColor(255, 0, 0);

	for (int i = 0; i < INSTANCE->GetCharaDataSize(); i++) {
		if (INSTANCE->GetCharaDate(i).GetOnActive() != false &&
			Calculator::Instance()->GetMoveArea(INSTANCE->GetCharaDate(i).GetMapPos()) == 1) {
			mTargeNum = i;
			mState++;
			return _a;
		}
	}
	Calculator::Instance()->Initialize();
	Initialize();
	mTargeNum = -2;
	mState = 2;
	mStayFlg = true;
	return mState;
}

int Enemy::AttackState(int _a) {
	Chara& tmpChara = INSTANCE->GetCharaDate(_a);
	int damage = 0;
	//Calculator::HitCalculate(*CharaDate[_a],*EnemyDate[tmp]);
	if (mRole == eCaster)damage = Calculator::Instance()->MagicDamageCalculate(*this, tmpChara);
	else damage = Calculator::Instance()->PhysicalDamageCalculate(*this, tmpChara);

	tmpChara.Damage(damage);
	if (tmpChara.GetOnActive() == false)tmpChara.SetStayFlg(true);
	else {
		if (tmpChara.GetRole() == eCaster)damage = Calculator::Instance()->MagicDamageCalculate(tmpChara, *this);
		else damage = Calculator::Instance()->PhysicalDamageCalculate(tmpChara, *this);
		Damage(damage);
		Initialize();
		mStayFlg = true;
		mState = 2;
		return mState;
	}
	Calculator::Instance()->Initialize();
	Initialize();
	mState = 2;
	mTargeNum = -2;
	mStayFlg = true;
	return mState;
}
