#pragma once
#include<iostream>
using namespace std;
#include <numeric>
#include<vector>
#include"Singleton.h"
#include"Map.h"
#include"Constant.h"
#include"DxLib.h"	
#include "UnitMgr.h"
#include"BaseObj.h"
/*�v�Z���s���N���X
��Ɉړ��͈͂̌v�Z��U���͈͂̌v�Z�Ȃ�*/
class Enemy;
class Chara;
class Fairy;

class UnitMgr;

class Calculator : public BaseObj, public Singleton<Calculator> {


private:
	int debugcount;
	/*�󂯂��Ƃ����}�b�v�����i�[����ϐ��@*/
	vector<Mass>* mCopyMap;
	/*�󂯂��Ƃ����}�b�v���ɕҏW��������Ƃ��Ɏg���ϐ��@*/
	vector<int> mRangeMap;
	/*�󂯂��Ƃ����}�b�v���ɕҏW��������Ƃ��Ɏg���ϐ��@*/
	vector<int> mTmpMap;
	//�ړ����[�g���������
	vector<int> mRootMap;
	/*�e�X�g�@�}�b�v�T�C�Y�̓ǂݍ���*/
	int mMapSize;
	BaseObj::sPos _issuPos;
	int mNowMapWidth;
	int mNowMapHeight;
	int mCharaRange;
	int mRangeArray[8];
	int mTargetNum;//�ړ��ڕW�Ƃ��閡���L����
	unsigned int mColor;
public:
	friend Singleton<Calculator>;

	Calculator();
	virtual	~Calculator();
	virtual	int Initialize();
	virtual	int Update();
	virtual	int  Draw();
	virtual	int Close();
	friend Singleton<Calculator>;
	void AddIssuPos(BaseObj::sPos _pos);
	/*�F�ݒ�֐�
	�������@�ԁ@0�`255
	�������@�΁@0�`255
	��O�����@�@0�`255
	*/
	void SetColor(int _r, int _b, int _g) {
		mColor = GetColor(_r, _b, _g);
	}
	/*�ړ��R�X�g��n�`���画�肵�ĕԂ��֐�
	�����Fint�^�@�n�`�̎��*/
	int SetCost(int _terrain);

	/*�ړ��ł���͈͂��v�Z����*/
	int CulMoveRange(int _x, int _y, int _moveRange);
	/*�ړ��ł���͈͂��v�Z����*/
	int CulMoveRange(Unit::sPos _pos, int _moveRange);
	/*�G�Ɩ���������ʒu�Ɉړ��ł��Ȃ��悤�ɂ���֐�
	����
		  �@���@vector<Chara>&		�L�����f�[�^
			���  vector<Enemy>&	�G�l�~�[�f�[�^
			��O�@ int						�����̗v�f��*/
	int  MoveJudg(vector<Chara*>& _chara, vector<Enemy*>& _enemy, int _num);
	int MoveJudg(BaseObj::sPos _pos);
	void SetMap(Map& _map);

	void SetData(vector<Fairy*>& _fairy) { ; }
	/*���̃}�X���ړ��ł��邩���擾����֐�
	������ �}�b�v�����W
	������ �}�b�v�����W*/
	int GetMoveArea(int _x, int _y) { return mTmpMap[_y * 20 + _x]; }
	/*���̃}�X���ړ��ł��邩���擾����֐�
	������ �}�b�v���W
	*/
	int GetMoveArea(Unit::sPos _pos) {
		return mTmpMap[(int)_pos.y * 20 + (int)_pos.x];
	}


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
	int HitCalculate(Unit �U�������j�b�g,Unit �h�䑤���j�b�g);
	����m���v�Z�֐�
	�����F
	�������@�U�������j�b�g
	�������@�h�䑤���j�b�g
	�߂�l�F���������������
	*************************************************/
	int HitCalculate(Unit _Atk, Unit _def);

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
	/************************************************
	int NearCaluculate(Unit �U�������j�b�g,Unit �h�䑤���j�b�g);
	�����v�Z����
	�����F
	�������@�G�̍��W
	�������@
	�߂�l�F��ԋ߂��L�����̗v�f��
	*************************************************/
	int NearCaluculate(int _x, int _y, int _range, int _index, int _area);
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
	int CulRange(int _x, int _y, int _range, int _index, int* _ary);
	int RootCreate(BaseObj::sPos, vector<int>& _dir);
	int RootCreate(int _x, int _y);

	int CreateDir(BaseObj::sPos _pos, vector<int>& _dir);

	int ActivetMove() {
		return accumulate(mRootMap.begin(), mRootMap.end(), 0);
	}
};
