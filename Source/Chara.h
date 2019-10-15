#pragma once
#include<iostream>
using namespace std;
#include "Unit.h"
#include"Fairy.h"
#include"Constant.h"
#include"DxLib.h"
class Chara :public Unit {
private:
	vector<Fairy*> mEquipSlot;//�����g
	unsigned int mColor;//�F
public:
	Chara();
	Chara(char* _name, eRole _role, int _hp, int _str, int _def, int _int, int _mnd,
		int _dex, int _agi, int _move, int _exp, int _lv);
		
	
	Chara(int x, int y);

	//Chara(Unit);
	~Chara();
	//Chara(Chara&);

	int Initialize();//����������
	int Initialize(char* _name, eRole _role, int _hp, int _str, int _def, int _int, int _mnd,
		int _dex, int _agi, int _move, int _exp, int _lv);	//����������(�����t��)
	
	int Update();	//�v�Z����
	int Draw();		//�`�揈��
	int Close();	//�I������
	/*�ړ�����*/
	int Move(int, int);
	int StatusUp(int lv);//���x���A�b�v�̔\�͕ω�
	int LastStatus();//����␳�܂߂��ŏI�X�e�[�^�X]

	//����������֐�
	//���� ����������Fairy�^�A����������ꏊ
	int SetFairy(Fairy* _fairy, int _num) {
		mEquipSlot[_num] = _fairy;
		if (mEquipSlot[_num] == _fairy)return 0;
		else return 1;
	}

};