#pragma once
#include <iostream>
#include<vector>
using namespace std;
#include "Unit.h"
#include "BaseTask.h"

//�G�Ɩ����̏���ێ�����N���X
class UnitMgr :public BaseTask {

private:
	vector<Unit> CharaDate;
	vector<Unit> EnemyDate;

public:
	//�L�����f�[�^�̒ǉ��E����
	//����Unit�^�|�C���^
	//int SetCharaData(Unit* _chara) {
	//	CharaDate.push_back(*_chara);
	//	return 0; 
	//}
	////�G�l�~�[�f�[�^�̎擾
	////����Unit�^�|�C���^
	//int SetCharaData(Unit* _chara) {
	//	EnemyDate.push_back(*_chara);
	//	return 0;
	//}

	vector<Unit>& GetCharaData() {
		return CharaDate;
	}

	/*int GetCharaData(Unit* _chara) {
		for (auto itr = CharaDate.begin; itr < CharaDate.end(); itr++) {
			if (&CharaDate+itr==_chara) {
				return &CharaDate + itr;
			}
		}
		return 0;
	}*/


	vector<Unit>& GetEnemyData() {
		return EnemyDate;
	}

	//�G�l�~�[�f�[�^�̎擾
	//����Unit�^�|�C���^
	/*int GetEnemyData(Unit* _chara) {
		for (auto itr = EnemyDate.begin; itr < EnemyDate.end(); itr++) {
			if (EnemyDate + itr == _chara) {
				return EnemyDate + itr;
			}
			return 0;
		}
	}*/
	virtual int Initialize() { return 0; }	//����������
	virtual int Update() { return 0; }//�v�Z����
	virtual int Draw() { return 0; }			//�`�揈��
	virtual int Close() { return 0; }		//�I������

};