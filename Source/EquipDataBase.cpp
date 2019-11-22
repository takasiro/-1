#include"EquipDataBase.h"

int EquipDataBase::Initialize() {
	for (int i = 0; i = 10; i++) {
		eqData.emplace_back(new EquipData(i,i+1,i+2));
	}
	return 0;
}

int EquipDataBase::GetEqCount(int _charaId) {
	int idCount;
	for (int i = 0; i < eqData.size(); i++) {
		if(eqData[i]->GetCharaId()==_charaId)idCount++;
	}
	return idCount;
}


int EquipDataBase::GetEq(int _charaId, int _eqNum) {
	int tmpNum = 0,eqId = 0;
	for (int i = 0; i < eqData.size(); i++) {
		if (eqData[i]->GetCharaId() == _charaId)tmpNum++;
		if (tmpNum == _eqNum) {
			eqId = eqData[i]->GetEquipId();
			break;
		}
	}
	return eqId;
}


void EquipDataBase::DeleteEq(int _charaId, int _eqId) {
	int dataId = 0;
	
	for (int i = 0; i < eqData.size(); i++) {
		if (eqData[i]->GetCharaId() == _charaId && eqData[i]->GetEquipId() == _eqId) {
			dataId = eqData[i]->GetId();
		}
	}

	eqData.erase(eqData.begin() +(dataId-1));


}