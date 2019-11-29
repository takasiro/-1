#pragma once
#include "DxLib.h"
#include "BaseTask.h"
#include "Singleton.h"
#include <map>


class SoundMgr : public BaseTask , public Singleton<SoundMgr>{
	
	//Singleton�p
	SoundMgr();
	virtual ~SoundMgr();
	friend Singleton<SoundMgr>;

private:
	//���y�f�[�^
	std::map<string, int> mSE;
	std::map<string, int> mBGM;

public:
	virtual int Initialize();	//����������
	virtual int Update();		//�v�Z����
	virtual int Draw();			//�`�揈��
	virtual int Close();		//�I������

	//�Đ�
	int PlaySE(const char*);
	int PlayBGM(const char*);
	//�m�F
	int CheckSE(const char*);
	int CheckBGM(const char*);
	//��~
	int StopSE(const char*);
	int StopBGM(const char*);

	int GetSE(const char* _SEName) { return mSE[_SEName]; }
	int GetBGM(const char * _BGMName){ return mBGM[_BGMName]; }
};