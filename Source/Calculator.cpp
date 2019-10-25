#include"Calculator.h"

Calculator::Calculator() {
	;
}

void Calculator::Initialize() {
	mTmpMap = vector<int>(mMapSize, -1);
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

int Calculator::CulMoveRange(int _x, int _y, int _moveRange) {
	if (_moveRange <= 0)return -1;
	for (int i = 0; i < 4; i++) {
		int vx = 0, vy = 0;
		switch (i) {
		case UP:
			vy--;
			break;
		case RIGHT:
			vx++;
			break;
		case DOWN:
			vy++;
			break;
		case LEFT:
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

int Calculator::MoveJudg(vector<Chara*>& _chara, vector<Enemy*>&_enemy, int _num) {

	for (int i = 0; i < _chara.size(); i++) {
		if (i == _num) continue;
		if (_chara[i]->GetOnActive() != false)mTmpMap[_chara[i]->GetPosY()/MASSSIZE * 20 + _chara[i]->GetPosX()/ MASSSIZE] = -1;
	}
	for (int i = 0; i < _enemy.size(); i++) {
		if (_enemy[i]->GetOnActive() != false)mTmpMap[_enemy[i]->GetPosY()/ MASSSIZE * 20 + _enemy[i]->GetPosX()/ MASSSIZE] = -1;
	}

	return 0;
}


int Calculator::PhysicalDamageCalculate(Unit _Atk, Unit _def) {
	//int tmp = UŒ‚.str + (UŒ‚.level * UŒ‚.str¬’·) + UŒ‚.•Šístr ( UŒ‚.•Šílevel * UŒ‚.•Šístr¬’·) -
	//			–hŒä.def + (–hŒä.level * –hŒä.def¬’·) + –hŒä.•Šídef ( –hŒä.•Šílevel * –hŒä.•Šídef¬’·)
	//if(tmp < 0) tmp = 0;
	//return tmp;
	return 0;
}
int Calculator::MagicDamageCalculate(Unit _Atk, Unit _def) {
	//int tmp = UŒ‚.mgc + (UŒ‚.level * UŒ‚.mgc¬’·) + UŒ‚.•Šímgc ( UŒ‚.•Šílevel * UŒ‚.•Šímgc¬’·) -
	//			–hŒä.mnd + (–hŒä.level * –hŒä.mnd¬’·) + –hŒä.•Šímnd ( –hŒä.•Šílevel * –hŒä.•Šímnd¬’·)
	//if(tmp < 0) tmp = 0;
	//return tmp;

	return 0;
}