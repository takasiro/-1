#pragma once

#ifndef _INCLUDE_KEYBOARD_
#define _INCLUDE_KEYBOARD_

#include "Singleton.h"
#include "DxLib.h"

#define GET_KEY Keyboard::Instance()->Get	//�L�[�l���ȈՉ�

class Keyboard :public Singleton <Keyboard>{
	Keyboard() {}
	friend Singleton <Keyboard>;
private:
	int Key[256];  // �L�[�̓��͏�Ԋi�[�p�ϐ�
public:
	void Update() {
		char tmpKey[256];             // ���݂̃L�[�̓��͏�Ԃ��i�[����
		GetHitKeyStateAll(tmpKey);  // �S�ẴL�[�̓��͏�Ԃ𓾂�
		for (int i = 0; i<256; i++) {
			if (tmpKey[i] != 0) { // i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
				Key[i]++;   // ���Z
			}
			else {              // ������Ă��Ȃ����
				Key[i] = 0; // 0�ɂ���
			}
		}
	}
	int Get(int KeyCode) {
		return Key[KeyCode]; // KeyCode�̓��͏�Ԃ�Ԃ�
	}

};


#endif