#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include"BaseTask.h"
#include"Mass.h"
class Map :public BaseTask {
private:
	//�}�X�n�`�̑I��p
	typedef enum Terrain {
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
	vector<Mass> mMap;
	vector<int> mConnect;//�ڑ�����Ă���}�b�v�ԍ�������
	int mMapNum;//�}�b�v�ԍ�
	Terrain terrain;
	unsigned int color;
public:
	Map();
	//Map(Mass*,int,int);

	virtual int Initialize();	//����������
	virtual int Update();		//�v�Z����
	virtual int Draw();			//�`�揈��
	virtual int Close();		//�I������
	//�}�b�v�f�[�^�̓ǂݍ���
	int FileRead(string);

	int GetMass(int _x) { mMap[_x].GetMass(); }
	vector<Mass>& GetMap() { return mMap; }
	
	void MassDraw(int _landType);
};