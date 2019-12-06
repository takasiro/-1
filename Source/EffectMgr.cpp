#include"EffectMgr.h"


EffectMgr::EffectMgr() {

}
EffectMgr:: ~EffectMgr() {

}
int EffectMgr::Initialize() {
	return 0;
}
int EffectMgr::Update() {
	return 0;
}

int EffectMgr::Draw() {
	return 0;
}
int EffectMgr::Close() {
	return 0;
}

int EffectMgr::PlayEffect(string _name, int _x, int _y) {
	mEffect.at(_name).SetPosXY(_x,_y);
	mEffect.at(_name).SetOnActive(true);
	mEffect.at(_name).ReSetEffectCounter();
	return 0;
}