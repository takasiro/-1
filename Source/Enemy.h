#pragma once
#include "Constant.h"
#include"Unit.h"

class Enemy :public Unit {
protected:

	

public:
	Enemy();
	Enemy(int _x, int _y);
	Enemy( char* _name, eRole _role, int _hp, int _str, int _def, int _int, int _mnd,
		int _dex, int _agi, int _move, int _exp, int _lv);
	virtual ~Enemy();

	Unit* GetEnemy() { GetUnit(); }
	int Initialize();//����������
	int Initialize( char* _name, eRole _role, int _hp, int _str, int _def, int _int, int _mnd,
		int _dex, int _agi, int _move, int _exp, int _lv);	//����������(�����t��)
	int Update();	//�v�Z����
	int Draw();		//�`�揈��
	int Close();	//�I������
	int StatusUp(int lv);//���x���A�b�v�̔\�͕ω�


	int LastStatus();//����␳�܂߂��ŏI�X�e�[�^�X
	//�o�O��̂ŃR�����g�A�E�g
	int SetFairy() {
		//�o�O��̂ŃR�����g�A�E�g
		//mEquipSlot = new Fairy();
	}


};