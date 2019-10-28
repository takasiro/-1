#pragma once
#include<iostream>
using namespace std;

#include<string>
#include<vector>
#include"BaseObj.h"
#include"BaseTask.h"
#include"Mouse.h"
#include"Mass.h"
#include"UnitMgr.h"
#include"Unit.h"
#include"fairy.h"
#include"Enemy.h"

class UI :public BaseTask {
private:
	typedef struct {
		string tank = "�^���N";
		string caster = "�L���X�^�[";
		string ranger = "�����W���[";
		string fighter = "�t�@�C�^�[";
	}sRole;

	int playerNumber, enemyNumber;
	string role;
	sRole roleType;
	int NameFontHandle,DataFontHandle,StatusFontHandle;

public:
	UI() { Initialize(); };
	virtual ~UI() {};

	int DrawStatus(int _num);
	string RoleType(int _type);

	int Initialize();	//����������
	int Update();	//�v�Z����
	int Draw();		//�`�揈��
	int Close() { return 0; }		//�I������
};
