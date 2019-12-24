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

//�V���O���g���}�N�� EquipDataBase���̊֐����g�p����Ƃ��Ɏg���Ă��������B�@��)EquipDB->Get����();
#define EquipDB EquipDataBase::Instance()

class EquipDataBase :public BaseTask, public Singleton<EquipDataBase> {
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

	friend Singleton<EquipDataBase>;

	int GetDataCount(eClass _unitType);  //�����f�[�^�̐����擾

	int GetEqCount(eClass _unitType, short _charaId);  //����L�����̑������퐔���擾
	int GetEq(eClass _unitType, short _charaId, short _eqNum);  //����L�����̎w����ڂ̕���ID���擾

	void SetEquipData(eClass _unitType, short _charaId, short _equipId);  //�����f�[�^�̒ǉ�

	void DeleteEq(eClass _unitType, short _charaId, short _eqId);  //����L�����̑����f�[�^������

	int Initialize();	//����������
	virtual int Update() { return 0; }		//�v�Z����
	virtual int Draw() { return 0; }		//�`�揈��
	virtual int Close() { return 0; }		//�I������
};