#pragma once
#include "DxLib.h"
#include "BaseTask.h"
#include "Singleton.h"
#include <map>


class SoundMgr : public BaseTask , public Singleton<SoundMgr>{
	
	//Singleton用
	SoundMgr();
	virtual ~SoundMgr();
	friend Singleton<SoundMgr>;

private:
	//音楽データ
	std::map<string, int> mSE;
	std::map<string, int> mBGM;

public:
	virtual int Initialize();	//初期化処理
	virtual int Update();		//計算処理
	virtual int Draw();			//描画処理
	virtual int Close();		//終了処理

	//再生
	int PlaySE(const char*);
	int PlayBGM(const char*);
	//確認
	int CheckSE(const char*);
	int CheckBGM(const char*);
	//停止
	int StopSE(const char*);
	int StopBGM(const char*);

	int GetSE(const char* _SEName) { return mSE[_SEName]; }
	int GetBGM(const char * _BGMName){ return mBGM[_BGMName]; }
};