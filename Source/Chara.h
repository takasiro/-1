#pragma once
#include<iostream>
using namespace std;
#include "Unit.h"
#include"Constant.h"
#include"DxLib.h"
class Chara :public Unit {


public:
	Chara();
	Chara(eRole _role, char* _name, int _hp, int _str, int _def, int _int, int _mnd,
		int _dex, int _agi, int _move, int _exp, int _lv);
	Chara(int x, int y);
	
	Chara(Unit);
	~Chara();
	Chara(Chara&);

	int Initialize();//����������
	int Initialize(eRole _role, char* _name, int _hp, int _str, int _def, int _int, int _mnd,
		int _dex, int _agi, int _move, int _exp, int _lv);	//����������(�����t��)
	int Update();	//�v�Z����
	int Draw();		//�`�揈��
	int Close();	//�I������
	int StatusUp(int lv);//���x���A�b�v�̔\�͕ω�
	int LastStatus();//����␳�܂߂��ŏI�X�e�[�^�X

};