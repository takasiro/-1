#include"SoundMgr.h"

SoundMgr::SoundMgr() {
	mSE["SE01"] = LoadSoundMem("../Resource/Sound/se_maoudamashii_battle01.mp3");
	mBGM["bgm_maoudamashii_orchestra19"] = LoadSoundMem("../Resource/Sound/bgm_maoudamashii_orchestra19.mp3");
	mBGM["bgm_maoudamashii_fantasy13"] = LoadSoundMem("../Resource/Sound/bgm_maoudamashii_fantasy13.mp3");
	mBGM["bgm_maoudamashii_fantasy06"] = LoadSoundMem("../Resource/Sound/bgm_maoudamashii_fantasy06.mp3");
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
