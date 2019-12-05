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
		int charaId;  //�L�����N�^�[ID
		int equipId;  //�����iID
	public:
		EquipData() { ; };
		EquipData(int _id, int _charaId, int _equipId) { id = _id; charaId = _charaId; equipId = _equipId; };

		//�e��f�[�^�̎擾�֐�
		int GetId() { return id; }
		int GetCharaId() { return charaId; }
		int GetEquipId() { return equipId; }

		int Initialize() { return 0; }	//����������
		int Close() { return 0; }		//�I������
	};

	vector<EquipData*> eqData;  //�����f�[�^�z��

public:
	EquipDataBase() { Initialize(); };
	virtual ~EquipDataBase() {};


	int GetEqCount(int _charaId);  //����L�����̑������퐔���擾
	int GetEq(int _charaId, int _eqNum);  //����L�����̎w����ڂ̕���ID���擾

	void SetEquipData(int _charaId, int _equipId);  //�����f�[�^�̒ǉ�

	void DeleteEq(int _charaId, int _eqId);  //����L�����̑����f�[�^������

	int Initialize();	//����������
	int Update() { return 0; }		//�v�Z����
	int Draw() { return 0; }		//�`�揈��
	int Close() { return 0; }		//�I������
};