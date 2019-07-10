#pragma once
#include "BaseObj.h"
#include <iostream>
using namespace std;
class fairy :public BaseObj {
protected:
	string *mName;
	int mDamage;//•Ší‚ÌUŒ‚—Í
	int	mRange;//•Ší‚ÌUŒ‚”ÍˆÍ
	int	mWeight;//“ñ‰ñUŒ‚‚É‰e‹¿‚³‚¹‚é•Ï”
	int	mMagicDamage;//–‚–@UŒ‚—Í
public:
	fairy();
	fairy(string *_name,int _damage, int _range, int _weight, int _magicdamage);
	virtual ~fairy();
	int Initialize();
	int Update();
	int Draw();
	int Close();

};