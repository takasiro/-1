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
		if (CharaDate[i]->GetStayFlg() == true)continue;
		CharaDate[i]->Update();
	}
	for (int i = 0; i < EnemyDate.size(); i++) {
		EnemyDate[i]->Update();
	}
	return 0;
}	

int UnitMgr::Update(int _a) {
	//エラー処理 何も触れていなかったら
	if (_a != -1)return 0;
		CharaDate[_a]->Update();
	
	for (int i = 0; i < EnemyDate.size(); i++) {
		EnemyDate[i]->Update();
	}
	return 0;
}
int UnitMgr::Draw() {
	for (int i = 0; i < CharaDate.size(); i++) {
		CharaDate[i]->Draw();
	}
	for (int i = 0; i < EnemyDate.size(); i++) {
		EnemyDate[i]->Draw();
	}
	return 0;
}			
int UnitMgr::Close() {
	return 0;
}		

int UnitMgr::CulNum(BaseObj::sPos _arg,int _type) {
	//プレイヤー検索
	if (_type == PLAYER) {
		for (int i = 0; i < CharaDate.size(); i++) {
			if (CharaDate[i]->GetStayFlg() != false)continue;
			if ((_arg.x  > CharaDate[i]->GetPosX())&& (_arg.x < CharaDate[i]->GetPosX()+MASSSIZE) +
				(_arg.y  > CharaDate[i]->GetPosY())&& (_arg.y < CharaDate[i]->GetPosY()+MASSSIZE)  )
				return i;
		}
	}
	//敵検索
	else if (_type == ENEMY) {
		for (int i = 0; i < EnemyDate.size(); i++) {
			if (EnemyDate.size() == 0)break;
			if (_arg.x / MASSSIZE == EnemyDate[i]->GetPosX() &&
				_arg.y / MASSSIZE == EnemyDate[i]->GetPosY())
				return i;
		}
	}
	else  {
		for (int i = 0; i < FairyDate.size(); i++) {
			if (FairyDate.size()==0)break;
			if (_arg.x / MASSSIZE == FairyDate[i]->GetPosX() &&
				_arg.y / MASSSIZE == FairyDate[i]->GetPosY())
				return i;
		}
	}
	return -1;
}