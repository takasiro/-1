#pragma once
#include "BaseObj.h"

class Effect : public BaseObj
{
private:
	char mName[256];
	int mAllNum = 0, mXNum = 0, mYNum = 0, mXSize = 0, mYSize = 0;
	char mFileName[256];
	int mEffectCounter = -1;
public:
	Effect();
	~Effect();
	int SetAll(char*, int, int, int, int, int, char*);
	int Initialize();
	int Update();
	int Draw();
	int Close();
	void ReSetEffectCounter() { mEffectCounter = -1; }
	int GetEffectCounter() { return mEffectCounter; }
	void SetPosXY(int _x, int _y) { mPos.x = _x, mPos.y = _y; }

	int GetAllNum() { return mAllNum; }
	int GetXNum() { return mXNum; }
	int GetYNum() { return mYNum; }
	int GetXSize() { return mXSize; }
	int GetYSize() { return mYSize; }
	char* GetFileName() { return mFileName; }
	void* RenameFileName(const char* _name) { return memcpy(mFileName, _name, 255); }

};

