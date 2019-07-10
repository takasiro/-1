#pragma once
#include "BaseObj.h"
#include <iostream>
using namespace std;
class fairy :public BaseObj {
protected:
	string *mName;
	int mDamage;//����̍U����
	int	mRange;//����̍U���͈�
	int	mWeight;//���U���ɉe��������ϐ�
	int	mMagicDamage;//���@�U����
public:
	fairy();
	fairy(string *_name,int _damage, int _range, int _weight, int _magicdamage);
	virtual ~fairy();
	int Initialize();
	int Update();
	int Draw();
	int Close();

};