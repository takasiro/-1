#include"Map.h"
#include"DxLib.h"
Map::Map() {
	//mMap
	//	mConnect
	mMapNum = 0;

}

int Map::Initialize() {
	return 0;
}

int Map::Update() {
	return 0;
}


int Map::Draw() {
	/*for (int i = 0; i < mMap.size(); i++) {
		DrawFormatString(0 + 10 * i, 0, GetColor(255, 255, 255), "%d\n", mMap[i].GetLandType());
	}*/
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 20; j++) {
			MassDraw(mMap[i * 20 + j].GetLandType());
			DrawBox(j * 64, i * 64, j * 64 + 64, i * 64 + 64, color, true);
		}
	}
	return 0;
}

void Map::MassDraw(int _landType) {
	if (_landType == 0)color = GetColor(0, 0, 0);
	else if (_landType == eGrassland)color = GetColor(198, 224, 180);
	else	 if (_landType == eGrass)color = GetColor(112, 173, 71);
	else	 if (_landType == eRock)color = GetColor(191, 143, 0);
	else	 if (_landType == eRiver)color = GetColor(155, 194, 230);
	else	 if (_landType == eHill)color = GetColor(128, 96, 0);
	else	 if (_landType == eVillage)color = GetColor(244, 176, 132);
	else	 if (_landType == eForest)color = GetColor(55, 86, 35);
	else	 if (_landType == eVolcanoSoil)color = GetColor(255, 0, 0);
	else	 if (_landType == eMagma)color = GetColor(192, 0, 0);
	else   if (_landType == eVolcanoRock)color = GetColor(166, 166, 166);
	else	 if (_landType == eCaveSoil)color = GetColor(131, 60, 12);
	else	 if (_landType == eCaveRock)color = GetColor(58, 56, 56);
	else	 if (_landType == eDemonKingFloor)color = GetColor(102, 0, 102);
	else	 if (_landType == eDemonKingPillars)color = GetColor(117, 113, 113);
	else	 if (_landType == eDemonKingCarpet)color = GetColor(165, 0, 33);
}

int Map::Close() {
	return 0;
}