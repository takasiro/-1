#pragma once
#include<iostream>
using namespace std;
#include<vector>

#include"Map.h"
#include"Constant.h"
#include"DxLib.h"	
#include "UnitMgr.h"


/*�v�Z���s���N���X
��Ɉړ��͈͂̌v�Z��U���͈͂̌v�Z�Ȃ�*/
class Calculator {


private:
	typedef enum Direction {
		eUP,
		eRIGHT,
		eDOWN,
		eLEFT
	}dir;
	/*�󂯂��Ƃ����}�b�v�����i�[����ϐ��@*/
	static vector<Mass>* mCopyMap;
	/*�󂯂��Ƃ����}�b�v���ɕҏW��������Ƃ��Ɏg���ϐ��@*/
	static vector<int> mTmpMap;
	/*�e�X�g�@�}�b�v�T�C�Y�̓ǂݍ���*/
	static	int mMapSize;

public:
	Calculator();
	static void Initialize();
	/*�ړ��R�X�g��n�`���画�肵�ĕԂ��֐�
	�����Fint�^�@�n�`�̎��*/
	static int SetCost(int _terrain);

	/*�ړ��ł���͈͂��v�Z����*/
	static	int CulMoveRange(int _x, int _y, int _moveRange);
	/*�G�Ɩ���������ʒu�Ɉړ��ł��Ȃ��悤�ɂ���֐�
	����
		  �@���@vector<Chara>&		�L�����f�[�^
			���  vector<Enemy>&	�G�l�~�[�f�[�^
			��O�@ int						�����̗v�f��*/
	static int  MoveJudg(vector<Chara*>& _chara, vector<Enemy*>& _enemy, int _num);

	static	void SetMap(Map& _map);

	static	void SetData(vector<Fairy*>& _fairy) { ; }
	/*���̃}�X���ړ��ł��邩���擾����֐�
	������ int x��
	������ int y��*/
	static int GetMoveArea(int _x, int _y) { return mTmpMap[_y * 20 + _x]; }


	/************************************************
	int PhysicalDamageCalculate(Unit �U�������j�b�g,Unit �h�䑤���j�b�g);
	�����_���[�W�v�Z�֐�
	�����F
	�������@�U�������j�b�g
	�������@�h�䑤���j�b�g
	�߂�l�F�_���[�W��
	�_���[�W�̓}�C�i�X�ɂ͂Ȃ�Ȃ�
	*************************************************/
	static int PhysicalDamageCalculate(Unit _Atk, Unit _def);

	/************************************************
	int EvasionCalculate(Unit �U�������j�b�g,Unit �h�䑤���j�b�g);
	����m���v�Z�֐�
	�����F
	�������@�U�������j�b�g
	�������@�h�䑤���j�b�g
	�߂�l�F���������������
	*************************************************/
	static	int EvasionCalculate(Unit _Atk, Unit _def);

	/************************************************
	int MagicDamageCalculate(Unit �U�������j�b�g,Unit �h�䑤���j�b�g);
	���@�_���[�W�v�Z�֐�
	�����F
	�������@�U�������j�b�g
	�������@�h�䑤���j�b�g
	�߂�l�F�_���[�W��
	�_���[�W�̓}�C�i�X�ɂ͂Ȃ�Ȃ�
	*************************************************/
	static int MagicDamageCalculate(Unit _Atk, Unit _def);
};
