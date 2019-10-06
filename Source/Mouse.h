#pragma once
#include "BaseObj.h"
#include "Singleton.h"
#include "DxLib.h"

#define GET_BUTTON Mouse::Instance()->GetMouseButton	//�L�[�l���ȈՉ�
#define GET_WHEEL Mouse::Instance()->GetMouseWheel	//�L�[�l���ȈՉ�
#define GET_POSITION Mouse::Instance()->GetMouse_Pos	//�L�[�l���ȈՉ�
#define RIGHTCLICK (Mouse::GET_BUTTON() & MOUSE_INPUT_RIGHT)//�E�N���b�N�����ꂽ��
#define LEFTCLICK (Mouse::GET_BUTTON() & MOUSE_INPUT_LEFT)//���N���b�N�����ꂽ��

class Mouse :public Singleton<Mouse> , public BaseObj{
	Mouse() { mButton=0, mWheel=0; }
	friend Singleton<Mouse>;
//protected:
	int mButton, mWheel;
public:
	int Update() {
		static int tmpx, tmpy;
		mButton = GetMouseInput();                //�}�E�X�̓��͏�Ԏ擾
		mWheel = GetMouseWheelRotVol();  //�z�C�[���̉�]�ʎ擾
		GetMousePoint(&tmpx, &tmpy);                //�}�E�X�̍��W�擾
		mPos.x = tmpx;
		mPos.y = tmpy;
		return 0;
	}
	int Draw() { return 0; }
	sPos GetMouse_Pos() { return mPos; }
	int GetMouseButton() { return mButton; }
	int GetMouseWheel(){ return mWheel; }

	int Initialize() { return 0; }
	int Close() { return 0; }

};
