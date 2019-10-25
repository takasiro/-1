#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include"BaseTask.h"
#include"Map.h"
#include"Constant.h"
#include"Chara.h"
#include "Enemy.h"
#include "Unit.h"
#include"DxLib.h"	

/*�v�Z���s���N���X
��Ɉړ��͈͂̌v�Z��U���͈͂̌v�Z�Ȃ�*/
class Calculator {
private:
	/*�󂯂��Ƃ����}�b�v�����i�[����ϐ��@*/
	vector<Mass>* mCopyMap;
	/*�󂯂��Ƃ����}�b�v���ɕҏW��������Ƃ��Ɏg���ϐ��@*/
	vector<int> mTmpMap;
	typedef enum eDirection {
		UP,
		RIGHT,
		DOWN,
		LEFT
	};
	/*�e�X�g�@�}�b�v�T�C�Y�̓ǂݍ���*/
	int mMapSize;
public:
	Calculator();

	void Initialize();
	/*�ړ��R�X�g��n�`���画�肵�ĕԂ��֐�
	�����Fint�^�@�n�`�̎��*/
	int SetCost(int _terrain);

	/*�ړ��ł���͈͂��v�Z����*/
	int CulMoveRange(int _x, int _y, int _moveRange);
	/*�G�Ɩ���������ʒu�Ɉړ��ł��Ȃ��悤�ɂ���֐�
	����
		  �@���@vector<Chara>&		�L�����f�[�^
			���  vector<Enemy>&	�G�l�~�[�f�[�^
			��O�@ int						�����̗v�f��*/
	int MoveJudg(vector<Chara*>& _chara, vector<Enemy*>& _enemy, int _num);

	void SetMap(Map& _map) {
		mCopyMap = _map.GetMapAdress();
		mMapSize = _map.GetMapSize();
		mTmpMap = vector<int>(mMapSize, -1);
		printf("%d", mTmpMap.size());
	}
	/*���̃}�X���ړ��ł��邩���擾����֐�
	������ int x��
	������ int y��*/
	int GetMoveArea(int _x, int _y) { return mTmpMap[_y * 20 + _x]; }


	/************************************************
	int PhysicalDamageCalculate(Unit �U�������j�b�g,Unit �h�䑤���j�b�g);
	�����_���[�W�v�Z�֐�
	�����F
	�������@�U�������j�b�g
	�������@�h�䑤���j�b�g
	�߂�l�F�_���[�W��
	�_���[�W�̓}�C�i�X�ɂ͂Ȃ�Ȃ�
	*************************************************/
	int PhysicalDamageCalculate(Unit _Atk, Unit _def);

	/************************************************
	int MagicDamageCalculate(Unit �U�������j�b�g,Unit �h�䑤���j�b�g);
	���@�_���[�W�v�Z�֐�
	�����F
	�������@�U�������j�b�g
	�������@�h�䑤���j�b�g
	�߂�l�F�_���[�W��
	�_���[�W�̓}�C�i�X�ɂ͂Ȃ�Ȃ�
	*************************************************/
	int MagicDamageCalculate(Unit _Atk, Unit _def);
};
