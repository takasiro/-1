#pragma once
#include "BaseTask.h"

class SoundMgr : public BaseTask {

public:

	SoundMgr();
	virtual ~SoundMgr();
	virtual int Initialize();	//‰Šú‰»ˆ—
	virtual int Update();		//ŒvZˆ—
	virtual int Draw();			//•`‰æˆ—
	virtual int Close();		//I—¹ˆ—
};