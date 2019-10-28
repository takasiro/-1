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
#include"Calculator.h"
#include "Mouse.h"
#include "Button.h"

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
	Calculator cul;
	void DataInit() {
		CharaDate.clear();
		EnemyDate.clear();
		FairyDate.clear();
		CharaDate.shrink_to_fit();
		EnemyDate.shrink_to_fit();
		FairyDate.shrink_to_fit();
	}
private:
	vector<Chara*> CharaDate;
	vector<Enemy*> EnemyDate;
	vector<Fairy*>FairyDate;

	int color;
	Unit::sPos prevPos;
	Unit::sPos mousePos;
	Unit::sPos mapPos;
	int mState;
	int mouseButton;
	int lastMouseButton;

	int (UnitMgr::* Fanctions[10])(int _a);
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

	/**************************************************************************
	�t�F�A���|�𑕔�������֐�
	�^:int

	����:Fairy _fairy...�Z�b�g����Fairy�̏��
			int _index �Z�b�g����L�����̗v�f��
	�@ �@int _num,�c�Z�b�g�������������ꏊ
	***************************************************************************/
	int SetFairyChara(Fairy _fairy, int _index, int _num) {
		CharaDate[_index]->SetFairy(_fairy, _num);
	}

	/**************************************************************************
	�����l�擾�֐�(chara)
	�^:int

	����:int _index set�������L�����̗v�f��
	***************************************************************************/
	int SetCharaGrowth(int _index, float _hp, float _str, float _def, float _int, float _mnd, float _dex, float _agi) {
		CharaDate[_index]->SetGrowth(_hp, _str, _def, _int, _mnd, _dex, _agi);
		return 0;
	}
	/**************************************************************************
	�����l�擾�֐�(enemy)
	�^:int

	����:int _index  set�������G�l�~�[�̗v�f��
	***************************************************************************/
	int SetEnemyGrowth(int _index, float _hp, float _str, float _def, float _int, float _mnd, float _dex, float _agi) {
		EnemyDate[_index]->SetGrowth(_hp, _str, _def, _int, _mnd, _dex, _agi);
		return 0;
	}
	/**************************************************************************
	�����l�擾�֐�(fairy)
	�^:int

	����:int _index  set�������t�F�A���[�̗v�f��
	***************************************************************************/
	int SetFairyGrowth(int _index, float _hp, float _str, float _def, float _int, float _mnd, float _dex, float _agi) {
		FairyDate[_index]->SetGrowth(_hp, _str, _def, _int, _mnd, _dex, _agi);
		return 0;
	}

	int GetCharaDataSize() { return CharaDate.size(); }
	int GetEnemyDataSize() { return EnemyDate.size(); }
	int GetFairyDataSize() { return FairyDate.size(); }

	vector<Enemy*>& GetEnemyDate() { return EnemyDate; }
	vector<Chara*>& GetCharaDate() { return CharaDate; }
	vector<Fairy*>& GetFairyDate() { return FairyDate; }

	Enemy& GetEnemyDate(int _num) { return *EnemyDate[_num]; }
	Chara& GetCharaDate(int _num) { return *CharaDate[_num]; }
	Fairy& GetFairyDate(int _num) { return *FairyDate[_num]; }

	/*�}�E�X�̈ʒu����ǂ���N���b�N���������肷��
	������ sPos �}�E�X���W
	�������@int ���������� 0 �v���C���[�@1�G�l�~�[�@2�t�F�A���[*/
	int CulNum(BaseObj::sPos _arg, int _type);
	void SetMapData(Map& _map) { cul.SetMap(_map); }
	virtual int Initialize();	//����������
	virtual int Update();	//�v�Z����
	virtual int Update(int _a);	//�v�Z����
	virtual int Draw();		//�`�揈��
	virtual int Close();		//�I������
	/*�S�����s���ς݂����肷��
	�����@int �v���C���[�̃^�[�����G�̃^�[��������
	1:�v���C���[�̃^�[��
	-1:�G�̃^�[��
	�߂�l 0 ���s��
			 1�@�s���ς�*/
	int CheckStay(int _turn);
	void InitCharaStayFlg() {
		for (int i = 0; i < CharaDate.size(); i++) {
			CharaDate[i]->SetStayFlg(false);
		}
	}
	void InitEnemyStayFlg() {
		for (int i = 0; i < EnemyDate.size(); i++) {
			EnemyDate[i]->SetStayFlg(false);
		}
	}

	void SetEnemyStayFlg() {
		for (int i = 0; i < EnemyDate.size(); i++) {
			EnemyDate[i]->SetStayFlg(true);
		}
	}
	/**************************************************************************
	�^:void
	���� : int _num, �c�Z�b�g�������G�̗v�f��
	sPos _pos....�Z�b�g���������W�\����
	***************************************************************************/
	void SetCharaPos(int _num, Unit::sPos _pos) {
		CharaDate[_num]->SetPos(_pos);
	}
	/**************************************************************************
�^:void
����: int _num,�c�Z�b�g�������G�̗v�f��
	 sPos _pos....�Z�b�g���������W�\����
***************************************************************************/
	void SetEnemyPos(int _num, Unit::sPos _pos) {
		EnemyDate[_num]->SetPos(_pos);
	}

	/**************************************************************************
�^:int 0�S�����j���Ă��Ȃ��@1�S�����j�ς�
����: int _type ����������Unit�̎��
***************************************************************************/
	int GetOnActive(int _type) {
		if(_type == eChara)	for (int i = 0; i < GetEnemyDataSize(); i++) {
			if (CharaDate[i]->GetOnActive() == true)return 0;
		}
		else if (_type == eEnemy) 	for (int i = 0; i < GetEnemyDataSize(); i++) {
			if (EnemyDate[i]->GetOnActive() == true)return 0;
		}
		return 1;
	}
	/**************************************************************************
�^:int 0�S���s�����Ă��Ȃ��@1�S���s���ς�
����: int _type ����������Unit�̎��
***************************************************************************/
	int GetStayFlg(int _type) {
		if (_type == eChara)	for (int i = 0; i < GetCharaDataSize(); i++) {
			if (CharaDate[i]->GetStayFlg() == false)return 0;
		}
		else if (_type == eEnemy) 	for (int i = 0; i < GetEnemyDataSize(); i++) {
			if (EnemyDate[i]->GetStayFlg() == false)return 0;
		}
		return 1;
	}
	int MoveJudgeState(int);
	int MoveState(int);
	int AttackJudgeState(int);
	int AttackState(int);

};