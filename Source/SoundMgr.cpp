#include"SoundMgr.h"

SoundMgr::SoundMgr() {
	mSE["SE01"] = LoadSoundMem("../Sound/se01.wav");
	mBGM["BGM01"] = LoadSoundMem("../Sound/bgm01.wav");
}
SoundMgr:: ~SoundMgr() {
	InitSoundMem();
}
int SoundMgr::Initialize() {
	return 0;
}
int SoundMgr::Update() {
	return 0;
}

int SoundMgr::Draw() {
	return 0;
}
int SoundMgr::Close() {
	return 0;
}


int SoundMgr::PlaySE(const char* _SEName) {
	return PlaySoundMem(mSE[_SEName], DX_PLAYTYPE_BACK, true);
}
int SoundMgr::PlayBGM(const char* _BGMName) {
	return PlaySoundMem(mBGM[_BGMName], DX_PLAYTYPE_LOOP, true);
}

int SoundMgr::CheckSE(const char* _SEName) {
	return  CheckSoundMem(mSE[_SEName]);
}
int SoundMgr::CheckBGM(const char* _BGMName) {
	return CheckSoundMem(mSE[_BGMName]);
}

int SoundMgr::StopSE(const char* _SEName) {
	return  StopSoundMem(mSE[_SEName]);
}
int SoundMgr::StopBGM(const char* _BGMName) {
	return StopSoundMem(mSE[_BGMName]);
}
