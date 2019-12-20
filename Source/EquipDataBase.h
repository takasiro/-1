#pragma once
#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include"BaseObj.h"
#include"BaseTask.h"
#include"Mass.h"
#include"UnitMgr.h"
#include"Unit.h"
#include"fairy.h"
#include"Enemy.h"

class EquipDataBase :public BaseTask {
private:

	class EquipData {  //�����f�[�^�N���X
	private:
		int id;  //ID
		int unitId;  //�L�����N�^�[ID
		int equipId;  //�����iID
	public:
		EquipData() { ; };
		EquipData(int _id, int _charaId, int _equipId) { id = _id; unitId = _charaId; equipId = _equipId; };

		//�e��f�[�^�̎擾�֐�
		int GetId() { return id; }
		int GetUnitId() { return unitId; }
		int GetEquipId() { return equipId; }

		int Initialize() { return 0; }	//����������
		int Close() { return 0; }		//�I������
	};

	vector<EquipData*> charaEqData;  //�����f�[�^�z��
	vector<EquipData*> enemyEqData;  //�����f�[�^�z��

public:
	EquipDataBase() { Initialize(); };
	virtual ~EquipDataBase() {};


	int GetEqCount(eClass _unitType,int _charaId);  //����L�����̑������퐔���擾
	int GetEq(eClass _unitType, int _charaId, int _eqNum);  //����L�����̎w����ڂ̕���ID���擾

	void SetEquipData(eClass _unitType, int _charaId, int _equipId);  //�����f�[�^�̒ǉ�

	void DeleteEq(eClass _unitType, int _charaId, int _eqId);  //����L�����̑����f�[�^������

	int Initialize();	//����������
	int Update() { return 0; }		//�v�Z����
	int Draw() { return 0; }		//�`�揈��
	int Close() { return 0; }		//�I������
};