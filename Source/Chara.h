#pragma once
#include<iostream>
using namespace std;
#include "Unit.h"
#include"Fairy.h"
#include"Constant.h"
#include"DxLib.h"

class Chara :public Unit {
private:
	//�v����
	double mHpPercent;
	unsigned int mColor;//�F
	unsigned int mHpColor;//�̗͐F
	int mState;
	int MoveJudgeState(int _A);
	int MoveState(int _a);
	int AttackJudgeState(int _a);
	int AttackState(int _a);
	int (Chara::* Fanctions[10])(int _a);
public:
	Chara();
	Chara(short _id,string _name, eRole _role, eWeapon _weapon ,int _hp, int _str, int _def, int _int, int _mnd,
		int _dex, int _agi, int _move, int _exp, int _lv);
		
	
	Chara(int x, int y);

	//Chara(Unit);
	~Chara();
	//Chara(Chara&);

	int Initialize();//����������
	int Initialize(short _id,string _name, eRole _role, eWeapon _weapon, int _hp, int _str, int _def, int _int, int _mnd,
		int _dex, int _agi, int _move, int _exp, int _lv);	//����������(�����t��)
	
	int Update();	//�v�Z����
	int Update(int _num);	//�v�Z����
	int Draw();		//�`�揈��
	int Close();	//�I������
	/*�ړ�����*/
	int Move(Unit::sPos _pos);
	int StatusUp(int lv);//���x���A�b�v�̔\�͕ω�
	int LastStatus();//����␳�܂߂��ŏI�X�e�[�^�X]

	/*����������֐�
	���� Fairy _fairy ����������t�F�A���[���A
	int _num ����������ꏊ*/
	/*int SetFairy(Fairy _fairy, int _num) {
		mEquipSlot.emplace_back(new Fairy(_fairy));
		return 0;
	}*/
	/*��������Ă�����̂̏����擾����֐�
	���� int _num ��������Ă���ꏊ*/
	/*Fairy GetFairy(int _num) {
		if (_num<0 && _num >mEquipSlot.size()) {
			;
		}
		else return *mEquipSlot[_num];
	}*/

	/*void operator + (sPos _pos) {
		mPos.x += _pos.x;
		mPos.y += _pos.y;
	}*/

};