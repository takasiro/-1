#include"Enemy.h"
#include "Calculator.h"
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
	LoadDivGraph("../Resource/Image/Enemy/Enemy00.png", 12, 3, 4, 64, 64, mGrHandles);
	/*for (int i = 0; i < 4; i++)mEquipSlot[i] = i;
	mEquipNum = 0;*/
}

Enemy::Enemy(short _id, string _name, eRole _role, eWeapon _weapon, int _hp, int _str, int _def, int _int, int _mnd,
	int _dex, int _agi, int _move, int _exp, int _lv, char* _filePath) : Unit(_id, _name, _role, _weapon, _hp, _str, _def, _int, _mnd, _dex, _agi, _move, _exp, _lv,  _filePath) {
	mGrHandlesCount = 12;
	mGrHandles = new int[mGrHandlesCount];
	LoadDivGraph("../Resource/Image/Enemy/Enemy00.png", 12, 3, 4, 64, 64, mGrHandles);
	Fanctions[0] = &Enemy::MoveJudgeState;
	Fanctions[1] = &Enemy::MoveState;
	Fanctions[2] = &Enemy::AttackJudgeState;
	Fanctions[3] = &Enemy::AttackState;
	mState = 2;
	mTargeNum = -1;
	/*for (int i = 0; i < 4; i++)mEquipSlot[i] = i;
	mEquipNum = 0;*/
}

Enemy:: ~Enemy() {
	;
}

int Enemy::Initialize() {
	return 0;
}

int Enemy::Initialize(char* _name, eRole _role, eWeapon _weapon, int _hp, int _str, int _def, int _int, int _mnd,
	int _dex, int _agi, int _move, int _exp, int _lv, char* _filePath) {
	return 0;
}

int Enemy::Update() {
	int hoge = 0;
	hoge = (this->*Fanctions[mState])(1);
	mC.x = mPos.x * 64 + 64 / 2;
	mC.y = mPos.y * 64 + 64 / 2;
	return hoge;
}

int Enemy::Draw() {
	Calculator::Draw();
	if (mOnActive == true) DrawGraph(mPos.x, mPos.y, mGrHandles[1], TRUE); //DrawBox(mPos.x, mPos.y, mPos.x + MASSSIZE, mPos.y + MASSSIZE, GetColor(255, 0, 0),true);
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


int Enemy::MoveJudgeState(int _a) {
	if (_a == -1)return _a;
	if (mState < -1)return mState = -1;
	//Initialize();
	for (int i = 0; i < INSTANCE->GetCharaDataSize(); i++) {
		Calculator::Initialize();
		Calculator::CulRange(mMapPos.x, mMapPos.y, 0, i, &mTargeNum);
		
	}
	Calculator::Initialize();
	Calculator::CulRange(mMapPos.x, mMapPos.y, 0, mTargeNum, &mTargeNum);
	/*Calculator::RootCreate(INSTANCE->GetCharaDate(mTargeNum).GetMapPos().x,
		INSTANCE->GetCharaDate(mTargeNum).GetMapPos().y, this);*/
	//Calculator::RootCreate(INSTANCE->GetCharaDate(mTargeNum).GetMapPos().x,
		//INSTANCE->GetCharaDate(mTargeNum).GetMapPos().y, this);
	//Calculator::NearCaluculate();
//	INSTANCE->SetColor(0, 0, 255);
	mState++;
	return _a;
}

int Enemy::MoveState(int _a) {
	//ˆÚ“®‚Í‚Å‚«‚é
	Unit::sPos pos = { 0 };
	//Move(pos);
		//if (Calculator::GetMoveArea(INSTANCE->GetMapPos()) == 1) {
		//	Move(INSTANCE->GetMapPos());
		//	Update();
		//	Calculator::Initialize();
		//	mState++;
		//	return _a;
		//}
	return _a;
}

int Enemy::AttackJudgeState(int _a) {
	Calculator::Initialize();
	Calculator::CulMoveRange(mMapPos.x,mMapPos.y, 2);
	INSTANCE->SetColor(255, 0, 0);

	for (int i = 0; i < INSTANCE->GetCharaDataSize(); i++) {
		if (INSTANCE->GetCharaDate(i).GetOnActive() != false&&
			Calculator::GetMoveArea(INSTANCE->GetCharaDate(i).GetMapPos()) == 1) {
			AttackState(i);
		}
	}
	Calculator::Initialize();
	mStayFlg = true;
	return _a;
}

int Enemy::AttackState(int _a) {
	Chara & tmpChara = INSTANCE->GetCharaDate(_a);
	int damage = 0;
	//Calculator::HitCalculate(*CharaDate[_a],*EnemyDate[tmp]);
	if (mRole == eCaster)damage = Calculator::MagicDamageCalculate(*this, tmpChara);
	else damage = Calculator::PhysicalDamageCalculate(*this, tmpChara);

	tmpChara.Damage(damage);
	//EnemyDate[tmp]->SetOnActive(false);
	Calculator::Initialize();
	mState=2;
	mStayFlg = true;
	return mState;
}
