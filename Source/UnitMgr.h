#pragma once
#include <iostream>
#include<vector>
using namespace std;
#include "Unit.h"
#include "BaseTask.h"
#include"Singleton.h"
#include "Fairy.h"
#include "Chara.h"
#include "Enemy.h"

//�V���O���g���}�N���@UnitMgr::Instance()
#define INSTANCE UnitMgr::Instance()
#define PLAYER 0
#define ENEMY 1
#define FAIRY 2

/*Chara Enemy Fairy�f�[�^���ꊇ�Ǘ�����N���X
���̎擾�Ȃǂ͂��̃N���X�ōs��*/
class UnitMgr :public BaseTask, public Singleton<UnitMgr> {
public:
	UnitMgr();
	~UnitMgr();
	friend Singleton<UnitMgr>;


private:

	vector<Chara*> CharaDate;
	vector<Enemy*> EnemyDate;
	vector<Fairy*>FairyDate;

public:
	/*�L�����f�[�^�̐���
	���� Chara�^�@�I�u�W�F�N�g*/
	int SetCharaData(Chara _chara) {
		CharaDate.emplace_back(new Chara(_chara));
		return 0;
	}
	/*�G�l�~�[�f�[�^����
		���� Enemy�^�@�I�u�W�F�N�g*/
	int SetEnemyData(Enemy _chara) {
		EnemyDate.emplace_back(new Enemy(_chara));
		return 0;
	}
	/*�t�F�A���[�f�[�^����
		���� Fairy�^�@�I�u�W�F�N�g*/
	int SetFairyDate(Fairy _fairy) {
		FairyDate.emplace_back(new Fairy(_fairy));
		return 0;
	}




	//int GetCharaData(Unit* _chara) {
	//	for (auto itr = CharaDate.begin; itr < CharaDate.end(); itr++) {
	//		if (CharaDate+itr==_chara) {
	//			return CharaDate + itr;
	//		}
	//	}
	//	return 0;
	//}
	////�G�l�~�[�f�[�^�̎擾
	////����Unit�^�|�C���^
	//int GetEnemyData(Unit* _chara) {
	//	for (auto itr = EnemyDate.begin; itr < EnemyDate.end(); itr++) {
	//		if (EnemyDate + itr == _chara) {
	//			return EnemyDate + itr;
	//		}
	//		return 0;
	//	}
	//}
	vector<Enemy*>* GetEnemyDate() { return &EnemyDate; }
	vector<Chara*>* GetCharaDate() { return &CharaDate; }
	vector<Fairy*>* GetFairyDate() { return &FairyDate; }
	/*�}�E�X�̈ʒu����ǂ���N���b�N���������肷��
	������ sPos �}�E�X���W
	�������@int ���������� 0 �v���C���[�@1�G�l�~�[�@2�t�F�A���[*/
	int CulNum(BaseObj::sPos _arg,int _type);

	virtual int Initialize();	//����������
	virtual int Update();	//�v�Z����
	virtual int Update(int _a);	//�v�Z����
	virtual int Draw();		//�`�揈��
	virtual int Close();		//�I������
};