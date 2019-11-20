#include"EquipDataBase.h"

int EquipDataBase::Initialize() {
	for (int i = 0; i = 10; i++) {
		eqData.emplace_back(new EquipData(i,i+1,i+2));
	}
	return 0;
}

int EquipDataBase::GetEqCount(int _charaId) {
	//for (int i = 0; i < eqData.size(); i++) {
	//	//eqData[i]
	//}
	return 0;
}


int EquipDataBase::GetEq(int _charaId, int _eqNum) {
	return 0;
}


void EquipDataBase::SetEq(int _charaId, int _eqId) {
	;
}


void EquipDataBase::DeleteEq(int _charaId, int _eqId) {
	;
}