#pragma once
#include <iostream>
using namespace std;
#define WINDOW_WIDTH 1280	//��ʂ̕�
#define WINDOW_HEIGHT 960	//��ʂ̍���


#define DEBUG

//DxLib�̕\���n�֐���xy���W�͑S�Ĉ�����int�̈�double�Ŏw�肷��ƌx�����ł�̂ŗ�O����
#pragma warning(disable: 4244)

//vector��size()�֐����g����for���ɂ�����
//size()�̖߂�l��unsigned int�ɂȂ�signed int�^�Ɣ�r����ƌx�����o��̂ŗ�O����
#pragma warning(disable: 4018)


//�E�Ɣ���悤��enum
typedef enum {
	eTank,
	eCaster,
	eRanger,
	eFighter
}eRole;




