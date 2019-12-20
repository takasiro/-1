#include"EffectMgr.h"


EffectMgr::EffectMgr() {

}
EffectMgr:: ~EffectMgr() {

}
int EffectMgr::Initialize() {
	Load load;
	load.LoadEffect("../Resource/Effect/Effect.csv", mEffect);

	for (auto itr = mEffect.begin(); itr != mEffect.end(); itr++) {
		char buf[256];
		snprintf(buf, 255, "../Resource/Effect/%s", mEffect[itr->first].GetFileName());
		mEffect[itr->first].RenameFileName(buf);
		mEffect[itr->first].Initialize();
		/*mEffect[itr->first].RenameFileName(buf);
		mEffect[itr->first].SetGrHandleCount(mEffect[itr->first].GetAllNum());
		mEffect[itr->first].SetGrHandles(new int[mEffect[itr->first].GetGrHandleCount()]);
		if (!LoadDivGraph(mEffect[itr->first].GetFileName(), mEffect[itr->first].GetAllNum(),
			mEffect[itr->first].GetXNum(), mEffect[itr->first].GetYNum(), mEffect[itr->first].GetXSize(), mEffect[itr->first].GetYSize(),
			mEffect[itr->first].GetGrHandles())) {
			//err
		}*/

	}

	return 0;
}
int EffectMgr::Update() {
	for (auto itr = mActiveObj.begin(); itr != mActiveObj.end(); itr++) {
		if (mEffect[*itr].GetOnActive() == false) {
			mActiveObj.erase(itr);
			if (mActiveObj.size() == 0)break;
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
	if (mEffect.at(_name).GetOnActive() == true)return -1;
	mEffect.at(_name).SetPosXY(_x,_y);
	mEffect.at(_name).SetOnActive(true);
	mEffect.at(_name).ReSetEffectCounter();
	mActiveObj.push_back(_name);
 	return 0;
}