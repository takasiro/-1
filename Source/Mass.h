#pragma once
#include<iostream>
using namespace std;


class Mass {
private:
	int mGrHandle;//�O���t�B�b�N�n���h��
	int mLandType;//�n�`�̎��
	int mMoveCost;//�ړ�����̂ɕK�v�ȃR�X�g
public:
	Mass() { ; }
	Mass(int _grHandle, int _landtype, int _movecost);
	virtual ~Mass() { ; }
	Mass* GetMass() { return this; }
	int GetLandType() { return mLandType; }
	int GetMoveCost() { return mMoveCost; }
};
