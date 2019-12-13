#include"Chara.h"
#include "Calculator.h"
Chara::Chara() {
}
Chara::Chara(short _id, string _name, eRole _role, eWeapon _weapon, int _hp, int _str, int _def, int _int, int _mnd,
	int _dex, int _agi, int _move, int _exp, int _lv, char* _filePath) :Unit(_id, _name, _role, _weapon, _hp, _str, _def, _int, _mnd,
		_dex, _agi, _move, _exp, _lv, _filePath) {
	/*mColor = GetColor(0, 0, 255);
	mGrHandlesCount = 12;
	mGrHandles = new int[mGrHandlesCount];
	LoadDivGraph("../Resource/Image/Player/Chara00.png", 12, 3, 4, 64, 64, mGrHandles);
*/
	mHpPercent = (double)mHp / (double)mMaXHp;
	mState = 0;
	mGrHandlesCount = 12;
	mGrHandles = new int[mGrHandlesCount];
	mGrHandles2 = new int[mGrHandlesCount];
	LoadDivGraph(mGrFilePath, 12, 3, 4, 64, 64, mGrHandles);
	int len = strlen(mGrFilePath) - 4;
	char tmpWord[256];
	memset(tmpWord, 0x00, sizeof(tmpWord));
   strncpy(tmpWord,mGrFilePath,len);
	strcat(tmpWord, "Acted.png");
	LoadDivGraph(tmpWord, 12, 3, 4, 64, 64, mGrHandles2);
	//mEquipNum = 0;
	Fanctions[0] = &Chara::MoveJudgeState;
	Fanctions[1] = &Chara::MoveState;
	Fanctions[2] = &Chara::AttackJudgeState;
	Fanctions[3] = &Chara::AttackState;
}
Chara::~Chara() {
	DeleteGraph(mGrHandle);
}

Chara::Chara(int _x, int _y) {
	mPos.x = _x;
	mPos.y = _y;
	SetPos(mPos);
	//SetFairy(Fairy(), 0);//フェアリー適当に生成
	mMove = 4;
	mStayFlg = false;
	mOnActive = true;
	mColor = GetColor(0, 0, 255);
	mGrHandlesCount = 12;
	mGrHandles = new int[mGrHandlesCount];
	LoadDivGraph("../Resource/Image/Player/Chara00.png", 12, 3, 4, 64, 64, mGrHandles);
}

//Chara::Chara(Unit) {
//	
//}
//
//Chara::Chara(Chara&) {
//	
//}

int Chara::Initialize() {
	Calculator::Initialize();
	mState = 0;
	INSTANCE->SetMouseButton(0);
	INSTANCE->SetLastMouseButton(0);
	INSTANCE->SetMapPos(Unit::sPos{ 0,0 });
	INSTANCE->SetMousePos(Unit::sPos{ 0,0 });
	return 0;
}
int Chara::Initialize(short _id, string _name, eRole _role, eWeapon _weapon, int _hp, int _str, int _def, int _int, int _mnd,
	int _dex, int _agi, int _move, int _exp, int _lv, char* _filePath) {

	return 0;
}
int Chara::Update() {
	mC.x = mPos.x * 64 + 64 / 2;
	mC.y = mPos.y * 64 + 64 / 2;
	if (mStayFlg == true) return 1;
	else return 0;
}
int Chara::Update(int _num) {
	if (mState < 0) {
		mState = 0;
		return -1;
	}
	int hoge = 0;
	mC.x = mPos.x * 64 + 64 / 2;
	mC.y = mPos.y * 64 + 64 / 2;
	hoge = (this->*Fanctions[mState])(_num);

	return hoge;
}

int Chara::Draw() {
	HpBar();
	/*if (mStayFlg == false)mColor = GetColor(0, 0, 255);
	else mColor = GetColor(150, 150, 150);*/
	//if(mGrHandle == -1)DrawBox(mPos.x, mPos.y, mPos.x + MASSSIZE, mPos.y + MASSSIZE, mColor, true);
	 //else LoadGraphScreen(mPos.x, mPos.y,"../Resource/Image/Map/map1.png",false);
	if (mOnActive == true) {
		if (mStayFlg == false) DrawGraph(mPos.x, mPos.y, mGrHandles[2], TRUE);
		else DrawGraph(mPos.x, mPos.y, mGrHandles2[2], TRUE);
		DrawBox(mPos.x + 10, mPos.y + 58, mPos.x + 54, mPos.y + 64, GetColor(0, 0, 0), true);
		DrawBox(mPos.x + 10, mPos.y + 58, (mPos.x + 10) + 44 * mHpPercent, mPos.y + 64, mHpColor, true);
	}
	return 0;
}
int Chara::Close() {
	return 0;
}
int Chara::StatusUp(int lv) {
	return 0;
}
int Chara::LastStatus() {
	return 0;
}

int Chara::Move(Unit::sPos _pos) {
	mPos.x = _pos.x * MASSSIZE;
	mPos.y = _pos.y * MASSSIZE;
	mMapPos.x = _pos.x;
	mMapPos.y = _pos.y;
	//ステイフラグは一時的な処理
	/*if (mStayFlg == false) {
		mStayFlg = true;
		mColor = GetColor(150, 150, 150);
	}
	else {
		mStayFlg = false;
		mColor = GetColor(0, 0, 255);
	}*/
	return 0;
}

int Chara::MoveJudgeState(int _a) {
	if (_a == -1)return _a;
	if (mState < -1)return mState = -1;
	//Initialize();
	Calculator::CulMoveRange(INSTANCE->SetPrevPosX(mPos.x / MASSSIZE), INSTANCE->SetPrevPosY(mPos.y / MASSSIZE), mMove);
	Calculator::MoveJudg(INSTANCE->GetCharaDate(), INSTANCE->GetEnemyDate(), _a);
	INSTANCE->SetColor(0, 0, 255);
	mState += 1;
	return _a;
}

int Chara::MoveState(int _a) {

	if (RIGHTCLICK != FALSE && INSTANCE->GetMouseButton() != INSTANCE->GetLastMouseButton()) {
		Initialize();
		mState -= 1;
	}
	if (LEFTCLICK != FALSE && INSTANCE->GetMouseButton() != INSTANCE->GetLastMouseButton()) {
		/*Unit::sPos clickPos = GET_POSITION();
		Unit::sPos mapPos = clickPos;
		mapPos.x = (int)mapPos.x / MASSSIZE;
		mapPos.y = (int)mapPos.y / MASSSIZE;*/
		INSTANCE->SetMousePos(GET_POSITION());
		INSTANCE->SetMapPos(GET_POSITION());
		//INSTANCE->SetMousePos(GET_POSITION());

		//INSTANCE->SetMapPos(INSTANCE->GetMousePos());

		//Unit::sPos tmp = INSTANCE->GetMapPos();
		if (Calculator::GetMoveArea(INSTANCE->GetMapPos()) == 1) {
			Move(INSTANCE->GetMapPos());
			Update();
			Calculator::Initialize();
			mState++;
			return _a;
		}
	}
	return _a;
}

int Chara::AttackJudgeState(int _a) {
	if (mRole != eCaster) {
		Calculator::CulMoveRange(mPos.x / MASSSIZE, mPos.y / MASSSIZE, 2);
	}
	else {
		Calculator::CulMoveRange(mPos.x / MASSSIZE, mPos.y / MASSSIZE, 1);
	}
	INSTANCE->SetColor(255, 0, 0);
	if (RIGHTCLICK != FALSE && INSTANCE->GetMouseButton() != INSTANCE->GetLastMouseButton()) {
		Move(INSTANCE->GetPrevPos());
		mStayFlg = false;
		Initialize();
	}



	if (LEFTCLICK != FALSE && INSTANCE->GetMouseButton() != INSTANCE->GetLastMouseButton()) {
		INSTANCE->SetMousePos(GET_POSITION());
		INSTANCE->SetMapPos(GET_POSITION());
		if (INSTANCE->GetMapPos().x == mMapPos.x &&
			INSTANCE->GetMapPos().y == mMapPos.y) {
			Initialize();
			mStayFlg = true;
			mState = -1;
			return mState;
		}
		else if (Calculator::GetMoveArea(INSTANCE->GetMapPos()) == 1) {
			int tmp = INSTANCE->CulNum(INSTANCE->GetMapPos(), ENEMY, 1);

			if (tmp == -1) {
				//Initialize();
				//mState = -1;
				//return mState;

			}
			else {
				mStayFlg = true;
				mState++;
			}
		}


	}
	//	state++;

	return _a;
}

int Chara::AttackState(int _a) {
	int tmp = 0;
	tmp = INSTANCE->CulNum(INSTANCE->GetMousePos(), ENEMY, 0);
	int damage = 0;
	Enemy& tmpEnemy = INSTANCE->GetEnemyDate(tmp);
	//Calculator::HitCalculate(*CharaDate[_a],*EnemyDate[tmp]);
	if (mRole == eCaster)damage = Calculator::MagicDamageCalculate(*this, tmpEnemy);
	else damage = Calculator::PhysicalDamageCalculate(*this, tmpEnemy);

	tmpEnemy.Damage(damage);
	if (tmpEnemy.GetOnActive() == false)tmpEnemy.SetStayFlg(true);
	//EnemyDate[tmp]->SetOnActive(false);
	Initialize();
	mStayFlg = true;
	mState = -1;
	return mState;
}


