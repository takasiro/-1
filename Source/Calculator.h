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
class Enemy;
class Chara;
class Fairy;
class Calculator {


private:

	/*�󂯂��Ƃ����}�b�v�����i�[����ϐ��@*/
	static vector<Mass>* mCopyMap;
	/*�󂯂��Ƃ����}�b�v���ɕҏW��������Ƃ��Ɏg���ϐ��@*/
	static vector<int> mRangeMap;
	/*�󂯂��Ƃ����}�b�v���ɕҏW��������Ƃ��Ɏg���ϐ��@*/
	static vector<int> mTmpMap;
	//�ړ����[�g���������
	static vector<int> mRootMap;
	/*�e�X�g�@�}�b�v�T�C�Y�̓ǂݍ���*/
	static	int mMapSize;

	static int mNowMapWidth;
	static int mNowMapHeight;
	static int mCharaRange;
public:
	Calculator();
	static void Initialize();
	static void  Draw();
	/*�ړ��R�X�g��n�`���画�肵�ĕԂ��֐�
	�����Fint�^�@�n�`�̎��*/
	static int SetCost(int _terrain);

	/*�ړ��ł���͈͂��v�Z����*/
	static	int CulMoveRange(int _x, int _y, int _moveRange);
	/*�ړ��ł���͈͂��v�Z����*/
	static	int CulMoveRange(Unit::sPos _pos, int _moveRange);
	/*�G�Ɩ���������ʒu�Ɉړ��ł��Ȃ��悤�ɂ���֐�
	����
		  �@���@vector<Chara>&		�L�����f�[�^
			���  vector<Enemy>&	�G�l�~�[�f�[�^
			��O�@ int						�����̗v�f��*/
	static int  MoveJudg(vector<Chara*>& _chara, vector<Enemy*>& _enemy, int _num);

	static	void SetMap(Map& _map);

	static	void SetData(vector<Fairy*>& _fairy) { ; }
	/*���̃}�X���ړ��ł��邩���擾����֐�
	������ �}�b�v�����W
	������ �}�b�v�����W*/
	static int GetMoveArea(int _x, int _y) { return mTmpMap[_y * 20 + _x]; }
	/*���̃}�X���ړ��ł��邩���擾����֐�
	������ �}�b�v���W
	*/
	static int GetMoveArea(Unit::sPos _pos) { return mTmpMap[(int)_pos.y * 20 + (int)_pos.x]; }


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
	int HitCalculate(Unit �U�������j�b�g,Unit �h�䑤���j�b�g);
	����m���v�Z�֐�
	�����F
	�������@�U�������j�b�g
	�������@�h�䑤���j�b�g
	�߂�l�F���������������
	*************************************************/
	static	int HitCalculate(Unit _Atk, Unit _def);

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
	/************************************************
	int NearCaluculate(Unit �U�������j�b�g,Unit �h�䑤���j�b�g);
	�����v�Z����
	�����F
	�������@�G�̍��W
	�������@
	�߂�l�F��ԋ߂��L�����̗v�f��
	*************************************************/
	static int NearCaluculate(int _x, int _y, int _range, int _index, int _area);
	/************************************************
int NearCaluculate(Unit �U�������j�b�g,Unit �h�䑤���j�b�g);
�����v�Z����
�����F
������,�������@�@�G�̍��W
��O�����@�����͈�
��l�����@��������L�����̗v�f��
��܈����@�v�f�����󂯎��ϐ��̃A�h���X
�߂�l�F��ԋ߂��L�����̗v�f��
*************************************************/
	static int CulRange(int _x, int _y, int _range, int _index, int* _ary);
	static int RootCreate(BaseObj::sPos, vector<int> &_dir);
	static int RootCreate(int _x, int _y);
};
