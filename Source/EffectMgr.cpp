#include"EffectMgr.h"


EffectMgr::EffectMgr() {

}
EffectMgr:: ~EffectMgr() {

}
int EffectMgr::Initialize() {
	Load load;
	load.LoadEffect("../Resource /Effect/Effect.csv", mEffect);
	return 0;
}
int EffectMgr::Update() {
	for (auto itr = mActiveObj.begin(); itr != mActiveObj.end(); itr++) {
		if (mEffect[*itr].GetOnActive()) {
			mActiveObj.erase(itr);
			continue;
		}
		mEffect[*itr].Update();
	}
//	for (auto itr = mEffect.begin(); itr != mEffect.end(); itr++) {
//		itr->second.Update();		
//	}
	return 0;
}

int EffectMgr::Draw() {
	for (auto itr = mActiveObj.begin(); itr != mActiveObj.end(); itr++) {
		mEffect[*itr].Draw();
	}
	return 0;
}
int EffectMgr::Close() {

	return 0;
}

int EffectMgr::PlayEffect(string _name, int _x, int _y) {
	//if (mEffect.at(_name))return -1;
	mEffect.at(_name).SetPosXY(_x,_y);
	mEffect.at(_name).SetOnActive(true);
	mEffect.at(_name).ReSetEffectCounter();
	mActiveObj.push_back(_name);
	return 0;
}