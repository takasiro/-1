#include"Calculator.h"
#define START  0
#define GOAL -5
Calculator::Calculator() {
	Initialize();
}

void Calculator::Initialize() {
	Calculator::mTmpMap = vector<int>(mMapSize, -1);
	Calculator::mRangeMap = vector<int>(mMapSize, -1);
	Calculator::mRootMap = vector<int>(mMapSize, 0);
	mCharaRange = 0;
}
int Calculator::SetCost(int _terrain) {
	int tmpCost = 0;
	if (_terrain == 0)return tmpCost = 0;
	else if (_terrain == Map::eGrassland)return tmpCost = 1;
	else	 if (_terrain == Map::eGrass)return tmpCost = 1;
	else	 if (_terrain == Map::eRock)return tmpCost = 10;
	else	 if (_terrain == Map::eRiver)return tmpCost = 10;
	else	 if (_terrain == Map::eHill)return tmpCost = 2;
	else	 if (_terrain == Map::eVillage)return tmpCost = 1;
	else	 if (_terrain == Map::eForest)return tmpCost = 2;
	else	 if (_terrain == Map::eVolcanoSoil)return tmpCost = 1;
	else	 if (_terrain == Map::eMagma)return tmpCost = 1;
	else   if (_terrain == Map::eVolcanoRock)return tmpCost = 10;
	else	 if (_terrain == Map::eCaveSoil)return tmpCost = 1;
	else	 if (_terrain == Map::eCaveRock)return tmpCost = 10;
	else	 if (_terrain == Map::eDemonKingFloor)return tmpCost = 1;
	else	 if (_terrain == Map::eDemonKingPillars)return tmpCost = 10;
	else	 if (_terrain == Map::eDemonKingCarpet)return tmpCost = 1;
}

void Calculator::SetMap(Map& _map) {
	mCopyMap = _map.GetMapAdress();
	mMapSize = _map.GetMapSize();
	mNowMapWidth = 20;//;map.GetMapWidth();
	mNowMapHeight = 15;//_map.GetMapHeight();
	mTmpMap = vector<int>(Calculator::mMapSize, -1);
	mRangeMap = vector<int>(Calculator::mMapSize, -1);
	mRootMap = vector<int>(Calculator::mMapSize, 0);
	//printf("%d", mTmpMap.size());
}

int Calculator::CulMoveRange(int _x, int _y, int _moveRange) {
	if (_moveRange <= 0)return -1;
	for (int i = 0; i < 4; i++) {
		int vx = 0, vy = 0;
		switch (i) {
		case eUP:
			vy--;
			break;
		case eRIGHT:
			vx++;
			break;
		case eDOWN:
			vy++;
			break;
		case eLEFT:
			vx--;
			break;
		}
		if (_x + vx < 20 && _x + vx>0 && _y + vy < 15 && _y + vy>0) {
			if (mCopyMap->at((_y + vy) * 20 + ((_x)+vx)).GetMoveCost() < 10) {
				mTmpMap[(_y + vy) * 20 + ((_x)+vx)] = 1;
				CulMoveRange(_x + vx, _y + vy, _moveRange - mCopyMap->at((_y - 1) * 20 + (_x - 1)).GetMoveCost());
			}
		}
	}
	return 0;

}
int Calculator::CulMoveRange(Unit::sPos _pos, int _moveRange) {
	if (_moveRange <= 0)return -1;
	for (int i = 0; i < 4; i++) {
		int vx = 0, vy = 0;
		switch (i) {
		case eUP:
			vy--;
			break;
		case eRIGHT:
			vx++;
			break;
		case eDOWN:
			vy++;
			break;
		case eLEFT:
			vx--;
			break;
		}						//Map.GetMapWidth()
		if (_pos.x + vx < 20 && _pos.x + vx>0 && _pos.y + vy < 15 && _pos.y + vy>0) {
			if (mCopyMap->at((_pos.y + vy) * 20 + ((_pos.x) + vx)).GetMoveCost() < 10) {
				mTmpMap[(_pos.y + vy) * 20 + ((_pos.x) + vx)] = 1;
				CulMoveRange(_pos, _moveRange - mCopyMap->at((_pos.y - 1) * 20 + (_pos.x - 1)).GetMoveCost());
			}
		}
	}
	return 0;

}


int Calculator::MoveJudg(vector<Chara*>& _chara, vector<Enemy*>& _enemy, int _num) {

	for (int i = 0; i < _chara.size(); i++) {
		if (i == _num) continue;
		if (_chara[i]->GetOnActive() != false)mTmpMap[_chara[i]->GetMapPos().y * 20 + _chara[i]->GetMapPos().x] = -1;
	}
	for (int i = 0; i < _enemy.size(); i++) {
		if (_enemy[i]->GetOnActive() != false)mTmpMap[_enemy[i]->GetMapPos().y * 20 + _enemy[i]->GetMapPos().x] = -1;
	}

	return 0;
}
//template  typename T
int Calculator::HitCalculate(Unit _Atk, Unit _Def) {
	if ((_Atk.GetAgi() + _Def.GetAgi()) / 2 < _Atk.GetAgi() - _Def.GetAgi());
	return 0;
}
int Calculator::PhysicalDamageCalculate(Unit _Atk, Unit _def) {
	//Fairy& AtkFairy = INSTANCE->GetFairyDate(_Atk.GetEquip(_Atk.GetEquipNum()));
	//Fairy& DefFairy = INSTANCE->GetFairyDate(_def.GetEquip(_def.GetEquipNum()));
	int tmp = (_Atk.GetStr() /*+ AtkFairy.GetStr()*/) - (_def.GetDef() /*+ DefFairy.GetDef()*/);
	if (tmp < 0)tmp = 0;
	//int tmp = çUåÇ.str + (çUåÇ.level * çUåÇ.strê¨í∑) + çUåÇ.ïêäÌstr ( çUåÇ.ïêäÌlevel * çUåÇ.ïêäÌstrê¨í∑) -
	//			ñhå‰.def + (ñhå‰.level * ñhå‰.defê¨í∑) + ñhå‰.ïêäÌdef ( ñhå‰.ïêäÌlevel * ñhå‰.ïêäÌdefê¨í∑)
	//if(tmp < 0) tmp = 0;
	//return tmp;
	return tmp;
}
int Calculator::MagicDamageCalculate(Unit _Atk, Unit _def) {
	//Fairy& AtkFairy = INSTANCE->GetFairyDate(_Atk.GetEquip(_Atk.GetEquipNum()));
	//Fairy& DefFairy = INSTANCE->GetFairyDate(_def.GetEquip(_def.GetEquipNum()));
	int tmp = (_Atk.GetInt() /*+ AtkFairy.GetInt()*/) - (_def.GetMnd() /*+ DefFairy.GetDef()*/);
	if (tmp < 0)tmp = 0;
	//int tmp = çUåÇ.mgc + (çUåÇ.level * çUåÇ.mgcê¨í∑) + çUåÇ.ïêäÌmgc ( çUåÇ.ïêäÌlevel * çUåÇ.ïêäÌmgcê¨í∑) -
	//			ñhå‰.mnd + (ñhå‰.level * ñhå‰.mndê¨í∑) + ñhå‰.ïêäÌmnd ( ñhå‰.ïêäÌlevel * ñhå‰.ïêäÌmndê¨í∑)
	//if(tmp < 0) tmp = 0;
	//return tmp;

	return tmp;
}

int Calculator::CulRange(int _x, int _y, int _range, int _index, int* _arg,vector<Direction>* _dir) {
	//ÉÅÉìÉoïœêîÇ…Ç∑ÇÈÇ◊Ç´
	static	Unit::sPos pos = { 0 };
	static	vector<Chara*> test;
	static	int tmp;
	//ÉÅÉìÉoïœêîÇ…Ç∑ÇÈÇ◊Ç´
	static	int tmpArray[8] = { 99 ,99,99,99,99,99,99,99 };


	test = INSTANCE->GetCharaDate();
	if (pos.x != test[_index]->GetMapPos().x &&
		pos.y != test[_index]->GetMapPos().y) {
		pos.x = test[_index]->GetMapPos().x;
		pos.y = test[_index]->GetMapPos().y;
		tmp = 0;
	}
	for (int i = 0; i < test.size(); i++) {
		if (_index != i)mTmpMap[test[i]->GetMapPos().y * 20 + test[i]->GetMapPos().x] = -10;
		else mTmpMap[test[_index]->GetMapPos().y * 20 + test[_index]->GetMapPos().x] = GOAL;
	}
	if (_range == 0) {
		mRangeMap[_y * 20 + _x] = START;
		mTmpMap[_y * 20 + _x] = START;
	}
	if (_range >= 50)return -1;
	_range++;
	for (int i = 0; i < 4; i++) {

		int vx = 0, vy = 0;
		switch (i) {
		case eUP:
			vy--;
			break;
		case eRIGHT:
			vx++;
			break;
		case eDOWN:
			vy++;
			break;
		case eLEFT:
			vx--;
			break;
		}

		if ((_x == 0 && vx == -1) || (_y == 0 && vy == -1) ||
			(_x == mNowMapWidth - 1 && vx == 1) || (_y == mNowMapHeight - 1 && vy == 1) ||
			mTmpMap[(_y + vy) * 20 + (_x + vx)] == -10) {
			continue;
		}


		if (mTmpMap[(_y + vy) * 20 + (_x + vx)] == GOAL) {
			tmpArray[_index] = _range;
			mRangeMap[(_y + vy) * 20 + (_x + vx)] = _range ;
			_dir->emplace_back((i + 2) % 4);
		}
		////êVÇÃéûÇ…ãNìÆÇ∑ÇÈèåèÇ…
		if ((mCopyMap->at((_y + vy) * 20 + (_x + vx)).GetMoveCost() < 10 || mTmpMap[(_y + vy) * 20 + (_x + vx)] == GOAL) &&
			(mRangeMap[(_y + vy) * 20 + (_x + vx)] == -1 || mRangeMap[(_y + vy) * 20 + (_x + vx)] > _range)) {
			mRangeMap[(_y + vy) * 20 + (_x + vx)] = _range;
			_dir->emplace_back((i + 2) % 4);
			CulRange(_x + vx, _y + vy, _range, _index, _arg,_dir);
		}
	}
	if (_index == INSTANCE->GetCharaDataSize() - 1 && tmpArray[_index] != 99) {
		int idx = 0;
		for (int i = 0; i < INSTANCE->GetCharaDataSize(); i++) {
			if (tmpArray[idx] > tmpArray[i])idx = i;
		}
		*_arg = idx;

		//	memset(tmpArray, 99, 8);
	}
	return _range;
}
int Calculator::NearCaluculate(int _x, int _y, int _range, int _index, int _area) {
	//ÉÅÉìÉoïœêîÇ…Ç∑ÇÈÇ◊Ç´
	Unit::sPos pos = INSTANCE->GetCharaDate(_index).GetmPos();
	if (_range >= _area)return -1;
	_range++;
	for (int i = 0; i < 4; i++) {
		int vx = 0, vy = 0;
		switch (i) {
		case eUP:
			vy--;
			break;
		case eRIGHT:
			vx++;
			break;
		case eDOWN:
			vy++;
			break;
		case eLEFT:
			vx--;
			break;
		}
		if (mTmpMap[(_y + vy) * 20 + (_x + vx)] == 1 && (_y + vy != pos.y && _x + vx != pos.x)) {
			//if (mCharaRange < _range)mCharaRange = _range;
			return _index;
		}
	}

	return _index;
}


int Calculator::RootCreate(int _x, int _y) {
	for (int i = 0; i < 4; i++) {
		int vx = 0, vy = 0;
		switch (i) {
		case eUP:
			vy--;
			break;
		case eRIGHT:
			vx++;
			break;
		case eDOWN:
			vy++;
			break;
		case eLEFT:
			vx--;
			break;
		}

		if ((_x == 0 && vx == -1) || (_y == 0 && vy == -1) ||
			(_x == mNowMapWidth - 1 && vx == 1) || (_y == mNowMapHeight - 1 && vy == 1)) {
			continue;
		}

		if (mRangeMap[(_y + vy) * 20 + (_x + vx)] == 0) {
			if (mTmpMap[(_y + vy) * 20 + (_x + vx)] == START) {
				mRootMap[(_y + vy) * 20 + (_x + vx)] = 0;
				return 0;
			}
		}
		else if (mRangeMap[(_y + vy) * 20 + (_x + vx)] == mRangeMap[(_y) * 20 + (_x)] - 1) {
			/*routeDirection[routeDirectionCount] = i;
			routeDirectionCount++;*/
			mRootMap[(_y + vy) * 20 + (_x + vx)] = 1;
			RootCreate(_x + vx, _y + vy);
			return 0;
		}
	}
	return 0;
}
int Calculator::RootCreate(BaseObj::sPos _pos) {
	for (int i = 0; i < 4; i++) {
		int vx = 0, vy = 0;
		switch (i) {
		case eUP:
			vy--;
			break;
		case eRIGHT:
			vx++;
			break;
		case eDOWN:
			vy++;
			break;
		case eLEFT:
			vx--;
			break;
		}

		if ((_pos.x == 0 && vx == -1) || (_pos.y == 0 && vy == -1) ||
			(_pos.x == mNowMapWidth - 1 && vx == 1) || (_pos.y == mNowMapHeight - 1 && vy == 1)) {
			continue;
		}

		if (mRangeMap[(_pos.y + vy) * 20 + (_pos.x + vx)] == 0) {
			if (mRangeMap[(_pos.y + vy) * 20 + (_pos.x + vx)] == START) {
				mRootMap[(_pos.y + vy) * 20 + (_pos.x + vx)] = 0;
				return 0;
			}
		}
		else if (mRangeMap[(_pos.y + vy) * 20 + (_pos.x + vx)] == mRangeMap[(_pos.y) * 20 + (_pos.x)] - 1) {
			/*routeDirection[routeDirectionCount] = i;
			routeDirectionCount++;*/
			mRootMap[(_pos.y + vy) * 20 + (_pos.x + vx)] = 1;
			RootCreate(_pos.x + vx, _pos.y + vy);
			return 0;
		}
	}
	return 0;
}

void Calculator::Draw() {
	if (mRangeMap.size() != 0) {
		for (int i = 0; i < mTmpMap.size(); i++) {
			DrawFormatString(64 * (i % 20), 64 * (i / 20), GetColor(0, 0, 0), "%d", mTmpMap[i]);
		}
		for (int i = 0; i < mRangeMap.size(); i++) {
			DrawFormatString(64 * (i % 20), 64 * (i / 20) + 20, GetColor(0, 0, 0), "%d", mRangeMap[i]);
		}
		for (int i = 0; i < mRootMap.size(); i++) {
			DrawFormatString(64 * (i % 20), 64 * (i / 20) + 40, GetColor(255, 0, 0), "%d", mRootMap[i]);
		}
	}
}

vector<Mass>* Calculator::mCopyMap;
vector<int> Calculator::mRangeMap;
vector<int> Calculator::mTmpMap;
vector<int> Calculator::mRootMap;
int Calculator::mMapSize;
int Calculator::mNowMapHeight;
int Calculator::mNowMapWidth;
int Calculator::mCharaRange;
