#include"Calculator.h"

Calculator::Calculator() {
	;
}

void Calculator::Initialize() {
	Calculator::mTmpMap = vector<int>(mMapSize, -1);
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
	mTmpMap = vector<int>(Calculator::mMapSize, -1);
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

int Calculator::MoveJudg(vector<Chara*>& _chara, vector<Enemy*>& _enemy, int _num) {

	for (int i = 0; i < _chara.size(); i++) {
		if (i == _num) continue;
		if (_chara[i]->GetOnActive() != false)mTmpMap[_chara[i]->GetPosY() / MASSSIZE * 20 + _chara[i]->GetPosX() / MASSSIZE] = -1;
	}
	for (int i = 0; i < _enemy.size(); i++) {
		if (_enemy[i]->GetOnActive() != false)mTmpMap[_enemy[i]->GetPosY() / MASSSIZE * 20 + _enemy[i]->GetPosX() / MASSSIZE] = -1;
	}

	return 0;
}

int Calculator::EvasionCalculate(Unit _Atk, Unit _Def) {
	return 0;
}

int Calculator::PhysicalDamageCalculate(Unit _Atk, Unit _def) {
	Fairy& AtkFairy = INSTANCE->GetFairyDate(_Atk.GetEquip(_Atk.GetEquipNum()));
	Fairy& DefFairy = INSTANCE->GetFairyDate(_def.GetEquip(_def.GetEquipNum()));
	int tmp = (_Atk.GetStr() + AtkFairy.GetStr()) - (_def.GetDef() + DefFairy.GetDef());
	if (tmp < 0)tmp = 0;
	//int tmp = UŒ‚.str + (UŒ‚.level * UŒ‚.str¬’·) + UŒ‚.•Šístr ( UŒ‚.•Šílevel * UŒ‚.•Šístr¬’·) -
	//			–hŒä.def + (–hŒä.level * –hŒä.def¬’·) + –hŒä.•Šídef ( –hŒä.•Šílevel * –hŒä.•Šídef¬’·)
	//if(tmp < 0) tmp = 0;
	//return tmp;
	return tmp;
}
int Calculator::MagicDamageCalculate(Unit _Atk, Unit _def) {
	Fairy& AtkFairy = INSTANCE->GetFairyDate(_Atk.GetEquip(_Atk.GetEquipNum()));
	Fairy& DefFairy = INSTANCE->GetFairyDate(_def.GetEquip(_def.GetEquipNum()));
	int tmp = (_Atk.GetInt() + AtkFairy.GetInt()) - (_def.GetMnd() + DefFairy.GetDef());
	if (tmp < 0)tmp = 0;
	//int tmp = UŒ‚.mgc + (UŒ‚.level * UŒ‚.mgc¬’·) + UŒ‚.•Šímgc ( UŒ‚.•Šílevel * UŒ‚.•Šímgc¬’·) -
	//			–hŒä.mnd + (–hŒä.level * –hŒä.mnd¬’·) + –hŒä.•Šímnd ( –hŒä.•Šílevel * –hŒä.•Šímnd¬’·)
	//if(tmp < 0) tmp = 0;
	//return tmp;

	return tmp;
}

vector<Mass>* Calculator::mCopyMap;

vector<int> Calculator::mTmpMap;

int Calculator::mMapSize;