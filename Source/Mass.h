#pragma once
#include<iostream>
using namespace std;


class Mass {
private:
	int mGrHandle;//�O���t�B�b�N�n���h��
	int mLandType;//�n�`�̎��
	int mMoveCost;//�ړ�����̂ɕK�v�ȃR�X�g
public:
	Mass(int _grHandle = 0, int _landtype = 0, int _movecost = 0);
	virtual ~Mass();
	int GetType() { return mLandType; }
	int GetMoveCost() { return mMoveCost; }
};
