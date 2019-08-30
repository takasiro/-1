#include "UnitMgr.h"

UnitMgr::UnitMgr() {
	;
}
UnitMgr::~UnitMgr() {
	;
}
int UnitMgr::Initialize() {
	return 0;
}	
int UnitMgr::Update() {
	for (int i = 0; i < CharaDate.size(); i++) {
		CharaDate[i]->Update();
	}
	for (int i = 0; i < EnemyDate.size(); i++) {
		EnemyDate[i]->Update();
	}
	return 0;
}	
int UnitMgr::Draw() {
	return 0;
}			
int UnitMgr::Close() {
	return 0;
}		