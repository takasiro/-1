#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include"BaseTask.h"
#include"Mass.h"
#include "BaseObj.h"
class Map :public BaseTask {
public:
	//�}�X�n�`�̑I��p
	typedef enum eTerrain {
		eGrassland = 1,
		eGrass,
		eRock,
		eRiver,
		eHill,
		eVillage,
		eForest,
		eVolcanoSoil,
		eMagma,
		eVolcanoRock,
		eCaveSoil,
		eCaveRock,
		eDemonKingFloor,
		eDemonKingPillars,
		eDemonKingCarpet
	};
private:
	vector<Mass> mMap;
	vector<int> mConnect;//�ڑ�����Ă���}�b�v�ԍ�������
	int mMapNum;//�}�b�v�ԍ�
	eTerrain terrain;
	unsigned int color;
	int* mGrHandles;	//�O���t�B�b�N�n���h����������ꍇ
	int mGrHandlesCount;	//��������ꍇ�̌�
	BaseObj::sPos mMapPos;//�}�b�v��\�����鍶�㌴�_�l
	int mMapWidth;//�}�b�v�̉���
	int mMapHeight;//�}�b�v�̏c��
public:
	Map();
	//Map(Mass*,int,int);
	virtual ~Map();
	virtual int Initialize();	//����������
	virtual int Update();		//�v�Z����
	virtual int Draw();			//�`�揈��
	virtual int Close();		//�I������


	int GetMass(int _x) { mMap[_x].GetMass(); }
	vector<Mass>& GetMap() { return mMap; }
	vector<Mass>* GetMapAdress() { return &mMap; }
	int GetMapSize() { return mMap.size(); }
	int MassDraw(int _landType);

	void operator +(BaseObj::sPos _pos) {
		mMapPos.x += _pos.x;
		mMapPos.y += _pos.y;
	}

	int GetMapWidth() { return mMapWidth; }
	int GetMapHeight() { return mMapHeight; }
};