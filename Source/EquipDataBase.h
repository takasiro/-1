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

	class EquipData {
	private:
		int id;  //ID
		int charaId;  //�L�����N�^�[ID
		int equipId;  //�����iID
	public:
		EquipData(int _id, int _charaId, int _equipId) { id = _id; charaId = _charaId; equipId = _equipId; };

		int GetId() { return id; }
		int GetCharaId() { return charaId; }
		int GetEquipId() { return equipId; }

		int Initialize() { return 0; }	//����������
		int Close() { return 0; }		//�I������
	};

	vector<EquipData*> eqData;

public:
	EquipDataBase() { Initialize(); };
	virtual ~EquipDataBase() {};

	void SetEquipData(int _charaId, int _equipId) { eqData.emplace_back(new EquipData(eqData.size()+1, _charaId, _equipId)); };

	int GetEqCount(int _charaId);  //�f�[�^�x�[�X�ɃL�����i���o�[i���������邩
	int GetEq(int _charaId, int _eqNum);  //i�Ԗڂ̃L������j�ڂ̑���
	void DeleteEq(int _charaId, int _eqId);  //�L����i��j�𑕔������@�G���[������

	int Initialize();	//����������
	int Update() { return 0; }		//�v�Z����
	int Draw() { return 0; }		//�`�揈��
	int Close() { return 0; }		//�I������
};